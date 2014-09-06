//
//  main.cpp
//  2014-07-zad5
//
//  Created by Vladimir Kuzmov on 9/1/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>

using namespace std;

const int N = 10;

int labyrinth[N][N] = {
    {1,0,0,0,0,0,0,0,0,0},
    {1,1,0,0,0,0,0,0,0,0},
    {0,1,0,1,1,1,1,1,1,1},
    {0,1,0,0,0,0,0,0,0,1},
    {0,1,0,1,1,1,1,1,1,1},
    {0,1,0,0,0,0,0,1,0,0},
    {0,1,0,1,1,1,0,1,0,0},
    {0,1,0,1,0,1,0,1,1,1},
    {0,1,1,1,0,1,0,0,0,0},
    {0,1,0,0,0,1,1,1,1,1}
};

bool walk(int lab[N][N], char * path) {
    int x = N-1, y = N-1;

    if ( ! labyrinth[x][y])
    {
//        cout << "terminate at start" << en dl;
        return false;
    }
    
    for (int i=(int) strlen(path)-1; i>=0; i--)
    {
        
        switch (path[i])
        {
            case 'E':
                y -= 1;
                break;
                
            case 'W':
                y += 1;
                break;
                
            case 'N':
                x += 1;
                break;
                
            case 'S':
                x -= 1;
                break;
        }

//        cout << "current(" << x << ", " << y << ")" << endl;
//        cout << path[i] << " " << lab[x][y] << endl;
        
        if ( ! labyrinth[x][y])
        {
//            cout << "terminate" << endl;
            return false;
        }
    }
    
    return true;
}

int main(int argc, const char * argv[])
{
    char path[] = "NEENNEESSSEEEE";
    
    if (walk(labyrinth, path)) {
        cout << "ima" << endl;
    }
    else {
        cout << "nqma" << endl;
    }
    
    return 0;
}

