//
//  main.cpp
//  WordSwitcher
//
//  Държавен изпит, 08.09.2010, зад 3
//
//  Created by Vladimir Kuzmov on 7/4/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctype.h>
#include <cstring>
#include <regex>
#include <list>

using namespace std;

char * reorder (char * str)
{
	char *buf = (char *)malloc(strlen(str) + 1);
	int i = 0;
	int j = strlen(str) - 1;
	int m = j;
    
	while (i < strlen(str))
	{
		int q = 0;
		int n = 0;
        
		while ( ! isalnum(str[i])) i++;
        
		n = i;
        
		while (isalnum(str[n])) n++;
        
		while ( ! isalnum(str[m]))
		{
			buf[j] = str[m];
			m--; j--;
		}
        
		while (isalnum(str[i]))
		{
			buf[j] = str[n-q-1];
			j--;
			i++;
			q++;
		}
        
		while (isalnum(str[m])) {m--;}
	}
    
	return buf;
}

int main(int argc, const char * argv[])
{
    char * word = "123;;2;3;4;;567890.";
//    char * word = "xcc.123.asd";
    
    cout << "input:\t" << word << endl;
    cout << "output:\t" << reorder(word) << endl;
    
    return 0;
}

