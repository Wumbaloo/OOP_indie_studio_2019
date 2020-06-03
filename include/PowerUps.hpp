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

class BombUp : public AnimatedModel
{
    private:
        PowerUpsType _type;

    public:
        BombUp(scene::IAnimatedMeshSceneNode *, std::string);
        ~BombUp();

        PowerUpsType getPowerUpType(void) const;
        void affectPlayer(Player *);
};

class FireUp : public AnimatedModel
{
    private:
        PowerUpsType _type;

    public:
        FireUp(scene::IAnimatedMeshSceneNode *, std::string);
        ~FireUp();

        PowerUpsType getPowerUpType(void) const;
        void affectPlayer(Player *);
};

class SpeedUp : public AnimatedModel
{
    private:
        PowerUpsType _type;

    public:
        SpeedUp(scene::IAnimatedMeshSceneNode *, std::string);
        ~SpeedUp();

        PowerUpsType getPowerUpType(void) const;
        void affectPlayer(Player *);
};

class WallPass : public AnimatedModel
{
    private:
        PowerUpsType _type;

    public:
        WallPass(scene::IAnimatedMeshSceneNode *, std::string);
        ~WallPass();

        PowerUpsType getPowerUpType(void) const;
        void affectPlayer(Player *);
};

#endif