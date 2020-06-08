/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Irrlicht savesystem cpp
*/

#include <iostream>
#include "IndieStudio.hpp"
#include "Irrlicht.hpp"

using namespace std;

void Game::saveParser()
{
    string *buffer;
    FILE *fileStream = fopen("savefile.sav", "r");
    size_t size_read = 0;

    for (int i = 0; i < MAP_HEIGHT; i++) {
        size_read = fread(buffer, sizeof(char), MAP_WIDTH, fileStream);
        // generateMapLine();
    }
    fclose(fileStream);
}