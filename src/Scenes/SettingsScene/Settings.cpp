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

void Settings::manageMute(IrrlichtDevice *window, settings_t *settings)
{
    if (!settings->isMuted) {
        this->_soundsDefault[1]->setVisible(false);
        this->_soundsHover[1]->setVisible(false);
        this->_soundsHover[0]->setVisible(this->_soundsDefault[0]->isPointInside(window->getCursorControl()->getPosition()));
        if (this->_soundsHover[0]->isPressed()) {
            settings->isMuted = !settings->isMuted;
            this->_music->muteAll();
        }
    } else {
        this->_soundsDefault[1]->setVisible(true);
        this->_soundsHover[1]->setVisible(this->_soundsDefault[0]->isPointInside(window->getCursorControl()->getPosition()));
        if (this->_soundsHover[1]->isPressed()) {
            settings->isMuted = !settings->isMuted;
            this->_music->demute();
        }
    }
}

Events Settings::checkEvents(IrrlichtDevice *window, InputManager *inputManager, settings_t *settings)
{
    settings->volume = this->_volumeBox->getValue();
    this->checkHoverButton(window->getCursorControl()->getPosition(), {this->_menuButtonDefault}, {this->_menuButtonHover});
    this->manageMute(window, settings);
    for (int i = 0; settings->nbrPlayers < 2; i++) {
        if (!settings->playing[i]) {
            settings->playing[i] = true;
            settings->nbrPlayers++;
            this->_checkboxes[i]->setChecked(true);
            this->updateEnabledPlayers(settings);
        }
    }
    this->updateSettings(settings);
    if (inputManager->isKeyPressed(CLOSE)) {
        delete(this->_music);
        return CLOSE;
    }
    if (this->_menuButtonHover->isPressed()) {
        this->_music->playHoverSound();
        return BACK_MENU;
    }
    return NONE;
}

void Settings::displaySkins()
{
    std::vector<core::position2d<s32>> skinsPositions =
        {
            {260, 465},
            {460, 465},
            {660, 465},
            {860, 465}
        };
    for (int i = 0; i < 4; i++) {
        this->_driver->draw2DImage(this->_skinsEnabled[i], skinsPositions[i]);
        if (!this->_checkboxes[i]->isChecked())
            this->_driver->draw2DImage(this->_skinDisabled, skinsPositions[i]);
    }
}

void Settings::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    this->_driver->draw2DImage(this->_settingsBackground,
        core::position2d<s32>(0, 0),
        core::rect<s32>(0, 0, 1920, 1080), 0,
        video::SColor(255, 255, 255, 255), true);
    this->displaySkins();
    this->_smgr->drawAll();
    this->_guienv->drawAll();
}

void Settings::createButtons()
{
    this->_menuButtonDefault = this->newButton(core::rect<s32>(10, 850, 430, 1010), true, "./assets/images/menuDefault.png");
    this->_menuButtonHover = this->newButton(core::rect<s32>(10, 850, 430, 1010), false, "./assets/images/menuHover.png");
    this->_soundsDefault.push_back(this->newButton(core::rect<s32>(475, 850, 895, 1010), true, "./assets/images/soundOnDefault.png"));
    this->_soundsHover.push_back(this->newButton(core::rect<s32>(475, 850, 895, 1010), false, "./assets/images/soundOnHover.png"));
    this->_soundsDefault.push_back(this->newButton(core::rect<s32>(475, 850, 895, 1010), false, "./assets/images/soundOffDefault.png"));
    this->_soundsHover.push_back(this->newButton(core::rect<s32>(475, 850, 895, 1010), false, "./assets/images/soundOffHover.png"));
}

void Settings::resetScene(IrrlichtDevice *window, settings_t *settings, InputManager *im)
{
    this->_nameBoxes.clear();
    this->_listBoxes.clear();
    this->_checkboxes.clear();
    this->_skinsEnabled.clear();
    this->_soundsDefault.clear();
    this->_soundsHover.clear();
    this->_guienv->clear();
    this->_smgr->clear();
    this->_driver->removeAllTextures();
    this->_settingsBackground = this->_driver->getTexture("./assets/images/backgroundMenu.png");
    this->createButtons();
    this->generateSettings(settings);
    if (settings->isMuted)
        this->_music->muteAll();
    else
        this->_music->demute();
}