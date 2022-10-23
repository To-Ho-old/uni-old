//  Flexarray  class  IMPLEMENTATION
//
//  see flexarray.h for complete documentation of functions
//
// *******************************************************************


#include <cstdlib>
#include <cassert>
#include <iostream>
#include "flexarray.h"
using namespace std;
flexarray::flexarray(int size, const int &fillValue,  int lb)
// precondition: size >= 0
// postcondition: flexarray has a capacity of size items, all of which are set
//                by assignment to fillValue 
    : mySize(size),
      myList(new int[size]),
      lower(lb)
{
    int k;
    for(k = 0; k < size; k++)
    {
        myList[k] = fillValue;
    }
}
flexarray::flexarray(const flexarray & fla)
// postcondition: flexarray object is a copy of fla
    : mySize(fla.length()),
      myList(new int[mySize]),
      lower(fla.lbound())
{
    int k;
        // copy elements
    for(k = 0; k < mySize; k++){
        myList[k] = fla.myList[k];
    }
}
flexarray::~flexarray ()
// postcondition: flexarray object is destroyed
{
    delete [] myList;
}

const flexarray &
flexarray::operator= (const flexarray &rhs)
// postcondition: normal assignment via copying has been performed;
//                if flexarray object and rhs were different sizes, flexarray object
//                has been resized to  match the size of rhs
{
    if (this != &rhs)                           // don't assign to self!
    {
        delete [] myList;                       // get rid of old storage
        mySize = rhs.length();
        lower  = rhs.lbound();
        myList = new int [mySize];         // allocate new storage

            // copy rhs
        int k;
        for(k=0; k < mySize; k++)
        {
            myList[k] = rhs.myList[k];
        }
    }
    return *this;                               // permit a = b = c = d
}
int flexarray::length() const
// postcondition: returns flexarray's size (number of memory cells
//                allocated for flexarray object)
{
    return mySize;
}

int flexarray::lbound() const
// postcondition: returns flexarray's lower index bound 
{
    return lower;
}

int flexarray::ubound() const
// postcondition: returns flexarray's upper index bound
{
   return (lower+mySize-1);
}

int & flexarray::operator [] (int k)
// description: range-checked indexing, returning kth item
// precondition:  lower <= k < length() + lower
// postcondition: returns the kth item
{

    if (k < lower || k >= (mySize + lower))
    {
        cerr << "Illegal flexarray index: " << k << endl;
        cerr << "The array has " << mySize << " elements"  <<endl;
        cerr << "And the lowest valid inddex is " << lower << endl;
        cerr << "Exiting ..." << endl;
        exit(1);
    }
    return myList[k-lower];
}

const int& flexarray::operator [] (int k) const
// safe indexing, returning const reference to avoid modification
// precondition: 0 <= index < length
// postcondition: return index-th item
// exception: exits if index is out-of-bounds
{
    if (k < lower || k >= (mySize + lower))
    {
        cerr << "Illegal flexarray index: " << k << endl;
        cerr << "The array has " << mySize << " elements"  <<endl;
        cerr << "And the lowest valid inddex is " << lower << endl;
        cerr << "Exiting ..." << endl;
        exit(1);
    }
    return myList[k-lower];
}

void flexarray::resize(int newSize)
// description:  resizes the flexarray object to newSize elements
// precondition: the current size of flexarray is length(); newSize >= 0
// postcondition: the current size of flexarray is newSize; for each k
//                such that 0 <= k <= min(length, newSize), flexarray[k]
//                is a copy of the original; other elements of flexarray are
//                initialized using the 0-argument int constructor
//                Note: if newSize < length, elements may be lost
{
    int k;
    int numToCopy = newSize < mySize ? newSize : mySize;

         // allocate new storage and copy element into new storage

    int * newList = new int[newSize];
    for(k=0; k < numToCopy; k++)
    {
        newList[k] = myList[k];
    }
    for(k=numToCopy; k < newSize; k++)
    {
        newList[k] = 0;
    }

    delete [] myList;                      // de-allocate old storage
    mySize = newSize;                      // assign new storage/size
    myList = newList;
}


