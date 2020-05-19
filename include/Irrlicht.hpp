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

    public:
        Irrlicht(const std::string name);
        ~Irrlicht() = default;

        const std::string &getName() const;
        // // gameManagement
        void refreshWindow(void) const;
        bool isWindowOpen(void) const;
        // // events
        // bool mouseIsOverObject(sf::Vector2i mousePos, string objectName);
        Events checkEvents(void);
        // Events clickEvents(sf::Event event);
        // // create
        scene::IAnimatedMesh *createModel(video::IVideoDriver* driver,
            scene::ISceneManager *smgr, std::string modelPath,
            std::string texturePath);
        Object *createObject(std::string model, std::string texture);
        // TextObject *createText(string text, sf::Vector2f pos, string name, int fontSize);
        void createGame(void);
        void createWindow(void);
        void createMenu(void);
        // // display
        // void displaySprite(void);
        // void displayText(string playerName);
        void displayObjects(std::vector<Object *> objs, EndStatus endStatus, int score);
        void display(void);
        // // destroy
        void destroy(void);
        void close(void);
};

#endif