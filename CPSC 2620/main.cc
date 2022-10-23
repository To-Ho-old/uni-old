#include <iostream>
#include "rationalOB.h"

using namespace std;

int main(){
  Rational p,q, r; //testing the constructor Rational();
  cout << "p = ";
  p.insert(cout);
  cout << "  q = " ;
  q.insert(cout);
  cout << "  r = "; 
  r.insert(cout);
 cout << endl;

  Rational s(1,0); //testing the constructor Rational(int,int) for error input
  cout << "s = ";
  r.insert(cout) ; 
  cout << endl;
 
  Rational t(1,1); //testing the constructor Rational(int,int) for correct input
  cout << "t = ";
  t.insert(cout) ; 
  cout << endl;
 
  // testing extract, insert, and arithmetic operations 
  cout << "Enter a rational number (numerator denominator): ";
  p.extract(cin);
  cout << endl;
  cout << "Enter a rational number (numerator denominator): "; 
  q.extract(cin);

  r = p.plus(q);
  cout << "The sum of "; 
  p.insert(cout); 
  cout << " and " ;
  q.insert(cout); 
  cout << " is ";
  r.insert(cout);
 cout  << endl;
 
 r = p.minus(q);
  cout << "The difference of ";
  p.insert(cout);
  cout << " and " ;
  q.insert(cout);
  cout << " is ";
  r.insert(cout);
 cout  << endl;

 r = p.times(q);
  cout << "The product of ";
  p.insert(cout);
  cout << " and " ;
  q.insert(cout);
  cout << " is ";
  r.insert(cout);
 cout  << endl;

 r = p.divide(q);
  p.insert(cout);
  cout << " divided by  " ;
  q.insert(cout);
  cout << " is ";
  r.insert(cout);
 cout  << endl;
  return(0);
} 
