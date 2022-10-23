//******************************
//CPSC 2620 - Fall 2017
//Assignment 3
//Inplementation of the member class
//Name: Quoc Ho
//Nov 10, 2017
//******************************
#include "./member.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//*******************************************
//Function:
//
//*******************************************
member::member()
{
}

//*******************************************
//Function:
//
//*******************************************
member::member(string nm, char gen, int hob[]):(name = nm, gender = gen,
						hobby[] = hob[])
{
  string nm;
  char gen;
  int hob[5];
  ifstream file;
  int numHobbies = 0;

  file.open("match.dat");
  if(file.is_open())
    {
      while(file >> nm >> gen >> hob[5]){
	  file >> setw(21) >> nm;
	  file >> gen;
	  for (int i = 0; i<5; i++)
	    {
	      file >> hob[i];
	      numHobbies++;
	    }
      }
      f1.close();
    }
  else
    cout << "Can not read match data!" << endl;
}

//*******************************************
//Function:
//
//*******************************************
member::getName const
{
  
