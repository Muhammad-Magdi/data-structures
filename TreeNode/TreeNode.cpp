template <class KT, class DT>
inline TreeNode <KT, DT> :: TreeNode(KT k){
  key = k;
  left = right = nullptr;
  color = 0;                      //0 is black
}

template <class KT, class DT>
TreeNode <KT, DT> :: TreeNode(KT k, DT d){
  key = k;
  data = d;
  left = right = nullptr;
  color = 0;                      //0 is black
}

template <class KT, class DT>
TreeNode <KT, DT> :: TreeNode(KT k, DT d, TreeNode<KT, DT>* l, TreeNode<KT, DT> * r, bool col){
  key = k;
  data = d;
  left = l;
  right = r;
  color = col;
}

template<class KT, class DT>
void TreeNode<KT, DT> :: setNodeValues(TreeNode<KT, DT> * node){
  color = node->getColor();
  data = node->getData();
  key = node->getKey();
}

template <class KT, class DT>
inline void TreeNode <KT, DT> :: setData(DT d){
  data = d;
}

template <class KT, class DT>
inline DT TreeNode <KT, DT>:: getData() const{
  return data;
}

template <class KT, class DT>
inline DT& TreeNode <KT, DT>:: getDataReference(){
  return data;
}

template <class KT, class DT>
inline void TreeNode <KT, DT> :: setKey(KT k){
  key = k;
}

template <class KT, class DT>
inline KT TreeNode <KT, DT>:: getKey() const{
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

template<class KT, class DT>
inline void TreeNode<KT, DT> :: setColor(bool col){
  color = col;
}

template<class KT, class DT>
inline bool TreeNode<KT, DT> :: getColor() const{
  return color;
}
