#include <iostream>
#include "Stack.h"
#include <string>

using namespace std;

Stack<char> s1, s2;
string s, str2;

bool isAlphabit(char c){
  return (c>='a' && c<='z' || c>='A' && c<='Z');
}

void toLower(char &c){
  if(c>='a' && c<='z')  return;
  c += ('a'-'A');
}

int main(){
  freopen("input.txt", "rt", stdin);
  while(getline(cin, s)){
    while(!s1.empty())  s1.pop();
    while(!s2.empty())  s2.pop();
    bool isPalindrome = 1;
    int n = s.length();
    str2 = s;
    for(int i = 0 ; i < n ; ++i){
      if(!isAlphabit(s[i])){
        s.erase(s.begin() + i);
        --i;
        --n;
      }
      else toLower(s[i]);
    }
    for(int i = 0 ; i < n ; ++i){
      s1.push(s[i]);
      s2.push(s[n-i-1]);
    }
    while(!s1.empty()){
      if(s1.top() == s2.top()){
        s1.pop();
        s2.pop();
      }else{
        isPalindrome = 0;
        break;
      }
    }
    if(isPalindrome)  cout << str2 << " is a palindrome\n";
  }
  return 0;
}
