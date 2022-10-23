//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Client Test file
// Written by Quoc Ho
// Date: Dec 3, 2017
//********************************************************************
#include<iostream>
#include"structuredMatrix.h"
#include"symmetricMatrix.h"
#inlcude"triangularMatrix.h"
#include"lowerMatrix.h"
#include"upperMatrix.h"
#include<fstream>
#include<string>
#include<vector>

using namespace std;

const int MAX = 20;

void process_str_matrix(vector<Structured_Matrix*>v);

int main()
{
  vector<string>v;

  Structured_Matrix *s0(3,3) = new Structured_Matrix;
  s0.print();
  s0.infnorm();
  
  Symmetric_Matrix *s1(3,5) = new Symmetric_Matrix;
  s1->print();
  s1->infnorm();
  
  Upper_Triangular_Matrix *u1(2,3) = new Upper_Triangular_Matrix;
  u1->print();
  u1->infnorm();
  Lower_Triangular_Matrix *l1(4,1) = new Lower_Triangular_Matrix;
  l1->print();
  l1->infnorm;

  Symmetric_Matrix *s2 = new Symmetric_Matrix;
  s2 -> read();
  v.push_back(s2);
  
  Upper_Triangular_Matrix u2 = new Upper_Triangular_Matrix;
  u2-> read();
  v.push_back(u2);
  
  Lower_Triangular_Matrix l2 = new Lower_Triangular_Matrix;
  l2->read();
  v.push_back(l2);

  process_str_matrix(v);

  return 0;		     
}

void process_str_matrix(Structured_Matrix *mtxPtr[])
{
  for (int i = 0; i<MAX; i++)
    {
      cout << v[i]->print() << endl;
      cout << "The largest row sum is: " << v[i]->infnorm() << endl;
    }
}
