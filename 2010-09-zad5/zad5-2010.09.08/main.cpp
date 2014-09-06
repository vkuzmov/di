//
//  main.cpp
//  zad5-2010.09.08
//
//  Created by Vladimir Kuzmov on 7/4/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Base
{
    char * name;

//protected:
public:
    Base(char * nn = "Base")
    {
        if (nn != NULL)
        {
            name = new char[16];
            strncpy(name, nn, 16);
        }
    }
    
public:
    virtual void f1()
    {
        cout << name << ": f1 " << endl;
    }
    
    virtual ~Base()
    {
        delete [] name;
    }
//private:
public:
    virtual void f2()
    {
        cout << name << ": f2" << endl;
    }
public:
    virtual void f3()
    {
        cout << name << ": f3" << endl;
    }
};

class Der : public Base
{
    char * name;
    
public:
    Der(char * nn = "Der") : Base("Der.Base")
    {
        if (nn != NULL)
        {
            name = new char[16];
            strncpy(name, nn, 16);
        }
    }
    
    ~Der()
    {
        cout << name << ": destr" << endl;
        delete [] name;
    }
    
//protected:
public:
    void f1()
    {
        cout << name << ": f1" << endl;
    }
    
public:
    void f2()
    {
        cout << name << ": f2" << endl;
    }
    
//private:
public:
    void f3()
    {
        cout << name << ": f3" << endl;
    }
};


int main(int argc, const char * argv[])
{
    Base * p = new Der("Dyn");
    Der d("Stat");
    Base b;
    Base * q = &d;
    
    b.f1();
    p->f1();
    d.f1();
    q->f1();
    
    cout << endl;
    
    b.f2();
    p->f2();
    d.f2();
    q->f2();
    
    cout << endl;
    
    b.f3();
    p->f3();
    d.f3();
    q->f3();
    
    cout << endl;
    
    delete p;

    return 0;
}









