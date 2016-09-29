#include <cstdlib>
#include <string>
#include <iostream>
#include "Queue.h"
#include "Order.h"

using namespace std;

Queue::Queue(string category){
  this->category = category;
  head = tail = -1;
}

Queue::~Queue(void) { }


void Queue::enqueue(Order & o){
  tail++;
  orders[tail % 64] = o;
}

Order & Queue::dequeue(void){
  head++;
  return orders[head % 64];
}

int Queue::queueSize(void){
  return (tail - head);
}

bool Queue::isEmpty(){
  return (head == tail);
}

const int Queue::getTail() const{
  return this->tail;
}

const int Queue::getHead() const{
  return this->head;
}

const string Queue::getQCat() const{
  return this->category;
}
