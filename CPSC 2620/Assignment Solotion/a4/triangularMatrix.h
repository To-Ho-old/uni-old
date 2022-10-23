// ***************************************************************************
// CPSC2620 - Fall 2017 Prof: Hossain
// Assignment 4
// Implementation file for TriangularMatrix class
// Written by Arie Bomhof
// Date: Dec. 4, 2017
// ***************************************************************************

#ifndef TRIANGULARMATRIX_H
#define TRIANGULARMATRIX_H

#include<iostream>
#include"structuredMatrix.h"
using namespace std;

class TriangularMatrix : public StructuredMatrix
{
  public:
   TriangularMatrix(int = 0, int = 0); 
   virtual const int& operator()(int, int) const = 0;  // makes this ABC
   virtual int& operator()(int, int) = 0;  // makes this ABC
   virtual void print(ostream&) const = 0;
};
#endif
