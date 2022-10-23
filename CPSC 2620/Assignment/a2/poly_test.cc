//***********************************************************
//CPSC 2620 - Fall 2017
//Assignment 2
//test_polynomial.cc
//Purpose: A test program to thoroughly test the member functions and the
//         class Polynomial
//By: Quoc Ho
//Date: Oct 20, 2017
//***********************************************************

#include "./polynomial.h"
#include <iostream>

using namespace std;

int main()
{
  //Create a P1 vector with 4 coefficients and 3 degrees
  vector<int> coeff1(4) = {5, 4, -3, 1};
  Polynomial P1(coeff1);
  cout << "P1: " << P1 << endl;
  //Create a P2 vector with 8 coefficient and 7 degrees
  vector<int> coeff2(8) = {10, 6, 0, 7, 0, -1, 0, 6};
  Polynomial P2(coeff2);
  cout << "P2: " << P2 << endl;

  Polynomial P3(); //create an empty vector
  cout << "P3: " << P3 << endl;

  Polynomial Ptest1();
  Polynomial Ptest2();

  //Chech the operator+
  Ptest1 = P1 + P2;
  cout << "P1 + P2 = " << Ptest1 << endl;

  //Check the operator-
  Ptest2 = P2 - P1;
  cout << "P2 - P1 = " << Ptest2 << endl;

  return 0;
}
  
   
