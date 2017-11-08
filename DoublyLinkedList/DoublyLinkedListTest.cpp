#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main(){
  DoublyLinkedList<int> l;
  l.pushFront(1);
  l.pushFront(2);
  l.pushFront(3);
  l.pushFront(4);
  l.pushFront(100);
  l.printList();
  l.reverse();
  l.printList();
  return 0;
}
