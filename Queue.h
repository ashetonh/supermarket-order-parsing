/**
 * Queue class
 */

#ifndef _QUEUE_H
#define _QUEUE_H

/**
 * The queue will store orders until the order dispatcher
 * dequeues the order and pushes it onto a stack.
 * Each category of product will have different order queues.
 */
#include <string>
#include <cstdlib>
#include <iostream>
#include "Order.h"

using namespace std;

class Queue {

 public:

  Order orders[64];
  int head, tail;
  string category = ""; // the product category whose orders are stored in this queue.
  
  /**
   * Default constructor
   */
  Queue(void) = default;
  

  /**
   * Constructor
   */
  Queue(string category);

  
  /**
   * Destructor
   */
  ~Queue(void);

  
  /**
   * Insert a member into the queue
   * at the end
   */
  void enqueue(Order & o);

 
  /**
   * Remove a queue member from the
   * front of the queue
   */
  Order & dequeue(void);

  
  /**
   * Returns the current size of the queue
   */
  int queueSize(void);

  
  /**
   * Returns true if the queue is empty
   */
  bool isEmpty();


  const int getTail() const;
  const int getHead() const;
  const string getQCat() const;

};

#endif //_QUEUE_H
