/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

// #include <IrrlichtDevice.h>
#include "IndieStudio.hpp"

bool isBorderNext(vector2f_t pos, vector2f_t height, vector2f_t width, float step, float range);

Game::Game(IrrlichtDevice *window)
{
    this->_driver = window->getVideoDriver();
    this->_smgr = window->getSceneManager();
    this->_guienv = window->getGUIEnvironment();
}

void Game::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    this->_smgr->drawAll();
    this->_guienv->drawAll();
}

void Game::refreshWindow()
{
    this->_driver->endScene();
}

void Game::resetScene(IrrlichtDevice *window)
{
    printf("I'm resetting the game\n");
    this->_driver->removeAllTextures();
    this->_guienv->clear();
    this->_objects.clear();
    this->_smgr->clear();
    this->_smgr->addCameraSceneNode(0, core::vector3df(0, 30, -15),
        core::vector3df(0, 0, 0));
    this->_then = window->getTimer()->getTime();
    this->Music_play();
    this->_main_music.play();
    this->createGameScene();
}

void Game::save()
{
    string *buffer;
    FILE *fileStream = fopen("savefile.sav", "w");

    for (int ) {

    }
}

void Game::load()
{
    string *buffer;
    FILE *fileStream = fopen("savefile.sav", "r");
    size_t size_read = 0;
    int k = 0;
    int x = 0;
    int z = 0;

    for (int i = 0; i < MAP_HEIGHT; i++) {
        size_read = fread(buffer, sizeof(char), MAP_WIDTH, fileStream);
        for (int j = 0; j < MAP_HEIGHT; j++) {
            Model *obj = NULL;
            if (buffer->at(j) == 'x')
                obj = this->createObject("destructible", "Square.obj", "Destruct.jpg", {(float) x, 0, (float) z}, {1, 1, 1});
            if (buffer->at(j) != '_')
                this->_map[k++].push_back(obj);
            x += 2;
            z += 2;
        }
    }
    fclose(fileStream);
}