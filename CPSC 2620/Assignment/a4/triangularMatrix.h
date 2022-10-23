//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Triangular Matrix class definition file
// Written by Quoc Ho
// Date: Nov 30, 2017
//********************************************************************
#ifndef TRIANGULAR_MATRIX_H
#define TRIANGULAR_MATRIX_H

#inlcude "structuredMatrix.h"

using namespace std;

class Triangular_Matrix:public Structured_Matrix
{
 public:
  Triangular_Matrix(int = 0; double = 0.0);
  virtual const double& operator()(int, int) const = 0; //pure virtual because
  // this abstract class does not need to implement this function

  virtual double& operator() (int, int) = 0; //pure virtual because this
  // abstract class does not need to implement this function
  
  virtual void read(); //virtual because this function will be used for
  // upper and lower triangularmatrices
  
  virtual void print() = 0; //pure virtual because this class does not need to
  // print out the array. Lower and upper triangular matrices will do the
  // printing
  
  virtual double infnorm() = 0; //pure virtual becuase this class does not need
  // to calculate the largest row sum. This is the job for lower and upper
  //triangular matrices

 private:
  double* arr;
  int dim;
  int numSize;
};
#endif
