/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 4
*/

//Header file for RPNCalc

#ifndef RPNCALC_H
#define RPNCALC_H
#include "GenStack.h"
#include <iostream>
using namespace std;

class RPNCalc{
public:
  RPNCalc(); //constructor
  ~RPNCalc(); //destructor
  float calculateVal(string inString); //calculate value given string in RPN separated by spaces
};

#endif
