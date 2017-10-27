template <class T>
Stack<T> :: Stack(){
  root = nullptr;
  numNodes = 0;
}

template <class T>
Stack<T> :: Stack(Stack<T> &st1){
  numNodes = 0;
  Node<T> * root1 = st1.root, *cur = root = new Node<T>();
  while(root1){
    cur->setVal(root1->getVal());
    root1 = root1->getNext();
    cur->setNext(new Node<T>());
    cur = cur->getNext();
    ++numNodes;
  }
  delete root1;
  delete cur;
  cur = nullptr;
}

template <class T>
void Stack<T> :: insertNode(Node<T> & node){

}

template <class T>
void Stack<T> :: push(T val){
  Node<T>* newRoot = new Node<T>(val);
  newRoot->setNext(root);
  root = newRoot;
  ++numNodes;
}

template <class T>
T& Stack<T> :: top(){
  if(root == nullptr) throw "Empty Stack does not have a top\n";
  return root->getVal();
}

template <class T>
void Stack<T> :: pop(){
  if(root == nullptr) throw "Empty Stack does not have a top\n";
  Node<T> * newRoot = root->getNext();
  delete root;
  root = newRoot;
  --numNodes;
}

template <class T>
int Stack<T> :: size(){
  return numNodes;
}

template <class T>
bool Stack<T> :: empty(){
  return !numNodes;
}
