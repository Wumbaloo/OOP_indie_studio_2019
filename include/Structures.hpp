/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** structure hpp
*/

#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include <iostream>
#include <vector>
#include <irrlicht/irrlicht.h>
#include "Enums.hpp"

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

typedef struct settings_s
{
    int volume = 100;
    int nbrPlayers = 4;
    std::vector<PlayerType> types = {HUMAN, AI, AI, AI};
    std::vector<std::string> names = {"Human", "Bot1", "Bot2", "Bot3"};
} settings_t;

#endif