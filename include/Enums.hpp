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
    END_GAME,
    PAUSE,
    TO_SETTINGS,
    MOVE_UP_1,
    MOVE_DOWN_1,
    MOVE_LEFT_1,
    MOVE_RIGHT_1,
    BOMB_1,
    MOVE_UP_2,
    MOVE_DOWN_2,
    MOVE_LEFT_2,
    MOVE_RIGHT_2,
    BOMB_2,
    MOVE_UP_3,
    MOVE_DOWN_3,
    MOVE_LEFT_3,
    MOVE_RIGHT_3,
    BOMB_3,
    MOVE_UP_4,
    MOVE_DOWN_4,
    MOVE_LEFT_4,
    MOVE_RIGHT_4,
    BOMB_4,
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