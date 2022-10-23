#ifndef RATIONAL_H
#define RATIONAL_H
// Rational class definition 
// representing rational numbers i.e., numbers of the form
// n/d with n and d integers and d not zero(0). 
// Author:  
// Date:

#include <iostream>

using namespace std;

class Rational {

 public: 

// Stream insertion and extraction operations.
// They are not needed by the clients as
// we have overloaded the corresponding operators.
 
// Stream insertion.
// Precondition:   None
// Postcondition:  For Rational object l via which this function is called,
//                 l.insert() outputs  l as:
//                 l.numerator/l.denominator to ostream if denominator is not 1;
//                 otherwise it outputs l.numerator.

      void insert(ostream& )const;
 
// Stream extraction.
// Precondition:  None
// Postcondition: Rational object l (via which this function is called),
//                l.extract() is assigned new value read from
//                istream; the next two integers read are set to
//                numerator and denominator, respectively where denominator
//                is not zero (0); if
//                denominator is zero an error message to cout and the object
//                l is unchanged..

      void extract(istream&);


      Rational():numerator(0),denominator(1){}
// A constructor that takes two parameters. 
// Precondition:  None
// Postcondition: If den is not zero a Rational object representing
//                num/den is created; otherwise
//                the newly created Rational object is initialized to the value zero (0)
//                and an error message is output to cerr.

      Rational(int num, int den);
	
// Type conversion constructor to create a rational number from an integer
// Precondition:  None
// Postcondition: The integer parameter is stored as a rational number  

      Rational(int i):numerator(i),denominator(1){}

// We allow mixed mode arithmetic such that it is possible to have one of the 
// arguments integers;
// First define the compound assignment operators 
//    +=, -=, *=, /= which must be members


// Precondition:  None
// Postcondition: This object is assigned the result of the sum of it  
//                with the object in the parameter. 

      Rational& operator+=(const Rational& );

// Precondition:  None
// Postcondition: This object is assigned the result of the sum of it
//                with the integer in the parameter.


      Rational& operator+=(int);  

// Precondition:  None
// Postcondition: The object in the parameter is subtracted from this object 
//                and the result is assigned to this object. 


      Rational& operator-=(const Rational& );

// Precondition:  None
// Postcondition: The integer in the parameter is subtracted from this object
//                and the result is assigned to this object.

      Rational& operator-=(int);             

// Precondition:  None
// Postcondition: The object in the parameter is multiplied with this object
//                and the result is assigned to this object.


      Rational& operator*=(const Rational& );

// Precondition:  None
// Postcondition: The integer in the parameter is multiplied with  this object
//                and the result is assigned to this object.

      Rational& operator*=(int);             

// Precondition:  None
// Postcondition: This object is divided  by the object in parameter 
//                and the result is assigned to this object.

      Rational& operator/=(const Rational& );

// Precondition:  None
// Postcondition: This object is divided  by the integer in parameter 
//                and the result is assigned to this object.

      Rational& operator/=(int);             
    
// Increment and decrement operators
//
// Post-increment/post-decrement
  Rational&  operator++();
  Rational&  operator--();

// Pre-increment/pre-decrement
// note the dummy argument

  Rational  operator++(int);
  Rational  operator--(int);

 // Comparisons

  bool operator==(const Rational& r) {
    return ((numerator == r.numerator) && (denominator == r.denominator));
  }
  bool operator!=(const Rational& r){
    return !(*this == r);
  }
 
  bool operator<(const Rational& r);
  bool operator<=(const Rational& r);
  bool operator>(const Rational& r);
  bool operator>=(const Rational& r);
      
 private:
//  Pre-condition: The parameters are positive integers.
//  Post-condition: The gcd of the parameters is returned.

    int gcd(int, int); 

//  Pre-condition:  none 
//  Post-condition: The numerator is relatively prime to the denominator of 
//                  this object. 

    void reduce(int,int);

// Data members
     int numerator;
     int denominator;
};

// Non-member arithmetic operators
// return by const reference for cascaded calls 

const Rational& operator+(const Rational &, const Rational &);
const Rational& operator+(const Rational &, int );
const Rational& operator+(int, const Rational &);
const Rational& operator-(const Rational &, const Rational &);
const Rational& operator-(const Rational &, int );
const Rational& operator-(int, const Rational &);

const Rational& operator*(const Rational &, const Rational &);
const Rational& operator*(const Rational &, int );
const Rational& operator*(int, const Rational &);

const Rational& operator/(const Rational &, const Rational &);
const Rational& operator/(const Rational &, int );
const Rational& operator/(int, const Rational &);

// Overloaded stream insertion and extraction operators.

ostream& operator<<(ostream& sout, const Rational& s);
istream& operator>>(istream& sin, Rational& s);

#endif
