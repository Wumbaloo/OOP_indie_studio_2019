/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Main loop game file
*/

#include "IndieStudio.hpp"

void checkTransition(Irrlicht *lib)
{
    switch (lib->getScene()->checkEvents(lib->getWindow(), lib->getInputManager()))
    {
        case PLAY:
            lib->changeGameStatus(GAME);
            lib->getScene()->resetScene(lib->getWindow());
            printf("Switched to the game ?\n");
        case BACK_MENU:
            lib->changeGameStatus(MENU);
            lib->getScene()->resetScene(lib->getWindow());
            printf("Switched to the menu ?\n");
        default:
            return;
    }
}

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
        checkTransition(lib);
        if (lib->getScene()->checkEvents(lib->getWindow(), lib->getInputManager()) == CLOSE)
            break;
    }
    lib->destroy();
    lib->close();
    return 0;
}