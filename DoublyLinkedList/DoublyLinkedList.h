#include "../DoublyNode/DoublyNode.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList{
private:
  int numNodes;
  DoublyNode<T> * insertAfter(DoublyNode<T> *, T);
  DoublyNode<T> * insertBefore(DoublyNode<T> *, T);
  DoublyNode<T> * findNode(int);
  DoublyNode<T> * root;
  bool deleteAfter(DoublyNode<T> *);
  bool deleteBefore(DoublyNode<T> *);
public:
  DoublyLinkedList();
  DoublyNode<T> * insert(int, T);
  bool erase(T);
  void reverse();
  void printList();
  bool swapNodes(int);
  int findIndex(T);
  DoublyNode<T> * begin() const;
  void printReverse(DoublyNode<T> *)const;
  int size()const;
};

#include "DoublyLinkedList.cpp"
