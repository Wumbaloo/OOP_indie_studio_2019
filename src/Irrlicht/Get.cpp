/*
** EPITECH PROJECT, 2019
** InideStudio
** File description:
** getters Irrlicht cpp
*/

#include <iostream>
#include "Irrlicht.hpp"

using namespace irr;

const std::string &Irrlicht::getName(void) const
{
    return (this->_name);
}

AScene *Irrlicht::getScene()
{
    return this->_scenes[this->_status];
}

std::vector<AScene *> Irrlicht::getScenes()
{
    return this->_scenes;
}

InputManager *Irrlicht::getInputManager()
{
    return this->_inputManager;
}

settings_t *Irrlicht::getSettings()
{
    return this->_gameSettings;
}