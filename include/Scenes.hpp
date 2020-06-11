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
#include "Macros.hpp"

using namespace irr;

class AScene {
    protected:
        gui::IGUIEnvironment *_guienv;
        video::IVideoDriver *_driver;
        scene::ISceneManager *_smgr;
    public:
        explicit AScene(IrrlichtDevice *);
        ~AScene() = default;
        music_t *_musics = new music_t;
        void refreshWindow();
        gui::IGUIButton *newButton(core::rect<s32> pos, bool visible,
            core::string<fschar_t> path);
        virtual void display() = 0;
        virtual Events checkEvents(IrrlichtDevice *, InputManager *, settings_t *) = 0;
        virtual void resetScene(IrrlichtDevice *, settings_t *, InputManager *) = 0;
        virtual void createButtons() = 0;
        void checkHoverButton(core::vector2d<s32> cursorPos,
            std::vector<gui::IGUIButton *>, std::vector<gui::IGUIButton *>);
};

class Win : public AScene
{
    private:
        video::ITexture *_winPanel;
        video::ITexture *_playerSkin;
        gui::IGUIButton *_menuDefault;
        gui::IGUIButton *_menuHover;
        gui::IGUIStaticText *_playerName;
    public:
        Win(IrrlichtDevice *);
        ~Win() = default;
        void resetScene(IrrlichtDevice *, settings_t *, InputManager *) override;
        Events checkEvents(IrrlichtDevice *, InputManager *, settings_t *) override;
        void display() override;
        void createButtons() override;
};

class Load : public AScene
{
    private:
        std::vector<gui::IGUIButton *> _defaultButtons;
        std::vector<gui::IGUIButton *> _hoverButtons;
        video::ITexture *_loadBackground;
    public:
        Load(IrrlichtDevice *);
        ~Load() = default;
        void display() override;
        void resetScene(IrrlichtDevice *, settings_t *, InputManager *) override;
        void createButtons() override;
        Events checkEvents(IrrlichtDevice *, InputManager *, settings_t *) override;
};

class Menu : public AScene
{
    private:
        std::vector<gui::IGUIButton *> _defaultButtons;
        std::vector<gui::IGUIButton *> _hoverButtons;
        video::ITexture *_menuBackground;

    public:
        Menu(IrrlichtDevice *);
        ~Menu() = default;

        static void Main_music(music_t *_musics);
        static void Bonus_sound_effect(music_t *_musics);
        static void Hover_sound_effect(music_t *_musics);
        static void Title_music(music_t *_musics);

        void display() override;
        Events checkEvents(IrrlichtDevice *, InputManager *, settings_t *) override;
        void resetScene(IrrlichtDevice *, settings_t *, InputManager *) override;
        void createButtons() override;
        void close(void);
};

class HowToPlay : public AScene
{
    private:
        std::vector<gui::IGUIButton *> _defaultButtons;
        std::vector<gui::IGUIButton *> _hoverButtons;
        video::ITexture *_htpBackground;

    public:
        HowToPlay(IrrlichtDevice *);
        ~HowToPlay() = default;
        void display() override;
        void resetScene(IrrlichtDevice *, settings_t *, InputManager *) override;
        void createButtons() override;
        Events checkEvents(IrrlichtDevice *, InputManager *, settings_t *) override;
};

class Settings : public AScene
{
    private:
        video::ITexture *_settingsBackground;
        std::vector<gui::IGUIButton *> _soundsDefault;
        std::vector<gui::IGUIButton *> _soundsHover;
        gui::IGUIButton *_menuButtonDefault;
        gui::IGUIButton *_menuButtonHover;
        std::vector<gui::IGUIEditBox *> _nameBoxes;
        std::vector<video::ITexture *> _skinsEnabled;
        video::ITexture *_skinDisabled;
        std::vector<gui::IGUIListBox *> _listBoxes;
        std::vector<gui::IGUICheckBox *> _checkboxes;

    public:
        explicit Settings(IrrlichtDevice *);
        ~Settings() = default;

        void display() override;
        void createButtons() override;
        void resetScene(IrrlichtDevice *, settings_t *, InputManager *) override;
        Events checkEvents(IrrlichtDevice *, InputManager *, settings_t *) override;

