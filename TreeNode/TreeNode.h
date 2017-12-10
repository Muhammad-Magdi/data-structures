template <class KT, class DT>
class TreeNode{
protected:
  KT key;
  DT data;
  TreeNode<KT, DT> * left, *right;
public:
  inline TreeNode(KT);
  TreeNode(KT, DT);
  TreeNode(KT, DT, TreeNode<KT, DT>*, TreeNode<KT, DT>*);
  inline void setData(DT);
  inline DT& getData();
  inline void setKey(KT);
  inline KT& getKey();
  inline void setLeft(TreeNode<KT, DT>*);
  inline void setRight(TreeNode<KT, DT>*);
  inline TreeNode<KT, DT>* getLeft() const;
  inline TreeNode<KT, DT>* getRight() const;
};

#include "TreeNode.cpp"
