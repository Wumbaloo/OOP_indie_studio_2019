/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Where models are created
*/

#include <iostream>
#include <string>
#include <irrlicht.h>
#include "IndieStudio.hpp"

irr::scene::IAnimatedMesh *createModel(irr::video::IVideoDriver* driver, irr::scene::ISceneManager *smgr, std::string modelPath, std::string texturePath)
{
    irr::scene::IAnimatedMesh *mesh = smgr->getMesh(std::string(MODELS_PATH + modelPath).c_str());
    irr::scene::IAnimatedMeshSceneNode *node = NULL;

    if (!mesh)
        return (NULL);
    node = smgr->addAnimatedMeshSceneNode(mesh);
    if (node) {
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setMD2Animation(irr::scene::EMAT_STAND);
        node->setMaterialTexture(0, driver->getTexture(std::string(TEXTURES_PATH + texturePath).c_str()));
    }
    return (mesh);
}