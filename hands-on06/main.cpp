/**************************************************************
 * Change only                                                *
 *  1) function calcDiscount,                                 *
 *  2) its prototype                                          *
 *  3) change Pre comment in calcDiscount as appropriate,     *
 *  4) add your name into signature function!                 *
 **************************************************************/

#include <iostream>
#include <iomanip>

#define DISC_RATE 0.1

using namespace std;

// Function prototypes
void signature(void);
double calcDiscount(double&);

int main()
{
  // Declare variaables
  double amtOwing, discount;
  
  // Input amouont owed
  cout << "Enter amount owed: " ;
  cin >> amtOwing;
  
  // Calculate discount and update amount owing
  discount = calcDiscount(amtOwing);
  
  // Output discount and undated amount owed
  cout << setprecision(2) << fixed;
  cout << "Amount of Discount: " << discount << endl;
  cout << "Amount Owed: " << amtOwing << endl;
  
  signature();
  return 0;
}

///////////////////////////////////////////////////////////////

double calcDiscount(double &owe)
{
  /*
   Pre:     owe - pointer to amount owed
   Post:    Amount of discount
   Purpose: Calculate discount and update `owe` to reflect the discount
   */
  
  double disc;
  
  // Calculate Discount
  disc = DISC_RATE * owe;
  
  // Update amount owed
  owe = owe - disc;
  
  return disc;
}

//////////////////////////////////////////////////////////

void signature()
{
  cout << "Programmed by: " << "Noah Cardoza\n";
}
