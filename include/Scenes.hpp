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
        std::vector<Model *> _objects;
        std::vector<AnimatedModel *> _animObjects;

    public:
        Game(IrrlichtDevice *);
        ~Game() = default;
        Events checkEvents(IrrlichtDevice *, InputManager *) override;
        void display() override;
        void refreshWindow() override;

        Model *createModel(std::string, std::string, std::string);
        AnimatedModel *createAnimatedObject(std::string, std::string, std::string);
        scene::IAnimatedMeshSceneNode *createAnimatedModel(std::string, std::string);
        scene::IMeshSceneNode *createModel(std::string, std::string);
        Events KeyboardEvents(InputManager *, IrrlichtDevice *);
        Model *getObjectByName(std::string) const;
        AnimatedModel *getAnimObjByName(std::string) const;
        void makeBorderMap();
        void generateMap(unsigned int);
        void resetScene(IrrlichtDevice *) override;
        core::vector3df PlayerMovements(core::vector3df, AnimatedModel *, InputManager *);
};