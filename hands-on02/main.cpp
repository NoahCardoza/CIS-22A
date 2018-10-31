//
//  main.cpp
//  hands-on02
//
//  Adapted by Noah Cardoza from Mary Pape on 10/8/18.
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  //Utility-type expenses
  double pge = 247.5, xfinity = 186.5, garbage = 105, att = 77.40, water = 141.78;
  
  double total;
  
  //Calculate total
  total = pge + xfinity + garbage + att + water;
  
  //Output expenses
  cout << setprecision(2) << fixed << showpoint;
  cout << left << setw(20) << "PG&E" << right << setw(6) << pge << endl;
  cout << left << setw(20) << "TV and Internet" << right << setw(6) << xfinity << endl;
  cout << left << setw(20) << "Waste Management" << right << setw(6) << garbage << endl;
  cout << left << setw(20) << "Cell devices" << right << setw(6) << att << endl;
  cout << left << setw(20) << "Water" << right << setw(6) << water << endl;
  cout << setw(26) << "_____________" << endl;
  cout << left << setw(20) << "Total" << total << endl;

  
  return 0;
}

//PG&E                247.50
//TV and Internet     186.50
//Waste Management    105.00
//Cell devices         77.40
//Water               141.78
//             _____________
//Total               758.18

