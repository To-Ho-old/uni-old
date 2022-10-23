// ***************************************************************************
// CPSC2620 - Fall 2017 Prof: Hossain
// Assignment 2
// Implementation file for LowerMatrix class
// Written by Arie Bomhof
// Date: Dec. 2017
// An example of a lower triangular 3x3 matrix:
//         | 3  0  0 |
//         | 4  5  0 |
//         | 6  7  8 |
// ***************************************************************************

#ifndef LOWERMATRIX_H
#define LOWERMATRIX_H

#include<iostream>
#include"triangularMatrix.h"
using namespace std;

class LowerMatrix : public TriangularMatrix
{
  public:
   LowerMatrix(int = 0, int =0); 
   virtual int& operator()(int, int);
   virtual const int& operator()(int, int) const;
   virtual void print(ostream&) const;
};

#endif

   
     
