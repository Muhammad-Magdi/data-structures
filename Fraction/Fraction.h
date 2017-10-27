#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class Fraction{
private:
  int num, denom;
public:
  Fraction();
  Fraction(int);
  Fraction(int, int, int);
  Fraction(string);
  Fraction invert();
  int getNum();
  int getDenom();
  int getSign();
  void setNum(int);
  void setDenom(int);
  Fraction reduce();
  Fraction operator +(const Fraction &) const;
  Fraction operator -(const Fraction &) const;
  Fraction operator *(const Fraction &) const;
  Fraction operator /(const Fraction &) const;
  bool operator <(const Fraction &) const;
  bool operator <=(const Fraction &) const;
  bool operator >(const Fraction &) const;
  bool operator >=(const Fraction &) const;
  bool operator ==(const Fraction &) const;
};

#include "Fraction.cpp"
