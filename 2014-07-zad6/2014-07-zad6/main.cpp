//
//  main.cpp
//  2014-07-zad6
//
//  Created by Vladimir Kuzmov on 9/1/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include "ChessPiece.h"
#include "Rook.h"
#include "Knight.h"

using namespace std;

int main(int argc, const char * argv[])
{
    Rook r = Rook(ChessPosition('D', 4));
    if (r.captures(ChessPosition('A', 4)))
    {
        cout << "DA" << endl;
    }
    else
    {
        cout << "NE" << endl;
    }
    
    Knight k = Knight(ChessPosition('D', 4));
    if (k.captures(ChessPosition('F', 5)))
    {
        cout << "DA" << endl;
    }
    else
    {
        cout << "NE" << endl;
    }
    
    return 0;
}

