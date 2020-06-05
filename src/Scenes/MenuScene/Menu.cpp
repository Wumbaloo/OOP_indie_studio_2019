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

Events Menu::checkEvents(IrrlichtDevice *window, InputManager *inputManager)
{
    std::vector<Events> types = {PLAY, SETTINGS, CLOSE};

    checkHoverButton(window->getCursorControl()->getPosition());
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
    this->_defaultButtons.clear();
    this->_hoverButtons.clear();
    this->createButtons();
    this->_menuBackground = this->_driver->getTexture("../assets/images/backgroundMenu.png");
    this->Music_play();
    this->_title_music.play();
}

irr::gui::IGUIButton *Menu::newButton(irr::core::rect<irr::s32> pos, bool visible, irr::core::string<fschar_t> path)
{
    irr::gui::IGUIButton *button;

    button = this->_guienv->addButton(pos, nullptr, -1, nullptr);
    button->setUseAlphaChannel(true);
    button->setDrawBorder(false);
    button->setImage(this->_driver->getTexture(path));
    button->setVisible(visible);
    return button;
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