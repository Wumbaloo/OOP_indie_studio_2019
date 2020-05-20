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
#include "InputManager.hpp"
#include "IDisplayModule.hpp"
#include "Object.hpp"

using namespace irr;

class Irrlicht : public IDisplayModule
{
    private:
        const std::string _name;
        IrrlichtDevice *_window;
        video::IVideoDriver* _driver;
        scene::ISceneManager* _smgr;
        gui::IGUIEnvironment* _guienv;
        std::vector<Object *> _objects;
        InputManager *_inputManager = NULL;
        u32 _then;
        f32 _frameDeltaTime;

    public:
        Irrlicht(const std::string name);
        ~Irrlicht() = default;

        const std::string &getName() const;
        Object *getObjectByName(std::string name) const;
        // gameManagement
        void refreshWindow(void) const;
        bool isWindowOpen(void) const;
        // events
        Events KeyboardEvents(void);
        Events checkEvents(void);
        // create
        scene::IAnimatedMeshSceneNode *createModel(video::IVideoDriver* driver,
            scene::ISceneManager *smgr, std::string modelPath,
            std::string texturePath);
        Object *createObject(std::string name, std::string model, std::string texture);
        void createGame(void);
        void createWindow(void);
        void createMenu(void);
        // display
        void displayObjects(std::vector<Object *> objs, EndStatus endStatus, int score);
        void display(void);
        // destroy
        void destroy(void);
        void close(void);
};

#endif