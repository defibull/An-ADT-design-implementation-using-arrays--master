#include <iostream>
#include <cassert>
#include "newMultiset.h"
using namespace std;
int main()
{
    Multiset abba(1000);   // a can hold at most 1000 distinct items
    Multiset b(5);      // b can hold at most 5 distinct items
    Multiset c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
    ItemType v[6] = { 12312,124135,1325123,1231254,123,4132 };
    // No failures inserting 5 distinct items twice each into b
    for (int k = 0; k < 5; k++)
    {
        assert(b.insert(v[k]));
        assert(b.insert(v[k]));
    }
    assert(b.size() == 10  &&  b.uniqueSize() == 5  &&  b.count(v[0]) == 2);
    // Failure if we try to insert a sixth distinct item into b
    assert(!b.insert(v[5]));
    
    // When two Multisets' contents are swapped, their capacities are swapped
    // as well:
    abba.swap(b);
    assert(!abba.insert(v[5])  &&  b.insert(v[5]));
    cerr << "all tests passed" << endl;
    
    Multiset a(30) ;
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
    
    
     a.dump();
    cerr << a.empty();
    cerr << "unique size " << a.uniqueSize() << endl;
    cerr << "False is " << false << endl;
    cerr << "Size is " << a.size()<< endl;
    cerr << "Count for non existant stuff is " << a.count(30) << endl;
    cerr << "count for existing" << a.count(3) << endl;
    cerr << "Does 30 exist ? " << a.contains(30) << endl;
    unsigned long temp;
    cerr << " Getting 283 " << a.get(3,temp) << endl;
    cerr << " Getting 283 " << a.get(3,temp) << endl;
    cerr << "Erase all 283 - 25 must be erased " << a.eraseAll(283) << endl;
    a.insert(30);
    a.insert (30);
    for (int i = 25 ; i < 30 ; i++)
    {
        a.eraseAll(i);
    }
    
    
    Multiset ms(3);
    assert(ms.empty());
    unsigned long x = 999;
    assert(ms.get(0, x) == 0  &&  x == 999);  // x unchanged by get failure
    assert( ! ms.contains(42));
    ms.insert(42);
    ms.insert(42);
    assert(ms.size() == 2  &&  ms.uniqueSize() == 1);
    assert(ms.get(1, x) == 0  &&  x == 999);  // x unchanged by get failure
    assert(ms.get(0, x) == 2  &&  x == 42);
    cerr << "Passed all tests" << endl;
    
    
       unsigned long temp2;
     cerr << "Getting at position last, no. of instances is " << a.get(a.uniqueSize()-1,temp2) << " Temp is " << temp2 << endl;
    
    a.dump();
    
    cerr << "Unique size after " << a.uniqueSize() << endl ;
    
    a.swap(ms);
    
   cerr << "A is as follows " << endl;
   a.dump();
   cerr << "MS is as follows" << endl;
    ms.dump();
    cerr << "Passed all tests" << endl;
    ms = a;
    cerr << "MS after getting a again "<< endl;
    ms.dump();
    cerr << "A - should still be the same" << endl;
    a.dump();
    cerr << "Does a contain 42 " << a.contains(42) <<endl;
    cerr << ms.uniqueSize();
   cerr << ms.size();
   /*
    Multiset a (2);
    a.insert("Sup");
    a.insert("Dawg");
    a.insert("Sup");
    a.dump();*/


}
