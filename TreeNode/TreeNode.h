template <class KT, class DT>
class TreeNode{
protected:
  KT key;
  DT data;
  bool color;
  TreeNode<KT, DT> * left, *right;
public:
  inline TreeNode(KT);
  TreeNode(KT, DT);
  TreeNode(KT, DT, TreeNode<KT, DT>*, TreeNode<KT, DT>*, bool);
  inline void setData(DT);
  inline DT getData() const;
  inline DT& getDataReference();
  void setNodeValues(TreeNode<KT, DT>*);
  inline void setKey(KT);
  inline KT getKey() const;
  inline void setLeft(TreeNode<KT, DT>*);
  inline TreeNode<KT, DT>* getLeft() const;
  inline void setRight(TreeNode<KT, DT>*);
  inline TreeNode<KT, DT>* getRight() const;
  inline void setColor(bool);
  inline bool getColor() const;
};

#include "TreeNode.cpp"
