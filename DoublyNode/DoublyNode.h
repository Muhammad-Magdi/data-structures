#include "../Node/Node.h"

template <class T>
class DoublyNode : public Node<T>{
private:
  Node<T> * prev;
public:
  DoublyNode();
  DoublyNode(T);
  void setPrev(DoublyNode*);
  DoublyNode* getPrev() const;
};

#include "DoublyNode.cpp"
