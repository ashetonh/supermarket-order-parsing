/**
* LinkedList class
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Queue.h"
#include <string>
#include <cstdlib>

using namespace std;
// forward declaration of LinkedList

class LinkedList;

/**
* Represents a node in a doubly-linked list.
* A node represent a category of product in the store.
* Each node stores information about the number of orders
* in that category that needs to be dispatched.
*/

class Node {

  friend class LinkedList;

 private:

  Node * next = nullptr;
  string category = "";   // The category of products in this node.
  Queue orderQueue; // The order queue for this category.
  // Node * prev = nullptr;


 public:

  int orderCount; // The number of orders in this node/category of product to dispatch.
  
  /**
   * Parameterized Constructor
   */
 Node(Node * next, string category, Queue &orderQueue) : next(next), category(category), orderQueue(orderQueue) { }


}; // Node







class LinkedList {
 
 private:
 
  Node * headptr = nullptr;
  // Node * tailptr = nullptr;

 public:

  int length = 0;
  
  /**
   * Adds an item to the end of this list.
   *
   * @param category The category of the queue, the node having this queue is being appended
   * @param orderQueue The queue this node will have
   */
  void append(string category, Queue &orderQueue);
  
  
  /**
   * Returns the queue for a given category.
   * Use this to quickly get the required queues
   * for enqueue and dequque operations.
   * @param cat the category for the required queue. 
   */
  Queue & getQueueByCat(string cat);

  
  /**
   * Sets the value of orderCount for the given category.
   *
   * @param cat the category name
   * @param count the number of orders to dispatch
   */
  void setOrderCount(string cat, int count);

  Node * grabNodeByCat(string category);
  
  /**
   * Returns the number of elements in this list.
   */
  const int size() const;
  

  /**
   * Returns whether or not this linked list is empty. 
   */
  const bool empty() const;

};



// LINKEDLIST IMPLEMENTATION

void LinkedList::append(string category, Queue &orderQueue){

  if(headptr == NULL){
    headptr = new Node(nullptr, category, orderQueue);
  }
  else{
    Node * p = headptr;
    
    while(p->next){
      p = p->next;
    }
    
    p->next = new Node(nullptr, category, orderQueue);
    
  }

  length++;


}


Queue & LinkedList::getQueueByCat(string cat){

  Node * p = headptr;
  
  while(p != NULL){

    if( cat == p->category ){
      break;
    }
      p = p->next;
  }

  return p->orderQueue;
}

Node * LinkedList::grabNodeByCat(string category){
  Node * temp = headptr;
  while(temp != NULL){
    if(category == temp->category){
      break;
    }
    else{
    temp = temp->next;
    }
  }

  return temp;

}

void LinkedList::setOrderCount(string cat, int count){

  Node * p = headptr;
  while( p != NULL){
    if( cat == p->category ){
      p->orderCount = count;
      break;
    }
    p = p->next;
  }

}


const int LinkedList::size() const{
  return length;  
}

const bool LinkedList::empty() const{
  return (length == 0 && headptr == NULL);
}

 // LinkedList
#endif /** LINKED_LIST_H */
