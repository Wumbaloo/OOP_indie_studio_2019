/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** enum
*/

#ifndef ENUM_HPP
#define ENUM_HPP

enum Events
{
    NONE,
    CLOSE,
    PLAY,
    BACK_MENU,
    RESTART,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    END_GAME,
    BOMB,
    PAUSE,
    TO_SETTINGS,
};

enum PlayerType {
    HUMAN,
    AI
};

enum GameStatus {
    MENU,
    GAME,
    SETTINGS,
    UNKNOWN
};

enum PlayerAnimations {
    IDLE,
    RUNNING
};

enum PowerUpsType {
    NOPOWER,
    BOMBUP,
    SPEEDUP,
    FIREUP,
    WALLPASS,
};

enum ObjectType {
    NOTYPE,
    OBSTACLE,
    BREAKABLE,
    POWERUP,
    ENEMY,
    PLAYER,
};

enum Direction {
    LEFT,
    UP,
    DOWN,
    RIGHT,
};

enum EndStatus {
    NOTHING,
    WIN,
    LOSE,
};

#endif