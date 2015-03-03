//
//  testStudentMultiset.cpp
//  CS32 Hw1
//
//  Created by Shashank Khanna  on 1/20/15.
//  Copyright (c) 2015 CS 32. All rights reserved.
//
#include <iostream>
#include <cassert>
#include "StudentMultiset.h"
using namespace std;

int main()
{
    unsigned long n;
    StudentMultiset a;
    while (n !=25)
    {
        cout << "Enter upto 200 ids, '25' to end"  << endl;
        cin >> n ;
        if (n!=25)
            a.add(n);
        
    }
    
    cout << "The size of a is "<<  a.size() << endl;
    cout << "Printing a " << endl ;
    a.print();
}
