//
//  StudentMultiset.cpp
//  CS32 Hw1
//
//  Created by Shashank Khanna  on 1/20/15.
//  Copyright (c) 2015 CS 32. All rights reserved.
//

#include "StudentMultiset.h"
#include <iostream>
using namespace std;
StudentMultiset::StudentMultiset():m_students(){}

bool StudentMultiset::add(unsigned long id)
{
    bool a;
    a = m_students.insert(id);
    if (a)
        return true;
    
    return false;
}

int StudentMultiset::size() const
{
    return m_students.size();
}

void StudentMultiset::print() const
{
    for (int i = 0; i < DEFAULT_MAX_ITEMS ; i++)
    {
        ItemType temp;
        int times = m_students.get(i,temp);
        for (int j = 0; j<times; j++)
        {
            cout << temp << endl;
        }
        
    }
}
