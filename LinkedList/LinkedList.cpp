template <class T>
LinkedList<T> :: LinkedList(){
  root = new Node<T>();
  numNodes = 0;
}

template <class T>
Node<T> * LinkedList<T> :: insertAfter(Node<T> * first, T val){
  Node<T> * second = new Node<T>(val);
  second->setNext(first->getNext());
  first->setNext(second);
  ++numNodes;
  return second;
}

template <class T>
bool LinkedList<T> :: deleteAfter(Node<T> * node){
  Node<T> * nxt = node->getNext();
  if(nxt){
    node->setNext(nxt->getNext());
    --numNodes;
    return delete nxt, 1;
  }
  return 0;
}

template <class T>
Node<T>* LinkedList<T> :: findNode(int idx){
  Node<T>* cur = root;
  int curIdx = 0;
  while(idx != curIdx){
    ++curIdx;
    cur = cur->getNext();
  }
  return cur;
}

template <class T>
Node<T> * LinkedList<T> :: insert(int idx, T val){
  if(idx < 0 || idx > numNodes) throw "Invalid Location in the LinkedList\n";        //invalid index
  Node<T> * cur = findNode(idx);
  return insertAfter(cur, val);
}

template <class T>
bool LinkedList<T> :: erase(T val){
  Node<T> * cur = root, * nxt = root->getNext();
  while(nxt && nxt->getVal() != val){
    cur = nxt;
    nxt = nxt->getNext();
  }
  if(nxt && nxt->getVal() != val)  return 0;
  return  deleteAfter(cur);
}

template <class T>
void LinkedList<T> :: reverse(){
  Node<T> * cur = this->root, * next, *prev;
  while(cur){
    next = cur->getNext();
    cur->setNext(prev);
    prev = cur;
    cur = next;
  }
  this->root = prev;
}

template <class T>
int LinkedList<T> :: findIndex(T val){
  Node<T> * cur = root;
  int idx = -1;
  do{
    cur = cur->getNext();
    ++idx;
  }while(cur->getNext() && cur->getVal() != val);
  return (cur->getVal() == val)? idx : numNodes;
}

template <class T>
int LinkedList<T> :: size()const{
  return numNodes;
}

template <class T>
void LinkedList<T> :: printList(){
  Node<T> * cur = root;
  int idx = 0;
  while(idx < numNodes){
    cur = cur->getNext();
    cout << "index " << idx++ << " -> " << cur->getVal() << "\n";
  }
}

template <class T>
bool LinkedList<T> :: swapNodes(int idx){
  if(idx < 0 || idx+1 >= numNodes) throw "Invalid Location in the LinkedList\n";        //invalid index
  Node<T>* prev = root, * cur, * nxt;
  int curIdx = 0;
  cur = root->getNext();
  nxt = cur->getNext();
  while(idx != curIdx && nxt){
    prev = cur;
    cur = nxt;
    nxt = nxt->getNext();
    ++curIdx;
  }
  if(idx == curIdx){
    prev->setNext(nxt);
    cur->setNext(nxt->getNext());
    nxt->setNext(cur);
    return 1;
  }
  return 0;
}
template <class T>
static LinkedList<T> merge(LinkedList<T> &l1, LinkedList<T> &l2){
  LinkedList<T> l3;
  bool isFirst = 1;
  Node<T>* cur = l3.begin(), *r1 = l1.begin(), *r2 = l2.begin();
  while(r1 != nullptr || r2 != nullptr){
    // cout << cnt++ << endl;
    if(!isFirst){
      Node<T> * newNode = new Node<T>();
      cur->setNext(newNode);
      cur = cur->getNext();
    }
    if(r1 != nullptr && r2!=nullptr && r1->getVal() < r2->getVal()){
      cur->setVal(r1->getVal());
      r1 = r1->getNext();
    }
    else if(r2){
      cur->setVal(r2->getVal());
      r2 = r2->getNext();
    }
    else{
      cur->setVal(r1->getVal());
      r1 = r1->getNext();
    }
    isFirst = 0;
  }
  return l3;
}

template <class T>
Node<T> * LinkedList<T> :: begin() const{
  return root;
}

template <class T>
void LinkedList<T> :: printReverse(Node<T> * root) const{
  if(root == nullptr) return ;
  printReverse(root->getNext());
  if(root != this->root) cout << root->getVal() << " ";
}
