/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** object
*/

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <irrlicht/irrlicht.h>
#include "Structures.hpp"
#include "Enums.hpp"

using namespace irr;

class AObject
{
    protected:
        const int _id;
        std::string _name;

    public:
        AObject() = delete;
        AObject(std::string);
        ~AObject() = default;

        // getters
        std::string getName(void) const;
        const int getId(void) const;

        void setName(std::string name);
};

class Model : public AObject
{
    private:
        scene::IMeshSceneNode *_node;

    public:
        Model() = delete;
        Model(scene::IMeshSceneNode *, std::string);
        ~Model() = default;

        scene::IMeshSceneNode *getSceneNode() const;
        core::vector3df getPos(void) const;
        core::vector3df getRotation(void) const;

        void setPos(core::vector3df);
        void setRotation(core::vector3df);
};

class AnimatedModel : public AObject
{
    private:
        scene::IAnimatedMeshSceneNode *_node;
        int _health;
        bool _running;
        core::vector3df _rotateFix;

    public:
        AnimatedModel() = delete;
        AnimatedModel(int health, scene::IAnimatedMeshSceneNode *, std::string);
        ~AnimatedModel() = default;

        scene::IAnimatedMeshSceneNode *getSceneNode() const;
        core::vector3df getPos(void) const;
        core::vector3df getRotation(void) const;
        core::vector3df getRotateFix(void) const;
        bool isRunning(void) const;

        void setPos(core::vector3df);
        void setRotation(core::vector3df);
        void changeAnimation(Animations);
};

#endif