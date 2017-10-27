static int GCD(int a, int b){
  if(!a)  return b;
  return GCD(b%a, a);
}

static int LCM(int a, int b){
  return (a*b)/GCD(a, b);
}

Fraction :: Fraction(){
  num = 0;
  denom = 1;
}

Fraction :: Fraction(int n){
  num = n;
  denom = 1;
}

Fraction :: Fraction(int n, int d, int reduce = 0){
  if(!d)  throw "Can't Divide by ZERO\n";
  int g = reduce? GCD(abs(n), abs(d)) : 1;
  if(d<0){
    d = abs(d);
    n*=-1;
  }
  num = n/g;
  denom = d/g;
}

Fraction :: Fraction(string s){
  int a = 0, b = 0, e = 1000000007, i = 0;
  string sa, sb;
  stringstream ss = stringstream(s);
  getline(ss, sa, '/');
  a = stoi(sa);
  getline(ss, sb);
  b = (sb!=""? stoi(sb) : 1);
  if(b<0){
    b = abs(b);
    a*=-1;
  }
  num = a;
  denom = b;
}

Fraction Fraction :: reduce(){
  int g = GCD(num, denom);
  return Fraction(num/g, denom/g);
}

int Fraction :: getNum(){
  return num;
}

int Fraction :: getDenom(){
  return denom;
}

void Fraction :: setNum(int _num){
  num = _num;
}

void Fraction :: setDenom(int _denom){
  if(!_denom)  throw "Can't Divide by ZERO\n";
  denom = _denom;
}

static Fraction readFraction(bool prntMsg = 1){
  int x, y;
  char slash;
  do{
    if(prntMsg) puts("Enter a Fraction in the form a/b : ");
    scanf("%d%c%d", &x, &slash, &y);
  }while(slash != '/');
  return Fraction(x, y);
}

static Fraction printFraction(Fraction  f){
  printf("%d/%d", f.getNum(), f.getDenom());
}

static void printMixedFraction(Fraction  f){
  int q = f.getNum()/f.getDenom(), r = (abs(f.getNum())+f.getDenom())%f.getDenom();
  if(f.getNum()<0) printf("-(");
  if(q && r)
    printf("%d + %d/%d", abs(q), abs(r), f.getDenom());
  else if(q)
    printf("%d", abs(q));
  else
    printf("%d/%d", abs(r), f.getDenom());
  if(f.getNum()<0) printf(")");
}

Fraction Fraction :: invert(){
  if(!num)  throw "Can't Divide by ZERO\n";
  return Fraction(denom, num);
}

Fraction Fraction :: operator + (const Fraction & f) const{
  Fraction tmp = Fraction(num*f.denom + denom*f.num, denom*f.denom, 1);
  return tmp;
}

Fraction Fraction :: operator - (const Fraction & f) const{
  Fraction tmp = Fraction(num*f.denom - denom*f.num, denom*f.denom, 1);
  return tmp;
}

Fraction Fraction :: operator * (const Fraction & f) const{
  Fraction tmp = Fraction(num*f.num, denom*f.denom, 1);
  return tmp;
}

Fraction Fraction :: operator / (const Fraction & f) const{
  Fraction tmp = Fraction(num*f.denom, denom*f.num, 1);
  return tmp;
}

bool Fraction :: operator < (const Fraction & f) const{
  //a*d < b*c
  return (num*f.denom < f.num*denom);
}

bool Fraction :: operator <= (const Fraction & f) const{
  //a*d < b*c
  return (num*f.denom <= f.num*denom);
}

bool Fraction :: operator > (const Fraction & f) const{
  //a*d > b*c
  return (num*f.denom > f.num*denom);
}

bool Fraction :: operator >= (const Fraction & f) const{
  //a*d > b*c
  return (num*f.denom >= f.num*denom);
}

bool Fraction :: operator == (const Fraction & f) const{
  //a*d > b*c
  int g1 = GCD(num, denom), g2 = GCD(f.num, f.denom);
  return (num/g1 == f.num/g2 && denom/g1 == f.denom/g2);
}
