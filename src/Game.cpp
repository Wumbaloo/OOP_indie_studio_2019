/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Main loop game file
*/

#include "IndieStudio.hpp"

int GameManager(Irrlicht *lib)
{
    lib->createWindow();
    lib->createMenu();
    while(lib->isWindowOpen()) {
        lib->display();
        lib->refreshWindow();
        lib->checkEvents();
    }
    lib->destroy();
    lib->close();
    return 0;
}