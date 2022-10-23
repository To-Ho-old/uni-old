//************************************************************************
// CPSC2620 Fall 2017 Prof: Shahadat
// Assignment #3
// Match class implementation file
// Written by Arie
// Date: Nov. 8, 2017
//************************************************************************

#include"match.h"
#include"member.h"
#include<iostream>
#include<cmath>
using namespace std;

//***********************************************************************
// Defaut Match constructor
//***********************************************************************
Match::Match()
{
   capM = 5;
   sizeM = 0;
   capF = 5;
   sizeF = 0;
   males = new Member[capM];
   fems = new Member[capF];
}

//***********************************************************************
// Destructor
//***********************************************************************
Match::~Match()
{
   delete [] males;
   delete [] fems;
   males = nullptr;
   fems = nullptr;
}

//***********************************************************************
// Function 1
// Find the index of name in the array of names
//***********************************************************************
int Match::getIndex(const string& name, char s) const
{
   int index = 0;
   if(s == 'M')
   {
      while(name != males[index].getName()&& static_cast<size_t>(index) < sizeM)
	 index++;
      if(static_cast<size_t>(index) < sizeM)
	 return index;
   }
   else if(s == 'F')
   {
      while(name != fems[index].getName() && static_cast<size_t>(index) < sizeF)
	 index++;
      if(static_cast<size_t>(index) < sizeF)
	 return index;
   }
   return -1; // name could not be found
}     

//***********************************************************************
// Function 2
// Add new member, m, to the list
//***********************************************************************
size_t Match::push_back(const Member& m)
{
   char gender = m.whatSex();
   if(gender == 'M')
   {
      if(sizeM == capM)
	 addCapacity(this->males,this->sizeM,this->capM);
      males[sizeM++] = m;
      return sizeM;
   }
   else
   {
      if(sizeF == capF)
	 addCapacity(this->fems,this->sizeF,this->capF);
      fems[sizeF++] = m;
      return sizeF;
   }
}

//***********************************************************************
// Function 3
// Compute the compatability score between s1 and s2
//***********************************************************************
double Match::compScore(const string& s1, const string& s2) const
{
   int index1 = getIndex(s1,'M');
   int index2 = getIndex(s2,'F');
   double compatabilityScore;
   double num = 0, den1 = 0, den2 = 0, den3;
   if(index1 >= 0 && index2 >= 0)
   {
      for(int i=0; i<5; i++)
      {
	 num += males[index1].getHob(i) * fems[index2].getHob(i);
	 den1 += pow(static_cast<double>(males[index1].getHob(i)),2.0);
	 den2 += pow(static_cast<double>(fems[index2].getHob(i)),2.0);
      }
      den3 = sqrt(den1) * sqrt(den2);
      if(den3 > 0)
	 compatabilityScore = num/den3;
      else
	 compatabilityScore = 0.0;
   }
   else // either one or both names do not exist
      compatabilityScore = 0.0;
   return compatabilityScore;
}

//***********************************************************************
// Function 4
// Search the list of members of the opposite sex of n and return the index
// of the first member such the the compatability score between n and the
// member in the list is >= to threshhold score, std.
//***********************************************************************
int Match::findMatch(const string& n, double std) const
{
   double cptScore = 0.0;
   size_t index;
   if(findSex(n) == 'M')
   {
      index = 0;
      do
      {
	 cptScore = compScore(n,fems[index].getName());
	 //cout <<n<< "'s cptScore with " << fems[index].getName() << " is " 
	 //<< cptScore << endl;
	 if(cptScore >= std)
	    return static_cast<int>(index);
	 index++;
      }
      while(index < sizeM);
   }
   else
   {
      index = 0;
      do
      {
	 cptScore = compScore(males[index].getName(),n);
	 //cout <<n<< "'s cptScore with " << males[index].getName() << " is " 
	 //<< cptScore << endl;
	 if(cptScore >= std)
	    return static_cast<int>(index);
	 index++;
      }
      while(index < sizeF);
   }
   return -1; // could not find n if we get here
}

