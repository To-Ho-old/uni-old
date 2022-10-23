// ***************************************************************************
// CPSC2620 Fall 2017
// Assignment 4
// Implementation file for Lower Matrix class
// Written by Arie Bomhof
// Date: Dec. 2017
// An example of an lower triangular 3x3 matrix:
//         | 3  0  0 |
//         | 9  2  0 |
//         | 5  4  9 |
// ***************************************************************************

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include"lowerMatrix.h"
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
LowerMatrix::LowerMatrix(int d, int t) : TriangularMatrix(d,t) {}

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
int& LowerMatrix::operator()(int r, int c)
{
   if(r < c)
      return element[memSize];
   return element[r*(r+1)/2 + c];
}

// constant overloaded index operator
const int& LowerMatrix::operator()(int r, int c) const
{
   if(r < c)
      return element[memSize];
   return element[r*(r+1)/2 + c];
}

// ***************************************************************************
// matrix print operation
// Parameter Usage:
//    input - outs - the stream to which current object is to be displayed
// Post-Condition: the current object is printed to the supplied ostream.
//                 Zeroed elements of the triangular matrix will be printed
// ***************************************************************************
void LowerMatrix::print(ostream& outs) const
{
   cout << "Lower Matrix" << endl;
   for(int i=0; i<dim; i++)
   {
      for(int j=0; j<dim; j++)
	 outs << setw(7)<< (*this)(i,j);
      cout << endl;
   }
}

