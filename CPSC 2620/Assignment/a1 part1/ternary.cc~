//************************************************************************
// CS2620 - Fall 2017
// Assignment 1a
// Implementation of the Ternary class
// Written by Arie
// Sep. 22, 2017
//*************************************************************************

#include <iostream>
#include <cmath>
#include <cctype> // for abs function
#include "ternary.h"
using namespace std;

//*******************************************************************
// default constructor
//
// post-condition -- Ternary number will be 0, numBits = 1, sign is pos. 
//*******************************************************************
Ternary::Ternary()
{
   decimal_equivalent = 0;
}

//*******************************************************************
// Constructor to set the value of a Ternary number
//
// val -- imports the Ternary the number
// If the input val is not a legal Ternary number this constructor,
// will give an "error" and sets this Ternary number to the default value of 0.
// post-condition -- The decimal value of the Ternary number is entered.
//*******************************************************************
Ternary::Ternary(int val)
{
   decimal_equivalent = 0;
   int cntr = 0;
   int digit;
   while(val != 0)
   {
      digit = val % BASE10;
      if(abs(digit) > 2)
      {
	 cout << "Illegal ternary number. This ternary is set to 0" << endl;
	 decimal_equivalent = 0;
	 break;
      }
      decimal_equivalent += digit *
	 pow(static_cast<double>(BASE3),static_cast<double>(cntr));
      cntr++;
      val = val/BASE10;
   }
}

//********************************************************************
// Public member function to add two Ternary numbers
// param [in] -- t, the Ternary number to add to current object
// post-condition: Two Ternary numbers are added and produce another
//                 Ternary number which is returned.
//********************************************************************
Ternary Ternary::plus(const Ternary& t) const
{
   Ternary temp; // Create a temporary Ternary object
   int sum = decimal_equivalent + t.decimal_equivalent;
   temp.decimal_equivalent = sum;
   return temp; 
}

//********************************************************************
// Public member function to subtract two Ternary numbers
// param [in] -- t, the Ternary number to subtract from current object
// post-condition: Two Ternary numbers are subtracted and produce another
//                 Ternary number which is returned.
//********************************************************************
Ternary Ternary::minus(const Ternary& t) const
{ 
   Ternary temp; // Create a temporary Ternary object
   int diff = decimal_equivalent - t.decimal_equivalent;
   temp.decimal_equivalent = diff;
   return temp; 
}

//********************************************************************
// Public member function to multiply two Ternary numbers
// param [in] -- t, the Ternary number to multiply to current object
// post-condition: Two Ternary numbers are multiplied and produce another
//                 Ternary number which is returned
//********************************************************************
Ternary Ternary::times(const Ternary& t) const
{
   Ternary temp;
   int product = decimal_equivalent * t.decimal_equivalent;
   temp.decimal_equivalent = product;
   return temp; //create a Ternary number from result
}

//********************************************************************
// Public member function that outputs a Ternary number
//
// pre-condition -- param [in]: outS - output stream (eg cout)
// post-condition -- The Ternary is output to outS
//********************************************************************
void Ternary::insert(ostream& outS) const
{
   int val;
   bool negative = decimal_equivalent < 0; // this Ternary negative?
   val = abs(decimal_equivalent);
   int digitArray[MAX_BITS] = {0};
   int bit = 0;
   while (val > 0)
   {
      digitArray[bit] = val % BASE3;
      val = val / BASE3;
      if(val > 0)
	 bit++;
   }
   if(negative)
      outS << '-';
   for(int i=bit; i>=0; i--)
      outS << digitArray[i];
}

//********************************************************************
// Public member function that outputs a Ternary number
//
// pre-condition -- param [in]: outS - output stream (eg cout)
// post-condition -- The Ternary is output to outS
//********************************************************************
void Ternary::extract(istream& iStr)
{
   int value;
   iStr >> value;
   Ternary temp(value);
   decimal_equivalent = temp.decimal_equivalent;
};
