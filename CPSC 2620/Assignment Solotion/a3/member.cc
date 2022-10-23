//************************************************************************
// CPSC2620 Fall 2017 Prof: Shahadat
// Assignment #3
// Member class implementation file
// Written by Arie
// Date: Nov. 8, 2017
//************************************************************************
#include"member.h"
#include<iostream>
#include<iomanip>
using namespace std;

//***********************************************************************
// Defaut Member constructor
//***********************************************************************
Member::Member()
{
   name = "";
   sex = '\0';
   numHobbies = 0;
   status = -1;
}

//***********************************************************************
// Constructor given a name, sex, and array of hobbies
//***********************************************************************
Member::Member(string str, char s, size_t hobs[])
{
   name = str;
   sex = s;
   numHobbies = 0;
   for(size_t i=0; i<5; i++)
   {
      hobbies[i] = hobs[i];
      if(hobbies[i] != 1)
	 numHobbies++;
   }
   status = -1;
}

//***********************************************************************
// Return the name of current member
//***********************************************************************
string Member::getName() const
{
   return name;
}
//***********************************************************************
// Return the gender of current member
//***********************************************************************
char Member::whatSex() const
{
   return sex;
}
//***********************************************************************
// Return the number of hobbies of current member
//***********************************************************************
size_t Member::numberHobbies() const
{
   return numHobbies;
}

//***********************************************************************
// Return the status of current member
//***********************************************************************
size_t Member::getHob(size_t i) const
{
   return hobbies[i];
}

//***********************************************************************
// Return the status of current member
//***********************************************************************
int Member::getStatus() const
{
   return status;
}

//***********************************************************************
// Return the status of current member
//***********************************************************************
void Member::setStatus(int s)
{
   status = s;
}


//***********************************************************************
// Print the hobbies of the current member
//***********************************************************************
void Member::showHobbies() const
{
   cout << '[';
   for(size_t i=0; i<5; i++)
      cout << setw(2) << hobbies[i];
   cout << " ]" << endl;
}

//***********************************************************************
// Print details of current member
//***********************************************************************
void Member::print() const
{
   cout << "Name: " << getName() << endl;
   cout << "Sex: " << whatSex() << endl;
   cout << "Number of Hobbies: " << numberHobbies() << endl;
   cout << "Hobbies: ";
   showHobbies();
   cout << "Status: " << getStatus() << endl;
}
   
