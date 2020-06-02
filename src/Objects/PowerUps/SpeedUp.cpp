/*
** EPITECH PROJECT, 2019
** OOP_Indie_Studio
** File description:
** Power up speedup
*/

#include <iostream>
#include "PowerUps.hpp"

SpeedUp::SpeedUp(scene::IAnimatedMeshSceneNode *node, std::string name) : AnimatedModel(node, name)
{
}

SpeedUp::~SpeedUp()
{
    this->_node->remove();
}

PowerUpsType SpeedUp::getPowerUpType(void) const
{
    return this->_type;
}

void SpeedUp::affectPlayer(Player *player)
{
    player->setSpeedUp();
}
