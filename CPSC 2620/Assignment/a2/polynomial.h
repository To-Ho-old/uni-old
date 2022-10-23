
// polynomial.h
// A simple ploynomial class of degree n
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>
#include <iostream>
using namespace std;

class Polynomial
{
  public:
   // Postcondition: Creates an "empty" polynomial 
   Polynomial();
   
   // Postcondition: Creates a polynomial with coefficients provided in the
   // vector parameter; the degree of the polynomial is the size of the
   // vector plus 1
   Polynomial(const vector<int>& coeff);
   
   // Basic arithmetic operations:   
   // Operator +
   // Postcondition: The sum of this polynomial and RHS is returned; this
   //                 and RHS are unchanged
   const Polynomial& operator+(const Polynomial& RHS) const;
   
   // Operator -
   // Postcondition: The RHS is subtracted from  this  and the result is
   // returned; this and RHS are unchanged
   const Polynomial& operator-(const Polynomial& RHS) const;
   
   // Evaluation; 
   // Operator ()
   // Postcondition: this polynomial is evaluated at x and the the value 
   //                is returned; this polynomial is unchanged 
   double operator()(double x) const;
   
   // Set the coefficient of x^k
   // Precondition: k >= 0 and k <= n, where n is the degree of this polynomial
   // Postcondition: If precondition is met, then coefficient of x^k is
   // changed to c and returns true; otherwise no change is made and returns
   // false;
   bool  setCoeff(int k, int c);
   
   // Get the coefficient of x^k
   // Precondition: k >= 0 and k <= n, where n is the degree of this polynomial
   // Postcondition: If precondition is met, then the function assigns the 
   //                coefficient of x^k  
   //                in parameter c and return true; 
   //                otherwise returns false and parameter c remains unchanged 
   bool  getCoeff(int k, int& c);
   
   
   // Stream insertion 
   // Postcondition: Write the polynomial onto stream ostr.
   ostream& insert(ostream& ostr);
   
  private:
   vector<int> P;     // coefficients of the polynomial; P[i] is the coefficient
                      //    of x raised to power i; 
   
};

// overloaded stream to write the polynomial RHS onto stream Out 
ostream& operator<<(ostream& Out, const Polynomial& RHS);
#endif

