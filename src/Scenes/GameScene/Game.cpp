/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

// #include <IrrlichtDevice.h>
#include "IndieStudio.hpp"

Game::Game(IrrlichtDevice *window) : AScene(window)
{
    this->_paused = false;
    this->_then = 0;
    this->_frameDeltaTime = 0;
}

void Game::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    // if (!this->_paused)
    this->_smgr->drawAll();
    this->_guienv->drawAll();
}

void Game::resetScene(IrrlichtDevice *window, settings_t *settings, InputManager *im)
{
    printf("I'm resetting the game\n");
    this->_driver->removeAllTextures();
    this->_guienv->clear();
    this->_objects.clear();
    this->_smgr->clear();
    this->_smgr->addCameraSceneNode(0, core::vector3df(0, 25, -5),
        core::vector3df(0, -12.5, -2.5));
    this->_then = window->getTimer()->getTime();
    Game::Main_music(this->_musics);
    this->_musics->_main_music.play();
    this->_musics->_title_music.stop();
    this->createGameScene(settings, im);
}

void Game::save()
{
    string *buffer;
    FILE *fileStream = fopen("savefile.sav", "w");

    // for (int i = 0; i < MAP_HEIGHT + 2; i++) {
    //     for (int j = 0; j < MAP_WIDTH; j++) {
    //         switch (this->_map[i][j]->getType()) {
    //             case BREAKABLE :
    //                 fwrite("x", 1, 1, fileStream);
    //                 break;
    //             case OBSTACLE :
    //                 fwrite("o", 1, 1, fileStream);
    //                 break;
    //             default :
    //                 fwrite("_", 1, 1, fileStream);
    //         }
    //     }
    // }
    fclose(fileStream);
}

void Game::load()
{
    string *buffer;
    FILE *fileStream = fopen("savefile.sav", "r");
    size_t size_read = 0;
    int k = 0;
    int x = 0;
    int y = 0;

    for (int i = 0; i < MAP_HEIGHT + 2; i++) {
        size_read = fread(buffer, sizeof(char), MAP_WIDTH, fileStream);
        for (int j = 0; j < MAP_WIDTH; j++) {
            Model *obj = NULL;
            if (buffer->at(j) == 'o')
                obj = this->createObject("destructible", "Cube.obj", "Cube.jpg", {(float) 0, 0, (float) 0}, {1, 1, 1}, BREAKABLE);
            if (buffer->at(j) == 'x')
                obj = this->createObject("wall", "Cube.obj", "Square.jpg", {(float) 0, 0, (float) 0}, {1, 1, 1}, OBSTACLE);
            if (buffer->at(j) != '_') {
                this->_map[i].push_back(obj);
                if (x >= MAP_WIDTH) {
                    x = 0;
                    y++;
                }
                this->placeInMap(obj, x, y);
            }
            x++;
        }
    }
    fclose(fileStream);
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