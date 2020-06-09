/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** APower ups
*/

#ifndef POWER_UPS_HPP
#define POWER_UPS_HPP

#include <iostream>
#include "Enums.hpp"
#include "AnimatedObjects.hpp"

class PowerUp : public AnimatedModel
{
    private:
        PowerUpsType _type;

    public:
        PowerUp(scene::IAnimatedMeshSceneNode *, std::string, PowerUpsType);
        ~PowerUp();

        PowerUpsType getType(void) const;
        void affectPlayer(Player *, IrrlichtDevice *);
};

#endif