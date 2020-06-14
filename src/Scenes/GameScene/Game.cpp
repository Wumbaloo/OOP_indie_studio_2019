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
    if (this->_paused) {
        if (this->_pauseBg)
            this->_driver->draw2DImage(this->_pauseBg, irr::core::position2d<irr::s32>(0,0),
            irr::core::rect<irr::s32>(0,0,1920,1080), 0,
            irr::video::SColor(255, 255, 255, 255), true);
        this->_pausegui->drawAll();
        this->_guienv->drawAll();
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
    this->_pauseBg = this->_driver->getTexture("./assets/images/background.png");
    this->_defaultButtons.clear();
    this->_hoverButtons.clear();
    this->_defaultButtons.push_back(this->newButton(core::rect<s32>(750, 210, 1170, 370), true, "./assets/images/playDefault.png"));
    this->_defaultButtons.push_back(this->newButton(core::rect<s32>(750, 410, 1170, 570), true, "./assets/images/menuDefault.png"));
    this->_defaultButtons.push_back(this->newButton(core::rect<s32>(750, 610, 1170, 770), true, "./assets/images/settingsDefault.png"));
    this->_defaultButtons.push_back(this->newButton(core::rect<s32>(750, 810, 1170, 970), true, "./assets/images/quitDefault.png"));
    this->_hoverButtons.push_back(this->newButton(core::rect<s32>(750, 210, 1170, 370), false, "./assets/images/playHover.png"));
    this->_hoverButtons.push_back(this->newButton(core::rect<s32>(750, 410, 1170, 570), false, "./assets/images/menuHover.png"));
    this->_hoverButtons.push_back(this->newButton(core::rect<s32>(750, 610, 1170, 770), false, "./assets/images/settingsHover.png"));
    this->_hoverButtons.push_back(this->newButton(core::rect<s32>(750, 810, 1170, 970), false, "./assets/images/quitHover.png"));
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

    this->makeBorderMap();
    for (int j = 0; j < MAP_HEIGHT; j++) {
        for (int i = 0; i < MAP_WIDTH; i++) {
            Model *obj = NULL;

            if (buffer.at(i + MAP_WIDTH * j) == 'o') {
                obj = this->createObject("destructible", "Cube.obj", "Cube.jpg", {(float) 0, 0, (float) 0}, {1, 1, 1}, BREAKABLE);
                this->_map[j].push_back(obj);
                this->placeInMap(obj, i + 1, j + 1);
            }
            else if (buffer.at(i + MAP_WIDTH * j) == 'x') {
                obj = this->createObject("wall", "Cube.obj", "Square.jpg", {(float) 0, 0, (float) 0}, {1, 1, 1}, OBSTACLE);
                this->_map[j].push_back(obj);
                this->placeInMap(obj, i + 1, j + 1);
            }
            else if (buffer.at(i + MAP_WIDTH * j) == 'b') {
                this->_powerUpObjects.push_back(this->createPowerUpObject(BOMBUP, "BombUp", {"bombUp.md3", "Rough.png",
                {i + 1, 0, j + 1}, {.8, .8, .8}, {0, 50}, 25}));
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
    for (auto object : this->_bombObjects) {
        for (auto explosions : object->getBombExplosions())
            delete(explosions);
        delete (object);
    }
    if (this->_pauseBg)
        delete(this->_pauseBg);
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