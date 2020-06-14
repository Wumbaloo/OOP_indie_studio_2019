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
    this->_driver->beginScene(true, true, video::SColor(255, 82, 138, (u32) 85.4f));
    this->_smgr->drawAll();
    if (this->_paused) {
        this->_pausegui->drawAll();
//        this->_guienv->drawAll();
    }
}

void Game::resetScene(IrrlichtDevice *window, settings_t *settings, InputManager *im)
{
    printf("I'm resetting the game\n");
    this->_driver->removeAllTextures();
    this->_paused = false;
    if (this->_pausegui)
        this->_pausegui->clear();
    this->_guienv->clear();
    this->_objects.clear();
    this->_smgr->clear();
    this->_pausegui = window->getGUIEnvironment();
    this->_defaultButtons.clear();
    this->_hoverButtons.clear();
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
    this->createPauseScene();
    this->createGameScene(settings, im);
}

void Game::destroy()
{
    for (auto object : this->_objects)
        delete (object);
    this->_objects.clear();
    for (auto object : this->_playerObjects)
        delete (object);
    this->_playerObjects.clear();
    for (auto object : this->_bombObjects) {
        for (auto explosions : object->getBombExplosions())
            delete(explosions);
        delete (object);
    }
    this->_defaultButtons.clear();
    this->_hoverButtons.clear();
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