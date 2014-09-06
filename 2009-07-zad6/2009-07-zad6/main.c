//
//  main.c
//  2009-07-zad6
//
//  Created by Vladimir Kuzmov on 9/6/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
    int fd, n_byt, i=0, status;
    char sline[40], c;
    
    if (fork())
    {
        wait(&status);
        execlp("echo", "echo", "End_of_program", (char *) 0);
    }
    else
    {
        if ((fd = open("fileA.txt", O_RDONLY)) == -1)
        {
            printf("\n Cannot open \n");
            exit(1);
        }
        
        n_byt = read(fd, sline, 20);
        c = sline[i++];
        
        if (c >= 'a' && c <= 'z')
        {
            while (sline[i++] != '\n' && i < n_byt)
                write(1, "$", 1);
            write(1, "\n", 1);
        }
        
        while (i < n_byt)
            write(1, &sline[i++], 1);
        
        close(fd);
        
        execlp("wc", "wc", "-l", "fileA.txt", (char *) 0);
    }
    
    return 0;
}

