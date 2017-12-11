#include "Map.h"
#include <iostream>

using namespace std;

int main(){
  Map<int, int> mp;
  mp[10] = 15;
  mp.printSortedMap(mp.getRoot(), 1);
  puts("");
  mp.erase(10);
  printf("The size is %d\n", mp.size());
  mp.printSortedMap(mp.getRoot(), 1);
  puts("");
  mp.insert(15, 10);
  mp.printSortedMap(mp.getRoot(), 1);
  puts("");
  mp.insert(100, 12);
  mp[1] = 15;
  mp[7] = 23;
  mp.insert(0, 10);
  printf("The size is %d\n", mp.size());
  mp.printSortedMap(mp.getRoot(), 1);
  puts("");
  mp.erase(15);
  printf("The size is %d\n", mp.size());
  mp.printSortedMap(mp.getRoot(), 1);
  puts("");
  mp.erase(10);
  printf("The size is %d\n", mp.size());
  mp.printSortedMap(mp.getRoot(), 1);
  puts("");
  return 0;
}
