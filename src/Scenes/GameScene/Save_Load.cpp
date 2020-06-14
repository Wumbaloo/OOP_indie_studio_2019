/*
** EPITECH PROJECT, 2023
** Indie Studio
** File description:
** Save and load management
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include "IndieStudio.hpp"

void Game::save()
{
    std::string *buffer;
    bool start = false;
    std::ofstream saveFile("bomberman.sav");

    if (saveFile.fail())
        return;
    for (int i = 1; i < MAP_HEIGHT + 1; i++) {
        std::cout << "+ I: " << i << std::endl;
        for (int j = 2; j < MAP_WIDTH; j++) {
            if (j >= this->_map[i].size())
                break;
            Model *obj = this->_map[i].at(j);
            if (!obj) {
                saveFile << ((j > 2 ? ";" : "")) << "_(0,0)";
                continue;
            }
            core::vector3df pos = obj->getPos();
            saveFile << ((j > 2 ? ";" : ""));
            switch (obj->getType()) {
                case BREAKABLE:
                    saveFile << "x";
                    break;
                case OBSTACLE:
                    saveFile << "o";
                    break;
                default:
                    saveFile << "_";
            }
            saveFile << "(" << pos.X << ":" << pos.Z << ")";
        }
        saveFile << std::endl;
    }
    saveFile.close();
}

std::vector<std::string> split(std::string& s, std::string delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    size_t pos = 0;

    pos = s.find(delimiter);
    while (pos != std::string::npos) {
        token = s.substr(0, pos);
        s = s.substr(pos + delimiter.length());
        tokens.push_back(token);
        pos = s.find(delimiter);
    }
    return tokens;
}

void Game::load()
{
    std::string buffer;
    std::ifstream fileStream("bomberman.sav");

    if (!fileStream.is_open()) {
        std::cout << "Failed in open bomberman.sav. Please check the rights of the file." << std::endl;
        exit(84);
    }
    this->makeBorderMap();
    for (int y = 0; !fileStream.eof(); y++) {
        fileStream >> buffer;
        std::vector<std::string> separate = split(buffer, ";");

        for (std::string str : separate) {
            Model *obj = NULL;
            float x = 0;
            float z = 0;
            char type = str.at(0);
            size_t open = str.find("(");
            size_t middle = str.find(":");
            size_t close = str.find(")");

            if ((type != 'o' && type != 'x' && type != '_')
                || (open == std::string::npos || open != 1)
                || (close == std::string::npos || close != str.length() - 1)) {
                std::cout << "Invalid save" << std::endl;
                exit(84);
            }
            x = std::stof(str.substr(open + 1, middle - 1));
            z = std::stof(str.substr(middle + 1, close - middle - 1));
            switch (type) {
                case 'x':
                    this->createObject("destructible", "Cube.obj", "Cube.jpg", {(float) x, 0, (float) z}, {1, 1, 1}, BREAKABLE);
                    break;
                default:
                case 'o':
                    this->createObject("wall", "Cube.obj", "Square.jpg", {(float) x, 0, (float) z}, {1, 1, 1}, OBSTACLE);
                    break;
            }
            if (obj) {
                this->_map[y].push_back(obj);
                std::cout << "Y is " << y << std::endl;
            }
        }
    }
    fileStream.close();
}
