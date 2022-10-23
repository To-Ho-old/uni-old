//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Triangular Matrix class implementation file
// Written by Quoc Ho
// Date: Nov 30, 2017
//********************************************************************
#include "triangularMatrix.h"

using namespace std;

//*******************************************************************
// Triangular Matrix constructor given a dimension number, and input
//*******************************************************************
Triangular_Matrix::Triangular_Matrix(int i, double value)
{
  dim = i;
  numSize = (dim*(dim+1))/2;
  arr = new double [numSize+];
  arr[numSize] = 0;
  for(int a = 0; a<dim; a++)
    arr[a] = value;
}

//*******************************************************************
// Function to read triangular matrix value input by user
//*******************************************************************
void Triangular_Matrix::read()
{
  cout << "Enter the value for array: " << endl;
  for (int i = 0; i < numSize; i++)
    {
      cout << "Index " << i << ": ";
      cin >> arr[i];
      while(arr[i] == 0)
	{
	  cout << endl << "Can not enter 0!" << endl;
	  cout << "Enter the value for index " << i << ": ";
	  cint >> arr[i];
	}
      cout << endl;
    }
}
      

