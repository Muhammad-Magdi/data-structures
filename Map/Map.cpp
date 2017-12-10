template<class KT, class DT>
Map<KT, DT> :: Map(){
  root = nullptr;
  numNodes = 0;
}

/*
To find the parent of a given key:
we may face 3 cases:
1- Empty SubTree -> we should return a pointer to the root itself.
2- One Node SubTree -> we should return a pointer to the root itself.
3- Non-empty SubTree -> a pointer to another node in left|right SubTrees.
*/
template<class KT, class DT>
TreeNode<KT, DT> * Map<KT, DT> :: findParent(TreeNode<KT, DT>* root, KT key) const{
  TreeNode<KT, DT> * ret = nullptr;
  if(root==nullptr || root->getKey() == key)  ret = root;    //Empty Tree OR Exact Node
  else if(key < root->getKey())  ret = findParent(root->getLeft(), key);    //Is it in left subTree
  else ret = findParent(root->getRight(), key);     //Try to find it in the right subTree
  return ret? ret : root;
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
  TreeNode<KT, DT> * parent = findParent(root, key);
  if(parent)  cout << key << "  " << parent->getKey() << endl;
  if(parent){
    if(key == parent->getKey()){
      parent->setData(data);
      return 0;
    }else if(key < parent->getKey())    parent->setLeft(new TreeNode<KT, DT>(key, data));
    else  parent->setRight(new TreeNode<KT, DT> (key, data));
  }else   root = new TreeNode<KT, DT> (key, data);
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
  TreeNode<KT, DT> * parent = findParent(root, key), * ret = nullptr;
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
  1- An empty Node -> we won't erase.
  2- A non-empty Node -> then it depends on the state of its children.
*/
template <class KT, class DT>
bool Map<KT, DT> :: erase(KT key){
  TreeNode<KT, DT> * parent = findParent(root, key);
  if(parent && parent->getLeft() && parent->getLeft()->getKey() == key){

  }
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
