//
//  main.cpp
//  test-cpp
//
//  Created by Vladimir Kuzmov on 7/14/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
using namespace std;

class A {
private:
    int n;
    double d;
public:
    A(int a = 0): n(a), d(a)
    {
        d = 1.5; dump();
    }
    
    A (const A &p)
    {
        cout << "copy constructor A" << endl;
        n = p.n + 1;
        d = p.d + 1.5;
        dump();
    }
    
    A & operator= (const A &p)
    {
        if (this != &p)
        {
            n = p.n;
            d = p.d;
            dump();
        }
        return * this;
    }
    
    void dump()
    {
        cout << "A(n): " << n << ", A(d): " << d << endl;
    }

    int getad()
    {
        return d;
    }
};

class B {
private:
    int n; double d;
public:
    B(double b = 2.5)
    {
        n = 2;
        d = b;
        dump();
    }
    
    B(const B &p)
    {
        cout << "copy constructor B" << endl;
        n = p.n;
        d = p.d;
        dump();
    }
    B & operator=(const B &p)
    {
        if (this != &p)
        {
            n = p.n + 2;
            d = p.d + 2.5;
            dump();
        }
        return * this;
    }
    void dump()
    {
        cout << "B(n): " << n << ", B(d): " << d << endl;
    }
    
    int getbd()
    {
        return d;
    }
};

class C: protected B, A {
private:
    int n,m;
public:
    C (int x = 3, int y = 2, int z = 1): A(x), B(y)
    {
        n = z;
        m = x + y;
        dump();
    }
    
    C & operator= (const C &p)
    {
        if (this != &p)
        {
            A::operator=(p);
            B::operator=(p);
            n = p.n;
            m = p.m;
            dump();
        }
        return * this;
    }
    
    void dump()
    {
        cout << "C(n): " << n << ", C(m): " << m << endl;
    }
};

int main(int argc, const char * argv[])
{
    cout << "A b(3)" << endl;
    A b(3); cout << endl;
    
    cout << "C c1" << endl;
    C c1; cout << endl;
    
    cout << "C c2(1,2,3)" << endl;
    C c2(1,2,3); cout << endl;
    
    cout << "C c3(4,5)" << endl;
    C c3(4,5); cout << endl;
    
    cout << "C c4(c1)" << endl;
    C c4(c1); cout << endl;
    
    cout << "c4 = c2" << endl;
    c4 = c2; cout << endl;
    
    return 0;
}

