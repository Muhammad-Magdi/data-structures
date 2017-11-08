template <class T>
DoublyNode<T> * DoublyLinkedList<T> :: insertAfter(DoublyNode<T> * node, T data){
  DoublyNode<T>* newNode = new DoublyNode<T>(data, node, node->getNext());
  if(node == tail)  tail = newNode;
  if(newNode->getNext())   newNode->getNext()->setPrev(newNode);
  node->setNext(newNode);
  ++numNodes;
  return newNode;
}

template <class T>
DoublyNode<T>* DoublyLinkedList<T> :: insertBefore(DoublyNode<T>* node, T data){
  DoublyNode<T>* newNode = new DoublyNode<T>(data, node->getPrev(), node);
  if(node == head)  head = newNode;
  if(newNode->getPrev())  newNode->getPrev()->setNext(newNode);
  node->setPrev(newNode);
  ++numNodes;
  return newNode;
}

template <class T>
inline void DoublyLinkedList<T> :: step(DoublyNode<T>* node, int &idx, bool forward){
  node = (DoublyNode<T>*)(forward? node->getNext() : node->getPrev());
  idx = (forward? idx+1 : idx-1);
}

template <class T>
DoublyNode<T> * DoublyLinkedList<T> :: findNode(int idx){
  if(idx<0 || idx>numNodes)  throw "Invalid Index";
  int dir, curIdx;
  DoublyNode<T>* cur;
  if(idx <= (numNodes >> 1)){
    dir = 1;
    cur = head;
    curIdx = 0;
  }else{
    dir = 0;
    cur = tail;
    curIdx = numNodes-1;
  }
  while(cur && idx!=curIdx){
    step(cur, curIdx, dir);
  }
  return cur;
}

template <class T>
bool DoublyLinkedList<T> :: deleteNode(DoublyNode<T>* node){
  if(!numNodes || node == nullptr) return 0;
  if(numNodes == 1){
    delete node;
    head = tail = nullptr;
  }
  else if(node == head){
    head = head->getNext();
    head->setPrev(nullptr);
    delete node;
  }else if(node == tail){
    tail = tail->getPrev();
    tail->setNext(nullptr);
    delete node;
  }else{
    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
    delete node;
  }
  --numNodes;
  if(!numNodes)   head = tail = nullptr;
  return 1;
}

template <class T>
DoublyLinkedList<T> ::  DoublyLinkedList(){
  head = tail = nullptr;
  numNodes = 0;
}

template <class T>
DoublyNode<T> * DoublyLinkedList<T> :: insert(int idx, T data){
  DoublyNode<T>* newNode;
  if(!numNodes){
    newNode = new DoublyNode<T>(data, nullptr, nullptr);
    head = tail = newNode;
    ++numNodes;
  }else if(idx == numNodes){
    newNode = insertAfter(tail, data);
  }else{
    newNode = findNode(idx);
    newNode = insertBefore(newNode, data);
  }
  return newNode;
}

template <class T>
void DoublyLinkedList<T> :: printList() const{
  DoublyNode<T>* cur = head;
  int curIdx = 0;
  while(cur){
    cout << "Index " << curIdx++ << " : " << cur->getData() << endl;
    cur=cur->getNext();
  }
}
template <class T>
inline void DoublyLinkedList<T> :: pushBack(T data){
  insert(numNodes ,data);
}

template <class T>
inline void DoublyLinkedList<T> :: pushFront(T data){
  insert(0, data);
}

template <class T>
inline void DoublyLinkedList<T> :: popBack(){
  if(!deleteNode(tail))   throw "Can't pop from an Empty List";
}

template <class T>
inline void DoublyLinkedList<T> :: popFront(){
  if(!deleteNode(head))   throw "Can't pop from an Empty List";
}

template <class T>
inline T& DoublyLinkedList<T> :: back(){
  if(!numNodes)   throw "Can't access back of an Empty List";
  return tail->getData();
}

template <class T>
inline T& DoublyLinkedList<T> :: front(){
  if(!numNodes)   throw "Can't access top of an Empty List";
  return head->getData();
}

template <class T>
inline int DoublyLinkedList<T> :: size()const{
  return numNodes;
}
