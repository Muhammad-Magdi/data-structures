#include "../TreeNode/TreeNode.h"
#include <iostream>

using namespace std;

template <class KT, class DT>
class Map{
private:
  int numNodes;
  TreeNode<KT, DT> * root;
  TreeNode<KT, DT> * findParent(KT)const;    //Done
  void reBalance();
public:
  Map();    //Done Coding and testing
  bool insert(KT, DT);    //Done Coding and testing
  TreeNode<KT, DT> * find(KT)const;   //Done Coding and testing
  inline bool count(KT) const;  //Done Coding and testing
  bool erase(KT);       //Done Coding and testing
  inline int size() const;    //Done Coding and testing
  void printSortedMap(TreeNode<KT, DT>*, int) const;   //Done Coding and testing
  inline TreeNode<KT, DT> * getRoot() const;    //Done Coding and testing
  DT& operator [] (KT);     //Done Coding and testing
};

#include "Map.cpp"
