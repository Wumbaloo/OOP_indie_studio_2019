/*
** EPITECH PROJECT, 2019
** InideStudio
** File description:
** create Irrlicht object cpp
*/

#include <iostream>
#include <string>
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
}

//scene::IAnimatedMeshSceneNode *Irrlicht::createModel(video::IVideoDriver* driver,
//    scene::ISceneManager *smgr, std::string modelPath,
//    std::string texturePath)
//{
//    scene::IAnimatedMesh *mesh;
//    scene::IAnimatedMeshSceneNode *node = NULL;
//     scene::ISceneNodeAnimator* anim = NULL;
//
//    mesh = smgr->getMesh(std::string(MODELS_PATH + modelPath).c_str());
//    if (!mesh)
//        return (NULL);
//    node = smgr->addAnimatedMeshSceneNode(mesh);
//    if (node) {
//        // anim = smgr->createFlyStraightAnimator({-(MAP_WIDTH / 2) + 2, 0, (MAP_HEIGHT / 2) - 4},
//        //     {-(MAP_WIDTH / 2) + 2, 0, (MAP_HEIGHT / 2) - 4}, 3500, true);
//        // if (!anim)
//        //     return (NULL);
//        // node->addAnimator(anim);
//        // anim->drop();
//        // node->setFrameLoop(0, 55);
//        node->setAnimationSpeed(15);
//        node->setMaterialFlag(video::EMF_LIGHTING, false);
//        node->setMD2Animation(scene::EMAT_STAND);
//        node->setMaterialTexture(0, driver->getTexture(std::string(TEXTURES_PATH + texturePath).c_str()));
//    }
//    return (node);
//}

//Object *Irrlicht::createObject(std::string name, std::string model, std::string texture)
//{
//
//    Object *NewObject = NULL;
//    scene::IAnimatedMeshSceneNode *object;
//
//    object = createModel(this->_driver, this->_smgr, model, texture);
//    if (!object) {
//        std::cout << "Failed to create a model" << std::endl;
//        exit(84);
//    }
//    NewObject = new Object(object);
//    NewObject->setName(name);
//    return NewObject;
//}

//void Irrlicht::createMenu(void)
//{
//    // anicotte
//    // this->_window->getCursorControl()->setVisible(false);
//    Object *player = this->createObject("player", "idle.3ds", "Guard.png");
//    player->getSceneNode()->setScale({0.02, 0.02, 0.02});
//    player->getSceneNode()->setPosition({-(MAP_WIDTH / 2) + 2, 0, (MAP_HEIGHT / 2) - 4});
//    this->_objects.push_back(player);
//    // this->generateMap(1590316001);
//    this->generateMap(time(nullptr));
//}

//void Irrlicht::createGame()
//{
//}