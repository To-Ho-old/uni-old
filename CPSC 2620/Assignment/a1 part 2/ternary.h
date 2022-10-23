//***************************************************************************
//CPSC2620 - Fall 2017
//Assignment 1 part 2
//File: ternary.h - interface file for the ternary class
//Name: Quoc Ho
//Date: Oct 6, 2017
//***************************************************************************

#ifndef TERNARY_H
#define TERNARY_H
#include <iostream>

using namespace std;

const int MAX_BITS = 32;
const int BASE3 = 3;
const int BASE10 = 10;

class Ternary
{
 public:
  //constructors

  //1st construcotr
  //default constructor. set ternary number to 0
  //Example: Ternary t1, t1 will be set to 0
  Ternary();

  //2nd constructor
  //set ternary number to input parameter
  //If given Ternary number is greater than 2, an error message is output on
  //to the terminal and its datamember is set to 0
  //Example: Ternary t2(122), t2 will be 17
  //         Ternary t3(4210), will give an error message and set to 0
  Ternary(int);

  //Overloaded add-assignment operator
  //Precondition: None
  //Poost Condition: The parameter is added to this Ternary number and this
  //                 Ternary number is returned
  Ternary& operator+=(const Ternary&);

  //Overloaded subtract-assignment operator
  //Precondition: None
  //Postcondition: The actual parameter is subtracted from this Ternary number
  //               and this Ternary number is returned
  Ternary& operator-=(const Ternary&);

  //Overloaded multiply-assignment operator
  //Precondition: None
  //Postcondition: The actual parameter is subtracted from this Ternary number
  //               and this Ternary number is returned.
  Ternary& operator*=(const Ternary&);

  //Overloaded unary minus
  //Precondition: None
  //Postcondition: This Ternary number is negated and returned
  Ternary& operator-();

  //Overloaded Boolean equality operator
  //Precondition: None
  //Postcondition: If the actual parameter is equal to this Ternary number
  //               the Boolean constant true is returned; otherwise Boolean
  //               constant false is returned.
  bool operator==(const Ternary&) const;

  //Overloaded Boolean not equal operator
  //Precondition: None
  //Postcondition: If the actual parameter is not equal to this Ternary number
  //               the Boolean constant true is returned; otherwise Boolean
  //               constant false is returned
  bool operator!=(const Ternary&) const;

  //Overloaded Boolean less-than operator
  //Precondition: None
  //Postcondition: If the actual parameter is less than this Ternary number
  //               the Boolean constant true is returned; otherwise Boolean
  //               constant false is returned
  bool operator<(const Ternary&) const;

  //Overloaded Boolean greater-than operator
  //Precondition: None
  //Postcondition: If the actual parameter is greater than this Ternary number
  //               the Boolean constant true is returned; otherwise Boolean
  //               constant false is returned
  bool operator>(const Ternary&) const;

  //Overloaded Boolean less-than-or-equal operator
  //Precondition: None
  //Postcondition: If the actual parameter is less than or equal to this
  //               Ternary number the Boolean constant true is returned;
  //               otherwise Boolean constant false is returned
  bool operator<=(const Ternary&) const;

  //Overloaded Boolean greater-than-or-equal operator
  //Precondition: None
  //Postcondition: If the actual parameter is greater than or equal to this
  //               Ternary number the Boolean constant true is returned;
  //               otherwise Boolean constant false is returned
  bool operator>=(const Ternary&) const;

  //Stream insertion
  //Precondition: None
  //Postcondition: this Ternary number is output to the output stream in the
  //               actual parameter. Converts the data member decimal
  //               equivalent to the equivalent Ternary and outputs it to the
  //               output stream in the actual parameter  
  istream& extract(istream&);

  //Stream extraction
  //Precondition: None
  //Postcondition: Extracts the next int from the input stream. The number
  //               extracted is checked to see if any of the digits in it is
  //               greater than 2 and if so an error message is output on the
  //               terminal and this Ternary number is initialized to zero;
  //               otherwise the int number extracted is converted to the
  //               corresponding decimal value and the decimal value is
  //               assigned to the data member decimal equivalent of this
  //               Ternary number
  ostream& insert(ostream&) const;

 private:

  //Check if the int parameter is a ternary number
  //Precondition: None
  //Postcondition: Returns Boolean constant true if the int parameter consists
  //               of digits 0, 1, or 2 only; if any digit is larger than two
  //               then the functions returns Boolean constant false.
  bool isTernary(int) const;

  //Converts the Ternary number passed as actual parameter to its decimal
  //equivalent. For example, if the number passed is 112, then it returns
  //its decimal equivalent 14
  //Precondition: The number passed must be a valid Ternary number i.e.,
  //              it does not contain a digit larger than 2
  //Postcondition: Returns the decimal number corresponding to the Ternary
  //               number passed to the function
  int toDecimal(int) const;

  //Converts the decimal number passed as actual parameterto its Ternary
  //equivalent. For example, if the number passed is 15, then the function
  //returns its Ternary equivalent 120
  //Precondition: The actual parameter is a valid integer
  //Postcondition: Returns the decimal number corresponding to the Ternary
  //               number passed to the function
  int toTernary(int) const;

  // Store the ternary number as an decimal value
  int decimal_equivalent;
};

//Overloaded stream insertion operator; uses the member function insert
//Precondition: None
//Postcondition: The Ternary actual parameter is inserted in the ostream
//               actual parameter
ostream& operator<<(ostream&, const Ternary&);

//Overloaded stream extraction operator; uses the member function extract
//Precondition: None
//Postcondition: The Ternary actual parameter is assigned the number extracted
//               from istream actual parameter
istream& operator>>(istream&, Ternary&);

//Overloaded add operator; uses overloaded add-assign operator
//Precondition: None
//Postcondition: The right actual parameter is added to the left actual
//               parameter and the result is returned
const Ternary& operator+(const Ternary&, const Ternary&);

//Overloaded subtraction operator; uses overloaded subtract-assign operator
//Precondition: None
//Postcondition: The right actual parameter is subtracted from the left actual
//               parameter and the result is returned
const Ternary& operator-(const Ternary&, const Ternary&);

//Overloaded multiplication operator; uses overloaded multiply-assign operator
//Precondition: None
//Postcondition: The right actual parameter is multiplied with the left actual
//               parameter and the result is returned
const Ternary& operator*(const Ternary&, const Ternary&);

#endif
