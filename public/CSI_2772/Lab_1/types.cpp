#include <iostream>
#include <typeinfo>

int main(){
  char c = '\x01';
  short int p = 10;

  std::cout << "Resultat 1: " << typeid(p + 3).name() << '\n';
  std::cout << "Resultat 2: " << typeid(c + 1).name() << '\n';
  std::cout << "Resultat 3: " << typeid(p + c).name() << '\n';
  std::cout << "Resultat 4: " << typeid(3 * p + 5 * c).name() << '\n';

  char a = '\x05';
  int n = 5;
  long o = 1000;
  float x = 1.25;
  double z = 5.5;

  float l = (float) z + n / 2;
  char io = (char) n + a;

  std::cout << "Resultat 1: " << typeid(n + a + o).name() << '\n';
  std::cout << "Resultat 2: " << typeid(2 * x + a).name() << '\n';
  std::cout << "Resultat 3: " << typeid(io).name() << '\n';
  std::cout << "Resultat 4: " << typeid(l).name() << '\n';
}
