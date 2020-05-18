/*
** EPITECH PROJECT, 2019
** IndieStduio
** File description:
** Setters for objects
*/

#include "Object.hpp"

void Object::setPos(int x, int y)
{
    this->_pos.x = x;
    this->_pos.y = y;
}

void Object::setPos(vector2_t pos)
{
    this->_pos = pos;
}
