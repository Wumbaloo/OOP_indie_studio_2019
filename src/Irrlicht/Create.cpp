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
    // this->_window->setMouseCursorVisible(true);
    this->_objects.push_back(this->createObject("BomberMan.3ds", "Bombermap.tga"));
}

void Irrlicht::createGame()
{
    // this->_win.push_back(this->createSprite("lib/assets/you_win.bmp",sf::Vector2f(832, 416), "youWin", sf::IntRect(0, 0, 256, 248)));
    // this->_lose.push_back(this->createSprite("lib/assets/game_over.bmp",sf::Vector2f(768, 408), "youLose", sf::IntRect(0, 0, 384, 264)));
    // this->_endTexts.push_back(this->createText("Press B to get back to the menu", sf::Vector2f(150, 850), "backMenuText", 12));
    // this->_endTexts.push_back(this->createText("Press R to restart the game", sf::Vector2f(150, 880), "restartGameText", 12));
    // this->_endTexts.push_back(this->createText("", sf::Vector2f(150, 910), "gameScore", 12));
}