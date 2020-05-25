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

using namespace irr;

class Object
{
    private:
        const int _id;
        std::string _name;
        int _health;
        scene::IAnimatedMeshSceneNode *_object;

    public:
        Object() = delete;
        Object(scene::IAnimatedMeshSceneNode *object);
        ~Object() = default;

        void move(int x, int y);

        // getters
        std::string getName(void) const;
        const int getId(void) const;
        core::vector3df getPos(void) const;
        core::vector3df getRotation(void) const;
        scene::IAnimatedMeshSceneNode *getSceneNode() const;

        // setters
        void setPos(int x, int y, int z);
        void setPos(core::vector3df);
        void setName(std::string name);
};

#endif