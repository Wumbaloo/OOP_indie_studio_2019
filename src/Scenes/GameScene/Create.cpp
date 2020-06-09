/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** create game component cpp
*/

#include "IndieStudio.hpp"
#include "AnimatedObjects.hpp"

scene::IMeshSceneNode *Game::createModel(std::string modelPath, std::string texturePath)
{
    scene::IMesh *mesh;
    scene::IMeshSceneNode *node = NULL;

    mesh = this->_smgr->getMesh(std::string(MODELS_PATH + modelPath).c_str());
    if (!mesh)
        return (NULL);
    node = this->_smgr->addMeshSceneNode(mesh);
    if (node) {
        node->setMaterialFlag(video::EMF_LIGHTING, false);
        node->setMaterialTexture(0, this->_driver->getTexture(std::string(TEXTURES_PATH + texturePath).c_str()));
    }
    return (node);
}

scene::IAnimatedMeshSceneNode *Game::createAnimatedModel(std::string modelPath, std::string texturePath, data_animations_t data)
{
    scene::IAnimatedMesh *mesh;
    scene::IAnimatedMeshSceneNode *node = NULL;

    mesh = this->_smgr->getMesh(std::string(MODELS_PATH + modelPath).c_str());
    if (!mesh)
        return (NULL);
    node = this->_smgr->addAnimatedMeshSceneNode(mesh);
    if (node) {
        node->setMaterialFlag(video::EMF_LIGHTING, false);
        node->setMaterialTexture(0, this->_driver->getTexture(std::string(TEXTURES_PATH + texturePath).c_str()));
        node->setScale(data.scale);
        node->setPosition(data.pos);
        node->setFrameLoop(data.frameLoop.x, data.frameLoop.y);
        node->setAnimationSpeed(data.animationSpeed);
    }
    return (node);
}

Model *Game::createObject(std::string name, std::string model, std::string texture, core::vector3df pos, core::vector3df scale, ObjectType type)
{
    Model *NewObject = NULL;
    scene::IMeshSceneNode *object;

    object = createModel(model, texture);
    object->setPosition(pos);
    object->setScale(scale);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new Model(object, name, type);
    return NewObject;
}

Player *Game::createPlayerObject(int nb, std::string name, data_animations_t data, InputManager *im)
{
    Player *NewObject = NULL;
    scene::IAnimatedMeshSceneNode *object;

    object = createAnimatedModel(data.model, data.texture, data);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new Player(nb, object, name, im);
    return NewObject;
}

Bomb *Game::createBombObject(std::string name, data_animations_t data, std::string launcherName, u32 time)
{
    Bomb *NewObject = NULL;
    scene::IAnimatedMeshSceneNode *object;

    object = createAnimatedModel(data.model, data.texture, data);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new Bomb(name, object, launcherName, time);
    return NewObject;
}

PowerUp *Game::createPowerUpObject(PowerUpsType type, std::string name, data_animations_t data)
{
    PowerUp *NewObject = NULL;
    scene::IAnimatedMeshSceneNode *object;

    object = createAnimatedModel(data.model, data.texture, data);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new PowerUp(object, name, type);
    // placeInMap(NewObject, data.pos.X, data.pos.Z);
    return NewObject;
}

void Game::createGameScene(settings_t *settings, InputManager *im)
{
    for (int i = 0; i < settings->types.size(); i++) {
        if (settings->playing.at(i) == true) {
            std::string name = std::string("Player ") + std::to_string(i);
            irr::core::vector3df pos;

            switch (i + 1) {
                default:
                case 1:
                    pos = {-(MAP_WIDTH) + 2, -1, (MAP_HEIGHT) - 4};
                    break;
                case 2:
                    pos = {(MAP_WIDTH), -1, -(MAP_HEIGHT) - 2};
                    break;
                case 3:
                    pos = {(MAP_WIDTH), -1, (MAP_HEIGHT) - 4};
                    break;
                case 4:
                    pos = {-(MAP_WIDTH) + 2, -1, -(MAP_HEIGHT) - 2};
                    break;
            }
            this->_playerObjects.push_back(this->createPlayerObject(i + 1, name,
                {"guard.md3", std::string("Guard") + std::to_string(i + 1) + std::string(".png"), pos, {0.035, 0.035, 0.035}, {0, 200}, 32.5}, im));
        }
    }
    this->_powerUpObjects.push_back(this->createPowerUpObject(WALLPASS, "WallPass", {"WallPass.md3", "WallPass.bmp",
        {-(MAP_WIDTH) + 2, 0, (MAP_HEIGHT) - 5}, {.7, .7, .7}, {0, 50}, 25}));
    this->placeInMap(this->_powerUpObjects.at(0), 0, 0);
    // this->_powerUpObjects.push_back(this->createPowerUpObject(SPEEDUP, "speedUp", {"SpeedUp.md3", "wing_textureColor.png",
    //     {-(MAP_WIDTH / 2) - 5, 0, (MAP_HEIGHT / 2) - 4}, {.8, .8, .8}, {0, 31}, 20}));
    // this->_powerUpObjects.push_back(this->createPowerUpObject(BOMBUP, "BombUp", {"bombUp.md3", "Rough.png",
    //     {-(MAP_WIDTH / 2) - 15, 0, (MAP_HEIGHT / 2) - 4}, {.7, .7, .7}, {0, 50}, 25}));
    // this->_powerUpObjects.push_back(this->createPowerUpObject(FIREUP, "FireUp", {"FireUp.md3", "FireUp.png",
    //     {-(MAP_WIDTH / 2) - 20, 0, (MAP_HEIGHT / 2) - 4}, {.7, .7, .7}, {0, 62}, 25}));
    this->generateMap(time(nullptr));
}