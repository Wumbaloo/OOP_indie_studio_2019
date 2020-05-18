/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Getters for objects
*/

#include "Object.hpp"

const int Object::getId(void) const
{
    return this->_id;
}

vector2_t Object::getPos(void) const
{
    return this->_pos;
}
