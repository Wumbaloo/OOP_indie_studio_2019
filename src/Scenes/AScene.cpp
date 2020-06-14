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

void AScene::checkHoverButton(core::vector2d<s32> cursorPos, std::vector<gui::IGUIButton *> _defaultButtons, std::vector<gui::IGUIButton *> _hoverButtons)
{
    for (int i = 0; i < _defaultButtons.size(); i++) {
        if (!_hoverButtons[i])
            continue;
        _hoverButtons[i]->setVisible(_defaultButtons[i]->isPointInside(cursorPos));
    }
}

void AScene::refreshWindow()
{
    this->_driver->endScene();
}

gui::IGUIButton *AScene::newButton(core::rect<s32> pos,
    bool visible, core::string<fschar_t> path)
{
    gui::IGUIButton *button;
    video::ITexture *texture  = this->_driver->getTexture(path);

    if (texture == nullptr)
        exit (84);
    button = this->_guienv->addButton(pos, nullptr, -1, nullptr);
    button->setUseAlphaChannel(true);
    button->setDrawBorder(false);
    button->setImage(texture);
    button->setVisible(visible);
    return button;
}