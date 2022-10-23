// ***************************************************************************
// CPSC2620 - Fall 2017
// Assignment 4
// Implementation file for StructuredMatrix class
// Written by Arie Bomhof
// Date: Dec. 4, 2017
// ***************************************************************************

#ifndef STRUCTUREDMATRIX_H
#define STRUCTUREDMATRIX_H

#include<fstream>
using namespace std;

class StructuredMatrix
{
  public:

   // default constructor
   // default dim = 0
   // Usage: StructuredMatrix t;
   //        StructuredMatrix t(3);
   StructuredMatrix(int = 0, int = 0); 

   // destructor
   ~StructuredMatrix();

   // overloaded indexed access
   // allows for assignment of specific matrix element
   // allows for extraction of specific matrix element
   // Note: first parameter <= second parameter
   // Usage: t(1,2) = 3;
   // cout << t1(1,2);
   virtual const int& operator()(int, int) const = 0;  // makes this ABC
   virtual int& operator()(int, int) = 0;  // makes this ABC

   // matrix print operation
   // Usage example: t3.display(cout);
   virtual void print(ostream&) const = 0;

   // matrix read operations
   // Usage example: t3.read();
   // or t3.read(some input stream)
   //virtual int infnorm() const = 0;
   int infnorm() const;
   void read(istream&);
   void read();

  protected:
   int dim; // dimension
   int *element; // array
   int memSize; // amount of memory required for element
};
#endif

   
     
