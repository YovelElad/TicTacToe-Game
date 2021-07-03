// Name: Yovel Elad
// ID: 313412355
// Name: Amir Avidan
// ID: 205660178

#pragma once
#include <iostream>
#include "Game.h"
#include "TicTacToeGame.h"
#include "UI.h"
using namespace std;

class GameController
{
public:
    GameController() {}
    GameController(Game *newGame, UI *newUI) : game(newGame), userInterface(newUI) {}
    // ~GameController();
    void play();

private:
    Game *game;
    UI *userInterface;
};

void GameController::play()
{

    BoardGame *bg = dynamic_cast<BoardGame *>(game);
    if (!bg)
    {
        cout << "Error";
        exit(1);
    }

    Console *consol = dynamic_cast<Console *>(userInterface);
    if (!consol)
    {
        cout << "Error";
        exit(1);
    }

    while (bg->gameStatus() == 'R')
    {
        game->getPlayerMove();
        // consol->display(bg->getBoard());

        if (bg->gameStatus() != 'R')
        {
            consol->display(bg->getBoard());
            break;
        }
        game->getComputerMove();
        consol->display(bg->getBoard());
    }
}