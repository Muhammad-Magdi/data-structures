#include "Map.h"
#include <iostream>

using namespace std;

int main(){
  Map<int, int> mp;
  cout << mp.insert(10, 15) << endl;
  cout << mp.insert(1005, 120) << endl;
  cout << mp.insert(10, 1024) << endl;
  cout << mp.insert(11, 12) << endl;
  cout << mp.insert(17, 12000) << endl;
  cout << mp.insert(107, 12000) << endl;
  cout << mp.size() << endl;
  cout << mp.count(10) << endl;
  mp.printSortedMap(mp.getRoot(), 1);
  return 0;
}
