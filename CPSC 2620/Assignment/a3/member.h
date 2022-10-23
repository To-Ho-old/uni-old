//*********************************************************
//CPSC 2620 _Fall 2017
//Assignment 3
//File: member.h - interface file for the member class
//Name: Quoc Ho
//Date: Nov 20, 2017
//*********************************************************

#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <string>
using namespace std;

class member{
 public:
  member();
  member(string, char, int[]);
  getName const;
  print;
  setStatus(int);
  getStatus;

 private:
  string name;
  char gender;
  int numHobbies;
  int hobby[5];
  int status;
};

#endif
