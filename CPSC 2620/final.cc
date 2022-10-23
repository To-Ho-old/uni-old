#include <iostream>
#include <string>
using namespace std;
class bClass
{
public:
bClass(string data = "bClassData"):bs(data) {};
virtual void Display()
{
cout << "In bClass::Display() ";
cout << "bs = " << bs << endl;
};
void Print()
{
cout << "In bClass::Print() ";
cout << "bs = " << bs << endl;
}
private:
string bs;
};
class dClassOne : public bClass
{
public:
dClassOne(string data = "dClassOneData"):d1s(data) {};
virtual void Display()
{
cout << " In dClassOne::Display()";
bClass::Display();
cout << " d1s = " << d1s << endl;
7
};
void Print()
{
cout << " In dClassOne::Print()";
bClass::Print();
cout << " d1s = " << d1s << endl;
}
private:
string d1s;
};
class dClassTwo : public bClass
{
public:
dClassTwo(string ddata = " dClassTwoData ", string bdata= " bClassDataFromD2 ")
:bClass(bdata), d2s(ddata) {};
virtual void Display(int i)
{
cout << " In dClassTwo::Display()";
bClass::Display();
cout << " d2s = " << d2s << " i = " << i << endl;
};
private:
string d2s;
};
void Output( bClass &R)
{
R.Display();
}
int main()
{
bClass A("Object A");
dClassOne B("Object B");
dClassTwo C("Object C", "Object C ( ObjectC_A ) ");
bClass *Ptr;
Ptr = &B;
Ptr->Display();
Output(A);
Output(B);
A = B;
A.Display();
8
Ptr = &B;
Ptr->Print();
C.Display(3);
Ptr = &C;
Ptr->Display();
return 0;
}
