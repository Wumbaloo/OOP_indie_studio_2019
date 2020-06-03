/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** Created by Anthony ANICOTTE,
*/

#include <SFML/Audio.hpp>
#include "Object.hpp"
#include "InputManager.hpp"
#include "AnimatedObjects.hpp"
#include "PowerUps.hpp"

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
        sf::Music _title_music;
        void Music_play();
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
        std::vector<Player *> _playerObjects;
        std::vector<Bomb *> _bombObjects;
        std::vector<PowerUp *> _powerUpObjects;

    public:
        sf::Music _main_music;
        void Music_play();
        Game(IrrlichtDevice *);
        ~Game() = default;
        Events checkEvents(IrrlichtDevice *, InputManager *) override;
        void display() override;
        void refreshWindow() override;

        // create
        Model *createObject(std::string, std::string, std::string, core::vector3df, core::vector3df);
        Player *createPlayerObject(std::string, data_animations_t);
        Bomb *createBombObject(std::string, data_animations_t, std::string, u32);
        PowerUp *createPowerUpObject(PowerUpsType, std::string, data_animations_t);

        scene::IAnimatedMeshSceneNode *createAnimatedModel(std::string, std::string, data_animations_t);
        scene::IMeshSceneNode *createModel(std::string, std::string);

        void createGameScene(void);
        // others
        void bombHandling(IrrlichtDevice *);
        Events KeyboardEvents(InputManager *, IrrlichtDevice *);
        Model *getModelByName(std::string) const;
        Bomb *getBombByName(std::string) const;
        Player *getPlayerByName(std::string) const;
        void makeBorderMap();
        void generateMap(unsigned int);
        void resetScene(IrrlichtDevice *) override;
        core::vector3df PlayerMovements(core::vector3df, Player *, InputManager *);
};