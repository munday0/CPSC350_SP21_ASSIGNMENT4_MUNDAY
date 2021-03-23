/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 4
*/

//Header file for DNAComplement

#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H
#include "GenStack.h"

class DNAComplement{
public:
  DNAComplement(); //constructor
  ~DNAComplement(); //destructor
  GenStack<string> complementStack(string compConvert); //helper function; takes string input, converts to stack

  string Complement(string compConvert); //calculates the complement of DNA string
  string RevComplement(string revConvert); //calculates the reverse complement of DNA string
private:
  GenStack<string> stack;
};

#endif
