/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include <fstream>
#include "IndieStudio.hpp"

Game::Game(IrrlichtDevice *window) : AScene(window)
{
    this->_paused = false;
    this->_then = 0;
    this->_frameDeltaTime = 0;
    this->_winner = -1;
}

void Game::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 82, 138, 85.4));
    this->_smgr->drawAll();
    // this->_guienv->drawAll();
}

void Game::resetScene(IrrlichtDevice *window, settings_t *settings, InputManager *im)
{
    printf("I'm resetting the game\n");
    this->_driver->removeAllTextures();
    this->_guienv->clear();
    this->_objects.clear();
    this->_smgr->clear();
    scene::ICameraSceneNode *camera = this->_smgr->addCameraSceneNode(0, core::vector3df(0, 25, -5),
        core::vector3df(0, -12.5, -2.5));
    this->_then = window->getTimer()->getTime();
    if (settings->isMuted)
        this->_music->muteAll();
    else
        this->_music->demute();
    this->_music->manageVolume(settings->volume);
    if (!this->_music->isMusicOn())
        this->_music->playGameMusic();
    this->createGameScene(settings, im);
}

void Game::save()
{
    string *buffer;
    FILE *fileStream = fopen("../bomberman.sav", "w");

    for (int i = 0; i < MAP_HEIGHT + 2; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            switch (this->_map[i][j]->getType()) {
                case BREAKABLE :
                    fwrite("x", 1, 1, fileStream);
                    break;
                case OBSTACLE :
                    fwrite("o", 1, 1, fileStream);
                    break;
                default :
                    fwrite("_", 1, 1, fileStream);
            }
        }
    }
    fclose(fileStream);
}

void Game::load()
{
    std::string buffer;
    ifstream fileStream("../bomberman.sav");

    if (!fileStream.is_open())
        return;
    fileStream >> buffer;

    std::cout << "*** debug ***\n" << buffer << std::endl;

    for (int j = 0; j < MAP_HEIGHT; j++) {
        for (int i = 0; i < MAP_WIDTH; i++) {
            Model *obj = NULL;

            if (buffer.at(i + MAP_WIDTH * j) == 'o') {
                obj = this->createObject("destructible", "Cube.obj", "Cube.jpg", {(float) 0, 0, (float) 0}, {1, 1, 1}, BREAKABLE);
                this->_map[j].push_back(obj);
                this->placeInMap(obj, i, j);
            }
            else if (buffer.at(i + MAP_WIDTH * j) == 'x') {
                obj = this->createObject("wall", "Cube.obj", "Square.jpg", {(float) 0, 0, (float) 0}, {1, 1, 1}, OBSTACLE);
                this->_map[j].push_back(obj);
                this->placeInMap(obj, i, j);
            }
        }
    }
    fileStream.close();
}

void Game::destroy()
{
    for (auto object : this->_objects)
        delete (object);
    this->_objects.clear();
    for (auto object : this->_playerObjects)
        delete (object);
    this->_playerObjects.clear();
    for (auto object : this->_bombObjects)
        delete (object);
    this->_bombObjects.clear();
    for (auto object : this->_powerUpObjects)
        delete (object);
    this->_powerUpObjects.clear();
    for (int y = 0; y < MAP_HEIGHT + 2; y++) {
        for (auto object : this->_map[y])
            delete (object);
        this->_map[y].clear();
    }
}