/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Main loop game file
*/

#include "IndieStudio.hpp"

Events checkTransition(Irrlicht *lib)
{
    switch (lib->getScene()->checkEvents(lib->getWindow(), lib->getInputManager())) {
        case PLAY:
            lib->changeGameStatus(GAME);
            lib->getScene()->resetScene(lib->getWindow());
            printf("Switched to the game ?\n");
            break;
        case BACK_MENU:
            lib->changeGameStatus(MENU);
            lib->getScene()->resetScene(lib->getWindow());
            printf("Switched to the menu ?\n");
            break;
        case CLOSE:
            return CLOSE;
        default:
            break;
    }
    return NONE;
}

int GameManager(Irrlicht *lib)
{
    lib->createWindow();
    lib->addScene(new Menu(lib->getWindow()));
    lib->addScene(new Game(lib->getWindow()));
    lib->changeGameStatus(GAME);
    lib->getScene()->resetScene(lib->getWindow());
    while(lib->isWindowOpen()) {
        lib->getScene()->display();
        lib->getScene()->refreshWindow();
        if (checkTransition(lib) == CLOSE)
            break;
    }
    lib->destroy();
    lib->close();
    return 0;
}