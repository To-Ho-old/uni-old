// ***************************************************************************
// CPSC2620 Fall 2017 Prof: Hossain
// Assignment 4
// Implementation file for SymmetricMatrix class
// Written by Arie Bomhof
// Date: Dec. 2017
// ***************************************************************************

#include<iostream>
#include<cstdlib>
#include"structuredMatrix.h"
using namespace std;


// ***************************************************************************
// Default constructor
// Parameter Usage:
//    input - d - dimension of matrix
//    input - t - type of triangular Matrix
// Post-Condition: current object is created with a dimension, d.
//                 memory size required, and array of size memSize
// ***************************************************************************
StructuredMatrix::StructuredMatrix(int d,int value)
{
   dim = 0;
   if(d > 0)
   {
      dim = d;
      memSize = dim*(dim+1)/2;
      element = new int[memSize+1];
      element[memSize] = 0;
      for(int i=0; i<memSize; i++)
	 element[i] = value;
   }
   else
      element = nullptr;
}


// ***************************************************************************
// destructor
// Parameter Usage: non
// Pre-Condition: current object exists
// Post-Condition: allocated heap memory is deleted.
// ***************************************************************************
StructuredMatrix::~StructuredMatrix()
{
   delete [] element;
   element = nullptr;
}

// ***************************************************************************
// matrix fill operation from keyboard
// Parameter Usage:
//    input - none
// Pre-Condition: values for the zeroed elements of the triangular Matrix are
//                not supplied
// Post-Condition: the current object's element array is filled with the
//                 non-zeroed elements of the matrix.
// ***************************************************************************
void StructuredMatrix::read()
{
   int size;
   cout << "What is the size of this Matrix? ";
   cin >> size;
   if(size != dim)
   {
      dim = size;
      memSize = dim*(dim+1)/2;
      delete [] element;
      element = new int[memSize+1];
      element[memSize] = 0;
   }
   cout << "Enter the " << memSize << " elements of this matrix: ";
   for(int i=0; i<memSize; i++)
      cin >> element[i];
}
      
// ***************************************************************************
// matrix fill operation from file
// Parameter Usage:
//    input - ins - stream from which to receive input
// Pre-Condition: values for the zeroed elements of the triangular Matrix are
//                not supplied
// Post-Condition: the current object's element array is filled with the
//                 non-zeroed elements of the matrix.
// ***************************************************************************
void StructuredMatrix::read(istream& ins)
{
   int size;
   ins >> size;
   if(size != dim)
   {
      dim = size;
      memSize = dim*(dim+1)/2;
      delete [] element;
      element = new int[memSize+1];
      element[memSize]=0;
   }
   for(int i=0; i<memSize; i++)
      ins >> element[i];
}
   
// return the largest row sum
int StructuredMatrix::infnorm() const
{
   int maxSum=0,rowSum=0;
   for(int i = 0; i<dim; i++)
   {
      rowSum=0;
      for(int j=0; j<dim; j++)
	 rowSum += abs((*this)(i,j));
      if(rowSum > maxSum)
	 maxSum = rowSum;
   }
   return maxSum;
}
