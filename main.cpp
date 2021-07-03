// Name: Yovel Elad
// ID: 313412355
// Name: Amir Avidan
// ID: 205660178

#include "GameController.h"
#include "Game.h"
#include "TicTacToeGame.h"
#include "UI.h"

int main(int argc, char const *argv[])
{

    for (;;)
    {
        int gameChoose, dificultlyChoose, interfaceChoose, signCoose;
        char sign;

        cout << "Hello!" << endl;
        do
        {
            cout << "Choose a Game to play:" << endl;
            cout << "1. TicTacToe" << endl;
            cout << "2. Not Available." << endl;
            cin >> gameChoose;
            if (gameChoose != 1)
            {
                cout << "Game is no available." << endl;
            }
        } while (gameChoose != 1);

        do
        {
            cout << "Which one would you rather be?" << endl;
            cout << "1. 'X'" << endl;
            cout << "2. 'O'" << endl;
            cin >> signCoose;
            if(signCoose != 1 && signCoose != 2)
            {
                cout << "Choose again." << endl;
            }
        } while (signCoose != 1 && signCoose != 2);
        if(signCoose == 1)
            sign = 'X';
        else if(signCoose == 2)
            sign = 'O';

        do
        {
            cout << "choose dificultly:" << endl;
            cout << "1. Easy" << endl;
            cout << "2. Hard" << endl;
            cin >> dificultlyChoose;
            if (dificultlyChoose != 1 && dificultlyChoose != 2)
            {
                cout << "This is too hard for you, start with something easier. :)" << endl;
            }
        } while (dificultlyChoose != 1 && dificultlyChoose != 2);

        do
        {
            cout << "Choose the User Interface:" << endl;
            cout << "1. Console interface" << endl;
            cout << "2. Grephical User intergace" << endl;
            cin >> interfaceChoose;
            if (interfaceChoose != 1)
                cout << "This User interface is not valid." << endl;
        } while (interfaceChoose != 1);
        UI *ui;
        Game *game;
        GameController *GC;

        if (interfaceChoose == 1)
            ui = new Console();

        if (gameChoose == 1 && dificultlyChoose == 1)
        {
            game = new TicTacToeRand(sign);
            GC = new GameController(game,ui);
            cout << "Have fun!" << endl;
            cout << "Row <space> Col" << endl;
        }

        if (gameChoose == 1 && dificultlyChoose == 2)
        {
            game = new TicTacToeEdu(sign);
            GC = new GameController(game,ui);
            cout << endl;
            cout << "Have fun!" << endl;
            cout << "Row <space> Col" << endl;
        }

        GC->play();

        delete ui;
        delete game;
        delete GC;
        
    }

    return 0;
}
