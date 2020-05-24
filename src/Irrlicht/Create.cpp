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
    this->_window = createDevice(video::EDT_SOFTWARE,
            core::dimension2d<u32>(1920, 1080), 16,
            false, false, false, 0);
    if (!this->_window) {
        std::cout << "Failed to create window" << std::endl;
        exit(84);
    } else if (this->_inputManager)
        this->_window->setEventReceiver(this->_inputManager);
    this->_window->setWindowCaption(L"Bomberman - Indie Studio");
    this->_driver = this->_window->getVideoDriver();
    this->_smgr = this->_window->getSceneManager();
    this->_guienv = this->_window->getGUIEnvironment();
    this->_guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!", core::rect<s32>(10,10,260,22), true);
    this->_smgr->addCameraSceneNode(0, core::vector3df(0,30,-15), core::vector3df(0,0,0));
    this->_then = this->_window->getTimer()->getTime();
}

scene::IAnimatedMeshSceneNode *Irrlicht::createModel(video::IVideoDriver* driver,
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
    return (node);
}

Object *Irrlicht::createObject(std::string name, std::string model, std::string texture)
{

    Object *NewObject = NULL;
    scene::IAnimatedMeshSceneNode *object;

    object = createModel(this->_driver, this->_smgr, model, texture);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new Object(object);
    NewObject->setName(name);
    return NewObject;
}

void Irrlicht::createMenu(void)
{
    // anicotte
    // this->_window->getCursorControl()->setVisible(false);
    Object *player = this->createObject("player", "BomberMan.3ds", "Bombermap.tga");
    player->getSceneNode()->setScale({0.02, 0.02, 0.02});
    player->getSceneNode()->setRotation({-90, 0, 0});
    player->getSceneNode()->setPosition({-(MAP_WIDTH / 2) + 2, 0, (MAP_HEIGHT / 2) - 4});
    this->_objects.push_back(player);
    // this->generateMap(1590316001);
    this->generateMap(time(nullptr));
}

void Irrlicht::createGame()
{
}