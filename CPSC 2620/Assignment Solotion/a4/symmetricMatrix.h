// ***************************************************************************
// CPSC2620 - Fall 2017
// Assignment 4
// Implementation file for SymmetricMatrix class
// Written by Arie Bomhof
// Date: Dec. 2017
// An example of an symmetric 3x3 matrix:
//         | 1  2  3 |
//         | 2  4  5 |
//         | 3  5  6 |
// ***************************************************************************

#ifndef SYMMETRICMATRIX_H
#define SYMMETRICMATRIX_H
#include"structuredMatrix.h"
#include<iostream>
using namespace std;

class SymmetricMatrix : public StructuredMatrix
{
  public:
   SymmetricMatrix(int = 0, int = 0);
   int& operator()(int, int);
   const int& operator()(int, int) const;
   void print(ostream&) const;
};
#endif

   
     
