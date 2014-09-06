//
//  ChessPiece.h
//  2014-07-zad6
//
//  Created by Vladimir Kuzmov on 9/1/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#ifndef ___014_07_zad6__ChessPiece__
#define ___014_07_zad6__ChessPiece__

#include <iostream>
#include <list>

using namespace std;

struct ChessPosition {
    char x;
    int y;
    ChessPosition () {};
    ChessPosition(char _x, int _y)
    {
        this->x = _x;
        this->y = _y;
    }
    
    void Print() const
    {
        cout << this->x << "-" << this->y << endl;
    }
};

class ChessPiece {

public:
    ChessPiece () {};
    ChessPiece(const ChessPosition &);

    ChessPosition getPosition();

    virtual list<ChessPosition> AllowedMoves() = 0;

    bool captures(const ChessPosition &);

private:
    ChessPosition pos;
};

#endif /* defined(___014_07_zad6__ChessPiece__) */
