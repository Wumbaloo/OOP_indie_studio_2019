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

void Settings::checkEditBoxUpdate(settings_t *settings)
{
    for (int i = 0; i < 4; i++)
        settings->names[i] = std::wstring(this->_nameBoxes[i]->getText());
}

void Settings::checkListBoxUpdate(settings_t *settings)
{
    for (int i = 0; i < 4; i++)
        settings->types[i] = static_cast<PlayerType>(this->_listBoxes[i]->getSelected());
}

void Settings::checkCheckBoxUpdate(settings_t *settings)
{
    int cpt = 0;

    for (int i = 0; i < 4; i++) {
        settings->playing[i] = this->_checkboxes[i]->isChecked();
        cpt += this->_checkboxes[i]->isChecked();
    }
    settings->nbrPlayers = cpt;
}

void Settings::updateEnabledPlayers(settings_t *settings)
{

    for (int i = 0; i < 4; i++) {
        this->_nameBoxes[i]->setEnabled(settings->playing[i]);
        this->_listBoxes[i]->setEnabled(settings->playing[i]);
    }
}

void Settings::updateSettings(settings_t *settings)
{
    this->checkEditBoxUpdate(settings);
    this->checkListBoxUpdate(settings);
    this->checkCheckBoxUpdate(settings);
    this->updateEnabledPlayers(settings);
}

Events Settings::checkEvents(IrrlichtDevice *window, InputManager *inputManager, settings_t *settings)
{
    this->checkHoverButton(window->getCursorControl()->getPosition());
    for (int i = 0; settings->nbrPlayers < 2; i++) {
        if (!settings->playing[i]) {
            settings->playing[i] = true;
            settings->nbrPlayers++;
            this->_checkboxes[i]->setChecked(true);
            this->updateEnabledPlayers(settings);
        }
    }
    this->updateSettings(settings);
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

void Settings::resetScene(IrrlichtDevice *window, settings_t *settings, InputManager *im)
{
    this->_nameBoxes.clear();
    this->_listBoxes.clear();
    this->_checkboxes.clear();
    this->_guienv->clear();
    this->_smgr->clear();
    this->_driver->removeAllTextures();
    this->_settingsBackground = this->_driver->getTexture("../assets/images/backgroundMenu.png");
    this->createButtons();
    this->generateSettings(settings);
}