#include "DoublyNode.h"
#include <iostream>

using namespace std;

int main(){
  DoublyNode<int> n;
  n.setVal(100);
  cout << n.getVal() << endl;
  n.setVal(10);
  cout << n.getVal() << endl;
  return 0;
}
