#include <iostream>
#include <iomanip>

#define SHIPPING_PER_OUNCE 0.12
#define OUNCES_PER_POUND 16

using namespace std;

int main(int argc, const char * argv[]) {
  double pounds, ounces;
  
  cout << setprecision(2) << fixed;
  
  cout << "Enter number of pounds: ";
  cin >> pounds;
  cout << "Enter number of ounces: ";
  cin >> ounces;
  
  ounces += pounds * OUNCES_PER_POUND;
  
  cout << "\nCost: $" << ounces * SHIPPING_PER_OUNCE << endl;
  
  return 0;
}
