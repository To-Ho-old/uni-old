// *************************************************************************
// Program to demonstrate inheritance and pointers to objects
// File: nonVirtual.cc
// $cs2620A/notes/inheritance/basic
// Author: Arie Bomhof
//
// Since the formal parameter of callPrint1 is of type Base class, only
// Base print() will be executed no matter if the actual parameter
// is of type Base or Derived .  This is because of compile time
// binding, or static binding.
// C++ corrects this problem by providing virtual functions.  The binding
// of virtual functions occurs at run-time, not compile-time. So we simply
// add the word "virtual" to the print function of the Base class.  We can also
// add it to the print function of DerivedClass but it is not necessary
//
// Base has 3 members
// Since Derived inherits from BaseClass it has 6 members, the 3 from
// Base and the 3 of its own.
// *************************************************************************
#include<iostream>
using namespace std;

class Base
{
   public:
      Base(int = 0);
      void print();
   private:
      int x;
};

class Derived : public Base
{
   public:
      Derived(int = 0, int = 0);
   //void print();  // hides Base's print()
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

//void Derived::print()
//{
//   cout << "Now in Derived print!!!" << endl;
//   Base::print();
//   cout << "In Derived class print: y is: " << y << endl;
//}

// non-member functions
void callPrint1(Base* b);
void callPrint2(Derived* d);

int main()
{
   Base* bPtr = new Base(5);
   Derived* dPtr = new Derived(2,-15);
   cout << "*******1*******" << endl;
   bPtr->print();

   cout << "*******2*******" << endl;
   dPtr->print();

   cout << "*******3*******" << endl;
   callPrint1(bPtr);

   cout << "*******4*******" << endl;
   // call non-member functions
   callPrint1(dPtr); // may pass derived object as base object

   cout << "*******5*******" << endl;;
   //callPrint2(b1); // may not pass base object to derived object
   callPrint2(dPtr);
   return 0;
}

void callPrint1(Base* b)
{
   b->print();
}

void callPrint2(Derived* d)
{
   d->print();
}

// Sample output:
//In Base class print: x is: 5

//Now in Derived print!!!
//In Base class print: x is: 2
//In Derived class print: y is: -15

//In Base class print: x is: 5

//In Base class print: x is: 2

//Now in Derived print!!!
//In Base class print: x is: 2
//In Derived class print: y is: -15
