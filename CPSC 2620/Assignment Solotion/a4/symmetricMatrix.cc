// ***************************************************************************
// CPSC2620 Prof: Hossain Fall 2014
// Assignment 4
// Implementation file for SymmetricMatrix class
// Written by Arie Bomhof
// Date: Dec. 2017
// An example of an symmetric 3x3 matrix:
//         | 3  4  5 |
//         | 4  2  6 |
//         | 5  6  9 |
// ***************************************************************************

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include"symmetricMatrix.h"
#include"structuredMatrix.h"
using namespace std;

//***************************************************************************
// Constructor
//***************************************************************************
SymmetricMatrix::SymmetricMatrix(int d, int v) : StructuredMatrix(d,v) {}

// ***************************************************************************
// overloaded indexed access
// Parameter Usage:
//    input - r - row item #
//    input - c - column item #
// Pre-Condition: r and c are valid row,column numbers for current object
// Post-Condition: a reference to the current object array item is returned
//                 A mapping of element[r,j] =  element[r*(r+1)/2 + c]
// ***************************************************************************
int& SymmetricMatrix::operator()(int r, int c)
{
   int temp;
   if(r < c)
   {
      temp = r;
      r = c;
      c = temp;
   }
   return element[r*(r+1)/2 + c];
}

// constant overloaded index operator
const int& SymmetricMatrix::operator()(int r, int c) const
{
   int temp;
   if(r < c)
   {
      temp = r;
      r = c;
      c = temp;
   }
   return element[r*(r+1)/2 + c];
}

// ***************************************************************************
// matrix print operation
// Parameter Usage:
//    input - outs - the stream to which current object is to be displayed
// Post-Condition: the current object is printed to the supplied ostream.
//                 Zeroed elements of the triangular matrix will be printed
// ***************************************************************************
void SymmetricMatrix::print(ostream& outs) const
{
   cout << "Symmetric Matrix" << endl;
   for(int i=0; i<dim; i++)
   {
      for(int j=0; j<dim; j++)
	 outs << setw(5)<< (*this)(i,j);
      cout << endl;
   }
}

   

