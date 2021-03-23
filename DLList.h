/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 4
*/

//Header file for DLList

#ifndef DL_LIST_H
#define DL_LIST_H

#include <cstdlib>

template <typename T>
class ListNode{
public:
  ListNode(T d);
  ~ListNode();
  T data;
  ListNode<T>* next;
  ListNode<T>* prev;
};

//list node constructor
template <typename T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

//list node destructor
template <typename T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}

template <typename T>
class DLList{
public:
  DLList();
  ~DLList();
  int size();
  bool isEmpty();
  void insertFront(T d);
  void insertBack(T d);
  void insertAt(int p, T d);
  T removeFront();
  T removeBack();
  T removeFrom(int p);
  T peek(int p);

private:
  ListNode<T>* front;
  ListNode<T>* back;
  int m_size;
};

//list constructor
template <typename T>
DLList<T>::DLList(){
  front = NULL;
  back = NULL;
  m_size = 0;
}

//list destructor
template <typename T>
DLList<T>::~DLList(){
  //loop through list and delete all nodes
  ListNode<T>* current = front;
  while (current != NULL) {
    ListNode<T>* next = current->next;
    //free(current);
    current = NULL;
    current = next;
  }
  front = NULL;
  back = NULL;
}

//method to check if list is empty
template <typename T>
bool DLList<T>::isEmpty(){
  return (m_size==0);
}

//method to check size of list
template <typename T>
int DLList<T>::size(){
  return m_size;
}

//method to insert at front of list
template <typename T>
void DLList<T>::insertFront(T d){
  ListNode<T>* newNode = new ListNode<T>(d);
  if(isEmpty()){
    back = newNode;
  } else{
    front->prev = newNode;
  }
  newNode->next = front;
  front = newNode;
  ++m_size;
}

//method to insert at back of list
template <typename T>
void DLList<T>::insertBack(T d){
  ListNode<T>* newNode = new ListNode<T>(d);
  if(isEmpty()){
    front = newNode;
  } else{
    back->next = newNode;
    newNode->prev = back;
  }
  back = newNode;
  ++m_size;
}

//method to insert at postition p of list
template <typename T>
void DLList<T>::insertAt(int p, T d){
  //make sure valid position
  if(isEmpty()){
    insertFront(d);
    return;
  }
  if(p>=m_size-1){
    insertBack(d);
    return;
  }
  ListNode<T>* newNode = new ListNode<T>(d);
  int currIdx = 0;
  ListNode<T>* currNode = front;
  while(currIdx < p){
    ++currIdx;
    currNode = currNode->next;
  }
  newNode->next = currNode->next;
  currNode->next->prev = newNode;
  newNode->prev = currNode;
  currNode->next = newNode;
    ++m_size;
}

//method to remove from front of list
template <typename T>
T DLList<T>::removeFront(){
  //assume non-empty -> account for in error handling in GenStack
  T ret = front->data;
  if(front->next == NULL){ //single item
    back = NULL;
  }
  else{
    front->next->prev = NULL;
  }
  front=front->next;
  --m_size;

  return ret;
}

//method to remove from back of list
template <typename T>
T DLList<T>::removeBack(){
  //assume non-empty -> FIXME
  T ret = back->data;
  if(front->next==NULL){
    front = NULL;
  } else{
    back->prev->next = NULL;
  }
  back = back->prev;
  --m_size;
  return ret;
}

//method to remove from position p of list
template <typename T>
T DLList<T>::removeFrom(int p){
  //assume non-empty -> FIXME -> not being used in GenStack
  if(p>=m_size-1){
    return removeBack();
  }
  --m_size;
  int currIdx = 0;
  ListNode<T>* currNode = front;
  while(currIdx < p){
    ++currIdx;
    currNode = currNode->next;
  }
  T ret = currNode->next->data;
  currNode->next->prev = NULL;
  currNode->next->next->prev = currNode;
  currNode->next = currNode->next->next;
  //the thing we want to delete still has active next pointer -> FIXME using temp node
  return ret;
}

//method to peek at item at front of list
template <typename T>
T DLList<T>::peek(int p){
  //assume non-empty -> account for in error handling in GenStack
  if(p<=0){
    return front->data;
  }
  int currIdx = 0;
  ListNode<T>* currNode = front;
  while(currIdx < p){
    ++currIdx;
    currNode = currNode->next;
  }
  T ret = currNode->data;

  return ret;
}

#endif
