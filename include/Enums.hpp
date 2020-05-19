/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** enum
*/

#ifndef ENUM_HPP
#define ENUM_HPP

#define MAP_WIDTH 30
#define MAP_HEIGHT 30

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
};

enum GameStatus {
    UNKNOWN,
    MENU,
    GAME,
};

enum ObjectType {
    NOTYPE,
    OBSTACLE,
    CONSUMABLE,
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