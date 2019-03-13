#include "String.h"
#include <deque>
#include <string>
#include <cstring>
using namespace std;

String :: String(ll mod, ll base){
  this->mod = mod;
  this->base = base;
  this->hash = 0;
  this->inv = power(base, mod-2);   //Fermat's Little Theorim
  p = 1;
}

String :: String(string s, ll mod, ll base){
  String(mod, base);
  for(char c : s){
    push_back(c);
  }
}

//123 = 12*10 + 3
inline void String :: push_back(char c){
  dq.push_back(c);
  p = (p*base)%mod;
  hash = ((hash*base)%mod + c)%mod;
}

//123 = 23 + 1*100
inline void String :: push_front(char c){
  dq.push_front(c);
  hash = (hash + (c*p)%mod)%mod;
  p = (p*base)%mod;
}

//12 = (123 - 3)/10
void String :: pop_back(){
  hash = fixMod((hash - dq.back()) * inv, mod);
  dq.pop_back();
  p = (p*inv)%mod;
}

//23 = (123 - 1*100)
void String :: pop_front(){
  hash = fixMod((hash - p*dq.front()), mod);
  dq.pop_front();
  p = (p*inv)%mod;
}

inline void String :: clear(){
  dq.clear();
  hash = 0;
  p = 1;
}

inline ll String :: fixMod(const ll& a, const ll& b){
  return (a%b + b)%b;
}

ll String :: power(ll a, ll b){
  if(!b)  return 1;
  ll ret = power(a, b>>1)%mod;
  return (((ret*ret)%mod)*(b&1 ? a : 1))%mod;
}

// bool operator < (const String& s)const; //O(n)

// inline String operator += (char c){
//   push_back(c);
//   return *this;
// }
