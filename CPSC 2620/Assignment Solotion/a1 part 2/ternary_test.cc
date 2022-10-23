//************************************************************************
// CS2620 - Fall 2017
// Assignment 1 Part II
// client program to test the Ternary class
// Written by Arie
// Oct. 19, 2017
//*************************************************************************

#include <iostream>
#include "./ternary.h"

using namespace std;

int main()
{
   // Declare some Ternaries
   cout << "Now declaring Ternary t1 ..." << endl;
   Ternary t1;
   cout << "Now attempting to declare t2(-8) ..." << endl;
   Ternary t2(-8); // This declaration should produce error message
   cout << "t1 is: " << t1 << endl;
   cout << "t2 is: " << t2 << endl;
   
   Ternary t3(-12);
   Ternary t4(21);
   
   cout << "t3 is " << t3 << endl;
   cout << "t4 is " << t4 << endl;


   cout << "\n Now testing binary +" << endl;
   cout << t3 << " + " << t4 << " is " << t3+t4 << endl;

   cout << "\n Now testing binary -" << endl;
   cout << t3 << " - " << t4 << " is " << t3-t4 << endl;

   cout << "\n Now testing binary *" << endl;
   cout << t3 << " * " << t4 << " is " << t3*t4 << endl;

   cout << "\n Now testing overloaded >> operator" << endl;
   Ternary t5(12212);
   cout << "t5 is " << t5 << endl;
   cout << "Enter a new value for t5: ";
   cin >> t5;
   cout << "t5 after cin >> t5 is: " << t5 << endl;

   cout << "\n Now testing overloaded += operator " << endl;
   cout << "t3 is " << t3 << " and t4 is " << t4 << endl;
   t3 += t4;
   cout << "After t3 += t4, t3 is " << t3 << " while t4 is still " << t4 <<endl;

   cout << "\n Now testing overloaded -= operator " << endl;
   cout << "t3 is " << t3 << " and t4 is " << t4 << endl;
   t3 -= t4;
   cout << "After t3 -= t4, t3 is " << t3 << " while t4 is still " << t4 <<endl;

   cout << "\n Now testing overloaded *= operator " << endl;
   cout << "t3 is " << t3 << " and t4 is " << t4 << endl;
   t3 *= t4;
   cout << "After t3 *= t4, t3 is " << t3 << " while t4 is still " << t4 <<endl;

   
   cout << "\n*******************************" << endl;
   cout << "Now testing unary - operator" << endl;
   cout << "t3 is " << t3 << endl;
   cout << "t4 is " << t4 << endl;
   t4 = -t3;
   cout << "After t4 = -t3, t4 is: " << t4 << " and t3 is still " << t3
	<< endl;

   cout << "\n*******************************" << endl;
   cout << "Now testing == operator" << endl;
   cout << "t3 is " << t3 << endl;
   cout << "t4 is " << t4 << endl;
   if(t3 == t4)
      cout << t3 << " is equal to " << t4 << endl;
   else
      cout << t3 << " is not equal to " << t4 << endl;
   
   cout << "\n*******************************" << endl;
   cout << "Now testing != operator" << endl;
   cout << "t3 is " << t3 << endl;
   cout << "t4 is " << t4 << endl;
   if(t3 != t4)
      cout << t3 << " is not equal to " << t4 << endl;
   else
      cout << t3 << " is not not equal to " << t4 << endl;
      
   cout << "\n*******************************" << endl;
   cout << "Now testing <= operator" << endl;
   cout << "t3 is " << t3 << endl;
   cout << "t4 is " << t4 << endl;
   if(t3 <= t4)
      cout << t3 << " is less than or equal to " << t4 << endl;
   else
      cout << t3 << " is not less than or equal to " << t4 << endl;
   
   cout << "\n*******************************" << endl;
   cout << "Now testing >= operator" << endl;
   cout << "t3 is " << t3 << endl;
   cout << "t4 is " << t4 << endl;
   if(t3 >= t4)
      cout << t3 << " is greater than or equal to " << t4 << endl;
   else
      cout << t3 << " is not greater than or equal to " << t4 << endl;
   
   cout << "\n*******************************" << endl;
   cout << "Now testing < operator" << endl;
   cout << "t3 is " << t3 << endl;
   cout << "t4 is " << t4 << endl;
   if(t3 < t4)
      cout << t3 << " is less than " << t4 << endl;
   else
      cout << t3 << " is not less than " << t4 << endl;
   
   cout << "\n*******************************" << endl;
   cout << "Now testing > operator" << endl;
   cout << "t3 is " << t3 << endl;
   cout << "t4 is " << t4 << endl;
   if(t3 > t4)
      cout << t3 << " is greater than " << t4 << endl;
   else
      cout << t3 << " is not greater than " << t4 << endl;
   
   return 0;
}
