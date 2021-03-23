/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 4
*/

//Cpp file for main

#include "GenStack.h"
#include "DLList.h"
#include "RPNCalc.h"
#include "DNAComplement.h"
#include "FileProcessor.h"
#include <iostream>
using namespace std;

int main() {
  string mode;
  cout << "RPN or DNA" << endl;
  cin >> mode;
  if (mode == "RPN") {
    string input;
    cout << "Enter operands and operator (RPN notation) separated by spaces: " << endl;
    //ignores newline buffer
    cin.ignore();
    //gets full line of input, including spaces
    getline(std::cin, input);
    //performs calculations
    RPNCalc calc;
    float ans = 0;
    ans = calc.calculateVal(input);
  }
  else if (mode == "DNA"){
    string fileName;
    cout << "Enter file path/name: " << endl;
    cin >> fileName;
    //performs calculations
    DNAComplement dna;
    FileProcessor file;
    file.processFile(fileName);
  }
  else{
    cout << "Invalid mode" << endl;
  }

  return 0;
}
