// ***************************************************************************
// CPSC2620 Fall 2017 Prof: Hossain
// Assignment 4
// Test file for Structured Matrix class
// Written by Arie Bomhof
// Date: Dec. 2017
// ***************************************************************************

#include<fstream>
#include<iostream>
#include<vector>
#include"symmetricMatrix.h"
#include"lowerMatrix.h"
#include"upperMatrix.h"

using namespace std;
// This function allows for polymorphic behaviour
void processStrMatrix(vector<StructuredMatrix *>);

int main()
{
   ifstream ins;
   ins.open("strMatrix.dat");
   vector<StructuredMatrix *> v;
   SymmetricMatrix *t1 = new SymmetricMatrix;// ,t2,t3,t4,t5,t6,t7;
   SymmetricMatrix *t2 = new SymmetricMatrix;// ,t2,t3,t4,t5,t6,t7;
   LowerMatrix *t3 = new LowerMatrix;
   UpperMatrix *t4 = new UpperMatrix;
   t1->read(ins);
   v.push_back(t1);
   t2->read(ins);
   v.push_back(t2);
   t3->read(ins);
   v.push_back(t3);
   t4->read();
   v.push_back(t4);
   processStrMatrix(v);
   ins.close();
   return 0;
}

void processStrMatrix(vector<StructuredMatrix *> sPtr)
{
   for(size_t i=0; i<sPtr.size(); i++)
   {
      cout << i+1 << ") ";
      sPtr[i]->print(cout);
      cout << "    Largest row sum is: " << sPtr[i]->infnorm() << endl;
   }
}
      
