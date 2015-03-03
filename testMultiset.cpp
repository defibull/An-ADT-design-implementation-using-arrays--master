//
//  testMultiset.cpp
//  CS32 Hw1
//
//  Created by Shashank Khanna  on 1/20/15.
//  Copyright (c) 2015 CS 32. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Multiset.h"
using namespace std;


int main ()
{
    
    
    Multiset a ;
    for (int i = 0; i < 250; i++)
    {
        a.insert(1+i);
    }
    a.erase(4);
    a.insert(283);
    a.insert(283);
    a.insert(238);
    
    for (int j =0; j < 23; j++)
        a.insert(283);
    a.erase(2);
    a.insert (3);
    a.insert (2);
    a.erase(30);
    
    
    // a.dump();
    cout << a.empty();
    cout << "unique size " << a.uniqueSize() << endl;
    cout << "False is " << false << endl;
    cout << "Size is " << a.size()<< endl;
    cout << "Count for non existant stuff is " << a.count(30) << endl;
    cout << "count for existing" << a.count(3) << endl;
    cout << "Does 30 exist ? " << a.contains(30) << endl;
    unsigned long temp;
    cout << " Getting 283 " << a.get(3,temp) << endl;
    cout << " Getting 283 " << a.get(3,temp) << endl;
    cout << "Erase all 283 - 25 must be erased " << a.eraseAll(283) << endl;
    a.insert(30);
    a.insert (30);
    for (int i = 25 ; i < 30 ; i++)
    {
        a.eraseAll(i);
    }
    
    
    Multiset ms;
    assert(ms.empty());
    unsigned long x = 999;
    assert(ms.get(0, x) == 0  &&  x == 999);  // x unchanged by get failure
    assert( ! ms.contains(42));
    ms.insert(42);
    ms.insert(42);
    assert(ms.size() == 2  &&  ms.uniqueSize() == 1);
    assert(ms.get(1, x) == 0  &&  x == 999);  // x unchanged by get failure
    assert(ms.get(0, x) == 2  &&  x == 42);
    cout << "Passed all tests" << endl;
    
    
    //   unsigned long temp2;
    //   cout << "Getting at position last, no. of instances is " << a.get(a.uniqueSize()-1,temp2) << " Temp is " << temp2 << endl;
    
    //a.dump();
    
    //cout << "Unique size after " << a.uniqueSize() << endl
    
    a.swap(ms);
    
    cout << "A is as follows " << endl;
    a.dump();
    cout << "MS is as follows" << endl;
    ms.dump();
    cout << "Passed all tests" << endl;
}
