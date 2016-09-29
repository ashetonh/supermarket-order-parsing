#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <cerrno>
#include <fcntl.h>
#include <sstream>

#include "Order.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "SuperMarket.h"


using namespace std;

int main(int argc, char * argv[]){
  cout<< "Running...."<< endl;
  if(argc > 2){
    cout << "Program will only take one input file through the command line." 
	 << endl;
    return EXIT_FAILURE;
  }

  LinkedList mylist;
  string line;
  string categories[50];
  int numCats = 0;
  
  ifstream inputFile(argv[1]);
  if(!inputFile){
    cerr << "Unable to open this file." << endl;
    return EXIT_FAILURE;
  }
  

  while(inputFile){      

    getline(inputFile, line);
    line.pop_back();
    if(strcmp(line.c_str(), "CATEGORIES") == 0) continue;
    else if(strcmp(line.c_str(), "ORDERS") == 0) break;
    else{
      categories[numCats] = line;
      numCats++;
    }
  }

  for(int i = 0; i < numCats; i++){
    Queue q1(categories[i]);
    mylist.append(categories[i], q1);
  }

  string name, item, category, shipArea;
  int oNum = 1;
  while(getline(inputFile,line)){
   
    line.pop_back();
    if( line == "DISPATCH") break;
    stringstream iss(line);
    getline(iss, name, ',');
    
    getline(iss, item, ',');
    item.erase(0,1);

    getline(iss, category, ',');
    category.erase(0,1);
    
    getline(iss, shipArea);
    shipArea.erase(0,1);

    Order o1(oNum, name, item, category, shipArea);
    
    mylist.getQueueByCat(category).enqueue(o1);
    oNum++;
  }
  int numDispatch[50];
  int z = 0;
  string dispatchNum;
  string dispCats[50];
  while(getline(inputFile, line)){
    category = "";
    stringstream iss(line);
    getline(iss,category,' ');
    dispCats[z] = category;
    getline(iss, dispatchNum, '\n');
    numDispatch[z] = stoi(dispatchNum);
    z++;
    
  }
  
  for(int i = 0;i < z; i++){

    mylist.setOrderCount(dispCats[i], numDispatch[i]);
    
  }


  
  dispatchOrder(mylist, dispCats, z);





  cout<< "Run Successful! Goodbye." << endl;
  return EXIT_SUCCESS;
}
