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
    this->_nameBoxes.push_back(this->newNameBox(settings->names[0].c_str(), irr::core::rect<s32>(300, 425, 300 + TEXTWIDTH, 425 + TEXTHEIGTH), settings->playing[0]));
    this->_nameBoxes.push_back(this->newNameBox(settings->names[1].c_str(), irr::core::rect<s32>(500, 425, 500 + TEXTWIDTH, 425 + TEXTHEIGTH), settings->playing[1]));
    this->_nameBoxes.push_back(this->newNameBox(settings->names[2].c_str(), irr::core::rect<s32>(700, 425, 700 + TEXTWIDTH, 425 + TEXTHEIGTH), settings->playing[2]));
    this->_nameBoxes.push_back(this->newNameBox(settings->names[3].c_str(), irr::core::rect<s32>(900, 425, 900 + TEXTWIDTH, 425 + TEXTHEIGTH), settings->playing[3]));
}

void Settings::generateListBoxes(settings_t *settings)
{
    this->_listBoxes.push_back(this->newListBox(irr::core::rect<s32>(321, 600, 321 + LISTWIDTH, 600 + LISTHEIGHT), settings->types[0], settings->playing[0]));
    this->_listBoxes.push_back(this->newListBox(irr::core::rect<s32>(521, 600, 521 + LISTWIDTH, 600 + LISTHEIGHT), settings->types[1], settings->playing[1]));
    this->_listBoxes.push_back(this->newListBox(irr::core::rect<s32>(721, 600, 721 + LISTWIDTH, 600 + LISTHEIGHT), settings->types[2], settings->playing[2]));
    this->_listBoxes.push_back(this->newListBox(irr::core::rect<s32>(921, 600, 921 + LISTWIDTH, 600 + LISTHEIGHT), settings->types[3], settings->playing[3]));
}

void Settings::generateCheckBoxes(settings_t *settings)
{
    this->_checkboxes.push_back(this->newCheckBox(irr::core::rect<s32>(335, 650, 335 + CHECKBOXSIDE, 650 + CHECKBOXSIDE), settings->playing[0]));
    this->_checkboxes.push_back(this->newCheckBox(irr::core::rect<s32>(535, 650, 535 + CHECKBOXSIDE, 650 + CHECKBOXSIDE), settings->playing[1]));
    this->_checkboxes.push_back(this->newCheckBox(irr::core::rect<s32>(735, 650, 735 + CHECKBOXSIDE, 650 + CHECKBOXSIDE), settings->playing[2]));
    this->_checkboxes.push_back(this->newCheckBox(irr::core::rect<s32>(935, 650, 935 + CHECKBOXSIDE, 650 + CHECKBOXSIDE), settings->playing[3]));
}

void Settings::generateSettings(settings_t *settings)
{
    this->generateNameBoxes(settings);
    this->generateListBoxes(settings);
    this->generateCheckBoxes(settings);
}