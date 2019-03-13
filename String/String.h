#include <deque>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

class String{
public:
  String(ll mod = 1e9+7, ll base = 131);
  String(string s, ll mod = 1e9+7, ll base = 131);
  inline void push_back(char c);   //O(1)
  inline void push_front(char c);  //O(1)
  void pop_back();          //O(1)
  void pop_front();         //O(1)
  inline void clear();             //O(1)
  bool operator < (const String& s)const; //O(n)
  // String operator += (const String& s); //O(n)
  // inline String operator += (char c); //O(1)

  inline int size()const{return dq.size();}
  inline ll getHash()const{return hash;}
  inline string getString()const{return string(dq.begin(), dq.end());}
  bool operator == (const String& s)const{return hash == s.getHash();}    //O(1)
private:
  ll power(ll b, ll p);
  inline ll fixMod(const ll& a, const ll& b);
  deque<char> dq;
  ll hash;
  ll mod, base, p, inv;
};
