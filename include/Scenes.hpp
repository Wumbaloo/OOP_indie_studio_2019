/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include "Object.hpp"
#include "InputManager.hpp"

using namespace irr;

class IScene
{
    public:
        virtual ~IScene() = default;
        virtual Events checkEvents(IrrlichtDevice *, InputManager *) = 0;
        virtual void display() = 0;
        virtual void refreshWindow() = 0;
        virtual void resetScene(IrrlichtDevice *) = 0;
};

class Menu : public IScene
{
    private:
        gui::IGUIEnvironment* _guienv;
        video::IVideoDriver* _driver;
        scene::ISceneManager* _smgr;
        video::ITexture *_menuBackground;

    public:
        Menu(IrrlichtDevice *);
        ~Menu() = default;
        Events checkEvents(IrrlichtDevice *, InputManager *) override;
        void display() override;
        void refreshWindow() override;
        void resetScene(IrrlichtDevice *) override;
};

class Game : public IScene
{
    private:
        gui::IGUIEnvironment* _guienv;
        video::IVideoDriver* _driver;
        scene::ISceneManager* _smgr;
        u32 _then;
        f32 _frameDeltaTime;
        std::vector<Object *> _objects;

    public:
        Game(IrrlichtDevice *);
        ~Game() = default;
        Events checkEvents(IrrlichtDevice *, InputManager *) override;
        void display() override;
        void refreshWindow() override;

        Object *createObject(std::string, std::string, std::string);
        scene::IAnimatedMeshSceneNode *createModel(video::IVideoDriver*, scene::ISceneManager *, std::string, std::string);
        Events KeyboardEvents(InputManager *);
        Object *getObjectByName(std::string) const;
        void makeBorderMap();
        void generateMap(unsigned int);
        void resetScene(IrrlichtDevice *) override;
        core::vector3df PlayerMovements(core::vector3df, Object *, InputManager *);
};