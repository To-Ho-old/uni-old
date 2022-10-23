//************************************************************************
// CS2620 - Fall 2017
// Assignment 1 Part II
// Implementation of the Ternary class
// Written by Arie
// Oct. 19, 2017
//*************************************************************************

#include <iostream>
#include <cmath>
#include <cctype> // for abs function
#include "./ternary.h"
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
   decimal_equivalent = toTernary(val);
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
}

//********************************************************************
// Function: isTernary
// Input parameter, n, is a base 10 digit
// Returns true if n is a base 3 digit, false otherwise
//********************************************************************
bool Ternary::isTernary(int n) const
{
   if(abs(n) > 2)
   {
      cout << "Illegal ternary number. This ternary is set to 0" << endl;
      return false;
   }
   return true;
}

//********************************************************************
// Function: toTernary
// Input parameter, n, is a base 10 value
// If any digit of n is not base 3 the decimal value of this object is
// set to 0. Otherwise the decimal value of n is returned.
// Eg1. n = 121 = 16 (base 10) is returned
// Eg2. n = 822, because 8 is not base 3, 0 is returned.
//********************************************************************
int Ternary::toTernary(int n) const
{
   int sum = 0, cntr = 0, digit;
   while(n != 0)
   {
      digit = n % BASE10; // digit should be 0, 1, or 2. If not: Illegal
      if(isTernary(digit))
      {
	 sum += digit *
	    pow(static_cast<double>(BASE3),static_cast<double>(cntr));
	 n = n/BASE10;
	 cntr++;
      }
      else
	 return 0;
   }
   return sum;
}

//********************************************************************
// Function: Overloaded += operator
// Input parameter, t, a Ternary object
// The decimal_equivalent of t is added to this object's decimal_equivalent
// This object is returned.
//********************************************************************
Ternary& Ternary::operator+=(const Ternary& t)
{
   decimal_equivalent += t.decimal_equivalent;
   return *this;
}

//********************************************************************
// Function: Overloaded -= operator
// Input parameter, t, a Ternary object
// The decimal_equivalent of t is subtracted from this object's
// decimal_equivalent. This object is returned
//********************************************************************
Ternary& Ternary::operator-=(const Ternary& t)
{
   decimal_equivalent -= t.decimal_equivalent;
   return *this;
}

//************************************************************************
// Function: Overloaded *= operator
// Input parameter, t, a Ternary object
// The decimal_equivalent of t is multiplied to this object's decimal_equivalent
// This object is returned.
//*************************************************************************
Ternary& Ternary::operator*=(const Ternary& t)
{
   decimal_equivalent *= t.decimal_equivalent;
   return *this;
}
//********************************************************************
// Function: Overloaded - (negation) operator
// A new object that contains the negation of current object is returned
// This object is not changed.
//********************************************************************
Ternary Ternary::operator-() const
{
   int number = 0,cntr = 0,digit;
   int val = -decimal_equivalent;
   while(val != 0)
   {
      digit = val % 3;
      number += digit * pow(BASE10,static_cast<double>(cntr));
      val = val/3;
      cntr++;
   }
   return Ternary(number);
}
//********************************************************************
// Function: Overloaded == operator
// Returns true if this object is equal to input parameter t, false otherwise
//********************************************************************
bool Ternary::operator==(const Ternary& t) const
{
   return decimal_equivalent == t.decimal_equivalent;
}
//********************************************************************
// Function: Overloaded != operator
// Returns true if this object is not equal to input parameter t, false
// otherwise.
//********************************************************************
bool Ternary::operator!=(const Ternary& t) const
{
   return decimal_equivalent != t.decimal_equivalent;
}

//********************************************************************
// Function: Overloaded <= operator
// Returns true if this object is less than or equal to input parameter t,
// false otherwise.
//********************************************************************
bool Ternary::operator<=(const Ternary& t) const
{
   return decimal_equivalent <= t.decimal_equivalent;
}
//********************************************************************
// Function: Overloaded >= operator
// Returns true if this object greeater than or equal to  input parameter t,
// false otherwise.
//********************************************************************
bool Ternary::operator>=(const Ternary& t) const
{
   return decimal_equivalent >= t.decimal_equivalent;
}

//********************************************************************
// Function: Overloaded < operator
// Returns true if this object < input parameter t, false otherwise
//********************************************************************
bool Ternary::operator<(const Ternary& t) const
{
   return (!(*this >= t));
}

//********************************************************************
// Function: Overloaded > operator
// Returns true if this object greater than input parameter t, false otherwise
//
//********************************************************************
bool Ternary::operator>(const Ternary& t) const
{
   return (!(*this <= t));
}

//********************************************************************
// Non member overloaded insertion operator
// Outputs current object to output ostream
// Returns ostream object to enable concatenation of << 
//********************************************************************
ostream& operator<<(ostream& oStr, const Ternary& t)
{
   t.insert(oStr);
   return oStr;
}

//********************************************************************
// Non member overloaded extraction operator
// Allows for object input from input stream
// Returns istream object to enable concatenation of >>
//********************************************************************
istream& operator>>(istream& iStr, Ternary& t)
{
   t.extract(iStr);
   return iStr;
}

//********************************************************************
// Non member overloaded binary plus operator
// Returns the sum of input parameters
//********************************************************************
Ternary operator+(const Ternary& t1, const Ternary& t2)
{
   Ternary temp = t1;
   temp += t2;
   return temp;
}

//********************************************************************
// Non member overloaded binary minus operator
// Returns the difference of input parameters
//********************************************************************
Ternary operator-(const Ternary& t1, const Ternary& t2)
{
   Ternary temp = t1;
   temp -= t2;
   return temp;
}

//********************************************************************
// Non member overloaded binary times operator
// Returns the product of input parameters
//********************************************************************
Ternary operator*(const Ternary& t1, const Ternary& t2)
{
   Ternary temp = t1;
   temp *= t2;
   return temp;
}
