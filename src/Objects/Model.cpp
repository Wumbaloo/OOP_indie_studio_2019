/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** model cpp
*/

#include <iostream>
#include "Object.hpp"

Model::Model(scene::IMeshSceneNode *node, std::string name) : AObject(name)
{
    this->_node = node;
}

scene::IMeshSceneNode *Model::getSceneNode(void) const
{
    return _node;
}

core::vector3df Model::getPos(void) const
{
    return this->_node->getPosition();
}

core::vector3df Model::getRotation(void) const
{
    return this->_node->getRotation();
}

void Model::setPos(core::vector3df pos)
{
    this->_node->setPosition(pos);
}
void Model::setRotation(core::vector3df rotation)
{
    this->_node->setRotation(rotation);
}