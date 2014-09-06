//
//  main.c
//  2010-09-zad2
//
//  Created by Vladimir Kuzmov on 9/5/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
    int fdr, fdw, n_byt, i=0, status;
    char buff[40], c;
    
    if (fork())
    {
        wait(&status);
        if (open("file_new", 0) != -1)
            execlp("grep", "grep", "$", "file_new", (char *) 0);
    }
    else
    {
        if ((fdr = open("fileB.txt", 0)) == -1)
        {
            printf("\n Cannot open \n"); exit(1);
        }
        
        if ((fdw = creat("file_new", 0666)) == -1)
        {
            printf("\n Cannot creat \n"); exit(1);
        }
        
        n_byt = read(fdr, buff, 40);
        c = buff[i++];
        if (c <= '1' || c >= '9')
        {
            while (buff[i++] != '\n' && i < n_byt)
                write(fdw, "$", 1);
            write(fdw, "\n", 1);
            write(1, "\n", 1);
        }
        else
        {
            write(1, buff, n_byt);
            write(1, "\n", 1);
        }
        
        write(fdw, "$", 1);
        
        close(fdw);
        close(fdr);
    }
    
    return 0;
}

