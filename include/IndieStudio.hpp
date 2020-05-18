/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Main header file
*/

#ifndef INDIE_STUDIO_H
#define INDIE_STUDIO_H

#include <irrlicht.h>

#define MODELS_PATH     "../assets/Models/"
#define TEXTURES_PATH   "../assets/Textures/"

irr::scene::IAnimatedMesh *createModel(irr::video::IVideoDriver* driver, irr::scene::ISceneManager *smgr, std::string modelPath, std::string texturePath);

#endif