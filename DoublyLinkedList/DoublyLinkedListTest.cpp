#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main(){
  DoublyLinkedList<int> l;
  l.pushFront(1);
  l.pushFront(2);
  l.pushFront(3);
  l.pushFront(4);
  cout << l.front() << endl;
  l.popFront();
  cout << l.front() << endl;
  l.popFront();
  cout << l.back() << endl;
  l.popBack();
  cout << l.back() << endl;
  l.popBack();
  l.pushFront(5);
  cout << l.front() << endl;
  l.popFront();
  return 0;
}
