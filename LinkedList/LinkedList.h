#include "../Node/Node.h"
#include <iostream>

using namespace std;

template <class T>
class LinkedList{
private:
  int numNodes;
  Node<T> * insertAfter(Node<T> *, T);
  Node<T> * findNode(int);
  Node<T> * root;
  bool deleteAfter(Node<T> *);
public:
  LinkedList();
  Node<T> * insert(int, T);
  bool erase(T);
  void reverse();
  void printList();
  bool swapNodes(int);
  // static LinkedList<T> merge(LinkedList<T> &, LinkedList<T>&);
  // Node<T> * findNode(T);
  int findIndex(T);
  Node<T> * begin() const;
  void printReverse(Node<T> *)const;
  int size()const;
};

#include "LinkedList.cpp"
