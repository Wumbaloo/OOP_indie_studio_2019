/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include <string>
#include "Scenes.hpp"

Win::Win(IrrlichtDevice *window) : AScene(window)
{
}

Events Win::checkEvents(IrrlichtDevice *window, InputManager *inputManager, settings_t *settings)
{
    std::vector<Events> events = {BACK_MENU, PLAY, CLOSE};

    this->checkHoverButton(window->getCursorControl()->getPosition(), this->_defaultButtons, this->_hoverButtons);
    for (int i = 0; i < 3; i++)
        if (this->_hoverButtons[i]->isPressed())
            return events[i];
    return NONE;
}

void Win::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    this->_driver->draw2DImage(this->_winPanel, irr::core::position2d<irr::s32>(0, 0),
        irr::core::rect<irr::s32>(0, 0, 1920, 1080), 0,
        irr::video::SColor(255, 255, 255, 255), true);
    this->_driver->draw2DImage(this->_playerSkin,
        irr::core::position2d<irr::s32>(870, 210),
        irr::core::rect<irr::s32>(0, 0, 1920, 1080), 0,
        irr::video::SColor(255, 255, 255, 255), true
        );
    this->_smgr->drawAll();
    this->_guienv->drawAll();
}

void Win::createButtons()
{
    this->_defaultButtons.push_back(this->newButton(irr::core::rect<s32>(200, 850, 620, 1010), true, "../assets/images/menuDefault.png"));
    this->_defaultButtons.push_back(this->newButton(irr::core::rect<s32>(750, 850, 1170, 1010), true, "../assets/images/playDefault.png"));
    this->_defaultButtons.push_back(this->newButton(irr::core::rect<s32>(1320, 850, 1740, 1010), true, "../assets/images/quitDefault.png"));
    this->_hoverButtons.push_back(this->newButton(irr::core::rect<s32>(200, 850, 620, 1010), false, "../assets/images/menuHover.png"));
    this->_hoverButtons.push_back(this->newButton(irr::core::rect<s32>(750, 850, 1170, 1010), false, "../assets/images/playHover.png"));
    this->_hoverButtons.push_back(this->newButton(irr::core::rect<s32>(1320, 850, 1740, 1010), false, "../assets/images/quitHover.png"));
}

void Win::resetScene(IrrlichtDevice *window, settings_t *settings, InputManager *inputManager)
{
    std::string path = std::string("../assets/images/guard") + std::to_string(settings->winnerIdx) + std::string(".png");
    this->createButtons();
    this->_winPanel = this->_driver->getTexture("../assets/images/winPanel.jpg");
    this->_playerSkin = this->_driver->getTexture(path.c_str());
    this->_playerName = this->_guienv->addStaticText((const wchar_t *) settings->names.at(settings->winnerIdx - 1).c_str(), irr::core::rect<s32>(940, 405, 940 + 100, 405 + 30));
    this->_music->playWinSound();
}