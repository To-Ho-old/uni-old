//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Lower Triangular Matrix class definition file
// Written by Quoc Ho
// Date: Dec 2, 2017
//********************************************************************
#include "triangularMatrix.h"

using namespace std;

class Lower_Triangular_Matrix:public Triangular_Matrix
{
 public:
  Lower_Triangular_Matrix(int =0, double = 0.0);
  const double& operator()(int, int) const;
  double& operator() (int, int) = 0;
  void print();
  double infnorm();

 private:
  double* arr;
  int dim;
  int numSize;
};

// Example of mapping a lower triangular matrix with a dimension of 4
// 0 0 0 0
// 1 2 0 0
// 3 4 5 0
// 6 7 8 9
// using indexing formular (row(row+1))/2
