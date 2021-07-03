// Name: Yovel Elad
// ID: 313412355
// Name: Amir Avidan
// ID: 205660178


#pragma once
#include "BoardGame.h"
#include <bits/stdc++.h>

using namespace std;

class TicTacToeGame : public BoardGame
{
public:
    TicTacToeGame(char sign) : BoardGame(3, 3), playerSign(sign)
    {
        if (sign == 'X')
            computerSign = 'O';
        else
            computerSign = 'X';
    }
    ~TicTacToeGame() {}
    virtual void getPlayerMove();
    char gameStatus();

protected:
    char playerSign;
    char computerSign;
};

void TicTacToeGame::getPlayerMove()
{
    int i, j;
    cin >> i >> j;
    while (i > 2 && j > 2)
    {
        cout << "Illegal Move, try agein." << endl;
        cin >> i >> j;
    }
    Move move(i, j);
    board->setBoard(move, playerSign);
}

char TicTacToeGame::gameStatus()
{
    // cout << ":)" << endl;
    int i = 0, j = 0;
    int flag = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (isEmpty(board->getBoard()[i][j]))
            {
                flag = 1;
                break;
            }
        }
    }
    if (!flag)
    {
        cout << "It's a Tie!" << endl << endl;
        return 'T';
    }

    i = 0;
    j = 0;
    flag = 0;
    // Checking for Rows for X or O victory.
    for (i; i < 3; i++)
    {
        if (board->getBoard()[i][0] == board->getBoard()[i][1] && board->getBoard()[i][0] == board->getBoard()[i][2] && !isEmpty(board->getBoard()[i][0]))
        {
            cout << board->getBoard()[i][0] << " is the Winner!" << endl << endl;
            return board->getBoard()[i][0];
        }
    }

    // Checking for Columns for X or O victory.
    for (j; j < 3; j++)
    {
        if (board->getBoard()[0][j] == board->getBoard()[1][j] && board->getBoard()[0][j] == board->getBoard()[2][j] && !isEmpty(board->getBoard()[0][j]))
        {
            cout << board->getBoard()[0][j] << " is the Winner!" << endl << endl;
            return board->getBoard()[0][j];
        }
    }

    // Checking for Diagonals for X or O victory.
    if (board->getBoard()[0][0] == board->getBoard()[1][1] && board->getBoard()[0][0] == board->getBoard()[2][2] && !isEmpty(board->getBoard()[0][0]))
    {
        cout << board->getBoard()[0][0] << " is the Winner!" << endl << endl;
        return board->getBoard()[0][0];
    }

    if (board->getBoard()[0][2] == board->getBoard()[1][1] && board->getBoard()[0][2] == board->getBoard()[2][0] && !isEmpty(board->getBoard()[0][2]))
    {
        cout << board->getBoard()[0][2] << " is the Winner!" << endl << endl;
        return board->getBoard()[0][2];
    }

    return 'R';
}

class TicTacToeRand : public TicTacToeGame
{
public:
    TicTacToeRand(char sign) : TicTacToeGame(sign) {}
    ~TicTacToeRand() {}
    void getComputerMove() ;
};

void TicTacToeRand::getComputerMove() 
{
    int i = 0, j = 0;
    int flag = 0;
    while (board->getBoard()[i][j] != '*')
    {
        j++;
        if (i == 2 && j == 3)
        {
            cout << "GameOver" << endl;
            flag = 1;
            break;
        }
        if (j == 3)
        {
            j = 0;
            i++;
        }
    }
    if (!flag)
    {
        Move computerMove(i, j);
        board->setBoard(computerMove, computerSign);
    }
}

class TicTacToeEdu : public TicTacToeGame
{
public:
    TicTacToeEdu(char sign) : TicTacToeGame(sign) {}
    ~TicTacToeEdu() {}
    void getComputerMove();

    // 3 methods for Minimax Algorithem
    int evaluate(Board *);
    int minimax(Board *board, int depth, bool isMax);
    Move findBestMove(Board *board);

};



bool isMovesLeft(Board *board)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board->getBoard()[i][j] == '*')
                return true;
    return false;
}

int TicTacToeEdu::evaluate(Board *board)
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row < 3; row++)
    {
        if (board->getBoard()[row][0] == board->getBoard()[row][1] &&
            board->getBoard()[row][1] == board->getBoard()[row][2])
        {
            if (board->getBoard()[row][0] == computerSign)
                return +10;
            else if (board->getBoard()[row][0] == playerSign)
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col < 3; col++)
    {
        if (board->getBoard()[0][col] == board->getBoard()[1][col] &&
            board->getBoard()[1][col] == board->getBoard()[2][col])
        {
            if (board->getBoard()[0][col] == computerSign)
                return +10;

            else if (board->getBoard()[0][col] == playerSign)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (board->getBoard()[0][0] == board->getBoard()[1][1] && board->getBoard()[1][1] == board->getBoard()[2][2])
    {
        if (board->getBoard()[0][0] == computerSign)
            return +10;
        else if (board->getBoard()[0][0] == playerSign)
            return -10;
    }

    if (board->getBoard()[0][2] == board->getBoard()[1][1] && board->getBoard()[1][1] == board->getBoard()[2][0])
    {
        if (board->getBoard()[0][2] == computerSign)
            return +10;
        else if (board->getBoard()[0][2] == playerSign)
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}
int TicTacToeEdu::minimax(Board *board, int depth, bool isMax)
{
    int score = evaluate(board);
    if (score == 10)
        return score;
    if (score == -10)
        return score;
    if (isMovesLeft(board) == false)
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (isEmpty( board->getBoard()[i][j]))
                {
                    board->getBoard()[i][j] = computerSign;
                    best = max(best,
                               minimax(board, depth + 1, !isMax));

                    board->getBoard()[i][j] = '*';
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (isEmpty(board->getBoard()[i][j]))
                {
                    board->getBoard()[i][j] = playerSign;
                    best = min(best,
                               minimax(board, depth + 1, !isMax));
                    board->getBoard()[i][j] = '*';
                }
            }
        }
        return best;
    }
}

// This will return the best possible move 
Move TicTacToeEdu::findBestMove(Board *board)
{
    int bestVal = -1000;
    Move bestMove(-1,-1);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (isEmpty(board->getBoard()[i][j]))
            {
                board->getBoard()[i][j] = computerSign;
                int moveVal = minimax(board, 0, false);
                board->getBoard()[i][j] = '*';

                if (moveVal > bestVal)
                {
                    bestMove.setRow(i);
                    bestMove.setCol(j);
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

void TicTacToeEdu::getComputerMove() 
{
    Move computerMove = findBestMove(board);
    board->setBoard(computerMove, computerSign);
}