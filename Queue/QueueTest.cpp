#include <iostream>
#include "Queue.h"

using namespace std;

int n, x;

int main(){
  Queue<int> q;
  for(int i = 0 ; i <= 10 ; ++i)
    q.push(i);
  q.front() = 10;
  while(!q.empty()){
    cout << q.front() << endl;
    q.pop();
  }
  for(int i = 0 ; i <= 10 ; ++i)
  q.push(i);
  q.clear();
  while(!q.empty()){
    cout << q.front() << endl;
    q.pop();
  }
  return 0;
}
