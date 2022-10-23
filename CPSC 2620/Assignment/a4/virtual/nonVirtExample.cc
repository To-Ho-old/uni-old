// *************************************************************************
// Program to demonstrate inheritance
// File: personEmployee.cc
// $cs2620A/notes/inheritance/basic
// Author: Arie Bomhof
// Note: This program demonstrates inheritance without virtual functions
// *************************************************************************
#include<iostream>
#include<string>
using namespace std;

class Person
{
   public:
      Person(const string& n);
      string getName() const;
      void writeInfo() const;
   private:
      string name;
};

Person::Person(const string& n) : name(n) {}

string Person::getName() const
{
   return name;
}

void Person::writeInfo() const
{
   cout << name;
}

class Employee : public Person
{
   public:
      Employee(const string& n, double s);
      double getSalary() const;
      void writeInfo() const;
   private:
      double salary;
};

Employee::Employee(const string& n, double s)
   : Person(n), salary(s) {}

double Employee::getSalary() const
{
   return salary;
}

// Since writeInfo overrides Person's writeInfo any call to an employee's
// write info would call only the version for Employee unless we you explicitly
// call Person's writeInfo() as below.
void Employee::writeInfo() const
{
   Person::writeInfo(); 
   cout << endl;
   cout << salary;
}


int main()
{
   Employee* ePtr;
   Person *pPtr = new Person("Jim");
   Person p1("Mary Black");
   Employee e1("Joe Blow", 53.34);
   ePtr = &e1;
   pPtr = ePtr; //you can assign a derived obj to a base obj but you lose info
   pPtr->writeInfo();
   cout << endl;
   ePtr->writeInfo();
   cout << endl;
   //ePtr = pPtr; //bad...can't assign base obj to a derived obj
   cout << pPtr->getName() << endl; // Ok
   //cout << pPtr->getSalary() << endl; //bad Person is not necessarily an Empl.
   f f1;
   g g1;
   f1.write_stuff();
   g1.setNum(5);
   //cout << g1.getNum() << endl;
   g1.write_stuff();
   g h1(g1); //default copy constructor;
   h1.write_stuff();
   f1 = h1;
   f1.write_stuff();
   return 0;
}

