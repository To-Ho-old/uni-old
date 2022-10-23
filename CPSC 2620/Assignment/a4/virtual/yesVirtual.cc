// *************************************************************************
// Program to demonstrate virtual inheritance
// File: yesVirtual.cc
// $cs2620A/notes/inheritance/basic
// Author: Arie Bomhof
// 
// This program is essentially the same as nonVirtual.cc with a few minor
// differences.  There is only one non-member callPrint function.  We can
// pass it any object, Base or Derived, and since the print function is virtual
// we get dynamic (run time) binding.  When we pass a Base object it calls
// Base's print and when we pass a Derived object we get Derived's print.
//
// Note: Base is NOT an Abstract Class because it is not pure virtual.
// *************************************************************************
#include<iostream>
using namespace std;

class Base
{
  public:
      Base(int = 0);
      virtual void print(); 
   private:
      int x;
};

class Derived : public Base
{
   public:
      Derived(int = 0, int = 0);
      virtual void print(); // "virtual" not required
   private:
      int y;
};

Base::Base(int i) : x(i) {}

void Base::print()
{
   cout << "In Base class print: x is: " << x << endl;
}

Derived::Derived(int i, int j)
   : Base(i), y(j) {}

void Derived::print()
{
   cout << "Now in Derived print!!!" << endl;
   Base::print();
   cout << "In Derived class print: y is: " << y << endl;
}

// non-member function
void callPrint(Base* b);

int main()
{
   Base* bPtr = new Base(93);
   Derived* dPtr = new Derived(2,-15);
   bPtr->print(); cout << endl; // we call Base's print
   dPtr->print(); cout << endl; // we call Derived's print

   // call non-member functions
   callPrint(bPtr); // actual argument is b1, formal parameter is ptr to Base
   cout << endl;
   callPrint(dPtr); // actual argument is d1, formal parameter is ptr to Base
   
   delete bPtr; delete dPtr; bPtr=NULL; dPtr=NULL; 
   return 0;
}


void callPrint(Base* b)
{
   // The first callPrint is obvious
   // The second callPrint is surprising! The actual argment is a Derived object
   // and passed to a Base object.  Since Base's print function is virtual
   // the actual function to be called is decided during run time.  If Base's
   // print function is NOT virtual the function to be called is decided at
   // compile time.
   b->print();
}
   
// Sample output:
// In Base class print: x is: 93

// Now in Derived print!!!
// In Base class print: x is: 2
// In Derived class print: y is: -15

// In Base class print: x is: 93

// Now in Derived print!!!
// In Base class print: x is: 2
// In Derived class print: y is: -15
