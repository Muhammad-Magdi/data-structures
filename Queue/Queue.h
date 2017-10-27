#include "../Node/Node.h"
#include <iostream>

using namespace std;

template <class T>
class Queue{
private:
  Node<T> *head, *tail;
  int numNodes;
public:
  Queue();
  Queue(Queue<T>&);
  void push(T);
  void clear();
  T& front();
  void pop();
  int size();
  bool empty();
};

#include "Queue.cpp"
