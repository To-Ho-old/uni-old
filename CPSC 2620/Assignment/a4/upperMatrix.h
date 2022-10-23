//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Upper Triangular Matrix class definition file
// Written by Quoc Ho
// Date: Dec 2, 2017
//********************************************************************
#include "triangularMatrix.h"

using namespace std;

class Upper_Triangular_Matrix:public Triangular_Matrix
{
 public:
  Upper_Triangular_Matrix(int =0, double = 0.0);
  const double& operator()(int, int) const;
  double& operator() (int, int) = 0;
  void print();
  double infnorm();

 private:
  double* arr;
  int dim;
  int numSize;
};
// Example of mapping of a upper triangular matrix with a dimension of 4
// 0 1 2 3 
// 0 4 5 6
// 0 0 7 8
// 0 0 0 9
// using the indexing formular (dimesion*row) - ((row(row+1))/2) + column
