#include <iostream>
#include "rationalv1.h"

using namespace std;

// Creates a Rational object when values for numerator and denominator 
// are not specified by the user. 
// Example use: 
//		Rational r; 
//				r is declared above to be a Rational variable 
//                          	(or object);  It causes a Rational object 
//				to be created by an implicit call to a 
//				constructor function that can be called without 
//				any parameter.  
//			    			    

Rational::Rational() {
   numerator = 0;
   denominator = 1;
}

// Creates a Rational object when values for numerator and denominator 
// are  specified by the user.            
// Example use:         
//              Rational r(1,2); 
//                              r is declared above to be a Rational variable
//                              (or object);  It causes a Rational object
//                              to be created by an implicit call to a 
//                              constructor function that takes two  
//                              parameters: the first actual parameter, 
//				1 in this example, is taken as the numerator
//				and the second actual parameter, 2 in this 
//				example, is taken as the denominator. 
//                           

Rational::Rational(int num, int den){
    if (den == 0)
      {
       denominator = 1;
       numerator = num;
       cout << "Error: zero(0) as denominator is llegal; using one(1) " 
	    << "instead" <<endl; 
      }
    else {
      numerator = num;
      denominator = den;
    }
} 

// Add the Rational number through which plus is called to the 
// Rational number passed as parameter and return the resulting 
// Rational number. 
// Example use:        
//				r1.plus(r2); 
//                          	r1 is added with r2 and the result is 
//				returned. 
 
Rational Rational::plus(const Rational& r) const{
  int c = r.numerator;
  int d = r.denominator;
  int a = numerator;
  int b = denominator;
  return Rational(a*d + b*c, b*d); // a Rational object whose 
				   // numerator is a*d + b*c and whose 
			           // denominator is b*d is created 
			           // by a constructor function call
				   // Rational(int,int)
				   // and the resulting number is 
				   // returned.
}

// Subtract the Rational number passed as parameter from the 
// Rational number  through which minus is called and 
// return the resulting Rational number. 
// Example use:        
//                              r1.minus(r2); 
//                              r2 is subtracted from r1 and the result is 
//                              returned.

Rational Rational::minus(const Rational&r) const{
  int c = r.numerator; 
  int d = r.denominator; 
  int a = numerator;
  int b = denominator;
  return Rational(a*d - b*c, b*d); 
} 

// Multiply  the Rational number through which times is called with the 
// Rational number passed as parameter and return the resulting 
// Rational number.
// Example use:        
//                              r1.times(r2); 
//                              r1 is multiplied  with r2 and the result is 
//                              returned.

Rational Rational::times(const Rational&r) const{
  int c = r.numerator; 
  int d = r.denominator; 
  int a = numerator;
  int b = denominator;
  return Rational(a*c, b*d); 
} 

// Divide the Rational number through which divide is called by the
// Rational number passed as parameter and return the resulting
// Rational number.
// Example use:        
//                              r1.divide(r2);
//                              r1 is divided by r2 and the result is
//                              returned.

Rational Rational::divide(const Rational&r) const{
  int c = r.numerator; 
  int d = r.denominator; 
  int a = numerator;
  int b = denominator;
  return Rational(a*d, b*c); 
} 

// Display the Rational number through which insert is called
// onto the computer screen (or other output device).
// Example use:        
//                              r.insert(cout);
//                              r is displayed as numerator / denominator 
//				to the standard output cout.

void Rational::insert(ostream& sout){
   if (denominator == 1){
     sout << numerator;
     return;
   }
   sout << numerator << '/' << denominator; 
   return;
} 

// Read  numererator and denominator from keyboard (or other input device) into 
// the  Rational number through which extract is called
// Example use:        
//                              r.extract(cout);
//                              r.numerator and r.denominator are 
//				replaced with the next two integers 
//				entered at the keyboard. 
//				
void  Rational::extract(istream& sin){
   sin >> numerator >> denominator;
   return;
}  


