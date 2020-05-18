/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** main.c
*/

#include <SFML/Audio.h>
#include <boost/lambda/lambda.hpp>
#include <irrlicht/irrlicht.h>
#include "IndieStudio.hpp"
#include "Irrlicht.hpp"

using namespace irr;

int main()
{
    Irrlicht *lib = new Irrlicht("Irrlicht");

    lib->createWindow();
    lib->createMenu();
    while(lib->isWindowOpen()) {
        lib->display();
        lib->refreshWindow();
    }
    lib->destroy();
    lib->close();
    return 0;
}
