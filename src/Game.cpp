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
    lib->addScene(new Menu(lib->getWindow()));
    lib->addScene(new Game(lib->getWindow()));
    lib->changeGameStatus(MENU);
    lib->getScene()->resetScene(lib->getWindow());
    while(lib->isWindowOpen()) {
        lib->getScene()->display();
        lib->getScene()->refreshWindow();
        if (lib->getScene()->checkEvents(lib->getWindow(), lib->getInputManager()) == CLOSE)
            break;
    }
    lib->destroy();
    lib->close();
    return 0;
}