//***********************************************************************
// Function 5
// Updates the status of n and the member at index in the member list of the
// opposite sex if the compatability score is greater than or equal to
// the thresh hold score, std.
// We don't update the member of the opposite sex nor n's if the member of
// the opposite sex is already matched.
//***********************************************************************
bool Match::updateStatus(const string& n, size_t index, double std)
{
   double cptScore;
   char s = findSex(n);
   if(s == 'M')
   {
      cptScore = compScore(n,fems[index].getName());
      if(cptScore > std && fems[index].getStatus() == -1)
      {
	 size_t ind = getIndex(n,'M');
	 males[ind].setStatus(index);
	 fems[index].setStatus(static_cast<int>(ind));
	 return true;
      }
   }
   else if(s == 'F')
   {
      cptScore = compScore(males[index].getName(),n);
      if(cptScore > std && fems[index].getStatus() == -1 )
      {
	 size_t ind = getIndex(n,'F');
	 fems[ind].setStatus(index);
	 males[index].setStatus(static_cast<int>(ind));
	 return true;
      }
   }
   else
      cout << n << " could not be found." << endl;
   return false;
}
//***********************************************************************
// Function 6
// Set str's and str's matched partner's status back to single (-1) again.
//***********************************************************************
void Match::setAsSingle(const string& str)
{
   size_t index;
   int sts;
   char s = findSex(str);
   if(s == 'M')
   {
      index = getIndex(str,'M');
      sts = males[index].getStatus(); //get this guy's status
      if(sts != -1)
      {
	 // look for the girl whose status is this guy's index
	 for(size_t i=0; i<numFemales(); i++)
	    if(fems[i].getStatus() == static_cast<int>(index))
	    {
	       fems[i].setStatus(-1); // set the girl's status back to -1
	       break; // done, get out of loop
	    }
	 males[index].setStatus(-1); // set this str's status back to -1
      }
   }
   else if(s == 'F')
   {
      index = getIndex(str,'F');
      sts = fems[index].getStatus(); //get this girl's status
      if(sts != -1)
      {
	 // look for the guy whose status is this girl's index
	 for(size_t i=0; i<numMales(); i++)
	    if(males[i].getStatus() == static_cast<int>(index))
	    {
	       males[i].setStatus(-1);
	       break;
	    }
	 fems[index].setStatus(-1);
      }
   }
   else
      cout << str << " could not be found" << endl;
}      
      
//***********************************************************************
// Function 7
// Remove a name if it exists 
//***********************************************************************
void Match::removeMember(const string& str)
{
   int index;
   char s = findSex(str);
   if(s == 'M')
   {
      index = getIndex(str,'M');
      if(index != -1)
      {
	 //Found str as a male.  Now overwrite with next person and so on.
	 for(size_t i=static_cast<size_t>(index); i<sizeM-1; i++)
	       males[i] = males[i+1];
	 sizeM--;
      }
   }
   else if(s == 'F')
   {
      index = getIndex(str,'F');
      if(index != -1)
      {
	 for(size_t i=static_cast<size_t>(index); i<sizeF-1; i++)
	       fems[i] = fems[i+1];
	 sizeF--;
      }
   }
   cout << str << " could not be found." << endl;
}      
      
//***********************************************************************
// Print the male and female members of this match object 
//***********************************************************************
void Match::print() const
{
   cout << "Males: " << endl;
   for(size_t i=0; i<sizeM; i++)
   {
      males[i].print();
      cout << endl;
   }
   cout << "\nFemales: " << endl;
   for(size_t i=0; i<sizeF; i++)
   {
      fems[i].print();
      cout << endl;
   }
}

//***********************************************************************
// Private helper function
// Find the sex of a given member name.
// Returns 'M' if male and 'F' if female.  If n does not exist the null
// character is returned.
//***********************************************************************
char Match::findSex(const string& n) const
{
   size_t index = 0;
   while(n != males[index].getName() && static_cast<size_t>(index) < sizeM)
      index++;
   if(static_cast<size_t>(index) < sizeM)
      return males[index].whatSex();
   //if we get here then n was not a male now check to see if female
   index = 0;
   while(n != fems[index].getName() && static_cast<size_t>(index) < sizeF)
      index++;
   if(static_cast<size_t>(index) < sizeF)
      return fems[index].whatSex();
   return '\0'; // if we get here n could not be found
}

//***********************************************************************
// return number of males in male list
//***********************************************************************
size_t Match::numMales() const
{
   return sizeM;
}

//***********************************************************************
// return number of females in female list
//***********************************************************************
size_t Match::numFemales() const
{
   return sizeF;
}

//***********************************************************************
// Return the name of male at index i
//***********************************************************************
string Match::getMaleName(size_t i) const
{
   return males[i].getName();
}

//***********************************************************************
// Return the name of female at index i
//***********************************************************************
string Match::getFemaleName(size_t i) const
{
   return fems[i].getName();
}

//***********************************************************************
// non-member to add capacity to either the male array or the female array
// The second and third parameters are the size and capacity of the respctive
// arrays.  
//***********************************************************************
void addCapacity(Member*& arr, size_t size, size_t& cap)
{
   cap += 3;
   Member *temp = arr;
   arr = new Member[cap];
   for(size_t i = 0; i<size; i++)
      arr[i] = temp[i];
   delete [] temp;
   temp = 0;
}
   
   
