#include <iostream>


int main(){

  std::cout << "Enter two numbers:" << std::endl;
  int v1, v2;

  std::cin >> v1 >> v2; // read input
                        // use smaller number as lower bound for printing the range
                        // and larger number as upper bound

  int lower, upper;

  if (v1 <= v2) {
    lower = v1;
    upper = v2;
  } else {
    lower = v2;
    upper = v1;
  }

  // print values fromlower up to and but not including upper
  int newline_ctr = 0;

  for (int val = lower; val != upper; ++val) {
    std::cout << val << " ";
    ++newline_ctr; // increment counter to indicate another value printed

    if (newline_ctr == 10) { // if we’ve already printed 10 values
      std::cout << std::endl; // print this line
      newline_ctr = 0; // and reset the counter to 0
    }
  }

  std::cout << std::endl;

  return 0;

}
