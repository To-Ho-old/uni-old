//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Structured Matrix class implementation file
// Written by Quoc Ho
// Date: Nov 28, 2017
//********************************************************************
#include "structuredMatrix.h"
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

//*******************************************************************
// structured_matrix constructor given a dimension  numbers, and input
//*******************************************************************
Structured_Matrix::Structured_Matrix(int i, double value)
{
  dim = i;
  numSize = dim*dim;
  arr = new double[numSize+];
  arr[numSize] = 0;
  for (int a=0; a<numSize; a++)
    arr[a] = value;
}


//*******************************************************************
//Print the structured matrix
//*******************************************************************
void Structured_Matrix::print() const
{
  cout << "Structure Matrix:" << endl;
  for (int i = 0; i < numSize; i++)
    {
      cout << arr[i] << " ";
      if (((i+1)/dim) == 1)
	cout << endl;
    }
}

//*******************************************************************
//Read datas from user inputs
//*******************************************************************
void Structured_Matrix::read()
{
  cout << "Enter the value for array: " << end;
  for (int i =0; i < numSize; i++)
    {
      cout << "Index " << i << ": ";
      cin >> arr[i];
      cout << endl;
    }
}

//*******************************************************************
//Function to compute and return the largest row sum
//*******************************************************************
double Structured_Matrix::infnorm()
{
  double sum = 0;
  double temp = 0;
  for (int i = 0; i < numSize; i++)
    {
      temp = abs(arr[i]) + temp;
      if(((i+1)/dim)==1)
	{
	  if(temp>sum)
	    {
	      sum = temp;
	      temp = 0;
	    }
	  else
	    temp = 0;
	}
    }
  return sum;
}
