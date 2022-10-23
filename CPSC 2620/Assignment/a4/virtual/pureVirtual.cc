// *************************************************************************
// Program to demonstrate pure virtual inheritance
// File: pureVirtual.cc
// $cs2620A/notes/inheritance/basic
// Author: Arie Bomhof
// 
// This program is essentially the same as yesVirtual.cc with a few minor
// differences.  The Base print fuction is now pure virtual, ie it is
// assigned "= 0". Base class is NOW an Abstract Class because it has at least
// on pure virtual function. This means that we cannot declare Base objects but
// we MAY declare pointer objects to Base class. Essentially Base's print
// function is meaningless so we do not implement it.
//**************************************************************************

#include<iostream>
using namespace std;

class Base // an abstract class b/c it has pure virtual function
{
   public:
      Base(int u = 0);
      virtual void print() = 0; // this means function is pure virtual
      // and we normally do not define this function.  Only the derived
      // classes need to define the print functions.  If a derived class does
      // not implement the print function it too becomes an abstract class
   protected: 
      int x;
};

Base::Base(int u) : x(u) {}

class Derived1 : public Base
{
   public:
      Derived1(int u = 0, int v = 0);
      /*virtual*/ void print(); // don't need "virtual" if BaseClass has it
      // and since we do not have " = 0" we know that we will need to define
      // this function.  If we do not define print() Derived1 also becomes
      // an abstract class.
   protected:
      int y;
};

Derived1::Derived1(int u, int v)
   :Base(u), y(v) {}

void Derived1::print()
{
   cout << "In Derived1: x = " << x << ", y = " << y << endl;
}

class Derived2 : public Derived1
{
   public:
      Derived2(int u = 0, int v = 0, int w = 0);
      /*virtual*/ void print(); // don't need "virtual" if Base class has it
      // and since we do not have " = 0" we know that we will need to define
      // this function
   private:
      int z;
};

Derived2::Derived2(int u, int v, int w)
   :Derived1(u,v), z(w) {}

void Derived2::print()
{
   cout << "In Derived2: x = " << x << ", y = " << y
	<< ", z = " << z << endl;
}

// non member function
void callPrint(Base* b)
{
   b->print(); // dynamic binding
}

int main()
{
   //Base b1; // can't do b/c Base is Abstract class
   Base* bPtr;  //but we can create a pointer object to a Base
   Derived1* d1Ptr;
   Derived2* d2Ptr;
   //bPtr = new Base(5); //can't do
   d1Ptr = new Derived1(12, -97);
   d2Ptr = new Derived2(5, -3, 14);
      
   //bPtr->print(); //can't do
   d1Ptr->print();

   cout << "Calling non-member function, print" << endl;

   //callPrint(b1); can't do
   callPrint(d1Ptr);
   callPrint(d2Ptr);
   //Since the formal parameter of callPrint is of type Base* the binding
   //occurs at run-time, not compile-time.
   bPtr = d1Ptr;
   callPrint(bPtr);
   return 0;
}
   
