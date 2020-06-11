/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"

Events Menu::checkEvents(IrrlichtDevice *window, InputManager *inputManager, settings_t *settings)
{
    std::vector<Events> types = {HELP, TO_SETTINGS, CLOSE};

    this->checkHoverButton(window->getCursorControl()->getPosition(),
        this->_defaultButtons, this->_hoverButtons);
    for (int i = 0; i < this->_defaultButtons.size(); i++) {
        if (this->_hoverButtons[i]->isPressed()) {
            this->_music->playHoverSound();
            if (types[i] == HELP)
                this->_music->stopSound();
            return types[i];
        }
    }
    if (inputManager->isKeyPressed(CLOSE)) {
        this->_music->dropSound();
        delete(this->_music);
        return CLOSE;
    }
    return NONE;
}

void Menu::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    this->_driver->draw2DImage(this->_menuBackground, core::position2d<s32>(0,0),
        core::rect<s32>(0,0,1920,1080), 0,
        video::SColor(255, 255, 255, 255), true);
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
    if (settings->isMuted)
        this->_music->muteAll();
    else
        this->_music->demute();
    if (!this->_music->isMusicOn())
        this->_music->playMenuMusic();
    this->_menuBackground = this->_driver->getTexture("../assets/images/backgroundMenu.png");
}

void Menu::createButtons()
{
    this->_defaultButtons.push_back(this->newButton(core::rect<s32>(270, 410, 690, 570), true, "../assets/images/playDefault.png"));
    this->_defaultButtons.push_back(this->newButton(core::rect<s32>(270, 610, 690, 770), true, "../assets/images/settingsDefault.png"));
    this->_defaultButtons.push_back(this->newButton(core::rect<s32>(270, 810, 690, 970), true, "../assets/images/quitDefault.png"));
    this->_hoverButtons.push_back(this->newButton(core::rect<s32>(270, 410, 690, 570), false, "../assets/images/playHover.png"));
    this->_hoverButtons.push_back(this->newButton(core::rect<s32>(270, 610, 690, 770), false, "../assets/images/settingsHover.png"));
    this->_hoverButtons.push_back(this->newButton(core::rect<s32>(270, 810, 690, 970), false, "../assets/images/quitHover.png"));
}