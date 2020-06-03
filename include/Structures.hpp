/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** structure hpp
*/

#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include <iostream>
#include <irrlicht/irrlicht.h>

using namespace std;

typedef struct vector3_s
{
    int x;
    int y;
    int z;
} vector3_t;

typedef struct vector2f_s
{
    float x;
    float y;
} vector2f_t;

typedef struct data_animations_s
{
    std::string model;
    std::string texture;
    irr::core::vector3df pos;
    irr::core::vector3df scale;
    vector2f_t frameLoop;
    float animationSpeed;
} data_animations_t;

#endif