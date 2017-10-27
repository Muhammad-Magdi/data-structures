template <class T>
class Node{
protected:
  T val;
  Node<T> * nxt;
public:
  Node();
  Node(T);
  void setVal(T);
  T& getVal();
  void setNext(Node<T>*);
  Node<T>* getNext() const;
};

#include "Node.cpp"
