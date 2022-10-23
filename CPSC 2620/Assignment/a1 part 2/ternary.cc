//************************************************************************
//CPSC2620 - Fall 2017
//Assignment 1 part 2
//File: ternary.cc - implementation fo the Ternary class
//Name: Quoc Ho
//Date: Oct 6, 2017
//************************************************************************

#include<iostream>
#include<cmath>
#include<cctype> //for abs function
#include "ternary.h"

using namespace std;

//***********************************************************************
//Member Function: Ternary()
//Purpose: A ternary number is created by initializing its data member to 0
//Input param:
//Output Param: decimal_equivalent = 0
//***********************************************************************
Ternary::Ternary()
{
  decimal_equivalent = 0;
}

//***********************************************************************
//Member Function: Ternary(int value)
//Purpose: A ternary number is created by intializing its data member to value
//Input param: int value
//Output Param: decimal_equivalent
//***********************************************************************
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

//***********************************************************************
// Member function: operator+=(const Ternray& t)
// Purpose: This function adds t to this object and returns this object
// Input param: Ternary object, t.
// Output param: this object.  This object is returned so to enable cascading
// of the += operator
//***********************************************************************
Ternary& Ternary::operator+=(const Ternary& t)
{
  decimal_equivalent += t.decimal_equivalent;
  return *this;
}

//***********************************************************************
//Member Function: operator-=(const ternary& t)
//Purpose: This function substracts t to this object and return this object
//Input param: ternary object t
//Output Param: this object. This object is return so to enable cascading
// of the -= operator
//***********************************************************************
Ternary& Ternary::operator-=(const Ternary& t)
{
  decimal_equivalent -= t.decimal_equivalent;
  return *this;
}

//***********************************************************************
//Member Function: operator*=(const ternary& t)
//Purpose: This function multiplies t to this function and return this object
//Input param: ternary object t
//Output Param: this object. This object is return so to enable cascading
// of the *= operator
//***********************************************************************
Ternary& Ternary::operator*=(const Ternary& t)
{
  decimal_equivalent *= t.decimal_equivalent;
  return *this;
}

//***********************************************************************
//Member Function: operator-()
//Purpose: This function negates and return this object
//Input param: this object
//Output Param: -(*this). Ternary number is returned
//***********************************************************************
Ternary& Ternary::operator-()
{
  return -(*this);
}

//***********************************************************************
//Member Function: bool operator==(const Ternary& t)
//Purpose: Comparing if this object is equal to t
//Input param: this object and ternary object t
//Output Param: true or false 
//***********************************************************************
bool Ternary::operator==(const Ternary& t) const
{
  return (*this == t);
}

//***********************************************************************
//Member Function: bool operator!=(const Ternary& t)
//Purpose: comparing if this object is not equal to t
//Input param: this object and ternary object t
//Output Param: true or false
//***********************************************************************
bool Ternary::operator!=(const Ternary& t) const
{
  return (!(*this == t));
}

//***********************************************************************
//Member Function: bool operator<(const Ternary& t)
//Purpose: comparing if this object is smaller than t
//Input param: this object and ternary object t
//Output Param: true or false
//***********************************************************************
bool Ternary::operator<(const Ternary& t) const
{
  return (*this < t);
}

//***********************************************************************
//Member Function: bool operator>(const Ternary& t)
//Purpose: Comparing if this object is bigger than t
//Input param: this object and ternary object t
//Output Param: true or false
//***********************************************************************
bool Ternary::operator>(const Ternary& t) const
{
  return (*this > t);
}

//***********************************************************************
//Member Function: bool operator<=(const Ternary& t)
//Purpose: Comparing if this object is smaller or equal ternary object t
//Input param: this object and ternary object t
//Output Param: true or false
//***********************************************************************
bool Ternary::operator<=(const Ternary& t) const
{
  return (!(*this > t));
}

//***********************************************************************
//Member Function: bool operator>=(const Ternary& t)
//Purpose: Comparing if this object is bigger or equal ternary object t
//Input param: this object and ternary object t
//Output Param: true or false
//***********************************************************************
bool Ternary::operator>=(const Ternary& t) const
{
  return (!(*this < t));
}
  
//***********************************************************************
//Member Function: istream& extract(istream& sin)
//Purpose: This function extracts the nexts int from the input stream.
//         The number extracted is checked, if any digit greater than 2 then
//         output an error message and set the ternary number to 0.
//         Otherwise, converts the ternary into its decimal equivalent value.
//Input param: int value
//Output Param: decimal_equivalent
//***********************************************************************
istream& Ternary::extract(istream& sin)
{
  int val;
  sin >> val;
  if(isTernary(val) == false)
    {
      cout << "Error: The digit is larger than 2, set ternary to 0" << endl;
      val = 0;
      decimal_equivalent = val;
    }
  else
    decimal_equivalent = toDecimal(val);

  return sin;
}

