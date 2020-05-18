/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Object.cpp for Irrlicht
*/

#include "Object.hpp"

using namespace irr;

int id = 0;

Object::Object(scene::IAnimatedMesh *object) : _id(id++)
{
    this->_object = object;
}
