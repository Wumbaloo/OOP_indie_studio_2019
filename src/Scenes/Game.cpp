/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include <IrrlichtDevice.h>
#include "IndieStudio.hpp"

bool isBorderNext(vector2f_t pos, vector2f_t height, vector2f_t width, float step, float range);

Game::Game(IrrlichtDevice *window)
{
    this->_driver = window->getVideoDriver();
    this->_smgr = window->getSceneManager();
    this->_guienv = window->getGUIEnvironment();
}

Events Game::checkEvents(IrrlichtDevice *window, InputManager *inputManager)
{
    const u32 now = window->getTimer()->getTime();

    this->_frameDeltaTime = this->_frameDeltaTime = (f32)(now - this->_then) / 1000.f;
    this->_then = now;
    return (KeyboardEvents(inputManager));
}

void Game::display()
{
    this->_driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
    this->_smgr->drawAll();
    this->_guienv->drawAll();
}

void Game::refreshWindow()
{
    this->_driver->endScene();
}

Object *Game::createObject(std::string name, std::string model, std::string texture)
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

scene::IAnimatedMeshSceneNode *Game::createModel(video::IVideoDriver* driver,
    scene::ISceneManager *smgr, std::string modelPath,
    std::string texturePath)
{
    scene::IAnimatedMesh *mesh;
    scene::IAnimatedMeshSceneNode *node = NULL;
    scene::ISceneNodeAnimator* anim = NULL;

    mesh = smgr->getMesh(std::string(MODELS_PATH + modelPath).c_str());
    if (!mesh)
        return (NULL);
    node = smgr->addAnimatedMeshSceneNode(mesh);
    if (node) {
        // anim = smgr->createFlyStraightAnimator({-(MAP_WIDTH / 2) + 2, 0, (MAP_HEIGHT / 2) - 4},
        //     {-(MAP_WIDTH / 2) + 2, 0, (MAP_HEIGHT / 2) - 4}, 3500, true);
        // if (!anim)
        //     return (NULL);
        // node->addAnimator(anim);
        // anim->drop();
        // node->setFrameLoop(0, 55);
        node->setAnimationSpeed(15);
        node->setMaterialFlag(video::EMF_LIGHTING, false);
        node->setMD2Animation(scene::EMAT_STAND);
        node->setMaterialTexture(0, driver->getTexture(std::string(TEXTURES_PATH + texturePath).c_str()));
    }
    return (node);
}

Events Game::KeyboardEvents(InputManager *inputManager)
{
    Object *player = this->getObjectByName("player");
    core::vector3df nodePosition;

    if (!player)
        return NONE;
    if (inputManager->isKeyPressed(CLOSE))
        return CLOSE;
    nodePosition = PlayerMovements(nodePosition, player, inputManager);
    if (nodePosition != player->getPos())
        player->getSceneNode()->setPosition(nodePosition);
    return NONE;
}

Object *Game::getObjectByName(std::string name) const
{
    for (Object *obj : this->_objects) {
        if (obj->getName() == name)
            return obj;
    }
    return NULL;
}

void Game::makeBorderMap()
{
    float step = 2;
    float heightBegin = -(MAP_HEIGHT / 2);
    float heightEnd = MAP_HEIGHT / 2;
    float widthBegin = -(MAP_WIDTH / 2);
    float widthEnd = MAP_WIDTH / 2;

    for (float z = heightBegin; z < heightEnd; z+= step) {
        Object *left = this->createObject("wall", "Square.obj", "Square.jpg");
        scene::IAnimatedMeshSceneNode *node = left->getSceneNode();
        node->setPosition({(float) (widthBegin), 0, (float) z});
        Object *right = this->createObject("wall", "Square.obj", "Square.jpg");
        node = right->getSceneNode();
        node->setPosition({(float) (widthEnd), 0, (float) z});
        if (z == heightBegin || z >= (heightEnd - step)) {
            for (float x = widthBegin; x < widthEnd; x+= step) {
                Object *left = this->createObject("wall", "Square.obj", "Square.jpg");
                scene::IAnimatedMeshSceneNode *node = left->getSceneNode();
                node->setPosition({(float) (x), 0, (float) z});
            }
        }
    }
}

void Game::generateMap(unsigned int seed)
{
    float step = 2;
    srand(seed);
    std::cout << "Map with seed: " << seed << std::endl;
    float beginHeight = (MAP_HEIGHT / 2) - step * 2;
    float beginWidth = -(MAP_WIDTH / 2) + step;
    float endHeight = -(MAP_HEIGHT / 2);
    float endWidth = MAP_WIDTH / 2;

    this->makeBorderMap();
    for (float z = beginHeight; z > endHeight; z -= step) {
        for (float x = beginWidth; x < endWidth; x += step) {
            int random = rand() % 4;
            Object *obj = NULL;
            if (random == 0 || isBorderNext({x, z}, {beginHeight, endHeight}, {beginWidth, endWidth}, step, 0))
                continue;
            else if ((random > 0 && random < 3) || isBorderNext({x, z}, {beginHeight, endHeight}, {beginWidth, endWidth}, step, 2))
                obj = this->createObject("destructible", "Square.obj", "Destruct.jpg");
            else
                obj = this->createObject("wall", "Square.obj", "Square.jpg");
            scene::IAnimatedMeshSceneNode *node = obj->getSceneNode();
            node->setPosition({(float) x, 0, (float) z});
        }
    }
}

core::vector3df Game::PlayerMovements(core::vector3df nodePosition, Object *player, InputManager *inputManager)
{
    nodePosition = player->getPos();
    if (inputManager->isKeyPressed(MOVE_UP)) {
        nodePosition.Z += PLAYER_SPEED * this->_frameDeltaTime;
        player->getSceneNode()->setRotation((core::vector3df){0.f, 180.f, .0f});
    }
    if (inputManager->isKeyPressed(MOVE_DOWN)) {
        nodePosition.Z -= PLAYER_SPEED * this->_frameDeltaTime;
        player->getSceneNode()->setRotation((core::vector3df){0.f, 0.f, 0.f});
    }
    if (inputManager->isKeyPressed(MOVE_LEFT)) {
        nodePosition.X -= PLAYER_SPEED * this->_frameDeltaTime;
        player->getSceneNode()->setRotation((core::vector3df){0.f, 90.f, 0.f});
    }
    if (inputManager->isKeyPressed(MOVE_RIGHT)) {
        nodePosition.X += PLAYER_SPEED * this->_frameDeltaTime;
        player->getSceneNode()->setRotation((core::vector3df){0.f, -90.f, 0.f});
    }
    return nodePosition;
}

void Game::resetScene(IrrlichtDevice *window)
{
    this->_driver->removeAllTextures();
    this->_guienv->clear();
    this->_objects.clear();
    this->_smgr->clear();
    this->_smgr->addCameraSceneNode(0, core::vector3df(0, 30, -15),
        core::vector3df(0, 0, 0));
    this->_then = window->getTimer()->getTime();
    Object *player = this->createObject("player", "BomberMan.3ds",
        "Bombermap.tga");
    player->getSceneNode()->setScale({0.02, 0.02, 0.02});
    player->getSceneNode()->setRotation({-90, 0, 0});
    player->getSceneNode()->setPosition(
        {-(MAP_WIDTH / 2) + 2, 0, (MAP_HEIGHT / 2) - 4});
    this->_objects.push_back(player);
    this->generateMap(time(nullptr));
    this->_objects.push_back(this->createObject("player", "BomberMan.3ds", "Bombermap.tga"));
}
