/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** main.c
*/

#include <SFML/Audio.h>
#include <boost/lambda/lambda.hpp>
#include "IndieStudio.hpp"

int main()
{
    Irrlicht *lib = new Irrlicht("Irrlicht");

    GameManager(lib);
    return 0;
}
