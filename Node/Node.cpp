template <class T>
Node <T>:: Node(){
  nxt = nullptr;
}

template <class T>
Node <T> :: Node(T x){
  val = x;
  nxt = nullptr;
}

template <class T>
void Node <T> :: setVal(T x){
  val = x;
}

template <class T>
T& Node <T>:: getVal(){
  return val;
}

template <class T>
void Node <T> :: setNext(Node* n){
  nxt = n;
}

template <class T>
Node<T>* Node <T>:: getNext() const{
  return nxt;
}
