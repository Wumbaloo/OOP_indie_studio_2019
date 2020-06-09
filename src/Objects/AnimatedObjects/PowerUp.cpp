/*
** EPITECH PROJECT, 2019
** OOP_Indie_Studio
** File description:
** Power up bombup
*/

#include <iostream>
#include "PowerUps.hpp"

PowerUp::PowerUp(scene::IAnimatedMeshSceneNode *node, std::string name, PowerUpsType type) : AnimatedModel(node, name)
{
    this->_type = type;
}

PowerUp::~PowerUp()
{
    this->_node->remove();
}

PowerUpsType PowerUp::getType() const
{
    return this->_type;
}

void PowerUp::affectPlayer(Player *player, IrrlichtDevice *window)
{
    switch(this->_type) {
        case BOMBUP:
            player->setBombUp();
            break;
        case SPEEDUP:
            player->setSpeedUp(window->getTimer()->getTime());
            break;
        case FIREUP:
            player->setRange();
            break;
        case WALLPASS:
            player->setWallPass(window->getTimer()->getTime(), true);
            break;
        default:
            std::cout << "A powerUp has no type\n";
            exit(84);
            break;
    };
}