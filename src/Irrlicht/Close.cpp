/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Irrlicht close cpp
*/

#include <iostream>
#include "Irrlicht.hpp"

using namespace irr;

void Irrlicht::destroy(void)
{
    for (auto object : this->_objects)
        delete (object);
    this->_objects.clear();
}

void Irrlicht::close(void)
{
    this->_window->drop();
}
