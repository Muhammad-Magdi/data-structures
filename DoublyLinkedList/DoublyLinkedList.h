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
  inline void step(DoublyNode<T>* &, int &, bool = 1);
  DoublyNode<T> * findNode(int);
  bool deleteNode(DoublyNode<T> *);
public:
  DoublyLinkedList();
  DoublyNode<T> * insert(int, T);
  DoublyNode<T> * search(T);
  inline void pushBack(T);
  inline void pushFront(T);
  inline void popBack();
  inline void popFront();
  inline T& back();
  inline T& front();
  inline int size()const;
  inline bool erase(int);
  inline bool remove(T);
  void reverse();
  void printList() const;
  bool swapNodes(int);
  DoublyNode<T> * begin() const;
};

#include "DoublyLinkedList.cpp"
