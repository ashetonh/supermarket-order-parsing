#include <cstdlib>
#include <string>
#include <iostream>
#include "Order.h"

using namespace std;





Order::Order(const int orderNumber, const string &name, const string &item, const string &category, const string &shipArea){
  this->orderNumber = orderNumber;
  this->name = name;
  this->item = item;
  this->category = category;
  this->shipArea = shipArea;
}

Order::Order(const Order & o){
  this->orderNumber = o.orderNumber;
  this->name = o.name;
  this->item = o.item;
  this->category = o.category;
  this->shipArea = o.shipArea;
}

Order & Order::operator=(const Order & o){
  this->orderNumber = o.orderNumber;
  this->name = o.name;
  this->item = o.item;
  this->category = o.category;
  this->shipArea = o.shipArea;
  
  return *this;
}

Order::~Order(void){
}


