//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Upper Triangular Matrix class implementation file
// Written by Quoc Ho
// Date: Dec 2, 2017
//********************************************************************
#include "upperMatrix.h"

using namespace std;

//*******************************************************************
// Upper Triangular Matrix constructor given a dimension number, and input
//*******************************************************************
Upper_Triangular_Matrix::Upper_Triangular_Matrix(int i, double value)
{
  dim = i;
  numSize = (dim*(dim+1))/2;
  arr = new double [numSize+];
  arr[numSize]=0;
  for(int a = 0; a<dim; a++)
    arr[a] = value;
}

//*******************************************************************
// Indexing operator to work on const objects
//*******************************************************************
const double& Upper_Triangular_Matrix::operator() (int i, int j)
{
  int k;
  if ((i<dim) & (j<i))
    {
      cout << "Outside the size of index. Return 0.0" << endl;
      return arr[numSize];
    }
  else if((i<dim) & (j>=i) & (j<dim))
    {
      k = (dim*i) - ((i*(i+1))/2) + j;
    }
  else
    {
      cout << "Invalid row or column value!" <<endl;
      cout << "The structure has the dimension of " << dim << endl;
      cout << "Exiting....." << endl;
      exit(1);
    }
  return arr[k];
}

//*******************************************************************
// Indexing operator to work with non-const objects
//*******************************************************************
double& Upper_Triangular_Matrix::operator() (int i, int j)
{
   int k;
  if ((i<dim) & (j<i))
    {
      cout << "Outside the size of index. Return 0.0" << endl;
      return arr[numSize];
    }
  else if((i<dim) & (j>=i) & (j<dim))
    {
      k = (dim*i) - ((i*(i+1))/2) + j;
    }
  else
    {
      cout << "Invalid row or column value!" <<endl;
      cout << "The structure has the dimension of " << dim << endl;
      cout << "Exiting....." << endl;
      exit(1);
    }
  return arr[k];
}

//*******************************************************************
// Print function for Symmetric Matrix
//*******************************************************************
void Upper_Triangular_Matrix::print();
{
  int k;
  cout << "The Upper triangular matrix: " << endl;
  for(int r = 0; r<dim; r++)
    {
      for(int c =0; c<dim; c++)
	{
	  if (c<r)
	    {
	      cout << arr[numSize] << " "; //print 0
	    }
	  else if(c>=r)
	    {
	      k = (dim*i) - ((i*(i+1))/2) + j;
	      cout << arr[k] << " ";
	    }
	}
      cout << endl;
    }
}

//*******************************************************************
// Function to compute and return the absolute value of the largest
// row sum
//*******************************************************************
double Upper_Triangular_Matrix::infnorm()
{
  int k;
  double sum =0;
  double temp = 0;
  for(int r = 0; r<dim; r++)
    {
      for(int c = 0; c>=r; c++)
	{
	  k = (dim*r) - ((r*(r+1))/2) + c;
	  temp = abs(arr[k]) + temp;
	}
      if(temp >= sum)
	{
	  sum = temp;
	  temp = 0;
	}
      else
	temp = 0;
    }
  return sum;
}
