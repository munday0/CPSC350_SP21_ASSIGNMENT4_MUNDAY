/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 4
*/

//Cpp file for DNAComplement

#include "DNAComplement.h"

DNAComplement::DNAComplement(){
  //constructor
}

DNAComplement::~DNAComplement(){
  //destructor
}

//helper function; takes string input, converts to stack
GenStack<string> DNAComplement::complementStack(string compConvert){
  //create stack
  GenStack<string> comp;
  string complement = "";
  //for each letter in string, check if A, C, T, or G
  for (int i = 0; i < compConvert.size(); ++i) {
    switch(compConvert.at(i)){
      case 'A':
        complement = "T";
        break;
      case 'C':
        complement = "G";
        break;
      case 'T':
        complement = "A";
        break;
      case 'G':
        complement = "C";
        break;
      default:
        //not a valid part of DNA sequence
        complement = "F";
        break;
    }
    if (complement != "F") { //a valid part of DNA sequence
      comp.push(complement);
    }
    else{
      cout << "Not a valid sequence. Conversion terminated." << endl;
      break;
    }
  }
  return comp;
}

//calculates the complement of DNA string
string DNAComplement::Complement(string compConvert){
  string comp = "";
  string complement = "";
  //for each letter in string, check if A, C, T, or G
  for (int i = 0; i < compConvert.size(); ++i) {
    switch(compConvert.at(i)){
      case 'A':
        complement = "T";
        break;
      case 'C':
        complement = "G";
        break;
      case 'T':
        complement = "A";
        break;
      case 'G':
        complement = "C";
        break;
      default:
        //not a valid part of DNA sequence
        complement = "F";
        break;
    }
    if (complement != "F") { //a valid part of DNA sequence
      comp += complement;
    }
    else{
      cout << "Not a valid sequence. Conversion terminated." << endl;
      break;
    }
  }
  return comp;
}

//calculates the reverse complement of DNA string
string DNAComplement::RevComplement(string revConvert){
  //call complement()
  GenStack<string> comp = complementStack(revConvert);
  string rev = "";
  while (!comp.isEmpty()) {
    //reverse the complement stack into string
    rev += comp.pop();
  }
  return rev;
}
