//************************************************************************
// CPSC2620 Fall 2017 Prof: Shahadat
// Assignment #3
// Match class definition file
// Written by Arie
// Date: Nov. 8, 2017
//************************************************************************
#ifndef MATCH_H
#define MATCH_H

#include"member.h"

class Match
{
   friend class Member;
  public:
   Match();
   ~Match();
   int getIndex(const string&, char) const; // function 1
   size_t push_back(const Member&); // function 2
   double compScore(const string&, const string&) const; // function 3
   int findMatch(const string&, double) const; // function 4
   bool updateStatus(const string&, size_t, double); // function 5
   void setAsSingle(const string&); // function 6
   void removeMember(const string&);  // function 7
   size_t numMales() const;
   size_t numFemales() const;
   string getMaleName(size_t) const;
   string getFemaleName(size_t) const;
   void print() const;
  private:
   Member* males; //dynamic array to store male members
   Member* fems;  //dynamic array to store female members
   size_t capM; //capacity of male list
   size_t capF; //capacity of female list
   size_t sizeM; //number of males
   size_t sizeF; //number of females
   char findSex(const string&) const; // private helper function
   
};

// Dynamically add capacity to either the males array or the females array.
// The second and third parameters are the size and capacity of each of the
// given array. Capacity is increased by 3.
void addCapacity(Member*&, size_t, size_t&);

#endif
