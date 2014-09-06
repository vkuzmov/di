//
//  Rook.cpp
//  2014-07-zad6
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include "Rook.h"

Rook::Rook(const ChessPosition &p) : ChessPiece::ChessPiece(p)
{}

list<ChessPosition> Rook::AllowedMoves()
{
    list<ChessPosition> l;
    
    int x = ((int) this->getPosition().x) - 64;
    int y = this->getPosition().y;
    
    // Horizontal moves
    for (int i=x+1; i<=8; i++)
    {
        ChessPosition cp = ChessPosition((char) i+64, y);
        l.push_back(cp);
    }
    
    if (x > 1)
    {
        for (int i=x-1; i>0; i--)
        {
            ChessPosition cp = ChessPosition((char) i+64, y);
            l.push_back(cp);
        }
    }
    
    // Vertical moves
    for (int i=y+1; i<=8; i++)
    {
        ChessPosition cp = ChessPosition((char) x+64, i);
        l.push_back(cp);
    }
    
    if (y > 1)
    {
        for (int i=y-1; i>0; i--)
        {
            ChessPosition cp = ChessPosition((char) x+64, i);
            l.push_back(cp);
        }
    }
    
    return l;
}