        // generate
        void generateSettings(settings_t *);
        void generateNameBoxes(settings_t *);
        void generateSkins(settings_t *);
        void generateListBoxes(settings_t *);
        void generateCheckBoxes(settings_t *);

        // items
        gui::IGUIListBox *newListBox(core::rect<s32>, PlayerType, bool);
        gui::IGUIEditBox *newNameBox(const wchar_t *, core::rect<s32>, bool);
        gui::IGUICheckBox *newCheckBox(core::rect<s32>, bool);

        void manageMute(IrrlichtDevice *, settings_t *);
        void checkEditBoxUpdate(settings_t *);
        void checkListBoxUpdate(settings_t *);
        void checkCheckBoxUpdate(settings_t *);
        void updateEnabledPlayers(settings_t *);
        void updateSettings(settings_t *);
        void displaySkins();
};

class Game : public AScene
{
    private:
        float _grid;
        bool _paused;
        u32 _then;
        f32 _frameDeltaTime;
        int _winner;
        std::vector<Model *> _map[MAP_HEIGHT + 2];
        std::vector<Model *> _objects;
        std::vector<Player *> _playerObjects;
        std::vector<Bomb *> _bombObjects;
        std::vector<PowerUp *> _powerUpObjects;

    public:
        Game(IrrlichtDevice *);
        ~Game() = default;

        Events checkEvents(IrrlichtDevice *, InputManager *, settings_t *) override;
        void display(void) override;

        // create
        Model *createObject(std::string, std::string, std::string, core::vector3df, core::vector3df, ObjectType type = NOTYPE);
        Player *createPlayerObject(int, std::string, data_animations_t, InputManager *, bool isHuman);
        Bomb *createBombObject(std::string, data_animations_t, std::string, u32);
        PowerUp *createPowerUpObject(PowerUpsType, std::string, data_animations_t);
        scene::IAnimatedMeshSceneNode *createAnimatedModel(std::string, std::string, data_animations_t);
        scene::IMeshSceneNode *createModel(std::string, std::string);
        void createGameScene(settings_t *, InputManager *);

        // event
        bool checkColision(AnimatedModel *, std::vector<Model *>[], Direction, bool);
        Events KeyboardEvents(InputManager *, IrrlichtDevice *);
        void BombHandling(IrrlichtDevice *, InputManager *, Player *);
        void PowerUpContact(PowerUp *, Player *, IrrlichtDevice *);
        void PlayerMovements(Player *, InputManager *);
        bool AIGoToNearest(Player *, core::vector3df, core::vector2di);
        bool AIMovements(Player *);
        void BombExploded(Bomb *, vector<Player *> *);
        void deleteWall(Model *);
        void CheckIfNotBreakable(bool *, Bomb *, int);
        void CheckIfPlayer(bool *, Bomb *, vector<Player *> *, int);
        void CheckPowerUpsColision(Player *, IrrlichtDevice *);
        void SpawnPowerUps(core::vector3df );
        void PowerUpsTimerHandling(Player *, IrrlichtDevice *);
        void PlayerEvents(InputManager *, IrrlichtDevice *);

        // others
        int getNbBombByOwner(std::string owner) const;
        Model *getModelByName(std::string) const;
        Bomb *getBombByName(std::string) const;
        Player *getPlayerByName(std::string) const;
        void movePlayer(Player *player, core::vector2di dir);
        void resetScene(IrrlichtDevice *, settings_t *, InputManager *) override;
        void destroy(void);
        void close(void);

        // map
        void makeBorderMap(void);
        void generateMap(unsigned int);
        void generateTree(core::vector3df initialPos);
        void placeInMap(AObject *, int x, int y);
        AObject *getObjectFromMap(int x, int y);
        Model *getObjectFromGame(float x, float z);
        AObject *getObjectFromGame(core::vector3df pos);
        core::vector2di getMapPosition(AObject *object);
        core::vector2di getMapPosition(core::vector3df pos);

        // saves
        void save(void);
        void load(void);

        //Unused
        void createButtons() override {};
};