#include "DoublyNode.h"
#include <iostream>

using namespace std;

int main(){
  DoublyNode<int> n;
  n.setData(100);
  cout << n.getData() << endl;
  n.setData(10);
  cout << n.getData() << endl;
  return 0;
}
