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
    this->_inputManager->bindActionToKey(MOVE_UP, irr::KEY_KEY_Z);
    this->_inputManager->bindKeyToAction(irr::KEY_KEY_S, MOVE_UP);
}

bool Irrlicht::isWindowOpen(void) const
{
    return this->_window->run();
}

void Irrlicht::refreshWindow() const
{
    this->_driver->endScene();
}
