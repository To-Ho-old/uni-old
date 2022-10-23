//************************************************************************
// CS2620 - Fall 2017
// Assignment 2
// Implementation of the Polynomial class
// Written by Arie
// Oct. 31, 2017
//*************************************************************************
#include "./polynomial.h"

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//************************************************************************
// Function: Default Constructor
// Set degree to -1, a degree that emulates nothing in this polynomial
//************************************************************************
Polynomial::Polynomial()
{
   degree = -1;
}

//************************************************************************
// Function: Constructor that takes a vector as parameter
// Polynomial is created with values in vector as coefficents of polynomial
// Degree of polynomial is set to one less than size of vector
//************************************************************************
Polynomial::Polynomial(const vector<int>& v)
{
   degree = v.size() - 1;
   for(int i=0; i<=degree; i++)
      P.push_back(v[i]);
}

//************************************************************************
// Function: Overloaded operator +
// Adds this polynomial and parameter polynomial and returns the sum
// polynomial
//************************************************************************
Polynomial Polynomial::operator+(const Polynomial& RHS) const
{
   Polynomial larger,smaller;
   int min,max;
   if(degree < RHS.degree)
   {
      min = degree;
      max = RHS.degree;
      larger = RHS;
      smaller = *this;
   }
   else
   {
      max = degree;
      min = RHS.degree;
      larger=*this;
      smaller=RHS;
   }
   for(int i=0; i<=min; i++)
      larger.P[max-min+i] += smaller.P[i];
   return larger;
}

//************************************************************************
// Function: Overloaded operator -
// Subtracts the right polynomial from this polynomial and returns the 
// difference polynomial
//************************************************************************
Polynomial Polynomial::operator-(const Polynomial& RHS) const
{
   Polynomial larger,smaller;
   int min,max;
   if(degree < RHS.degree)
   {
      min = degree;
      max = RHS.degree;
      larger = RHS;
      smaller = *this;
   }
   else
   {
      max = degree;
      min = RHS.degree;
      larger = *this;
      smaller = RHS;
   }
   // Subract smallest poly from largest, regardless as to which is being
   // subracted from what.
   for(int i=0; i<=min; i++)
      larger.P[max-min+i] -= smaller.P[i];
   // Now we need to change the sign of each component if we are subtracting
   // the larger from the smaller.  No need if we are subracting smaller from
   // larger.
   if(degree < RHS.degree) 
      for(int i= 0; i<=max; i++)
	 larger.P[i] = -larger.P[i];
   return larger;
}

//************************************************************************
// Function: Overloaded () evaluation function
// This function evaluates this polynomial by plugging x in as the variable.
// The value of the polynomial evaluated at x is returned.
//************************************************************************
double Polynomial::operator()(double x) const
{
   double sum = 0.0;
   for(int i=degree; i>=0; i--)
      sum += P[i] * pow(x,static_cast<double>(degree-i));
   return sum;
}

//************************************************************************
// Function: setCoeff
// This function set the kth coefficient with 0 <= k <= degree.  If k is not
// in this range nothing is changed and false is returned.  If k in proper
// range, the kth coefficent is changed and true is returned.
//************************************************************************
bool Polynomial::setCoeff(int k, int c)
{
   if(k<0 || k > degree)
      return false;
   P[k] = c;
   return true;
}

//************************************************************************
// Function: getCoeff
// This function returns the kth coefficent through the reference parameter c.
// If k in not in range [0,n] c is not set and false is returned.
//************************************************************************
bool Polynomial::getCoeff(int k, int& c) const
{
   if(k<0 || k > degree)
      return false;
   c = P[k];
   return true;
}

//************************************************************************
// Function: insert
// This function outputs to an ostream the polynomial in the form:
// ax^n + bx^(n-1) + cx^(n-2 + ... + nx^0.
// Terms with 0 coefficient are ignored and terms with degree 1 are output as x
// and only the coefficient is output when the degree is 0.
//************************************************************************
ostream& Polynomial::insert(ostream& ostr) const
{
   unsigned cntr = 0, val;
   vector<int>::const_iterator it = P.begin();
   while(it != P.end())
   {
      if(*it != 0)
      {
	 if(*it < 0)
	    ostr << '(' << *it << ")";
	 else
	 {
	    if(*it == 1)
	       ;
	    else
	       ostr << *it;
	 }
	 val = P.size()-cntr-1;
	 if(val == 1)
	    cout << "x";
	 else if (val > 1)
	    ostr  << "x^"<< P.size()-cntr-1;
	 ++it;
	 vector<int>::const_iterator tmp = it; // a temporary iterator
	 while(tmp != P.end() && *tmp == 0) // see if rest of coeffs are 0
	    ++tmp;
	 if(tmp == P.end()) //if they are, then we are done and leave while loop
	    break;
	 ostr << " + "; // if not, print a '+'
	 cntr++;
      }
      else
      {
	 cntr++;
	 ++it;
      }
   }
   return ostr;
}

//************************************************************************
// Function: overloaded << output operator
// This function calls the member insert function.
//************************************************************************
ostream& operator<<(ostream& ostr, const Polynomial& RHS)
{
   RHS.insert(ostr);
   return ostr;
}


