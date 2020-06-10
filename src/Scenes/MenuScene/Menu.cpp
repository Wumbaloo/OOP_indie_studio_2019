/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"

Events Menu::checkEvents(IrrlichtDevice *window, InputManager *inputManager, settings_t *settings) {
    std::vector<Events> types = {HELP, TO_SETTINGS, CLOSE};
    Menu::Hover_sound_effect(this->_musics);
    this->checkHoverButton(window->getCursorControl()->getPosition(),
        this->_defaultButtons, this->_hoverButtons);
    for (int i = 0; i < this->_defaultButtons.size(); i++) {
        if (this->_hoverButtons[i]->isPressed()) {
            this->_musics->_bomb.play();
            return types[i];
        }
    }
    if (inputManager->isKeyPressed(CLOSE)) {
        this->_musics->_bomb.play();
        return CLOSE;
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
    Menu::Hover_sound_effect(this->_musics);
    Menu::Bonus_sound_effect(this->_musics);
    Menu::Main_music(this->_musics);
    Menu::Title_music(this->_musics);
    this->_musics->_title_music.play();
    this->_musics->_main_music.stop();
    this->_menuBackground = this->_driver->getTexture("../assets/images/backgroundMenu.png");
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