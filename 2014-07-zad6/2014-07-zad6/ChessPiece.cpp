//
//  ChessPiece.cpp
//  2014-07-zad6
//
//  Created by Vladimir Kuzmov on 9/1/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include "ChessPiece.h"

ChessPiece::ChessPiece(const ChessPosition &p)
{
    this->pos = ChessPosition(p.x, p.y);
}

ChessPosition ChessPiece::getPosition()
{
    return this->pos;
}

bool ChessPiece::captures(const ChessPosition &p)
{
    list<ChessPosition> moves = this->AllowedMoves();
    
    for (list<ChessPosition>::const_iterator iterator = moves.begin(), end = moves.end(); iterator != end; ++iterator)
    {
        if ((*iterator).x == p.x && (*iterator).y == p.y)
        {
            return true;
        }
    }
    return false;
}