#include <iostream>
#include "rational.h"

using namespace std;

Rational::Rational(int num, int den):numerator(num), denominator(den) {
    if (den == 0) {
       numerator = 0;
       denominator = 1;
       cerr << "Error: zero(0) as denominator is llegal; Rational object is initialized to zero (0)" 
	    << endl; 
        return;
      }
      int m = abs(numerator); int n = abs(denominator);
      int d = gcd(m,n);
      numerator = numerator/d;
      denominator = denominator/d;
      return;
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
      reduce(num,den);
/*
     int n = abs(num);
     int m = abs(den);
     int d = gcd(n,m);
     numerator = num/d; denominator = den/d;
 */    
   }
   return;
}  

void Rational::reduce(int p, int q){
   int n = abs(p);
     int m = abs(q);
     int d = gcd(p,q);
     numerator = p/d; denominator = q/d;
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
       	int num = numerator*r.denominator + denominator*r.numerator;
       	int den = denominator*r.denominator;
        reduce(num,den);
/*
         int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
       	 return *this;
}     

Rational& Rational::operator+=(int i){ //mixed mode arithmetic - int argument
	numerator += denominator*i;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
	return *this;
}

Rational& Rational::operator-=(const Rational& r){
	numerator = numerator*r.denominator - denominator*r.numerator;
	denominator = denominator*r.denominator;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
	return *this;
}

Rational& Rational::operator-=(int i){
	numerator -= denominator*i;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
	return *this;
}

Rational& Rational::operator*=(const Rational& r){
	numerator *= r.numerator;
	denominator *= r.denominator;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
	return *this;
}

Rational& Rational::operator*=(int i){
	numerator *= i;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
	return *this;
}

Rational& Rational::operator/=(const Rational& r){
	numerator *= r.denominator;
	denominator *= r.numerator;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
	return *this;
}

Rational& Rational::operator/=(int i){
	denominator *= i;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
	return *this;
}

Rational& Rational::operator++(){
        numerator += denominator;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
        return *this;
} 

Rational& Rational::operator--(){
        numerator -= denominator;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
        return *this;
}

Rational Rational::operator++(int){
        Rational temp(numerator,denominator);
        numerator += denominator;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
        return temp;
}

Rational Rational::operator--(int){
        Rational temp(numerator,denominator);
        numerator -= denominator;
        int num = numerator;
        int den = denominator;
        reduce(num,den);
/*
        int n = abs(num);
         int m = abs(den);
         int d = gcd(n,m);
         numerator = num/d; denominator = den/d;
*/
        return temp;
}

const Rational& operator+(const Rational &l, const Rational &r){
     Rational a = l;
     return a+= r;	

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

int Rational::gcd(int m, int n){
   if (m < n) {
        int temp = m;
        m = n;
        n = temp;
      }
   int a = m, b=n;
   int r = a%b;
   while (r > 0){
      a = b;
      b = r;
      r = a%b;
   }
   return b;
}

bool Rational::operator<(const Rational &r){
 int m = (*this).denominator*r.denominator; 
 Rational tl = (*this)*m;
 Rational tr = r*m;
 return (tl.numerator < tr.numerator);  
}

bool Rational::operator<=(const Rational &r){
  return (((*this) < r) || ((*this) == r));
}
bool Rational::operator>(const Rational &r){
 int m = (*this).denominator*r.denominator;
 Rational tl = (*this)*m;
 Rational tr = r*m;
 return (tl.numerator > tr.numerator);
}

bool Rational::operator>=(const Rational &r){
  return (((*this) > r) || ((*this) == r));
}

