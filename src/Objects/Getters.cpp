/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Getters for objects
*/

#include "Object.hpp"

using namespace irr;

const int Object::getId(void) const
{
    return this->_id;
}

core::vector3df Object::getPos(void) const
{
    return this->_object->getPosition();
}

scene::IAnimatedMeshSceneNode *Object::getSceneNode() const
{
    return this->_object;
}

std::string Object::getName(void) const
{
    return this->_name;
}