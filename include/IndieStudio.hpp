/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Main header file
*/

#ifndef INDIE_STUDIO_H
#define INDIE_STUDIO_H

#include <irrlicht/irrlicht.h>
#include "Irrlicht.hpp"

#define MODELS_PATH     "../assets/Models/"
#define TEXTURES_PATH   "../assets/Textures/"
#define PLAYER_SPEED    8.f
#define MAP_WIDTH       26
#define MAP_HEIGHT      22

int GameManager(Irrlicht *lib);

#endif