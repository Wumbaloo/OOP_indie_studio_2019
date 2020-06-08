/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"

Settings::Settings(IrrlichtDevice *window) : AScene(window)
{
}

void Settings::checkHoverButton(irr::core::vector2d<s32> cursorPos)
{
    this->_menuButtonHover->setVisible(this->_menuButtonDefault->isPointInside(cursorPos));
}

Events Settings::checkEvents(IrrlichtDevice *window, InputManager *inputManager)
{
    this->checkHoverButton(window->getCursorControl()->getPosition());
    if (inputManager->isKeyPressed(CLOSE))
        return CLOSE;
    if (this->_menuButtonHover->isPressed())
        return BACK_MENU;
    return NONE;
}

void Settings::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    this->_driver->draw2DImage(this->_settingsBackground,
        irr::core::position2d<irr::s32>(0, 0),
        irr::core::rect<irr::s32>(0, 0, 1920, 1080), 0,
        irr::video::SColor(255, 255, 255, 255), true);
    this->_smgr->drawAll();
    this->_guienv->drawAll();
}

void Settings::createButtons()
{
    this->_menuButtonDefault = this->newButton(irr::core::rect<irr::s32>(10, 850, 430, 1010), true, "../assets/images/quitDefault.png");
    this->_menuButtonHover = this->newButton(irr::core::rect<irr::s32>(10, 850, 430, 1010), false, "../assets/images/quitHover.png");
}

void Settings::resetScene(IrrlichtDevice *window)
{
    this->_guienv->clear();
    this->_smgr->clear();
    this->_driver->removeAllTextures();
    this->_settingsBackground = this->_driver->getTexture("../assets/images/backgroundMenu.png");
    this->createButtons();
    //    this->_guienv->addCheckBox(true, irr::core::rect<irr::s32>(0, 0, 50, 50),
//        nullptr, -1);
//    this->_guienv->addEditBox(L"Anthony", irr::core::rect<irr::s32>(0, 0, 100, 20), true, nullptr, -1);
//    irr::gui::IGUISpinBox *test = this->_guienv->addSpinBox(L"100", irr::core::rect<irr::s32>(0, 0, 50, 20), true, nullptr, -1);
//    test->setDecimalPlaces(0);
//    test->setRange(0, 100);
}