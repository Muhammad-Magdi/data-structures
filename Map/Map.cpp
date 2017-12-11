template<class KT, class DT>
Map<KT, DT> :: Map(){
  root = nullptr;
  numNodes = 0;
}

/*
An iterative approach to find the parent of a given key:
  we may face 3 cases:
    1- Empty SubTree -> we should return a pointer to the root itself (NULL).
    2- One Node SubTree -> we should return a pointer to the root itself.
    3- Non-empty SubTree -> a pointer to another node in left|right SubTrees.
*/
template<class KT, class DT>
TreeNode<KT, DT> * Map<KT, DT> :: findParent(KT key) const{
  TreeNode<KT, DT> * cur = root, *parent = root;
  if(!cur || cur->getKey() == key) return cur;
  cur = key < cur->getKey()? cur->getLeft() : cur->getRight();    //the first step
  while(cur && cur->getKey()!=key){     //while we didn't find an empty place
    parent = cur;
    if(key < cur->getKey())      //It may be in the left sub-tree
      cur = cur->getLeft();
    else if(key > cur->getKey()) //It may be in the right sub-tree
      cur = cur->getRight();
  }
  return parent;
}

/*
To insert a given key in the tree we should find its parent:
that may have 2 cases:
  1- Empty Node -> we should insert in that node.
  2- Non-empty Node -> depending on its key, we choose to insert either in it|its
    left|its right.
In case that the parent's key is the same "insert" function return 0 referring
  that no nodes were added.
*/
template<class KT, class DT>
bool Map<KT, DT> :: insert(KT key, DT data){
  TreeNode<KT, DT> * parent = findParent(key);    //find the parent of a node with a given key
  if(parent){                           //in case we found a tree
    if(key == parent->getKey()){
      parent->setData(data);
      return 0;
    }else if(key < parent->getKey() && !parent->getLeft())
      parent->setLeft(new TreeNode<KT, DT>(key, data));
    else if(key > parent->getKey() && !parent->getRight())
      parent->setRight(new TreeNode<KT, DT> (key, data));
    else{
      if(key < parent->getKey() && parent->getLeft())
        parent->getLeft()->setData(data);
      else if(key > parent->getKey() && parent->getRight())
        parent->getRight()->setData(data);
      return 0;
    }
  }else   root = new TreeNode<KT, DT> (key, data);      //Empty tree
  ++numNodes;
  return 1;
}

/*
To find the node of a given key in the tree we should find its parent:
that may have 3 cases:
  1- Empty Node -> node such node.
  2- Non-empty Node -> depending on its children, if we found that key in one of them
  we may return that whose key equal the wanted key.
  3- Non-empty Node with no children -> depending on its key.
*/
template<class KT, class DT>
TreeNode<KT, DT>* Map<KT, DT> :: find(KT key) const{
  TreeNode<KT, DT> * parent = findParent(key), * ret = nullptr;
  if(parent && parent->getLeft() && parent->getLeft()->getKey() == key)
    ret = parent->getLeft();
  else if(parent && parent->getRight() && parent->getRight()->getKey() == key)
    ret = parent->getRight();
  else if(parent && parent->getKey() == key)
    ret = parent;
  return ret;
}

/*
To erase some node with a given key we should first find its parent which may
have 3 possibilities:
  1- An empty Node -> we won't erase (as we didn't find it).
  2- A non-empty Node -> then it depends on the state of its children.
*/
template <class KT, class DT>
bool Map<KT, DT> :: erase(KT key){
  TreeNode<KT, DT> * parent = findParent(key), * cur, * tmp;
  bool iamInRight = 1, iamRoot = 0;
  if(parent && parent->getLeft() && parent->getLeft()->getKey() == key)
    cur = parent->getLeft(), iamInRight = 0;
  else if(parent && parent->getRight() && parent->getRight()->getKey() == key)
    cur = parent->getRight();
  else if(parent && parent->getKey() == key)
    cur = parent, iamRoot = 1;
  else return 0;            //couldn't find it
  tmp = cur;
  if(!cur->getRight()){         //No right child
    cur = cur->getLeft();
    if(iamInRight && !iamRoot)  parent->setRight(cur);
    else if(!iamRoot)  parent->setLeft(cur);
  }
  else if(!cur->getLeft()){     //No left child
    cur = cur->getRight();
    if(iamInRight && !iamRoot)  parent->setRight(cur);
    else if(!iamRoot) parent->setLeft(cur);
  }
  else{                     //it has both left and right
    tmp = cur->getLeft();  //we will erase the rightmost node in the left sub-tree
    TreeNode<KT, DT> * prev = cur;
    while(tmp->getRight()){     //get the rightmost node keeping its parent
      prev = tmp;
      tmp = tmp->getRight();
    }
    cur->setNodeValues(tmp);
    if(prev == cur)  prev->setLeft(tmp->getLeft());
    else  prev->setRight(tmp->getLeft());
  }
  delete tmp;
  --numNodes;
  if(!numNodes) root = cur;
  return 1;
}

template<class KT, class DT>
inline bool Map<KT, DT> :: count(KT key) const{
  return (find(key) != nullptr);
}

template<class KT, class DT>
inline int Map<KT, DT> :: size() const{
  return numNodes;
}

template <class KT, class DT>
void Map<KT, DT> :: printSortedMap(TreeNode<KT, DT>* root, int level) const{
  if(!root) return;
  printSortedMap(root->getLeft(), level+1);
  cout << "Level " << level << " Key " << root->getKey() << " has data "  << root->getData() << endl;
  printSortedMap(root->getRight(), level+1);
}

template<class KT, class DT>
inline TreeNode<KT, DT> * Map<KT, DT> :: getRoot() const{
  return root;
}

/*
The user of this class may use it to do two operations:
  1-Get the value of an already inserted node:
    in this case we return a reference to the data of that node so that
    he can either change it or print it.
  2-Insert a new node:
    in case we didn't find that node in our tree we will insert a node with that
    key and return a reference to its data so that he may edit its data.
*/
template<class KT, class DT>
DT& Map<KT, DT> :: operator [] (KT key){
  TreeNode<KT, DT> * parent = findParent(key), * cur;
  if(parent){                             //in case we found a tree
    if(key == parent->getKey()){            //this key is already here
      return parent->getDataReference();    //return a reference to its data
    }else if(key < parent->getKey()){
      parent->setLeft(new TreeNode<KT, DT>(key));    //insert an empty node
      cur = parent->getLeft();
    }
    else{
      parent->setRight(new TreeNode<KT, DT> (key));
      cur = parent->getRight();
    }
  }else{
    root = new TreeNode<KT, DT> (key);
    cur = root;
  }
  ++numNodes;          //increment number of nodes
  return cur->getDataReference();
}
