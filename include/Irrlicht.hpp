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
        void destroy(void);
        void close(void);

        void addScene(IScene *scene);
        IScene *getScene();
        std::vector<IScene *> getScenes();
        void changeGameStatus(GameStatus);
        IrrlichtDevice *getWindow();
        InputManager *getInputManager();

        void saveParser(); // en void temporairement le temps de savoir ce que sera le type qui sera return
};

#endif