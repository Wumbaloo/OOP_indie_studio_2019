/*
** EPITECH PROJECT, 2019
** InideStudio
** File description:
** getters Irrlicht cpp
*/

#include <iostream>
#include "Irrlicht.hpp"

using namespace irr;

const string &Irrlicht::getName(void) const
{
    return (this->_name);
}