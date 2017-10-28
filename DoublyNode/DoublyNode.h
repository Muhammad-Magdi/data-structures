template <class T>
class DoublyNode{
private:
  T data;
  DoublyNode<T> * prev, *next;
public:
  DoublyNode();
  DoublyNode(T);
  DoublyNode(T, DoublyNode<T>*, DoublyNode<T>*);
  void setPrev(DoublyNode<T>*);
  void setNext(DoublyNode<T>*);
  void setData(T);
  DoublyNode* getPrev() const;
  DoublyNode* getNext() const;
  T& getData();
};

#include "DoublyNode.cpp"
