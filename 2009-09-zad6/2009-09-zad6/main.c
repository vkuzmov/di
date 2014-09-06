//
//  main.c
//  2009-09-zad6
//
//  Created by Vladimir Kuzmov on 9/6/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, pid, flag = 2, status;
    pid = fork();
    
    if ( pid )
    {
        --flag;
        wait(&status);
    }
    else
        for (i=1; i <= 2; i++ )
            ++flag;
    
    ++flag;
    
    if (flag==3)
        exit(--i);
    
    printf ( "flag = %d\n",flag);
    
    return 0;
}

