#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main(){
  DoublyLinkedList<int> l;
  try{
    for(int i = 0 ; i < 10 ; ++i){
      l.pushBack(i);
    }
    for(int i = 0 ; i < 10 ; ++i){
      l.pushFront(i);
    }
  }catch(const char* msg){
    cerr << "Error : " << msg << endl;
  }
  l.printList();
  printf("%d\n", l.size());
  l.front() = 1024;
  try{
    for(int i = 0 ; i < 10 ; ++i){
      l.popBack();
    }
  }catch(const char* msg){
    cerr << "Error : " << msg << endl;
  }
  l.printList();
  printf("%d\n", l.size());
  return 0;
}
