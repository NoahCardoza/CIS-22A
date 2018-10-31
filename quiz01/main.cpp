#include <iostream>
#include <iomanip>
//
//int main() {
//  // I am slightly confused since you say
//  // "to output to the screen" but then say
//  // "No output needed", unless you are referring
//  // to output within a comment at the bottom of
//  // this "file" in which case this code should
//  // suffice.
//  std::cout << "Apple";
//  return 0;
//}

int main() {
  int x1 = 454, x2 = 56663, x3 =7465, x4 =54, x5=64;
//  std::cin >> x1;
//  std::cin >> x2;
//  std::cin >> x3;
//  std::cin >> x4;
//  std::cin >> x5;
  std::cout << "\n|" << std::setw(5) << x1 << '\n' << std::endl;
  std::cout << '|' << std::setw(5) << x2 << '\n' << std::endl;
  std::cout << '|' << std::setw(5) << x3 << '\n' << std::endl;
  std::cout << '|' << std::setw(5) << x4 << '\n' << std::endl;
  std::cout << '|' << std::setw(5) << x5 << '\n' << std::endl;

}
