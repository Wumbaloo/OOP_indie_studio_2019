/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** smfl hmm library
*/

#ifndef IRRLICHT_HPP
#define IRRLICHT_HPP

#include <iostream>
#include <vector>
#include <irrlicht/irrlicht.h>
#include "Scenes.hpp"
#include "InputManager.hpp"
#include "IDisplayModule.hpp"
#include "Object.hpp"

using namespace irr;

class Irrlicht : public IDisplayModule
{
    private:
        const std::string _name;
        IrrlichtDevice *_window;
        InputManager *_inputManager = NULL;
        std::vector<IScene *> _scenes;
        GameStatus _status = UNKNOWN;

    //        video::IVideoDriver* _driver;
    public:
        Irrlicht(const std::string name);
        ~Irrlicht() = default;

        const std::string &getName() const;
        bool isWindowOpen(void) const;
        void createWindow(void);

        // destroy
        void destroy(void);
        void close(void);

        void addScene(IScene *scene);
        IScene *getScene();
        std::vector<IScene *> getScenes();
        void changeGameStatus(GameStatus);
        IrrlichtDevice *getWindow();
        InputManager *getInputManager();

//        //Deprecated
//        // gameManagement
//        void refreshWindow(void) const;
//        // display
//        void displayObjects(std::vector<Object *> objs, EndStatus endStatus, int score);
//        void display(void);
//        void makeBorderMap(void);
//        void generateMap(unsigned int seed);
//        // events
//        core::vector3df PlayerMovements(core::vector3df nodePosition, Object *player);
//        Events KeyboardEvents(void);
//        Events checkEvents(void);
//        // create
//        scene::IAnimatedMeshSceneNode *createModel(video::IVideoDriver* driver,
//            scene::ISceneManager *smgr, std::string modelPath,
//            std::string texturePath);
//        Object *createObject(std::string name, std::string model, std::string texture);
//        void createGame(void);
//        void createMenu(void);
//        Object *getObjectByName(std::string name) const;
};

#endif