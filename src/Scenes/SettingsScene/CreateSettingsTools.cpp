/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"

gui::IGUIEditBox *Settings::newNameBox(const wchar_t *name, core::rect<s32> pos, bool isEnabled)
{
    gui::IGUIEditBox *nameBox = this->_guienv->addEditBox(name, pos, true);

    nameBox->setMultiLine(false);
    nameBox->setMax(15);
    nameBox->setEnabled(isEnabled);
    nameBox->setText(name);
    return nameBox;
}

gui::IGUIListBox *Settings::newListBox(core::rect<s32> pos, PlayerType type, bool isEnabled)
{
    gui::IGUIListBox *listBox = this->_guienv->addListBox(pos);

    listBox->addItem(L"Human");
    listBox->addItem(L"AI");
    listBox->setSelected(type);
    listBox->setEnabled(isEnabled);
    return listBox;
}

gui::IGUICheckBox *Settings::newCheckBox(core::rect<s32> pos, bool isEnabled)
{
    gui::IGUICheckBox *checkBox = this->_guienv->addCheckBox(isEnabled, pos);

    return checkBox;
}