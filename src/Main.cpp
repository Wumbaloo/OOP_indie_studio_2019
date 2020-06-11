/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** main.c
*/

#include <time.h>
#include "IndieStudio.hpp"

int main()
{
    Irrlicht *lib = new Irrlicht("Irrlicht");

    srand(time(0));
    GameManager(lib);
    return 0;
}
