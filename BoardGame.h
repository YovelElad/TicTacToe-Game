// Name: Yovel Elad
// ID: 313412355
// Name: Amir Avidan
// ID: 205660178

#pragma once
#include "Game.h"
using namespace std;

class Board
{
public:
    Board(int, int);
    ~Board();

    int getRowSize() const { return _boardRowSize; }
    int getColSize() const { return _boardColSize; }
    char **getBoard() const { return _board; }
    void setBoard(const Move &, char);

private:
    char **_board;
    int _boardRowSize;
    int _boardColSize;
};

Board::Board(int rowSize, int colSize)
    : _boardRowSize(rowSize),
      _boardColSize(colSize)
{
    _board = new char *[rowSize];
    for (int i = 0; i < rowSize; i++)
        _board[i] = new char[colSize];

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            _board[i][j] = '*';
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < _boardColSize; i++)
        delete[] _board[i];
    delete[] _board;
}

void Board::setBoard(const Move &move, char sign)
{
    if (_board[move.GetRow()][move.GetCol()] == '*')
        _board[move.GetRow()][move.GetCol()] = sign;
    else
    {
        cout << "Place is already tacken" << endl;
        int i, j;
        cin >> i >> j;
        Move newMove(i, j);
        setBoard(newMove,sign);
    }
}

class BoardGame : public Game
{
public:
    BoardGame(int, int);
    ~BoardGame();

    Board *getBoard() const { return board; }
    void setBoard(const Move &move, char sign) { board->setBoard(move, sign); }
    bool isEmpty(char);

protected:
    Board *board;
};

BoardGame::BoardGame(int rowSize, int colSize)
{
    board = new Board(rowSize, colSize);
    // board(rowSize,colSize);
}

BoardGame::~BoardGame()
{
    delete board;
}

bool BoardGame::isEmpty(char c)
{
    if (c == '*')
        return true;
    return false;
}
