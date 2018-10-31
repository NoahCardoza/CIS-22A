//
//  main.cpp
//  CIS 22A : Midterm Solution
//
//  Created by Noah Cardoza on 10/26/18.
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double beginningInventory,
         endingInventory,
         goodsSold,
         averageGoodsSold,
         turnover;
  
  cout << fixed << setprecision(2);
  cout << "Enter beginning inventory: ";
  cin >> beginningInventory;
  cout << "Enter ending inventory: ";
  cin >> endingInventory;
  cout << "Enter cost of goods sold: ";
  cin >> goodsSold;
  
  averageGoodsSold = (beginningInventory + endingInventory) / 2;
  turnover = goodsSold / averageGoodsSold;
  
  cout << "\nAverage Inventory: $ " << (beginningInventory + endingInventory) / 2 << endl;
  cout << fixed << setprecision(1);
  cout << "Turnover: " << turnover << endl;
  return 0;
}
