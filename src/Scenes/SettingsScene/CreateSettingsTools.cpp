/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"

irr::gui::IGUIEditBox *Settings::newNameBox(const wchar_t *name, irr::core::rect<s32> pos, bool isEnabled)
{
    irr::gui::IGUIEditBox *nameBox = this->_guienv->addEditBox(name, pos, true);

    nameBox->setMultiLine(false);
    nameBox->setMax(15);
    nameBox->setEnabled(isEnabled);
    nameBox->setText(name);
    return nameBox;
}

irr::gui::IGUIListBox *Settings::newListBox(irr::core::rect<s32> pos, PlayerType type, bool isEnabled)
{
    irr::gui::IGUIListBox *listBox = this->_guienv->addListBox(pos);

    listBox->addItem(L"Human");
    listBox->addItem(L"AI");
    listBox->setSelected(type);
    listBox->setEnabled(isEnabled);
    return listBox;
}

irr::gui::IGUICheckBox *Settings::newCheckBox(irr::core::rect<s32> pos, bool isEnabled)
{
    irr::gui::IGUICheckBox *checkBox = this->_guienv->addCheckBox(isEnabled, pos);

    return checkBox;
}