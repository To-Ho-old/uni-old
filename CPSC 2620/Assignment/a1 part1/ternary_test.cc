//************************************************************************
// CS2620 - Fall 2017
// Assignment 1 
// client program to test the Ternary class
// Written by Arie
// Sep. 21, 2017
//*************************************************************************

#include <iostream>
#include "ternary.h"

using namespace std;

int main()
{
   // Declare some Ternaries
   cout << "Now declaring Ternary t1 ..." << endl;
   Ternary t1;
   cout << "Now attempting to declare t2(-8) ..." << endl;
   Ternary t2(-8); // This declaration should produce error message
   cout << "t1 is: ";
   t1.insert(cout);
   cout << endl;
   cout << "t2 is: ";
   t2.insert(cout);
   cout << endl;
   
   Ternary t3(-12);
   Ternary t4(2);
   
   cout << "t3 is ";
   t3.insert(cout);
   cout << endl;
   cout << "t4 is ";
   t4.insert(cout);
   cout << endl;

   Ternary t5 = t3.plus(t4);
   Ternary t6 = t3.minus(t4);
   Ternary t7 = t3.times(t4);
   // + 
   t3.insert(cout);
   cout << " + (";
   t4.insert(cout);
   cout << ") = ";
   t5.insert(cout);
   cout << endl;
   
   // - 
   t3.insert(cout);
   cout << " - (";
   t4.insert(cout);
   cout << ") = ";
   t6.insert(cout);
   cout << endl;
   
   // * 
   t3.insert(cout);
   cout << " * (";
   t4.insert(cout);
   cout << ") = ";
   t7.insert(cout);
   cout << endl;

   Ternary t8(12212);
   cout << "t8 is ";
   t8.insert(cout);
   cout << endl;
   cout << "Enter a new value for t8: ";
   t8.extract(cin);
   cout << "t8 after t8.extract(cin) is: ";
   t8.insert(cout);
   cout << endl;
   
   return 0;
}
