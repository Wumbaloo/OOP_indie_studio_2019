/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SpriteObject
*/

#ifndef SPRITE_OBJECT_HPP
#define SPRITE_OBJECT_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class SpriteObject
{
    private:
        const string _name;
        sf::Sprite *_sprite;
        float _lastFrame = 0;
        sf::IntRect _dimensions;

    public:
        SpriteObject(string name, sf::Sprite *sprite, sf::IntRect dimensions);
        ~SpriteObject() = default;

        const string getName(void) const;
        sf::Sprite *getSprite(void) const;
        float getLastFrame(void) const;
        void setLastFrame(float time);
        sf::IntRect getDimensions(void) const;
        void setDimensions(sf::IntRect);
};


#endif
