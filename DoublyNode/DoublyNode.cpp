template <class T>
DoublyNode<T> :: DoublyNode(){
  Node<T> :: nxt = prev = nullptr;
}

template <class T>
DoublyNode<T> :: DoublyNode(T x){
  Node<T> :: nxt = prev = nullptr;
  Node<T> :: val = x;
}

template <class T>
void DoublyNode<T> :: setPrev(DoublyNode* node){
  prev = node;
}

template <class T>
DoublyNode<T>* DoublyNode<T> :: getPrev() const{
  return prev;
}
