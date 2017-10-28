#include "../DoublyNode/DoublyNode.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList{
private:
  int numNodes;
  DoublyNode<T> * head, *tail;
  DoublyNode<T> * insertAfter(DoublyNode<T> *, T);
  DoublyNode<T> * insertBefore(DoublyNode<T> *, T);
  inline void step(DoublyNode<T>*, int &, bool = 1);
  DoublyNode<T> * findNode(int);
  bool deleteNode(DoublyNode<T> *);
public:
  DoublyLinkedList();
  DoublyNode<T> * insert(int, T);
  inline void pushBack(T);
  inline void pushFront(T);
  inline void popBack();
  inline void popFront();
  inline T& back();
  inline T& front();
  bool erase(T);
  void reverse();
  void printList() const;
  bool swapNodes(int);
  int findIndex(T);
  DoublyNode<T> * begin() const;
  void printReverse(DoublyNode<T> *)const;
  inline int size()const;
};

#include "DoublyLinkedList.cpp"
