/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
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
        const ObjectType _type;

    public:
        AObject() = delete;
        AObject(std::string, ObjectType type = NOTYPE);
        ~AObject() = default;

        std::string getName(void) const;
        const int getId(void) const;
        const ObjectType getType(void) const;

        void setName(std::string name);
};

class Model : public AObject
{
    private:
        scene::IMeshSceneNode *_node;

    public:
        Model() = delete;
        Model(scene::IMeshSceneNode *, std::string, ObjectType type = NOTYPE);
        ~Model() = default;

        scene::IMeshSceneNode *getSceneNode() const;
        core::vector3df getPos(void) const;
        core::vector3df getRotation(void) const;

        void setPos(core::vector3df);
        void setRotation(core::vector3df);
};

#endif