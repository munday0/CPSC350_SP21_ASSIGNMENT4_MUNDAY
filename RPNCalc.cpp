/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 4
*/

//Cpp file for RPNCalc

#include "RPNCalc.h"

RPNCalc::RPNCalc(){
  //constructor
}

RPNCalc::~RPNCalc(){
  //destructor
}

//calculate value given string in RPN separated by spaces
float RPNCalc::calculateVal(string inString){
  //create stack
  GenStack<float> stack;
  //create values a, b, val, and modVal to store operands and results of operations
  float a;
  float b;
  float val;
  int modVal;
  //delimiter - the string being searched for in order to properly separate input
  string delimiter = " ";
  //position used for finding substring to properly separate input
  int pos = 0;
  //current substring - use when checking if operator or operand
  string curr;
  bool done = false;
  //while the string delimiter can be found
  while (!done) {
    pos = inString.find(delimiter);
    if (pos == -1) {
      done = true;
    }
    //set current substring from position 0 to the first appearance of the delimiter
    curr = inString.substr(0, pos);
    //if current substring is operator
    if (curr[0] == '+' || curr[0] == '-' || curr[0] == '*' || curr[0] == '/' || curr[0] == '%') {
      switch (curr[0]) {
        case '+': //add
          b = stack.pop();
          a = stack.pop();
          val = a + b;
          stack.push(val);
          break;
        case '-': //subtract
          b = stack.pop();
          a = stack.pop();
          val = a - b;
          stack.push(val);
          break;
        case '*': //multiply
          b = stack.pop();
          a = stack.pop();
          val = a * b;
          stack.push(val);
          break;
        case '/': //divide
          b = stack.pop();
          a = stack.pop();
          val = a / b;
          stack.push(val);
          break;
        case '%': //modula
          b = stack.pop();
          a = stack.pop();
          modVal = (int)a % (int)b;
          stack.push(modVal);
          break;
      }
    }
    else{
      //if current substring is operand
      try{
        if (stof(curr)) {
          //push to stack
          stack.push(stof(curr));
        }
      }
      catch (invalid_argument& e){
        //do nothing
      }
    }
    //since have multiple delimiters, remove current value in order to get the next one
    inString.erase(0, pos + delimiter.length());
  }
  cout << "Answer: " << stack.pop() << endl;
  return 0;
}
