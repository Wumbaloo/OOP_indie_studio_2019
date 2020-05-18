/*
** EPITECH PROJECT, 2019
** InideStudio
** File description:
** create Irrlicht object cpp
*/

#include <iostream>
#include <string>
#include "IndieStudio.hpp"
#include "Irrlicht.hpp"

using namespace irr;

void Irrlicht::createWindow(void)
{
    this->_window = createDevice( video::EDT_SOFTWARE,
            core::dimension2d<u32>(1920, 1080), 16,
            false, false, false, 0);
    if (!this->_window) {
        std::cout << "Failed to create window" << std::endl;
        exit(84);
    }
    this->_window->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
    this->_driver = this->_window->getVideoDriver();
    this->_smgr = this->_window->getSceneManager();
    this->_guienv = this->_window->getGUIEnvironment();
    this->_guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!", core::rect<s32>(10,10,260,22), true);
    this->_smgr->addCameraSceneNode(0, core::vector3df(0,200,99), core::vector3df(0,5,100));
}

scene::IAnimatedMesh *Irrlicht::createModel(video::IVideoDriver* driver,
    scene::ISceneManager *smgr, std::string modelPath,
    std::string texturePath)
{
    scene::IAnimatedMesh *mesh;
    scene::IAnimatedMeshSceneNode *node = NULL;

    mesh = smgr->getMesh(std::string(MODELS_PATH + modelPath).c_str());
    if (!mesh)
        return (NULL);
    node = smgr->addAnimatedMeshSceneNode(mesh);
    if (node) {
        node->setMaterialFlag(video::EMF_LIGHTING, false);
        node->setMD2Animation(scene::EMAT_STAND);
        node->setMaterialTexture(0, driver->getTexture(std::string(TEXTURES_PATH + texturePath).c_str()));
    }
    return (mesh);
}

Object *Irrlicht::createObject(std::string model, std::string texture)
{

    Object *NewObject = NULL;
    scene::IAnimatedMesh *object;

    object = createModel(this->_driver, this->_smgr, model, texture);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new Object(object);
    return NewObject;
}

void Irrlicht::createMenu(void)
{
    // this->_window->getCursorControl()->setVisible(false);
    this->_objects.push_back(this->createObject("BomberMan.3ds", "Bombermap.tga"));
}

void Irrlicht::createGame()
{
}