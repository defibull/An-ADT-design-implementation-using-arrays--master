//
//  newMultiset.h
//  Test
//
//  Created by Shashank Khanna  on 1/20/15.
//  Copyright (c) 2015 CS 32. All rights reserved.
//

#ifndef NEW_MULTISET_INCLUDED
#define NEW_MULTISET_INCLUDED
#include <iostream>
typedef unsigned long ItemType;

const int DEFAULT_MAX_ITEMS = 200;
class Multiset
{
public:
    Multiset(int ArraySize = DEFAULT_MAX_ITEMS) ;   // Create an empty multiset.
    Multiset(const Multiset& other); // if some external function is using multiset by copying
    Multiset& operator=(const Multiset& rhs);
    ~Multiset();
    
    bool empty() const;  // Return true if the multiset is empty, otherwise false.
     int size() const ;
     // Return the number of items in the multiset.  For example, the size
     // of a multiset containing "cumin", "cumin", "cumin", "turmeric" is 4.
     
     int uniqueSize() const;
     // Return the number of distinct items in the multiset.  For example,
     // the uniqueSize of a multiset containing "cumin", "cumin", "cumin",
     // "turmeric" is 2.
     
     bool insert(const ItemType& value);
     // Insert value into the multiset.  Return true if the value was
     // actually inserted.  Return false if the value was not inserted
     // (perhaps because the multiset has a fixed capacity and is full).
     
     int erase(const ItemType& value);
     // Remove one instance of value from the multiset if present.
     // Return the number of instances removed, which will be 1 or 0.
     
     int eraseAll(const ItemType& value);
     // Remove all instances of value from the multiset if present.
     // Return the number of instances removed.
     
     bool contains(const ItemType& value) const;
     // Return true if the value is in the multiset, otherwise false.
     
     int count(const ItemType& value) const;
     // Return the number of instances of value in the multiset.
     
     int get(int i, ItemType& value)const;
     // If 0 <= i < uniqueSize(), copy into value an item in the
     // multiset and return the number of instances of that item in
     // the multiset.  Otherwise, leave value unchanged and return 0.
     // (See below for details about this function.)
     
     void swap(Multiset& other);
     // Exchange the contents of this multiset with the other one.
     
     void dump() const ; // prints the contents of a multi-set- must only write to cerr !
     
private:
    struct NameandNumber
    {
        ItemType m_value;
        int m_number;
        
    };
    
    NameandNumber* m_NameandNumbers; // Dynamic array of Name and Numbers
    int m_ArraySize;
};

#endif //NEW_MULTISET_INCLUDED
