/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"

void Menu::checkHoverButton(irr::core::vector2d<s32> cursorPos)
{
    for (int i = 0; i < this->_defaultButtons.size(); i++)
        this->_hoverButtons[i]->setVisible(this->_defaultButtons[i]->isPointInside(cursorPos));
}

Events Menu::checkEvents(IrrlichtDevice *window, InputManager *inputManager, settings_t *settings)
{
    std::vector<Events> types = {PLAY, TO_SETTINGS, CLOSE};

    this->checkHoverButton(window->getCursorControl()->getPosition());
    for (int i = 0; i < this->_defaultButtons.size(); i++)
        if (this->_hoverButtons[i]->isPressed())
            return types[i];
    if (inputManager->isKeyPressed(CLOSE))
        return CLOSE;
    return NONE;
}

void Menu::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    this->_driver->draw2DImage(this->_menuBackground, irr::core::position2d<irr::s32>(0,0),
        irr::core::rect<irr::s32>(0,0,1920,1080), 0,
        irr::video::SColor(255, 255, 255, 255), true);
    this->_smgr->drawAll();
    if (this->_guienv)
        this->_guienv->drawAll();
}

Menu::Menu(IrrlichtDevice *window) : AScene(window)
{
}

void Menu::resetScene(IrrlichtDevice *window, settings_t *settings, InputManager *im)
{
    this->_guienv->clear();
    this->_smgr->clear();
    this->_driver->removeAllTextures();
    this->_defaultButtons.clear();
    this->_hoverButtons.clear();
    this->createButtons();
    this->_menuBackground = this->_driver->getTexture("../assets/images/backgroundMenu.png");
    this->Music_play();
    this->_title_music.play();
}

void Menu::createButtons()
{
    this->_defaultButtons.push_back(this->newButton(irr::core::rect<irr::s32>(270, 410, 690, 570), true, "../assets/images/playDefault.png"));
    this->_defaultButtons.push_back(this->newButton(irr::core::rect<irr::s32>(270, 610, 690, 770), true, "../assets/images/settingsDefault.png"));
    this->_defaultButtons.push_back(this->newButton(irr::core::rect<irr::s32>(270, 810, 690, 970), true, "../assets/images/quitDefault.png"));
    this->_hoverButtons.push_back(this->newButton(irr::core::rect<irr::s32>(270, 410, 690, 570), false, "../assets/images/playHover.png"));
    this->_hoverButtons.push_back(this->newButton(irr::core::rect<irr::s32>(270, 610, 690, 770), false, "../assets/images/settingsHover.png"));
    this->_hoverButtons.push_back(this->newButton(irr::core::rect<irr::s32>(270, 810, 690, 970), false, "../assets/images/quitHover.png"));
}