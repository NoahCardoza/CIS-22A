//
//  main.cpp
//  hands-on05 - US Population
//
//  Created by Noah Cardoza on 11/12/18.
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ctime>

#define GROWTH_RATE 1.007

using namespace std;

int main() {
  // Initialize Variables
  int year;
  double population;
  
  // Fetch Current Year
  time_t t = time(0);
  tm* now = localtime(&t);
  year = now->tm_year + 1900;
  
  // Ask For Input
  cin >> population;
  
  // Setup Decimal Formatting
  cout << fixed << setprecision(1);
  
  // Generate Output
  while ((population *= GROWTH_RATE) <= 400.0)
    cout << year++ << setw(8) << population << '\n';
  
  // Assignment Signature
  cout << "\nProgrammed By: Noah Cardoza" << endl;
  return 0;
}

/*
 325.7
 2018   328.0
 2019   330.3
 2020   332.6
 2021   334.9
 2022   337.3
 2023   339.6
 2024   342.0
 2025   344.4
 2026   346.8
 2027   349.2
 2028   351.7
 2029   354.1
 2030   356.6
 2031   359.1
 2032   361.6
 2033   364.2
 2034   366.7
 2035   369.3
 2036   371.9
 2037   374.5
 2038   377.1
 2039   379.7
 2040   382.4
 2041   385.1
 2042   387.8
 2043   390.5
 2044   393.2
 2045   396.0
 2046   398.7
 
 Programmed By: Noah Cardoza
 */
