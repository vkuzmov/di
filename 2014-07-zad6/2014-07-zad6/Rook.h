//
//  Rook.h
//  2014-07-zad6
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#ifndef ___014_07_zad6__Rook__
#define ___014_07_zad6__Rook__

#include <iostream>
#include "ChessPiece.h"

class Rook : public virtual ChessPiece {
public:
    Rook():ChessPiece() {};
    Rook(const ChessPosition &);
    
    list<ChessPosition> AllowedMoves();
};

#endif /* defined(___014_07_zad6__Rook__) */
