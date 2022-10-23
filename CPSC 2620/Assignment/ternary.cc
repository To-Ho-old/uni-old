#include <iostream>
#include <cmath>
#include "ternary.h"

using namespace std;

Ternary::Ternary(){
   decimal_equivalent = 0;
}

Ternary::Ternary(int ternary){
   {
      int temp = abs(ternary);
      int de_eq = 0;
      int i = 0;
      
      while(ternary>0){
	int r = temp%10;
	 if(r>2){
	    cout << "Error!!!";
	    decimal_equivalent = 0;
	 }
	 else{
	   de_eq = de_eq + (r*(3^i));
	    i=i+1;
	    temp = temp/10;
	 }
      }
      decimal_equivalent = de_eq;
   }
}

Ternary Ternary::plus(const Ternary& t) const{
   int t1 = decimal_equivalent;
   int t2 = t.decimal_equivalent;
   return Ternary(t1+t2);
}

Ternary Ternary::minus(const Ternary& t) const{
   int t1 = decimal_equivalent;
   int t2 = t.decimal_equivalent;
   return Ternary(t1-t2);
}

Ternary Ternary::times(const Ternary& t) const{
   int t1 = decimal_equivalent;
   int t2 = t.decimal_equivalent;
   return Ternary(t1*t2);
}

void Ternary::insert(ostream& sout){
   sout << decimal_equivalent;
   return;
}

void Ternary::extract(istream& sin){
   sin >> decimal_equivalent;
   return;
}
         
   
