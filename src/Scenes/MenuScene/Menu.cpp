/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"

Events Menu::checkEvents(IrrlichtDevice *window, InputManager *inputManager)
{
    if (this->_playButton->isPressed()) {
        return PLAY;
    }
    return NONE;
}

void Menu::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    this->_driver->draw2DImage(this->_menuBackground, irr::core::position2d<irr::s32>(0,0),
        irr::core::rect<irr::s32>(0,0,1920,1080), 0,
        irr::video::SColor(255, 255, 255, 255), true);
    this->_smgr->drawAll();
    this->_guienv->drawAll();
}

Menu::Menu(IrrlichtDevice *window)
{
    this->_driver = window->getVideoDriver();
    this->_smgr = window->getSceneManager();
    this->_guienv = window->getGUIEnvironment();
}

void Menu::refreshWindow()
{
    this->_driver->endScene();
}

void Menu::resetScene(IrrlichtDevice *window)
{
    this->_guienv->clear();
    this->_smgr->clear();
    this->_driver->removeAllTextures();
    this->_playButton = this->_guienv->addButton(irr::core::rect<irr::s32>(75, 200, 475, 400), 0, -1, L"JOUE A MON JEU STP");
    this->_playButton->setUseAlphaChannel(true);
    this->_playButton->setDrawBorder(false);
    this->_playButton->setImage(this->_driver->getTexture("../assets/images/button2.png"));
    this->_menuBackground = this->_driver->getTexture("../assets/Textures/menu_background.png");
    this->Music_play();
    this->_title_music.play();
}