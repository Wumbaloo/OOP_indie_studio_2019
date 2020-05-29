/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** Get for game cpp
*/

#include "Scenes.hpp"
#include "Object.hpp"

Model *Game::getObjectByName(std::string name) const
{
    for (Model *obj : this->_objects) {
        if (obj->getName() == name)
            return obj;
    }
    return NULL;
}

AnimatedModel *Game::getAnimObjByName(std::string name) const
{
    for (AnimatedModel *obj : this->_animObjects) {
        if (obj->getName() == name)
            return obj;
    }
    return NULL;
}