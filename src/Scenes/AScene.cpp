/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Scenes.hpp"

AScene::AScene(IrrlichtDevice *window)
{
    this->_guienv = window->getGUIEnvironment();
    this->_smgr = window->getSceneManager();
    this->_driver = window->getVideoDriver();
    this->_music = new Music();
}

void AScene::checkHoverButton(irr::core::vector2d<s32> cursorPos, std::vector<irr::gui::IGUIButton *> _defaultButtons, std::vector<irr::gui::IGUIButton *> _hoverButtons)
{
    for (int i = 0; i < _defaultButtons.size(); i++)
        _hoverButtons[i]->setVisible(_defaultButtons[i]->isPointInside(cursorPos));
}

void AScene::refreshWindow()
{
    this->_driver->endScene();
}

irr::gui::IGUIButton *AScene::newButton(irr::core::rect<irr::s32> pos,
    bool visible, irr::core::string<fschar_t> path)
{
    irr::gui::IGUIButton *button;

    button = this->_guienv->addButton(pos, nullptr, -1, nullptr);
    button->setUseAlphaChannel(true);
    button->setDrawBorder(false);
    button->setImage(this->_driver->getTexture(path));
    button->setVisible(visible);
    return button;
}