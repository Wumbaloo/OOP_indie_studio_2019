/*
** EPITECH PROJECT, 2019
** IndieStduio
** File description:
** Setters for objects
*/

#include "Object.hpp"

void Object::setPos(int x, int y, int z)
{
    core::vector3df pos;

    pos.X = x;
    pos.Y = y;
    pos.Z = z;
    this->_object->setPosition(pos);
}

void Object::setPos(core::vector3df pos)
{
    this->_object->setPosition(pos);
}

void Object::setName(std::string name)
{
    this->_name = name;
}
