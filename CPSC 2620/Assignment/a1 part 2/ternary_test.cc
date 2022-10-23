//********************************************************************
//CPSC 2620 - Fall 2017
//Assignment 1 part 2
//Client program to test the Ternary class
//Name: Quoc Ho
//Date: Oct 11, 2017
//********************************************************************

#include <iostream>
#include "ternary.h"

using namespace std;

int main()
{
  Ternary t1;
  Ternary t2(02512); //This should produce error massage
  cout << "t1 is: " << t1 << endl;
  cout << "t2 is: " << t2 << endl;

  Ternary t3(221);
  Ternary t4(112);
  cout << "t3 is: " << t3 << endl;
  cout << "t4 is: " << t4 << endl;

  cout <<"\n*********************************************" << endl;
  cout << "Now testing the += overloaded operator" << endl;
  cout << "t3 is: " << t3 << endl;
  cout << "t4 is: " << t4 << endl;
  t3 += t4; //t3 should change but not t4.
    cout << "After t3 += t4, t3 is: " << t3 << " and t4 is still "
	 << t4 << endl;

  cout <<"\n*********************************************" << endl;
  cout << "Now testing the -= overloaded operator" << endl;
  cout << "t3 is: " << t3 << endl;
  cout << "t4 is: " << t4 << endl;
  t4 -= t3; //t4 should change but not t3.
    cout << "After t4 -= t3, t4 is: " << t4 << " and t3 is still "
	 << t3 << endl;

  cout <<"\n*********************************************" << endl;
  cout << "Now testing the *= overloaded operator" << endl;
  cout << "t3 is: " << t3 << endl;
  cout << "t4 is: " << t4 << endl;
  t3 *= t4; //t3 should change but not t4.
    cout << "After t3 *= t4, t3 is: " << t3 << " and t4 is still "
	 << t4 << endl;

  cout <<"\n***********************************************" << endl;
  cout << "Now testing the unary - overloaded operator" << endl;
  cout << "t3 is: " << t3 << endl; 
  cout << "t4 is " << t4 << endl;
  t4 = -t3; // t4 should change but not t3.
  cout << "After t4 = -t3, t4 is: " << t4 << " and t3 is still " << t3
       << endl;

  cout <<"\n***********************************************" << endl;
  Ternary t6(112);
  Ternary t7(221);
  cout << "t6 is: " << t6 << endl;
  cout << "t7 is: " << t7 << endl;
  cout <<"\n***********************************************" << endl;
  cout << "Now testing Overloaded Boolean equality operator" << endl;
  if(t6 == t7)
    cout << "t6 is equal t7" << endl;
  else
    cout << "t6 is not equal t7" << endl;

  cout <<"\n***********************************************" << endl;
  cout << "Now testing Overloaded Boolean not equal operator" << endl;
  if(t6 != t7)
    cout << "t6 is not equal t7" << endl;
  else
    cout << "t6 is equal t7" << endl;

  cout <<"\n***********************************************" << endl;
  cout << "Now testing Overloaded Boolean less-than operator" << endl;
  if(t6 < t7)
    cout << "t6 is less than t7" << endl;
  else
    cout << "t6 is greater than or equal t7" << endl;

  cout <<"\n***********************************************" << endl;
  cout << "Now testing Overloaded Boolean less-than-or-equal operator" << endl;
  if(t6 <= t7)
    cout << "t6 is less than or equal t7" << endl;
  else
    cout << "t6 is greater t7" << endl;
  
  cout <<"\n***********************************************" << endl;
  cout << "Now testing Overloaded Boolean greater-than operator" << endl;
  if(t6 > t7)
    cout << "t6 is greater than t7" << endl;
  else
    cout << "t6 is less than or equal t7" << endl;

  cout <<"\n***********************************************" << endl;
  cout << "Now testing Overloaded Boolean greater-than-or-equal operator"
       << endl;
  if(t6 >= t7)
    cout << "t6 is greater than or equal t7" << endl;
  else
    cout << "t6 is less than t7" << endl;

  Ternary t5(-021102);
  cout << "t5 is: " << t5 << endl;
  cout << "Enter a new value for t5: ";
  cin >> t5;
  cout << "The new t5 is: " << t5 << endl;

  return 0;
}
  



  
