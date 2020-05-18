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
#include "Structure.hpp"

using namespace irr;

class Object
{
    private:
        const int _id;
        int _heal;
        scene::IAnimatedMesh *_object;
        vector2_t _pos;

    public:
        Object() = delete;
        Object(scene::IAnimatedMesh *object);
        ~Object() = default;

        void move(int x, int y);
        void move(vector2_t pos);

        // getters
        const int getId(void) const;
        vector2_t getPos(void) const;

        // setters
        void setPos(int x, int y);
        void setPos(vector2_t pos);
};

#endif