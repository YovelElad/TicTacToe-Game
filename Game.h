// Name: Yovel Elad
// ID: 313412355
// Name: Amir Avidan
// ID: 205660178

#pragma once
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Move
{
public:
    Move(int i, int j) : _i(i), _j(j){}
    int GetRow()const {     return _i;      }
    int GetCol()const {     return _j;      }
    void setRow(int i) {    _i = i;         }
    void setCol(int j) {    _j = j;         }


private:
    int _i,_j;
};





class Game
{
public:
    virtual void getPlayerMove()  = 0;
    virtual void getComputerMove() = 0;
    virtual char gameStatus() = 0;
};