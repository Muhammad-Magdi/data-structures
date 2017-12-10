template <class KT, class DT>
inline TreeNode <KT, DT> :: TreeNode(KT k){
  key = k;
  left = right = nullptr;
}

template <class KT, class DT>
TreeNode <KT, DT> :: TreeNode(KT k, DT d){
  key = k;
  data = d;
  left = right = nullptr;
}

template <class KT, class DT>
TreeNode <KT, DT> :: TreeNode(KT k, DT d, TreeNode<KT, DT>* l, TreeNode<KT, DT> * r){
  key = k;
  data = d;
  left = l;
  right = r;
}

template <class KT, class DT>
inline void TreeNode <KT, DT> :: setData(DT d){
  data = d;
}

template <class KT, class DT>
inline DT& TreeNode <KT, DT>:: getData(){
  return data;
}

template <class KT, class DT>
inline void TreeNode <KT, DT> :: setKey(KT k){
  key = k;
}

template <class KT, class DT>
inline KT& TreeNode <KT, DT>:: getKey(){
  return key;
}

template <class KT, class DT>
inline void TreeNode <KT, DT> :: setLeft(TreeNode* n){
  left = n;
}

template <class KT, class DT>
inline void TreeNode <KT, DT> :: setRight(TreeNode* n){
  right = n;
}

template <class KT, class DT>
inline TreeNode<KT, DT>* TreeNode <KT, DT>:: getLeft() const{
  return left;
}

template <class KT, class DT>
inline TreeNode<KT, DT>* TreeNode <KT, DT>:: getRight() const{
  return right;
}
