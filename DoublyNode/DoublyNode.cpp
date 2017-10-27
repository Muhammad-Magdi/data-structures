template <class T>
DoublyNode<T> :: DoublyNode(){
  Node<T> :: nxt = prev = nullptr;
}

template <class T>
DoublyNode<T> :: DoublyNode(T data){
  Node<T> :: nxt = prev = nullptr;
  Node<T> :: val = data;
}

template <class T>
DoublyNode<T> :: DoublyNode(T data, DoublyNode<T>* prev_, DoublyNode<T>* nxt_){
  Node<T> :: nxt = nxt_;
  Node<T> :: prev = prev_;
  Node<T> :: val = data;
}

template <class T>
void DoublyNode<T> :: setPrev(DoublyNode* node){
  prev = node;
}

template <class T>
DoublyNode<T>* DoublyNode<T> :: getPrev() const{
  return prev;
}
