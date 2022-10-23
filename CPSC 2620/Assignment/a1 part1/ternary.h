//***************************************************************************
// CPSC2620 - Fall 2017
// Assignment 1a
// File: ternary.h -- interface file for the Ternary class
// Prepared by: Arie
// Date: Sep. 22, 2017
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
   
   // Function to add a ternary number to ternary number.  A ternary number
   // is returned.
   // Example Usage: Ternary t1(122), t2(210), t3;
   //                t3 = t1.add(t2); 
   // t2 is added to t1, the result of which is returned as a ternary 
   Ternary plus(const Ternary&) const;
   
   // Function to subtract a ternary number from a ternary number.
   // A ternary number is returned.
   // Example Usage: Ternary t1(122), t2(210), t3;
   //                t3 = t1.subtract(t2);
   // t2 is subtracted from t1, the result of which is returned as a ternary 
   Ternary minus(const Ternary&) const;
   
   // Function to multiply a ternary number to ternary number. A ternary number
   // is returned.
   // Example Usage: Ternary t1(122), t2(210), t3;
   //                t3 = t1.subtract(t2);
   // t2 is multiplied with t1, the result of which is returned as a ternary 
   Ternary times(const Ternary&) const;
      
   private:
   // data member
   // Store the ternary number as an decimal value
   int decimal_equivalent;
};
#endif
