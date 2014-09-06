//
//  main.cpp
//  zad-4-2014-07-15
//
//  Created by Vladimir Kuzmov on 9/1/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const char * str)
{
//    cout << "original: " << str << endl;
    
    char reversed[strlen(str)];
    int rev_counter = 0;
    
    for (int i=(int) strlen(str)-1; i>=0; i--) {
        reversed[rev_counter++] = str[i];
    }
    reversed[rev_counter++] = '\0';
    
//    cout << "reversed: " << reversed << endl;
    
    return strcmp(str, reversed) == 0;
}

int main(int argc, const char * argv[])
{
    char str[] = "orrobborrow";
    bool result = false;
    
    for (int iterator=0; iterator < (int) strlen(str); iterator++) {
        int temp_counter = 0;
        char * temp = new char[strlen(str)];
        
        for (int i=iterator; i < (int) strlen(str); i++) {
            temp[temp_counter++] = str[i];
        }
        
        for (int j = 0; j<iterator; j++) {
            temp[temp_counter++] = str[j];
        }

        temp[temp_counter++] = '\0';

//        cout << "temp: " << temp << endl;
        
        result = is_palindrome(temp);

        if (result) {
            cout << iterator << " (" << temp << ")";
            break;
        }
        
        delete temp;
    }
    
    if ( ! result) {
        cout << "NO" << endl;
    }

    return 0;
}

