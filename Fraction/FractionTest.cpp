#include <bits/stdc++.h>
#include "Fraction.h"

using namespace std;

string s, s1, s2, op, s3;
Fraction x, y, c;
int n;

int main(){
  freopen("i.in", "rt", stdin);
  try{
    while(getline(cin, s)){
      stringstream ss = stringstream(s);
      ss >> s1 >> op;
      x = Fraction(s1);
      if(op == "I")
        printFraction(x.invert());
      else if(op == "+"){
        ss >> s2;
        y = Fraction(s2);
        printFraction(x+y);
      }
      else if(op == "-"){
        ss >> s2;
        y = Fraction(s2);
        printFraction(x-y);
      }
      else if(op == "*"){
        ss >> s2;
        y = Fraction(s2);
        printFraction(x*y);
      }
      else if(op == "/"){
        ss >> s2;
        y = Fraction(s2);
        printFraction(x/y);
      }
      else if(op == "M")
        printMixedFraction(x);
      else if(op == "R")
        printFraction(x.reduce());
      else if(op == "G")
        printf("%d", GCD(x.getNum(), x.getDenom()));
      else if(op == "L"){
        ss >> s2;
        y = Fraction(s2);
        printf("%d", LCM(x.getDenom(), y.getDenom()));
      }
      else if(op == "<"){
        ss >> s2;
        y = Fraction(s2);
        printf("%s", x<y ? "True" : "False");
      }
      else if(op == "<="){
        ss >> s2;
        y = Fraction(s2);
        printf("%s", x<=y ? "True" : "False");
      }
      else if(op == ">"){
        ss >> s2;
        y = Fraction(s2);
        printf("%s", x>y ? "True" : "False");
      }
      else if(op == ">="){
        ss >> s2;
        y = Fraction(s2);
        printf("%s", x>=y ? "True" : "False");
      }
      else if(op == "="){
        ss >> s2;
        y = Fraction(s2);
        printf("%s", x==y ? "True" : "False");
      }
      else if(op == "X"){
        ss >> op >> s2 >> op >> s3;
        Fraction y = Fraction(s2), z = Fraction(s3);
        Fraction ans = (z-y)/x;
        printf("X=");
        printFraction(ans.reduce());
      }
      puts("");
    }
  }catch(const char * s){
    cerr <<s << endl;
  }
  return 0;
}
