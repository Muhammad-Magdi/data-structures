template <class T>
DoublyNode<T>* DoublyLinkedList<T> :: insertBefore(DoublyNode<T>* node, T val){
  DoublyNode<T>* newNode = new DoublyNode<T>(val);
  newNode->setPrev(node->getPrev());
  newNode->getPrev()->setNxt(newNode);
  newNode->setNxt(node);
  node->setPrev(newNode);
  return newNode;
}

template <class T>
DoublyNode<T> * DoublyLinkedList<T> :: findNode(int idx){
  DoublyNode<T>* newNode = new DoublyNode<T>(val);

}

template <class T>
bool DoublyLinkedList<T> :: deleteAfter(DoublyNode<T>* node){

}

template <class T>
bool DoublyLinkedList<T> :: deleteBefore(DoublyNode<T>* node){

}

template <class T>
DoublyLinkedList<T> ::  DoublyLinkedList(){

}
