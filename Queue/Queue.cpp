template <class T>
Queue<T> :: Queue(){
  head = tail = nullptr;
  numNodes = 0;
}

template <class T>
Queue<T> :: Queue(Queue<T>& q1){

}

template <class T>
void Queue<T> :: push(T val){
  Node<T> * newNode = new Node<T>(val);
  if(tail){
    tail->setNext(newNode);
  }
  tail = newNode;
  if(!numNodes) head = tail;
  ++numNodes;
}

template <class T>
T& Queue<T> :: front(){
  if(!numNodes)   throw "Can't access front of an empty Queue!\n";
  return head->getVal();
}

template <class T>
void Queue<T> :: pop(){
  if(!numNodes)   throw "Can't pop form an empty Queue!\n";
  Node<T> * cur = head;
  head = head->getNext();
  delete cur;
  --numNodes;
}

template <class T>
int Queue<T> :: size(){
  return numNodes;
}

template <class T>
bool Queue<T> :: empty(){
  return !numNodes;
}

template <class T>
void Queue<T> :: clear(){
  while(!this->empty()) this->pop();
}
