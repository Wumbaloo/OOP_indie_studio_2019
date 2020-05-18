/*
** EPITECH PROJECT, 2019
** IndieStdio
** File description:
** Irrlicht lib class
*/

#include <iostream>
#include "Irrlicht.hpp"

using namespace irr;

Irrlicht::Irrlicht(const std::string name) : _name(name)
{}

bool Irrlicht::isWindowOpen(void) const
{
    return this->_window->run();
}

void Irrlicht::refreshWindow() const
{
    this->_driver->endScene();
}
