/**
* This file provides the function prototypes
* for dispatchOrder and printLabel
*/
#ifndef _SUPERMARKET_H
#define _SUPERMARKET_H

#include <cstdlib>
#include <string>
#include "LinkedList.h"
#include "Stack.h"
#include <fstream>
/*
Sample implementation to demonstrate usage */
/*
void dispatchOrder(LinkedList &myList, string cats[]){
    Stack *s = new ArrayStack();
    for(int i = 0; i < myList.size(); i++){
            string category = cats[i];
            for(int j = 0; j < myList.grabNodeByCat(category)->orderCount; j++){
                s->push(myList.getQueueByCat(category).dequeue());
            }
    }
    printLabel(*s);
}
*/

/**
* function printLabel
* This function will pop all the elements from the stack
* one-by-one and prints a label in the given format to a file.
**/
void printLabel(Stack &myStack){
  
  
  
    ofstream outFile("output.txt");
  int stacksize = myStack.stackSize();
  if(outFile.is_open()){
  for(int b = 0;b < stacksize; b++){
    Order temp;
    temp = myStack.pop();
    outFile<< " -------------------------"<< endl;
    outFile<<"Order Number: " << temp.orderNumber<<endl;
    outFile<<"Name: " << temp.name << endl;
    outFile<<"Item: " << temp.item << endl;
    outFile<<"Ship to: " << temp.shipArea << endl;
  }
  outFile<< " -------------------------"<< endl;
  outFile.close();
  }
}

/**
 * function dispatchOrder
 * This function will access the data part of the linked list
 * for the number of orders to be dequeued and pushed onto
 * the stack, it will also reset this data part to zero
 * after dequeuing for that node is complete.
 */
string pushCat = "";
void dispatchOrder(LinkedList &mylist, string cats[], int numElements){
  Stack s1;
  for(int i =0 ;i<numElements; i++){
    string pushCat = cats[i];
    for(int j=0;j<mylist.grabNodeByCat(pushCat)->orderCount;j++){
      s1.push(mylist.getQueueByCat(pushCat).dequeue());
    }
  }
  //  cout<< s1.top<<endl;
  printLabel(s1);

}

#endif // _SUPERMARKET_H