//***********************************************************************
//Member Function: ostream& insert(ostream& sout)
//Purpose: This functions converts the datamember decimal_equivalent to
//         equivalent Ternary and outputs it to the output stream in the
//         actual parameter
//Input param: decimal_equivalent
//Output Param: ternary
//***********************************************************************
ostream& Ternary::insert(ostream& sout) const
{
  int val = decimal_equivalent;
  int ter = toTernary(val);
  if(val < 0)
    {
      sout << "-" << ter << endl;
    }
  else
    sout << ter << endl;

  return sout;
}

//***********************************************************************
//Member Function: bool isTernary(int n) const
//Purpose: This functions checks if the int n is a ternary number
//Input param: int n
//Output Param: true or false
//***********************************************************************
bool Ternary::isTernary(int n) const
{
  int temp = abs(n);
  int d = 0;
  while((d<=2) &(temp>0))
    {
      d = temp%BASE10;
      temp = temp/BASE10;
    }
  if(d>2)
    return false;
  else
    return true;
}

//***********************************************************************
//Member Function: int toDecimal(int m) const
//Purpose: This functions converts the ternary number passed as actual
//         parameter to its decimal equivalent
//Input param: int m as an ternary number
//Output Param: int sum as an decimal equivalent of ternary number m
//***********************************************************************
int Ternary::toDecimal(int m) const
{
  int toDecSum = 0;
  int temp = abs(m);
  bool neg = false;
     
  if(isTernary(m) == true)
    {
      if(m<0)
	neg = true;
      int i = 0;
      while(temp>0)
	{
	  int d = temp%BASE10;
	  toDecSum = toDecSum + d*pow(BASE3,i);
	  i++;
	  temp = temp/BASE10;
	}
    }
  if(neg == true)
    toDecSum *= -1;
  return toDecSum;
}

//***********************************************************************
//Member Function: int toTernary(int n) cosnt
//Purpose: This function converts the decimal number passed as actua
//         parameter to its Ternary equivalent.
//Input param: int n as a decimal number
//Output Param: int sum as a ternary number 
//***********************************************************************
int Ternary::toTernary(int n) const
{
  int temp = abs(n);
  bool neg = false;
  if(n<0)
    neg = true;
  int d = temp%BASE3;
  int toTerSum = d;
  temp = temp/BASE3;
  int i = 0;

  while(temp>0)
    {
      d = temp%BASE3;
      i++;
      toTerSum = toTerSum + d*pow(BASE10,i);
      temp = temp/BASE3;
    }
  
  if(neg)
    toTerSum *= -1;
  return toTerSum;
}

//***********************************************************************
//Member Function: const Ternary& operator+(const Ternary& l, const Ternarty& r)
//Purpose: Overloaded add operator
//Input param: ternary object l, ternary object r
//Output Param: ternary object a
//***********************************************************************
const Ternary& operator+(const Ternary& l, const Ternary& r)
{
  Ternary a = l;
  return a += r;
}

//***********************************************************************
//Member Function: const Ternary& operator-(const Ternary& l. const Ternary& r)
//Purpose: Overloaded subtraction operator
//Input param: ternary object l, ternary object r
//Output Param: ternary object a
//***********************************************************************
const Ternary& operator-(const Ternary& l, const Ternary& r)
{
  Ternary a = l;
  return a -= r;
}
 
//***********************************************************************
//Member Function: cosnt Ternary& operator*(const Ternary& l, const Ternary& r)
//Purpose: Overloaded multiplication operator
//Input param: ternary object l, ternary object r
//Output Param: ternary object a
//***********************************************************************
const Ternary& operator*(const Ternary& l, const Ternary& r)
{
  Ternary a = l;
  return a *= r;
}

//***********************************************************************
//Member Function: ostream& operator<<(ostream& sout, const Ternary& t)
//Purpose: Overload stream insertion operator
//Input param: ternary object t
//Output Param: sout
//***********************************************************************
ostream& operator<<(ostream& sout, const Ternary& t)
{
  t.insert(sout);
  return sout;
}

//***********************************************************************
//Member Function: istream& operator>>(istream& sin, Ternary& t)
//Purpose: Overloaded stream extraction operator
//Input param: ternary object t
//Output Param: sin
//***********************************************************************
istream& operator>>(istream& sin, Ternary& t)
{
  t.extract(sin);
  return sin;
}


  
