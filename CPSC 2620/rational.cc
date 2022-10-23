#include <iostream>
#include "rational.h"

using namespace std;

Rational::Rational(int num, int den):numerator(num), denominator(den) {
    if (den == 0) {
       numerator = 0;
       denominator = 1;
       cerr << "Error: zero(0) as denominator is llegal; Rational object is initialized to zero (0)" 
	    << endl; 
      }
} 


void Rational::insert(ostream& sout) const{	
   if (denominator == 1){
     sout << numerator << endl;
   }
   else
      sout << numerator << '/' << denominator << endl; 
   return;
} 

void  Rational::extract(istream& sin){
   int den,num;
   sin >> num >> den;
   if (den == 0){ 
    cout <<"Error: zero(0) cannot be a denominator; object is unchanged " << endl;	
   } 
   else {
     numerator = num; denominator = den;
   }
   return;
}  

// Overloaded stream insertion operator. Note reference return of the modified stream. 

ostream& operator<<(ostream& sout, const Rational& s) {

   s.insert(sout);
   return sout;
}

// Overloaded stream extraction operator. Note reference return of the modified stream.

istream& operator>>(istream& sin, Rational& s) {
   s.extract(sin);
   return sin;
}

Rational& Rational::operator+=(const Rational& r){
       	numerator = numerator*r.denominator + denominator*r.numerator;
       	denominator = denominator*r.denominator;
       	return *this;
}     

Rational& Rational::operator+=(int i){ //mixed mode arithmetic - int argument
	numerator += denominator*i;
	return *this;
}

Rational& Rational::operator-=(const Rational& r){
	numerator = numerator*r.denominator - denominator*r.numerator;
	denominator = denominator*r.denominator;
	return *this;
}

Rational& Rational::operator-=(int i){
	numerator -= denominator*i;
	return *this;
}

Rational& Rational::operator*=(const Rational& r){
	numerator *= r.numerator;
	denominator *= r.denominator;
	return *this;
}

Rational& Rational::operator*=(int i){
	numerator *= i;
	return *this;
}

Rational& Rational::operator/=(const Rational& r){
	numerator *= r.denominator;
	denominator *= r.numerator;
	return *this;
}

Rational& Rational::operator/=(int i){
	denominator *= i;
	return *this;
}

Rational& Rational::operator++(){
        numerator += denominator;
        return *this;
} 

Rational& Rational::operator--(){
        numerator -= denominator;
        return *this;
}

Rational Rational::operator++(int){
        Rational temp(numerator,denominator);
        numerator += denominator;
        return temp;
}

Rational Rational::operator--(int){
        Rational temp(numerator,denominator);
        numerator -= denominator;
        return temp;
}

const Rational& operator+(const Rational &l, const Rational &r){
     Rational a = l;
     return a += r;	
}

const Rational& operator+(const Rational &l, int i){ //mixed-mode arithmetic: Rational+int
     Rational a = l;
     return a += i;
}

const Rational&  operator+(int i, const Rational &r){ // mixed-dode arithmetic: int + Rational 
     Rational a = r;
     return a += i;
}

const Rational&  operator-(const Rational &l, const Rational &r){
     Rational a = l;
     return a -= r;
}

const Rational&  operator-(const Rational &l, int i){
     Rational a = l;
     return a -= i;
}
 
const Rational&  operator-(int i, const Rational &r){
     Rational a = r;
     return a -= i;
}

const Rational&  operator*(const Rational &l, const Rational &r){
     Rational a = l;
     return a *= r;
}

const Rational&  operator*(const Rational &l, int i){
     Rational a = l;
     return a *= i;
}
 
const Rational&  operator*(int i, const Rational &r){
     Rational a = r;
     return a *= i;
}

const Rational&  operator/(const Rational &l, const Rational &r){
     Rational a = l;
     return a /= r;
}

const Rational&  operator/(const Rational &l, int i){
     Rational a = l;
     return a /= i;
}
 
const Rational&  operator/(int i, const Rational &r){
     Rational a = r;
     return a /= i;
}

