/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Object.cpp for Irrlicht
*/

#include "Object.hpp"

using namespace irr;

int id = 0;

AObject::AObject(std::string name, ObjectType type) : _id(id++), _type(type)
{
    this->_name = name;
}

void AObject::setName(std::string name)
{
    this->_name = name;
}

const int AObject::getId(void) const
{
    return this->_id;
}

std::string AObject::getName(void) const
{
    return this->_name;
}

const ObjectType AObject::getType(void) const
{
    return (this->_type);
}