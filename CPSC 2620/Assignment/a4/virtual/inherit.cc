// Program to demonstrate inheritance and polymorphism
#include<iostream>
using namespace std;
class Base
{
public:
   virtual void who() const = 0;
   //{
   //cout << "Base" << endl;
   //}
   virtual void what()const = 0;
   //{
   //cout<< "Top"<<endl;
   //}
};

class Derived1 : public Base
{
public:
   void who() const
   {
      cout << "Derived1" << endl;
   }
   void what() const
   {
      cout<<"Middle"<<endl;
   }
};

class Derived2 : public Derived1
{
public:
   void who() const
   {
      cout <<"Derived2"<<endl;
   }
   void what() const
   {
      cout <<"Bottom" << endl;
   }
};
void showMe(const Base& type)
{
   cout << "Now in \"showMe\"" <<endl;
   type.who();
   type.what();
}

int main()
{
   //Base b;
   Derived1 d1;
   Derived2 d2;
   
   //b.who();
   //b.what();
   //showMe(b);
   //cout << endl;
   
   d1.who();
   d1.what();
   showMe(d1);
   cout << endl;
   
   d2.who();
   d2.what();
   showMe(d2);
   cout << endl;
   
   Base* bPtr;
   bPtr=&d2;
   bPtr->who();
   bPtr->what();
   //showMe(bPtr); //can't do b/c bPtr is not a base object
   return 0;
}
   
   
