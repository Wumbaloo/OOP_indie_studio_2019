/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"
#define TEXTWIDTH 100
#define TEXTHEIGTH 30
#define LISTWIDTH 50
#define LISTHEIGHT 28
#define CHECKBOXSIDE 20

void Settings::generateNameBoxes(settings_t *settings)
{
    this->_nameBoxes.push_back(this->newNameBox(settings->names[0].c_str(), core::rect<s32>(300, 425, 300 + TEXTWIDTH, 425 + TEXTHEIGTH), settings->playing[0]));
    this->_nameBoxes.push_back(this->newNameBox(settings->names[1].c_str(), core::rect<s32>(500, 425, 500 + TEXTWIDTH, 425 + TEXTHEIGTH), settings->playing[1]));
    this->_nameBoxes.push_back(this->newNameBox(settings->names[2].c_str(), core::rect<s32>(700, 425, 700 + TEXTWIDTH, 425 + TEXTHEIGTH), settings->playing[2]));
    this->_nameBoxes.push_back(this->newNameBox(settings->names[3].c_str(), core::rect<s32>(900, 425, 900 + TEXTWIDTH, 425 + TEXTHEIGTH), settings->playing[3]));
}

void Settings::generateSkins(settings_t *settings)
{
    this->_skinsEnabled.push_back(this->_driver->getTexture("./assets/images/guard1.png"));
    this->_skinsEnabled.push_back(this->_driver->getTexture("./assets/images/guard2.png"));
    this->_skinsEnabled.push_back(this->_driver->getTexture("./assets/images/guard3.png"));
    this->_skinsEnabled.push_back(this->_driver->getTexture("./assets/images/guard4.png"));
    for (video::ITexture *texture : this->_skinsEnabled)
        if (texture == nullptr)
            exit(84);
    this->_skinDisabled = this->_driver->getTexture("./assets/images/noguard.png");
    if (this->_skinDisabled == nullptr)
        exit(84);
}

void Settings::generateListBoxes(settings_t *settings)
{
    this->_listBoxes.push_back(this->newListBox(core::rect<s32>(321, 665, 321 + LISTWIDTH, 665 + LISTHEIGHT), settings->types[0], settings->playing[0]));
    this->_listBoxes.push_back(this->newListBox(core::rect<s32>(521, 665, 521 + LISTWIDTH, 665 + LISTHEIGHT), settings->types[1], settings->playing[1]));
    this->_listBoxes.push_back(this->newListBox(core::rect<s32>(721, 665, 721 + LISTWIDTH, 665 + LISTHEIGHT), settings->types[2], settings->playing[2]));
    this->_listBoxes.push_back(this->newListBox(core::rect<s32>(921, 665, 921 + LISTWIDTH, 665 + LISTHEIGHT), settings->types[3], settings->playing[3]));
}

void Settings::generateCheckBoxes(settings_t *settings)
{
    this->_checkboxes.push_back(this->newCheckBox(core::rect<s32>(335, 715, 335 + CHECKBOXSIDE, 715 + CHECKBOXSIDE), settings->playing[0]));
    this->_checkboxes.push_back(this->newCheckBox(core::rect<s32>(535, 715, 535 + CHECKBOXSIDE, 715 + CHECKBOXSIDE), settings->playing[1]));
    this->_checkboxes.push_back(this->newCheckBox(core::rect<s32>(735, 715, 735 + CHECKBOXSIDE, 715 + CHECKBOXSIDE), settings->playing[2]));
    this->_checkboxes.push_back(this->newCheckBox(core::rect<s32>(935, 715, 935 + CHECKBOXSIDE, 715 + CHECKBOXSIDE), settings->playing[3]));
}

void Settings::generateSettings(settings_t *settings)
{
    this->generateNameBoxes(settings);
    this->generateSkins(settings);
    this->generateListBoxes(settings);
    this->generateCheckBoxes(settings);
    this->_volumeBox = this->_guienv->addSpinBox(L"Volume", core::rect<s32>(900, 920, 950, 940), true);
    this->_volumeBox->setRange(1, 100);
    this->_volumeBox->setDecimalPlaces(0);
    this->_volumeBox->setValue(settings->volume);
    this->_volumeBox->setStepSize(1);
}