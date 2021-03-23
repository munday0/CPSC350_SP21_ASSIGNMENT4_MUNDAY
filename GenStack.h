/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 4
*/

//Header file for GenStack

#ifndef GENSTACK_H
#define GENSTACK_H
#include "DLList.h"
#include <iostream>
using namespace std;

//Note: stack is LIFO structure

template <typename T>
class GenStack{
public:
  GenStack();
  ~GenStack();
  void push(T c);
  T pop();
  T peek();
  bool isEmpty();
  int size();

private:
  DLList<T> stackDL;

};

//constructor
template <typename T>
GenStack<T>::GenStack(){
}

//destructor
template <typename T>
GenStack<T>::~GenStack(){
}

//method to push an item onto the stack
template <typename T>
void GenStack<T>::push(T data){
  stackDL.insertFront(data);
}

//method to pop an item off of the stack
template <typename T>
T GenStack<T>::pop(){
  //error handling - throw exception if called when stack is empty
  if (!isEmpty()) {
    return stackDL.removeFront();
  }
  else{
    cout << "Stack is empty" << endl;
  }
}

//method to peek at item on top of the stack -> LIFO structure
template <typename T>
T GenStack<T>::peek(){
  //error handling - throw exception if called when stack is empty
  if (!isEmpty()) {
    return stackDL.peek(0);
  }
  else{
    cout << "Stack is empty" << endl;
  }
}

//method to check if stack is empty
template <typename T>
bool GenStack<T>::isEmpty(){
  return stackDL.isEmpty();
}

//method to check size of stack
template <typename T>
int GenStack<T>::size(){
  return stackDL.size();
}

#endif
