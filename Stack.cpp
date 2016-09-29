#include <cstdlib>
#include <iostream>
#include <string>
#include "Stack.h"
#include "Order.h"

Stack::~Stack(void) { }

void Stack::push(Order & order){
  this->top++;
  this->size++;
  stackOrder[top] = order;
}

Order & Stack::pop(void){ 
  size--;
  return stackOrder[top--];
}

int Stack::stackSize(void){
  return this->size;
}

bool Stack::isEmpty(void){
  return (this->top == this->size);
}

