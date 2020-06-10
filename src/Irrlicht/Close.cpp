/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Irrlicht close cpp
*/

#include <iostream>
#include "Irrlicht.hpp"

using namespace irr;

void Irrlicht::destroy()
{
//    for (auto object : this->_objects)
//        delete (object);
//    this->_objects.clear();
}

void Irrlicht::close()
{
    this->_window->drop();
}