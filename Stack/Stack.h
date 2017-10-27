#include "../Node/Node.h"
#include <iostream>

using namespace std;

template <class T>
class Stack{
private:
  Node<T> *root;
  int numNodes;
  void insertNode(Node<T> &);
public:
  Stack();
  Stack(Stack<T>&);
  void push(T);
  T& top();
  void pop();
  int size();
  bool empty();
};

#include "Stack.cpp"
