#include <iostream>

/*
In this exercise, we will implement heap as discussed in the class.
We need to implement the following functions.


ONLY THIS FILE MUST BE MODIFIED FOR SUBMISSION

You may edit main.cpp for writing more test cases.
But your code must continue to work with the original main.cpp


THERE IS ONLY ONE TEST CASE ONLY FOR YOUR UNDERSTANDING.

-- You may need to generate more random tests to get your tests right
-- Print will not work until you have a good printing function
*/


#include "heap.h"


int Heap::parent(int i) {
  return (i-1)/2; // dummy return
}

int Heap::left(int i) {
  return (2*i+1); // dummy return
}

int Heap::right(int i) {
  return (2*i+2); //dummy
}

int Heap::max() {
  return store[0]; //dummy
}

void Heap::swap(int i, int j) {
  swap_count++;
  //std::cout<<"i was "<<i<<" j was "<<j<<"\n";
  store[i] = store[i] + store[j];
  store[j] = store[i] - store[j];
  store[i] = store[i] - store[j];
  //std::cout<<"i is "<<i<<" j is "<<j<<"\n";  
}

void Heap::insert(int v) {
  append(v);
  int i = sz - 1;
  while (i >0 && store[parent(i)] < store[i]) {
    swap(parent(i),i);
    i = parent(i);
  }
  //std::cout<<"apna debugging re\n";
  for (int i=0; i<store.size(); i++) {
    std::cout<<store[i]<<" ";
  }
  //std::cout<<"\n";
}

void Heap::heapify(int i) {
  if (sz == 2) {
    if (store[0] < store[1]) {
      swap(0,1);
      return;
    }
  }
  //std::cout<<"heapify call hua\n";
  if (right(i) > sz-1) {
    //std::cout<<"par kuch hua nahi\n";
    return;
  }
  int c;
  int tmp = store[i];
  int bruh;
  if (store[right(i)] > store[left(i)]) {
    c = right(i);
  }
  else {
    c = left(i);
  }
  bruh = store[c];
  if (bruh > tmp) {
    swap(i,c);
    heapify(c);
  }
}


void Heap::deleteMax() {
  swap(0,sz-1);
  //std::cout<<"deleted thing is "<<store[sz-1]<<"\n";
  sz--;
  heapify(0);
  print();
}

void Heap::buildHeap() {
  for (int i = sz-1; i >=0; i--) {
    heapify(i);
  }
}

void Heap::heapSort() {
  buildHeap();
  vector<int>bruh;
  while (sz > 0) {
    bruh.push_back(max());
    deleteMax();
  }
  for (int i=bruh.size() - 1; i>=0; i--) {
    append(bruh[i]);
    bruh.pop_back();
  }
}


