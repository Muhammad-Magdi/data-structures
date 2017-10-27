#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

void reverse(string & x){
  Stack<char> st;
  int n = x.length();
  for(int i = 0 ; i < n ; ++i)
    st.push(x[i]);
  x = "";
  while(!st.empty()){
    x += st.top();
    st.pop();
  }
}

inline int sum(int x, int y, int c){
  return (x+y+c)%10;
}

inline int carry(int x, int y, int c){
  return (x+y+c)/10;
}

void removeZeros(string & x){
  while(x.back() == '0')
    x.pop_back();
}

string BigIntegerAdd(string &a, string & b){
  int n = a.length(), m = b.length();
  reverse(a);
  reverse(b);
  string ans = "";
  int car = 0, mini = min(n, m);
  for(int i = 0 ; i < mini ; ++i){
    ans.push_back('0' + sum(a[i]-'0', b[i]-'0', car));
    car = carry(a[i]-'0', b[i]-'0', car);
  }
  for(int i = mini ; i < n ; ++i){
    ans.push_back('0' + sum(a[i]-'0', 0, car));
    car = carry(a[i]-'0', 0, car);
  }
  for(int i = mini ; i < m ; ++i){
    ans.push_back('0' + sum(0, b[i]-'0', car));
    car = carry(0, b[i]-'0', car);
  }
  if(car) ans.push_back('0'+car);
  removeZeros(ans);
  reverse(ans);
  return ans;
}

int main(){
  string a, b;
  cin >> a >> b;
  cout << BigIntegerAdd(a, b) << endl;
  return 0;
}
