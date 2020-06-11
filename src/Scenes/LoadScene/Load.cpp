/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"

Load::Load(IrrlichtDevice *window) : AScene(window)
{
}

void Load::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    this->_driver->draw2DImage(this->_loadBackground,
        irr::core::position2d<irr::s32>(0, 0),
        irr::core::rect<irr::s32>(0, 0, 1920, 1080), 0,
        irr::video::SColor(255, 255, 255, 255), true);
    this->_smgr->drawAll();
    this->_guienv->drawAll();
}

Events Load::checkEvents(IrrlichtDevice *window, InputManager *inputManager, settings_t *settings)
{
    this->checkHoverButton(window->getCursorControl()->getPosition(), this->_defaultButtons, this->_hoverButtons);
    if (this->_hoverButtons[0]->isPressed()) {
        settings->loadFile = true;
        return PLAY;
    } else if (this->_hoverButtons[1]->isPressed()) {
        settings->loadFile = false;
        return PLAY;
    }
    return NONE;
}

void Load::createButtons()
{
    this->_defaultButtons.push_back(this->newButton(irr::core::rect<s32>(950, 850, 1370, 1010), true, "../assets/images/yesDefault.png"));
    this->_defaultButtons.push_back(this->newButton(irr::core::rect<s32>(500, 850, 920, 1010), true, "../assets/images/noDefault.png"));
    this->_hoverButtons.push_back(this->newButton(irr::core::rect<s32>(950, 850, 1370, 1010), false, "../assets/images/yesHover.png"));
    this->_hoverButtons.push_back(this->newButton(irr::core::rect<s32>(500, 850, 920, 1010), false, "../assets/images/noHover.png"));
}

void Load::resetScene(IrrlichtDevice *window, settings_t *settings, InputManager *inputManager)
{
    this->_guienv->clear();
    this->_smgr->clear();
    this->_driver->removeAllTextures();
    this->_defaultButtons.clear();
    this->_hoverButtons.clear();
    this->_loadBackground = this->_driver->getTexture("../assets/images/load.jpg");
    this->createButtons();
    if (settings->isMuted)
        this->_music->muteAll();
    else
        this->_music->demute();
}
