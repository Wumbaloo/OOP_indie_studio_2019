/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"

HowToPlay::HowToPlay(IrrlichtDevice *window) : AScene(window)
{
}

void HowToPlay::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    this->_driver->draw2DImage(this->_htpBackground, irr::core::position2d<irr::s32>(0,0),
        irr::core::rect<irr::s32>(0,0,1920,1080), 0,
        irr::video::SColor(255, 255, 255, 255), true);
    this->_smgr->drawAll();
    this->_guienv->drawAll();
}

Events HowToPlay::checkEvents(IrrlichtDevice *window, InputManager *inputManager, settings_t *settings) {
    std::vector<Events> types = {BACK_MENU, PLAY};

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

void HowToPlay::createButtons()
{
    this->_defaultButtons.push_back(this->newButton(irr::core::rect<irr::s32>(50, 850, 470, 1010), true, "../assets/images/menuDefault.png"));
    this->_defaultButtons.push_back(this->newButton(irr::core::rect<irr::s32>(1450, 850, 1870, 1010), true, "../assets/images/proceedDefault.png"));
    this->_hoverButtons.push_back(this->newButton(irr::core::rect<irr::s32>(50, 850, 470, 1010), false, "../assets/images/menuHover.png"));
    this->_hoverButtons.push_back(this->newButton(irr::core::rect<irr::s32>(1450, 850, 1870, 1010), false, "../assets/images/proceedHover.png"));
}

void HowToPlay::resetScene(IrrlichtDevice *, settings_t *, InputManager *)
{
    this->_guienv->clear();
    this->_smgr->clear();
    this->_driver->removeAllTextures();
    this->_defaultButtons.clear();
    this->_hoverButtons.clear();
    this->createButtons();
    this->_htpBackground = this->_driver->getTexture("../assets/images/howToPlay.png");
}