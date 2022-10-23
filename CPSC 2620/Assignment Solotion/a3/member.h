//************************************************************************
// CPSC2620 Fall 2017 Prof: Shahadat
// Assignment #3
// Member class definition file
// Written by Arie
// Date: Nov. 8, 2017
//************************************************************************
#ifndef MEMBER_H
#define MEMBER_H

#include<string>
using namespace std;

class Member
{
  public:
   Member(); // Default constructor
   Member(string,char,size_t []);
   // Accessor Methods
   string getName() const;
   char whatSex() const;
   size_t numberHobbies() const;
   void showHobbies() const;
   void print() const;
   size_t getHob(size_t) const;
   void setStatus(int);
   int getStatus() const;

  private: //data members
   string name;
   char sex;
   size_t numHobbies;
   size_t hobbies[5];
   int status;
};

#endif
