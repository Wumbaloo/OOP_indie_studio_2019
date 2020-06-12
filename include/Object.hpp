/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** object
*/

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <irrlicht.h>
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

        void setName(std::string name);
        virtual void setPos(core::vector3df) = 0;
        virtual void setRotation(core::vector3df) = 0;

        std::string getName(void) const;
        const int getId(void) const;
        const ObjectType getType(void) const;
        virtual core::vector3df getPos(void) const = 0;
        virtual core::aabbox3df getBoundingPos(void) const = 0;
        virtual core::vector3df getRotation(void) const = 0;
};

class Model : public AObject
{
    private:
        scene::IMeshSceneNode *_node = NULL;

    public:
        Model() = delete;
        Model(scene::IMeshSceneNode *, std::string, ObjectType type = NOTYPE);
        ~Model();

        void setPos(core::vector3df) override;
        void setRotation(core::vector3df) override;

        scene::IMeshSceneNode *getSceneNode(void) const;
        core::vector3df getPos(void) const override;
        core::vector3df getRotation(void) const override;
        core::aabbox3df getBoundingPos(void) const override;
};

#endif