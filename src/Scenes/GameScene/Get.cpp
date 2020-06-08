/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** Get for game cpp
*/

#include "Scenes.hpp"
#include "Object.hpp"

Model *Game::getModelByName(std::string name) const
{
    for (Model *obj : this->_objects) {
        if (obj->getName() == name)
            return obj;
    }
    return NULL;
}

Bomb *Game::getBombByName(std::string name) const
{
    for (Bomb *obj : this->_bombObjects) {
        if (obj->getName() == name)
            return obj;
    }
    return NULL;
}

Player *Game::getPlayerByName(std::string name) const
{
    for (Player *obj : this->_playerObjects) {
        if (obj->getName() == name)
            return obj;
    }
    return NULL;
}

int Game::getNbBombByOwner(std::string owner) const
{
    int nb = 0;

    for (Bomb *obj : this->_bombObjects) {
        if (obj->getOwner() == owner)
            nb++;
    }
    return nb;
}
