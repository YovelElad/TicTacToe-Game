// Name: Yovel Elad
// ID: 313412355
// Name: Amir Avidan
// ID: 205660178

#pragma once
#include <iostream>
using namespace std;


class UI
{
public:
    virtual void display(Board*) = 0;
};



class Console : public UI
{
public:
    void display(Board*);
};



void Console::display(Board *_board)
{
    for(int i=0;i<_board->getRowSize(); i++)
    {
        for(int j=0; j<_board->getColSize(); j++)
        {
            cout << _board->getBoard()[i][j];
        }
        cout << endl;
    }
}