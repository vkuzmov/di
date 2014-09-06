//
//  main.cpp
//  2010-07-zad3
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsEmpty(const string str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] != '\0')
			return false;
	}
    
	return true;
}

int main(int argc, const char * argv[])
{
    string str = "";
	string tmp = "";
	vector<string> words;
    
    int tempMax, result = 0
    ;
    
    words.push_back("string");
    words.push_back("ginrts");
    words.push_back("ringst");
    words.push_back("spong");
    words.push_back("shpong");
    words.push_back("pongs");
    
	// Check each character with each other
    for (size_t i = 0; i < words.size(); i++)
	{
        str = words[i];
        tempMax = 1;

        for (size_t j = 0; j < words.size(); j++)
        {
            if (i == j) continue;
            
            tmp = words[j];
            
            for (size_t k = 0; k < str.size(); k++)
            {
                for (size_t l = 0; l < tmp.size(); l++)
                {
                    if (str[k] == tmp[l])
                    {
                        tmp[l] = '\0';
                        break;
                    }
                }
            }
            
            if (IsEmpty(tmp))
            {
                tempMax++;
//                cout << words[j] << '\n';
            }
        }
        result = max(result, tempMax);
//        cout << endl;
    }
    
    cout << "Result: " << result << endl;

	return 0;
}

