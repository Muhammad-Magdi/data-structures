#include <iostream>
#include "Stack.h"

using namespace std;

int n, x;

int main(){
  Stack<int> st;
  scanf("%d\n", &n);
  for(int i = 0 ; i < n ; ++i){
    scanf("%d", &x);
    st.push(x);
  }
  Stack<int> st2(st);
  while(!st.empty()){
    printf("%d ", st.top());
    st.pop();
  }
  puts("");
  while(!st2.empty()){
    printf("%d ", st2.top());
    st2.pop();
  }
  puts("");
  return 0;
}
