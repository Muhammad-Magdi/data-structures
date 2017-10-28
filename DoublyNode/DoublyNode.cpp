template <class T>
DoublyNode<T> :: DoublyNode(){
  next = prev = nullptr;
}

template <class T>
DoublyNode<T> :: DoublyNode(T data_){
  next = prev = nullptr;
  data = data;
}

template <class T>
DoublyNode<T> :: DoublyNode(T data_, DoublyNode<T>* prev_, DoublyNode<T>* next_){
  next = next_;
  prev = prev_;
  data = data_;
}

template <class T>
void DoublyNode<T> :: setPrev(DoublyNode<T>* node){
  prev = node;
}

template <class T>
void DoublyNode<T> :: setNext(DoublyNode<T>* node){
  next = node;
}

template <class T>
void DoublyNode<T> :: setData(T data_){
  data = data_;
}

template <class T>
DoublyNode<T>* DoublyNode<T> :: getPrev() const{
  return prev;
}

template <class T>
DoublyNode<T>* DoublyNode<T> :: getNext() const{
  return next;
}

template <class T>
T& DoublyNode<T> :: getData(){
  return data;
}
