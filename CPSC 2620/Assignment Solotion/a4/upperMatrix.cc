// ***************************************************************************
// CPSC2620 Fall 2017 Prof: Hossain
// Assignment 4
// Implementation file for UpperMatrix class
// Written by Arie Bomhof
// Date: Dec. 2017
// ***************************************************************************

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include"upperMatrix.h"
#include"triangularMatrix.h"
using namespace std;


// ***************************************************************************
// Default constructor
// Parameter Usage:
//    input - d - dimension of matrix
//    input - t - type of triangular Matrix
// Post-Condition: current object is created with a dimension, matrix Type,
//                 memory size required, and array of size memSize
// ***************************************************************************
UpperMatrix::UpperMatrix(int d, int t) : TriangularMatrix(d,t) {}

// ***************************************************************************
// overloaded indexed access
// Parameter Usage:
//    input - r - row item #
//    input - c - column item #
// Pre-Condition: r and c are valid row,column numbers for current object
// Post-Condition: a reference to the current object array item is returned
//                 A mapping of element[r,j] = element[r*dim-r*(r-1)/2+c-r]
//                 is used if mType = 'U', element[r*(r+1)/2 + c] if mType = 'L'
// ***************************************************************************
int& UpperMatrix::operator()(int r, int c)
{
   if(r>c)
      return element[memSize]; // we know this is 0 and we need to return
                                  // a reference to a location.
   return element[r*dim - r*(r-1)/2 + (c - r)];
}

// constant overloaded index operator
const int& UpperMatrix::operator()(int r, int c) const
{
   if(r>c)
      return element[memSize]; // we know this is 0 and we need to return
                                  // a reference to a location.
   return element[r*dim - r*(r-1)/2 + (c - r)];
}

// ***************************************************************************
// matrix print operation
// Parameter Usage:
//    input - outs - the stream to which current object is to be displayed
// Post-Condition: the current object is printed to the supplied ostream.
//                 Zeroed elements of the triangular matrix will be printed
// ***************************************************************************
void UpperMatrix::print(ostream& outs) const
{
   cout << "Upper Matrix" << endl;
   for(int i=0; i<dim; i++)
   {
      for(int j=0; j<dim; j++)
	 outs << setw(7)<< (*this)(i,j);
      cout << endl;
   }
}

