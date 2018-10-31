//
//  main.cpp
//  Lab 02 - Small Business Taxes
//  Calulates taxes based on total money collected
//
//  Created by Noah Cardoza on 10/8/18.
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>

#define STATE_SALES_TAX .062

using namespace std;

// used to get the length of a number and it's
// decimal to the hundredths place
int strFloatLen(string s) {
  int len;
  string::size_type index;
  
  index = s.find(".");
  len = (int) s.length();
  if (index == string::npos) {
    // if there isn't a decimal in the number
    // we add 3 ".00" (1) . (2) 0 (3) 0
    return len + 3;
  }
  // otherwise we add 3 to the index of
  // the decimal incase the user inputs
  // something like a 10th of a cent for
  // some reason
  return ((int) index) + 3;
}

int main()
{
  const float COUNTY_SALES_TAX = .026;
  
  string totalIncomeStr, month;
  
  int magicWidth; // used to align the decimal points
  
  float productSales,
        totalIncome,
        totalStateTax,
        totalCountyTax,
        totalSalesTax;
  
  cout << "Month: ";
  getline(cin, month);
  cout << "Total Collected:  $";
  cin >> totalIncomeStr;
  
  magicWidth = strFloatLen(totalIncomeStr);
  totalIncome = stof(totalIncomeStr);
  
  // calculate product sales, county sales tax, state sales tax, and total sales tax
  productSales = totalIncome / (1 + STATE_SALES_TAX + COUNTY_SALES_TAX) ;
  totalStateTax = productSales * STATE_SALES_TAX;
  totalCountyTax = productSales * COUNTY_SALES_TAX;
  totalSalesTax  = productSales * (STATE_SALES_TAX + COUNTY_SALES_TAX);
  
  // display calculations
  cout << right << setprecision(2) << fixed;
  cout << "Sales:            $" << setw(magicWidth) << productSales   << endl;
  cout << "County Sales Tax: $" << setw(magicWidth) << totalCountyTax << endl;
  cout << "State Sales Tax:  $" << setw(magicWidth) << totalStateTax  << endl;
  cout << "Total Tales Tax:  $" << setw(magicWidth) << totalSalesTax  << endl;
  cout << "\nProgrammed By: Noah Cardoza" << endl;
  
  return 0;
}

//Month: September 2018
//Total Collected:  $93187.47
//Sales:            $85650.25
//County Sales Tax: $ 2226.91
//State Sales Tax:  $ 5310.32
//Total Tales Tax:  $ 7537.22
//
//Programmed By: Noah Cardoza

