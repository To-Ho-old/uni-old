//************************************************************************
// CPSC2620 Fall 2017 Prof: Shahadat
// Assignment #3
// Match class test file
// Written by Arie
// Date: Nov. 8, 2017
//************************************************************************
#include<iostream>
#include"member.h"
#include"match.h"
#include<iostream>
#include<fstream>
using namespace std;

void loadMatch(istream&, Match&);
const double COMPATABILITY_THRESHHOLD = 0.6;
int main()
{
   ifstream ins;
   ins.open("match.dat");
   Match match1;
   loadMatch(ins,match1);
   int index;
   index = match1.getIndex("Vicky",'F');
   cout << "Vicky is at index: " << index << endl;
   index = match1.getIndex("Cam",'M');
   cout << "Cam is at index: " << index << endl;
   double cS = match1.compScore("Sam", "Janet");
   cout << "Compatability Score for Sam and Janet is: " << cS << endl;

   index = match1.findMatch("Karen",COMPATABILITY_THRESHHOLD);
   if(index >= 0)
      cout << "Karen's match is " << index << endl;
   else
      cout << "Karen has no match." << endl;

   index = match1.findMatch("Arnold",COMPATABILITY_THRESHHOLD);
   if(index >= 0)
      cout << "Arnolds's match is " << index << endl;
   else
      cout << "Arnold has no match." << endl;

   for(size_t i=0; i<match1.numMales(); i++)
   {
      string n = match1.getMaleName(i);
      size_t j = 0;
      while(!(match1.updateStatus(n,j,COMPATABILITY_THRESHHOLD)) &&
	    j < match1.numFemales())
	 j++;
      if(j < match1.numFemales())
	 cout << n << " is matched with " << match1.getFemaleName(j)
	   << endl;
      else
	 cout << n << " has no match."  << endl; 
   }
   match1.setAsSingle("Sam");   
   match1.removeMember("John");
   match1.removeMember("Bill");
   match1.removeMember("Wendy");
   match1.print();
 
   
   return 0;
}

// Function to create and load Members into Match object
// Member data is coming from data file called match.dat
void loadMatch(istream& iStr, Match& m)
{
   string name;
   char sex;
   size_t hobby[5];
   iStr >> name;
   while(!iStr.eof())
   {
      iStr >> sex;
      for(size_t i=0; i<5; i++)
	 iStr >> hobby[i];
      m.push_back(Member(name,sex,hobby));
      iStr >> name;
   }
}
		     
