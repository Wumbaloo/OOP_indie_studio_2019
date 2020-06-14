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
#include <irrlicht.h>
#include "Scenes.hpp"
#include "InputManager.hpp"
#include "IDisplayModule.hpp"
#include "Object.hpp"
#include "Structures.hpp"

using namespace irr;

class Irrlicht : public IDisplayModule
{
    private:
        const std::string _name;
        IrrlichtDevice *_window = NULL;
        InputManager *_inputManager = NULL;
        std::vector<AScene *> _scenes;
        GameStatus _status = MENU;
        settings_t *_gameSettings = NULL;
    //        video::IVideoDriver* _driver;
    public:
        Irrlicht(const std::string name);
        ~Irrlicht() = default;

        const std::string &getName() const;
        bool isWindowOpen(void) const;
        void createWindow(void);
        void destroy(void);
        void close(void);

        void addScene(AScene *scene);
        AScene *getScene();
        std::vector<AScene *> getScenes();
        void changeGameStatus(GameStatus);
        IrrlichtDevice *getWindow();
        InputManager *getInputManager();
        settings_t *getSettings();
};

#endif