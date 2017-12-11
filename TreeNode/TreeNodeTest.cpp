#include <iostream>
#include "TreeNode.h"

using namespace std;

int main(){
  TreeNode<int, int> T(10, 0, NULL, NULL, 1);
  cout << T.getData() << endl;
  cout << T.getKey() << endl;
  cout << T.getColor() << endl;
  return 0;
}
