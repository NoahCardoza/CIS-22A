//
//  main.cpp
//  Lab: 03
//  Email: noahcardoza@gmail.com
//
//  Created by Noah Cardoza on 10/20/18.
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <limits>

#define TAX_RATE 0.09250010886

using namespace std;

void printTableHeader() {
  cout << "QTY    Description          Unit Price          Total Price" << endl;
}

// formats each row in the table and returns
// the subtotal for each item
float printTableRow(int qty, string desc, float price) {
  cout << setw(2)   << right << qty << "     ";
  cout << setw(21)  << left  << desc;
  cout << setw(9)   << right << price << "           ";
  cout << setw(10)  << right << qty * price << endl;
  
  return qty * price;
}

// returns only one integer per line
void getNextInt(istream &stream, int &n){
  stream >> n;
  stream.ignore(numeric_limits<int>::max(), '\n');
}

// asks a question and expects a interger in return
int askForInt(string q) {
  int n;
  cout << q << "? ";
  getNextInt(cin, n);
  return n;
}

int main(int argc, const char * argv[]) {
  // Declare and initiate constant price variables for each product
  const float
    EXTERNAL_MONITOR_PRICE = 182.15,
    DELL_KEYBOARD_PRICE = 18.30,
    DELL_MOUSE_PRICE = 16.45,
    WINDOWS_OS_PRECISION_T1700_PRICE = 2020.00,
    NETWORK_PRINTER_PRICE = 1100.00;
  
  float subtotal = 0;
  
  // Declare variables to hold the number and types of items purchased
  int monitors, keyboards, mice, windows, printers;
  
  // Ask user for the number of each item ordered
  monitors  = askForInt("How many External Monitors were ordered");
  keyboards = askForInt("How many Dell keyboards players were ordered");
  mice      = askForInt("How many Dell Mouse units were ordered");
  windows   = askForInt("How many Windows OS were ordered");
  printers  = askForInt("How many Network Printers were ordered");
  
  cout << setprecision(2) << fixed << endl;
  
  printTableHeader();
  
  // Print each row of the table
  subtotal += printTableRow(monitors,   "EXTERNAL MONITOR", EXTERNAL_MONITOR_PRICE);
  subtotal += printTableRow(keyboards,  "DELL KEYBOARD",    DELL_KEYBOARD_PRICE);
  subtotal += printTableRow(mice,       "DELL MOUSE",       DELL_MOUSE_PRICE);
  subtotal += printTableRow(windows,    "WINDOWS OS",       WINDOWS_OS_PRECISION_T1700_PRICE);
  subtotal += printTableRow(printers,   "NETWORKED PRINTER",  NETWORK_PRINTER_PRICE);
  
  cout << endl;
  
  // Calculate and provide subtotal, tax, and total information
  cout << setw(28) << "SUBTOTAL" << setw(15) << subtotal << endl;
  cout << setw(28) << "TAX"      << setw(15) << subtotal * TAX_RATE << endl;
  cout << setw(28) << "TOTAL"    << setw(15) << subtotal + (subtotal * TAX_RATE) << endl;
  
  cout << endl;
  
  // Assignment signature
  cout << "Programmed By: Noah Cardoza" << endl;
  cout << "Email: noahcardoza@gmail.com" << endl;
  cout << "Date: 10/20/18" << endl;
  return 0;
}

/*
 How many External Monitors were ordered? 1
 How many Dell keyboards players were ordered? 1
 How many Dell Mouse units were ordered? 10
 How many Windows OS were ordered? 10
 How many Network Printers were ordered? 5
 
 QTY    Description          Unit Price          Total Price
  1     EXTERNAL MONITOR        182.15               182.15
  1     DELL KEYBOARD            18.30                18.30
 10     DELL MOUSE               16.45               164.50
 10     WINDOWS OS             2020.00             20200.00
  5     NETWORKED PRINTER      1100.00              5500.00
 
                     SUBTOTAL       26064.95
                          TAX        2411.01
                        TOTAL       28475.96
 
 Programmed By: Noah Cardoza
 Email: noahcardoza@gmail.com
 Date: 10/20/18
 */
