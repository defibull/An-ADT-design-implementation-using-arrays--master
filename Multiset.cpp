//
//  Multiset.cpp
//  CS32 Hw1
//
//  Created by Shashank Khanna  on 1/20/15.
//  Copyright (c) 2015 CS 32. All rights reserved.
//

#include "Multiset.h"
#include <iostream>
using namespace std;
bool Multiset::empty()const // check for not empty with insert function
{
    
    int temp_empty = 0;
    
    for (int i= 0; i < DEFAULT_MAX_ITEMS ; i++)
    {
        if (m_NameandNumbers[i].m_number == 0)
            temp_empty++;
    }
    
    if (temp_empty == DEFAULT_MAX_ITEMS)
        return true;
    return false;
}

int Multiset::size()const
{
    int size = 0;
    
    for (int i = 0; i < DEFAULT_MAX_ITEMS ; i++)
    {
        size += m_NameandNumbers[i].m_number;
    }
    return size;
}

int Multiset::uniqueSize() const
{
    int unique_size = 0;
    
    for (int i = 0; i <DEFAULT_MAX_ITEMS; i++)
    {
        if (m_NameandNumbers[i].m_number != 0)
            unique_size++;
    }
    
    return unique_size;
}




bool Multiset::insert(const ItemType& value)
{
    /*checks to see if the value exists already - if it does then only increments the counter
     goes over all the items to see which one is 0
     inserts the value there and increments the counter to 1 */
    
    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        if (m_NameandNumbers[i].m_value == value)
        {  m_NameandNumbers[i].m_number++;
            return true;} // does this go through all of the elements to check if value exists first?
    }
    
    for (int j = 0 ; j< DEFAULT_MAX_ITEMS ; j++)
    {  if (m_NameandNumbers[j].m_number == 0)
    {   m_NameandNumbers[j].m_value = value;
        m_NameandNumbers[j].m_number++;
        return true;
    }
        
    }
    
    return false ;
}


int Multiset::erase(const ItemType& value)
{
    for (int i = 0 ; i < DEFAULT_MAX_ITEMS; i++)
    {
        if (m_NameandNumbers[i].m_value == value && m_NameandNumbers[i].m_number > 0)
        {
            m_NameandNumbers[i].m_number--;
            return 1;
        }
    }
    return 0;
}


int Multiset::eraseAll(const ItemType& value)
{
    int numErased;
    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        if (m_NameandNumbers[i].m_value == value)
        {
            numErased = m_NameandNumbers[i].m_number;
            m_NameandNumbers[i].m_number = 0;
            return numErased;
        }
    }
    return 0 ;
}

bool Multiset::contains(const ItemType& value) const
{
    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        if (m_NameandNumbers[i].m_value == value && m_NameandNumbers[i].m_number != 0)
            return true;
        
    }
    
    return false;
}


int Multiset::count(const ItemType& value) const
{
    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        if (m_NameandNumbers[i].m_value == value)
            return m_NameandNumbers[i].m_number;
    }
    return 0;
}


int Multiset::get(int i, ItemType& value)const
{
    int unique_Size =this->uniqueSize();
    int l = 0;
    if (i < 0 || i>= unique_Size)
        return 0;
    else
    {
        NameandNumber localArray [DEFAULT_MAX_ITEMS];
        for (int j = 0 ; j < DEFAULT_MAX_ITEMS ; j++)
        {
            if (m_NameandNumbers[j].m_number != 0)
            {
                {localArray[l].m_value = m_NameandNumbers[j].m_value;
                    localArray[l].m_number = m_NameandNumbers[j].m_number;
                    l++;
                }
            }
        }
        
        value = localArray[i].m_value;
        return localArray[i].m_number;
    }
    
}



void Multiset::swap(Multiset& other)
{
    if (this != &other)
    { Multiset temp;
        temp = other;
        other = *this;
        *this = temp;
    }
    
}



void Multiset::dump() const
{
    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        cerr << "Name is " << m_NameandNumbers[i].m_value << " the number is "<<  m_NameandNumbers[i].m_number << endl;
    }
    
}// prints the contents of a multi-set- must only write to cerr !
