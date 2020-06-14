/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** Animated object
*/

#ifndef ANIMATED_OBJECT_HPP
#define ANIMATED_OBJECT_HPP

#include <iostream>
#include <irrlicht.h>
#include <vector>
#include "Object.hpp"
#include "Enums.hpp"
#include "InputManager.hpp"

class AnimatedModel : public AObject
{
    protected:
        scene::IAnimatedMeshSceneNode *_node;

    public:
        AnimatedModel() = delete;
        AnimatedModel(scene::IAnimatedMeshSceneNode *, std::string, ObjectType type = NOTYPE);
        ~AnimatedModel() = default;

        scene::IAnimatedMeshSceneNode *getSceneNode() const;
        core::vector3df getPos(void) const;
        core::vector3df getRotation(void) const;
        core::aabbox3df getBoundingPos(void) const override;

        void setPos(core::vector3df);
        void setRotation(core::vector3df);
        void changeAnimation(PlayerAnimations);
};

class Bomb : public AnimatedModel
{
    private:
        std::string _owner;
        u32 _initial_time;
        u32 _time;
        int _range = 1;
        std::vector<Model *> _bombExplosions;

    public:
        Bomb(std::string, scene::IAnimatedMeshSceneNode *, std::string, u32, int);
        ~Bomb();

        int getRange(void) const;
        u32 getTime(void) const;
        void setTime(u32 newTime);
        void addBombExplosion(Model *explosion);
        std::vector<Model *> getBombExplosions(void) const;
        std::string getOwner(void) const;
        void clearExplosionsObjects(void);
};

class Player : public AnimatedModel
{
    private:
        core::vector3df _rotateFix;
        unsigned int _nb;
        bool _running;
        int _health;
        int _bombUp;
        float _speedUp;
        int _fireUp;
        bool _wallPass;
        bool _isHuman;
        u32 _speedupTime;
        u32 _wallpassTime;
        core::vector3df _originalPos;
        enum Events _upEvent;
        enum Events _downEvent;
        enum Events _leftEvent;
        enum Events _rightEvent;

    public:
        Player(int, scene::IAnimatedMeshSceneNode *, std::string, InputManager *, bool isHuman);
        ~Player();

        core::vector3df getRotateFix(void) const;
        float getSpeedUp(void) const;
        int getRange(void) const;
        int getBombUp(void) const;
        bool getWallPass(void) const;
        u32 getSpeedUpTime(void) const;
        u32 getWallPassTime(void) const;
        enum Events getUpEvent(void) const;
        enum Events getDownEvent(void) const;
        enum Events getLeftEvent(void) const;
        enum Events getRightEvent(void) const;
        enum Events getBombEvent(void) const;
        bool isHuman(void) const;
        core::vector3df getOriginalPos(void) const;
        int getNb() const;

        void setSpeedUp(u32, float = 1.5);
        void setRange(int = 1);
        void setBombUp(int = 1);
        void setWallPass(u32, bool);
        void setOriginalPos(core::vector3df);
        bool isRunning(void) const;
        void changeAnimation(PlayerAnimations);
};

#endif