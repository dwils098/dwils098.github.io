#include <iostream>

using namespace std;

int main(){
  int n ;
  cin >> n ;
  switch (n){
    case 0 : cout << "Nul\n" ;
    case 1 :
    case 2 : cout << "Petit\n" ;
    break ;
    case 3 :
    case 4 :
    case 5 : cout << "Moyen\n" ;
    default : cout << "Grand\n" ;
  }
return 0;
}
