// ***************************************************************************
// CPSC2620 - Fall 2017
// Assignment 4
// Implementation file for TriangularMatrix class
// Written by Arie Bomhof
// Date: Dec. 2017
// An example of an upper triangular 3x3 matrix:
//         | 3  4  5 |
//         | 0  2  6 |
//         | 0  0  9 |
// ***************************************************************************

#ifndef UPPERMATRIX_H
#define UPPERMATRIX_H

#include<iostream>
#include"triangularMatrix.h"
using namespace std;

class UpperMatrix : public TriangularMatrix
{
  public:
   UpperMatrix(int = 0, int =0); 
   virtual int& operator()(int, int);
   virtual const int& operator()(int, int) const;
   virtual void print(ostream&) const;
};
#endif

   
     
