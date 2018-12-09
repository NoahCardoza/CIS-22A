//
//  main.cpp
//  lab06 - Credit Card Debt
//  email - noahcardoza@gmail.com
//
//  Created by Noah Cardoza on 11/28/18.
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>

#define USE_FILE

using namespace std;

void printRow(ostream &fd, int month, double balance, double interest, double min, double sum);
void printHeader(ostream &fd);
void printInformation(ostream &fd, double balance, double apr, double minPayment);
void calculate(double &balance, double mpr, double minPayment, double &min, double &sum, double &interest);
void init(double &balance, double &apr, double &minPayment);

int main(void) {
  // Define Variables
  int month = 1;
  double balance, mpr, minPayment, interest, min, sum = 0;

  #ifdef USE_FILE
    // Open file if USE_FILE is true
    ofstream outFile;
    outFile.open("output.txt");
    ostream &out = outFile;
  #else
    // Use stdout otherwise
    ostream &out = cout;
  #endif
  
  // Initialize Variables
  init(balance, mpr, minPayment);
  // Print Inital Information
  printInformation(out, balance, mpr * 12, minPayment);
  printHeader(out);
  // Calculate the rows
  while (balance > 1) {
    calculate(balance, mpr, minPayment, min, sum, interest);
    printRow(out, month++, balance, interest, min, sum);
  }
  
  out << "\nProgrammed By: Noah Cardoza\nEmail: noahcardoza@gmail.com\nLab 6: Credit Card Debt" << endl;
  
  #ifdef USE_FILE
    // Close file if USE_FILE is true
    outFile.close();
  #endif
  return 0;
}

void init(double &balance, double &apr, double &minPayment) {
  //  Pre     :
  //    balance     - reference to the balance owed
  //    apr         - reference to the anual interest rate
  //    minPayment  - reference to the minimum payment
  //  Post    : N/A
  //  Purpose : Initalize the input reference variables from file
  ifstream inFile;
  
  inFile.open("lab6.txt");
  inFile >> balance;
  inFile >> apr;
  inFile >> minPayment;
  
  apr = apr / 100.0 / 12.0;
  minPayment /= 100.0;
  inFile.close();
}

void calculate(double &balance, double mpr, double minPayment, double &min, double &sum, double &interest) {
  //  Pre     :
  //    balance     - reference to the balance owed
  //    mpr         - monthly interest rate
  //    minPayment  - the minimum payment threshold
  //    min         - reference to the actual minimumpayment
  //    sum         - reference to the sum of payments
  //    interest    - reference to the interest rate
  //  Post    : N/A
  //  Purpose : calculates the values for each month
  interest = mpr * balance;
  balance += interest;
  min = balance * minPayment;
  min = (min < 15.0 ? 15.0 > balance ? balance : 15.0 : min);
  balance -= min;
  sum += interest;
}

void printInformation(ostream &fd, double balance, double apr, double minPayment){
  //  Pre     :
  //    fd          - reference to the file descriptor / output stream
  //    balance     - the balance owed
  //    mpr         - annual interest rate
  //    minPayment  - the minimum payment threshold
  //  Post    : N/A
  //  Purpose : prints out the header information to an output steam
  fd << fixed << setprecision(2);
  fd << "Balance Owed: $" << balance << endl;
  fd << setprecision(0);
  fd << "APR as %" << apr * 100 << endl;
  fd << "Percent for minimum payment as %" << minPayment * 100 << endl;
  fd << setprecision(2);
}

void printHeader(ostream &fd){
  //  Pre     :
  //    fd          - reference to the file descriptor / output stream
  //  Post    : N/A
  //  Purpose : prints out the table header to an output steam
  fd << "Month   Balance    Interest    Minimum        Sum of\n"
  << "                               this month     interest paid\n";
}
void printRow(ostream &fd, int month, double balance, double interest, double min, double sum){
  //  Pre     :
  //    fd          - reference to the file descriptor / output stream
  //    month       - the current month
  //    balance     - the balance owed
  //    interest    - the interest rate
  //    min         - the actual minimumpayment
  //    sum         - the sum of payments
  //  Post    : N/A
  //  Purpose : prints a table row to an output steam
  fd << setw(5) << month++ << setw(10) << balance << setw(12) << interest << setw(14) << min << setw(18) << sum << endl;
}

/*
 Balance Owed: $624.00
 APR as %24
 Percent for minimum payment as %4
 Month   Balance    Interest    Minimum        Sum of
 this month     interest paid
 1    611.02       12.48         25.46             12.48
 2    598.31       12.22         24.93             24.70
 3    585.87       11.97         24.41             36.67
 4    573.68       11.72         23.90             48.38
 5    561.75       11.47         23.41             59.86
 6    550.06       11.23         22.92             71.09
 7    538.62       11.00         22.44             82.09
 8    527.42       10.77         21.98             92.87
 9    516.45       10.55         21.52            103.41
 10    505.71       10.33         21.07            113.74
 11    495.19       10.11         20.63            123.86
 12    484.89        9.90         20.20            133.76
 13    474.80        9.70         19.78            143.46
 14    464.93        9.50         19.37            152.96
 15    455.26        9.30         18.97            162.25
 16    445.79        9.11         18.57            171.36
 17    436.51        8.92         18.19            180.27
 18    427.43        8.73         17.81            189.01
 19    418.54        8.55         17.44            197.55
 20    409.84        8.37         17.08            205.92
 21    401.31        8.20         16.72            214.12
 22    392.97        8.03         16.37            222.15
 23    384.79        7.86         16.03            230.01
 24    376.79        7.70         15.70            237.70
 25    368.95        7.54         15.37            245.24
 26    361.28        7.38         15.05            252.62
 27    353.50        7.23         15.00            259.84
 28    345.57        7.07         15.00            266.91
 29    337.48        6.91         15.00            273.82
 30    329.23        6.75         15.00            280.57
 31    320.82        6.58         15.00            287.16
 32    312.24        6.42         15.00            293.58
 33    303.48        6.24         15.00            299.82
 34    294.55        6.07         15.00            305.89
 35    285.44        5.89         15.00            311.78
 36    276.15        5.71         15.00            317.49
 37    266.67        5.52         15.00            323.01
 38    257.01        5.33         15.00            328.35
 39    247.15        5.14         15.00            333.49
 40    237.09        4.94         15.00            338.43
 41    226.83        4.74         15.00            343.17
 42    216.37        4.54         15.00            347.71
 43    205.69        4.33         15.00            352.03
 44    194.81        4.11         15.00            356.15
 45    183.70        3.90         15.00            360.04
 46    172.38        3.67         15.00            363.72
 47    160.83        3.45         15.00            367.17
 48    149.04        3.22         15.00            370.38
 49    137.02        2.98         15.00            373.36
 50    124.76        2.74         15.00            376.10
 51    112.26        2.50         15.00            378.60
 52     99.51        2.25         15.00            380.84
 53     86.50        1.99         15.00            382.84
 54     73.23        1.73         15.00            384.56
 55     59.69        1.46         15.00            386.03
 56     45.88        1.19         15.00            387.22
 57     31.80        0.92         15.00            388.14
 58     17.44        0.64         15.00            388.78
 59      2.79        0.35         15.00            389.13
 60      0.00        0.06          2.84            389.18
 
 Programmed By: Noah Cardoza
 Email: noahcardoza@gmail.com
 Lab 6: Credit Card Debt
 Program ended with exit code: 0
 */
