/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** Animated object
*/

#ifndef ANIMATED_OBJECT_HPP
#define ANIMATED_OBJECT_HPP

#include <iostream>
#include <irrlicht/irrlicht.h>
#include "Object.hpp"

class AnimatedModel : public AObject
{
    protected:
        scene::IAnimatedMeshSceneNode *_node;

    public:
        AnimatedModel() = delete;
        AnimatedModel(scene::IAnimatedMeshSceneNode *, std::string);
        ~AnimatedModel() = default;

        scene::IAnimatedMeshSceneNode *getSceneNode() const;
        core::vector3df getPos(void) const;
        core::vector3df getRotation(void) const;

        void setPos(core::vector3df);
        void setRotation(core::vector3df);
        void changeAnimation(Animations);
};

class Bomb : public AnimatedModel
{
    private:
        std::string _launcher;
        u32 _initial_time;
        u32 _time;
    public:
        Bomb(std::string, scene::IAnimatedMeshSceneNode *, std::string, u32);
        ~Bomb();

        u32 getTime(void) const;
        void setTime(u32 newTime);
};

class Player : public AnimatedModel
{
    private:
        core::vector3df _rotateFix;
        bool _running;
        int _health;

    public:
        Player(int, scene::IAnimatedMeshSceneNode *, std::string);
        ~Player() = default;

        core::vector3df getRotateFix(void) const;
        bool isRunning(void) const;
        void changeAnimation(Animations);

};

#endif