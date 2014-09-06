//
//  Knight.cpp
//  2014-07-zad6
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include "Knight.h"

Knight::Knight(const ChessPosition &p) : ChessPiece::ChessPiece(p)
{}

list<ChessPosition> Knight::AllowedMoves()
{
    list<ChessPosition> l;
    
    int x = ((int) this->getPosition().x) - 64;
    int y = this->getPosition().y;
    
    // Up Left
    if (x - 1 >= 1 && y - 2 >= 1)
    {
        ChessPosition p = ChessPosition((char) x - 1 + 64, y-2);
        l.push_back(p);
    }
    if (x - 2 >= 1 && y - 1 >= 1)
    {
        ChessPosition p = ChessPosition((char) x - 2 + 64, y-1);
        l.push_back(p);
    }
    
    // Up Right
    if (x + 1 <= 8 && y - 2 >= 1)
    {
        ChessPosition p = ChessPosition((char) x + 1 + 64, y-2);
        l.push_back(p);
    }
    if (x + 2 <= 8 && y - 1 >= 1)
    {
        ChessPosition p = ChessPosition((char) x + 2 + 64, y-1);
        l.push_back(p);
    }
    
    // Bottom Left
    if (x - 1 >= 1 && y + 2 <= 8)
    {
        ChessPosition p = ChessPosition((char) x - 1 + 64, y+2);
        l.push_back(p);
    }
    if (x - 2 >= 1 && y + 1 <= 8)
    {
        ChessPosition p = ChessPosition((char) x - 2 + 64, y+1);
        l.push_back(p);
    }
    
    // Bottom Right
    if (x + 1 >= 1 && y + 2 <= 8)
    {
        ChessPosition p = ChessPosition((char) x + 1 + 64, y+2);
        l.push_back(p);
    }
    if (x + 2 >= 1 && y + 1 <= 8)
    {
        ChessPosition p = ChessPosition((char) x + 2 + 64, y+1);
        l.push_back(p);
    }
    
    return l;
}