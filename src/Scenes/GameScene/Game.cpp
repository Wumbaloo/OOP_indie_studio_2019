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
    this->_smgr->addCameraSceneNode(0, core::vector3df(0, 25, -5),
        core::vector3df(0, -12, 0));
    this->_then = window->getTimer()->getTime();
    this->Music_play();
    this->_main_music.play();
    this->createGameScene();
}
