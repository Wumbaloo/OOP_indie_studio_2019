/*
** EPITECH PROJECT, 2019
** IndieStdio
** File description:
** Irrlicht lib class
*/

#include <iostream>
#include "Enums.hpp"
#include "Irrlicht.hpp"

using namespace irr;

Irrlicht::Irrlicht(const std::string name) : _name(name)
{
    this->_inputManager = new InputManager();
    this->_inputManager->bindActionToKey(PAUSE, KEY_ESCAPE);
    this->_gameSettings = new settings_t;
}

bool Irrlicht::isWindowOpen(void) const
{
    return this->_window->run();
}

void Irrlicht::changeGameStatus(GameStatus status)
{
    this->_status = status;
}

IrrlichtDevice *Irrlicht::getWindow()
{
    return this->_window;
}

void Irrlicht::addScene(AScene *scene)
{
    this->_scenes.push_back(scene);
}