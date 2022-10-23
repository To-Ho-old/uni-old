//***************************************************************************
// CPSC2620 - Fall 2017
// Assignment 1 PtII
// File: ternary.h -- interface file for the Ternary class
// Prepared by: Arie
// Date: Oct. 18, 2017
//***************************************************************************

#ifndef TERNARY_H
#define TERNARY_H
#include<iostream>
using namespace std;

const int MAX_BITS = 32;
const int BASE3 = 3;
const int BASE10 = 10;

class Ternary
{
  public:
   
   // constructors               
   // default, set ternary number to 0
   // Example Declaration: Ternary t1, t1 will be set to 0
   Ternary();
   
   // 2nd constructor. Set ternary number to input parameter
   // If invlalid Ternary number is given and error message will be displayed
   // and a value of 0 will be assigned.
   // Example Declaration: Ternary t2(122), will set t2 to be 17 base 10
   //                      Ternary t3(81122) will give an eror message and
   //                      set to 0.
   Ternary(int);
      
   // accessor methods
   // Function to "insert" Ternary into ostream parameter (usually cout)
   void insert(ostream&) const;

   // Ffunction to "extract" or read in a new value for given Ternary.
   // Read from istream (usually cin)
   void extract(istream&);
   
   // Overloaded += function
   // Purpose to add right hand parameter to current object
   // Right hand object is not changed.
   Ternary& operator+=(const Ternary&);
   // Overloaded += function
   // Purpose to add right hand parameter to current object
   // Right hand object is not changed.
   Ternary& operator-=(const Ternary&);
   // Overloaded += function
   // Purpose to add right hand parameter to current object
   // Right hand object is not changed.
   Ternary& operator*=(const Ternary&); 

   // Overloaded unary - operator
   // Purpose is to return the negation of current object but not to negate
   // itself.
   Ternary operator-() const;
   // Overloaded == operator
   // Purpose is to return whether or not right hand object is eqaul to current
   bool operator==(const Ternary&) const;

   // Overloaded != operator
   // Purpose is to return if right hand object not eqaul to current
   bool operator!=(const Ternary&) const;

   // Overloaded <= operator
   // Purpose is to return whether or not current <= to right hand object
   bool operator<=(const Ternary&) const;

   // Overloaded >= operator
   // Purpose is to return whether or not current >= to right hand object
   bool operator>=(const Ternary&) const;

   // Overloaded < operator
   // Purpose is to return whether or not current < than right hand object
   bool operator<(const Ternary&) const;

   // Overloaded > operator
   // Purpose is to return whether or not current > than right hand object
   bool operator>(const Ternary&) const;
  
      
   private:
   // data member
   // Store the ternary number as an decimal value
   int decimal_equivalent;
   bool isTernary(int) const;
   int toDecimal(int) const;
   int toTernary(int) const;
};
ostream& operator<<(ostream&, const Ternary&);
istream& operator>>(istream&, Ternary&);
Ternary operator+(const Ternary&, const Ternary&);
Ternary operator-(const Ternary&, const Ternary&);
Ternary operator*(const Ternary&, const Ternary&);

#endif
