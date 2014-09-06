//
//  Knight.h
//  2014-07-zad6
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#ifndef ___014_07_zad6__Knight__
#define ___014_07_zad6__Knight__

#include <iostream>
#include "ChessPiece.h"

class Knight : public virtual ChessPiece {
public:
    Knight():ChessPiece() {};
    Knight(const ChessPosition &);
    
    list<ChessPosition> AllowedMoves();
};

#endif /* defined(___014_07_zad6__Knight__) */
