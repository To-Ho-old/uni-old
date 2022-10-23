//************************************************************************
// CS2620 - Fall 2017
// Assignment 2 
// client program to test the Polynomial class
// Written by Arie
// Oct. 31, 2017
//*************************************************************************

#include<iostream>
#include"./polynomial.h"
using namespace std;

int main()
{
   vector<int> v1 = {-3,0,1,2};
   vector<int> v2 = {4,5,0,3,1,-7};
   Polynomial p1(v1);
   Polynomial p2(v2);
   Polynomial p3,p4;
   cout << "\n*********** Testing binary addition *************" << endl;
   p3 = p2+p1;
   cout << '[' << p2 << "] + " << endl;
   cout << p1 << " is " << endl;
   cout << p3 << endl << endl;
   
   cout << "*** Testing binary addition with operands interchanged ***" << endl;
   p3 = p1 + p2;
   cout << '[' << p1 << "] + " << endl;
   cout << p2 << " is " << endl;
   cout << p3 << endl << endl;

   cout << "\n*********** Testing binary subtraction *************" << endl;
   p3 = p2-p1;
   cout << '[' << p2 << "] - " << endl;
   cout << p1 << " is " << endl;
   cout << p3 << endl << endl;
   
   cout << "\n*** Testing binary subtraction with operands interchanged ***"
	<< endl;
   p3 = p1 - p2;
   cout << '[' << p1 <<  "] - " << endl;
   cout << p2 << " is " << endl;
   cout << p3 << endl << endl;

   cout << "\n*** Testing function evaluation function ****************" << endl;
   cout << "p1 is: " << p1 << endl;
   cout << "p3 is: " << p3 << endl;
   cout << "p1(1) = " << p1(1) << endl;
   cout << "p1(-1) = " << p1(-1) << endl;
   cout << "p1(2) = " << p1(2) << endl;
   cout << "p2(3) = " << p2(3) << endl;
   cout << "p2(-3) = " << p2(-3) << endl;
   cout << "p3(1) = " << p3(1) << endl;
   cout << "p3(-1) = " << p3(-1) << endl;

   cout << "\n*** Testing getCoeff function. We get all the coefficients ***"
	<< endl;
   int coeff;
   if(p2.getCoeff(0,coeff))
      cout << "The first coefficient of " << p2 << " is " << coeff << endl;
   else
      cout << "This coefficient does not exist" << endl;

   if(p2.getCoeff(1,coeff))
      cout << "The second coefficient of " << p2 << " is " << coeff << endl;
   else
      cout << "This coefficient does not exist" << endl;

   if(p2.getCoeff(2,coeff))
      cout << "The third coefficient of " << p2 << " is " << coeff << endl;
   else
      cout << "This coefficient does not exist" << endl;

   if(p2.getCoeff(3,coeff))
      cout << "The fourth coefficient of " << p2 << " is " << coeff << endl;
   else
      cout << "This coefficient does not exist" << endl;

   if(p2.getCoeff(4,coeff))
      cout << "The fifty coefficient of " << p2 << " is " << coeff << endl;
   else
      cout << "This coefficient does not exist" << endl;

   if(p2.getCoeff(5,coeff))
      cout << "The sixth coefficient of " << p2 << " is " << coeff << endl;
   else
      cout << "This coefficient does not exist" << endl;

   if(p2.getCoeff(6,coeff))
      cout << "The sevent coefficient of " << p2 << " is " << coeff << endl;
   else
      cout << "The seventh coefficient of " << p2 << " does not exist" << endl;

   cout << endl;


   cout << "\n***** Testing the setCoeff function. We change all coefficients"
	<< endl;
   cout << "Changing the first coefficient of " << endl;
   cout << "          " << p2 << " to 14 " << endl;
   if(p2.setCoeff(0,14))
      cout << "p2 is now " << p2 << endl;
   else
      cout << "Could not change first coefficient. " << endl;

   cout << "Changing the second coefficient of " << endl;
   cout << "          " << p2 << " to -22 " << endl;
   if(p2.setCoeff(1,-22))
      cout << "p2 is now " << p2 << endl;
   else
      cout << "Could not change second coefficient. " << endl;

   cout << "Changing the third coefficient of " << endl;
   cout << "          " << p2 << " to 1 " << endl;
   if(p2.setCoeff(2,1))
      cout << "p2 is now " << p2 << endl;
   else
      cout << "Could not change third coefficient. " << endl;
   cout << "Changing the fourth coefficient of " << endl;
   cout << "          " << p2 << " to 1032 " << endl;
   if(p2.setCoeff(3,1032))
      cout << "p2 is now " << p2 << endl;
   else
      cout << "Could not change fourth coefficient. " << endl;

   cout << "Changing the fifth coefficient of "<< endl;
   cout << "          " << p2 << " to 0 " << endl;
   if(p2.setCoeff(4,0))
      cout << "p2 is now " << p2 << endl;
   else
      cout << "Could not change fifth coefficient. " << endl;

   cout << "Changing the sixth coefficient of "<< endl;
   cout << "          " << p2 << " to 20 " << endl;
   if(p2.setCoeff(5,20))
      cout << "p2 is now " << p2 << endl;
   else
      cout << "Could not change sixth coefficient. " << endl;

   cout << "Changing the seventh coefficient of "<< endl;
   cout << "          " << p2 << " to 85 " << endl;
   if(p2.setCoeff(6,85))
      cout << "p2 is now " << p2 << endl;
   else
      cout << "Could not change seventh coefficient. " << endl;

   return 0;
}
