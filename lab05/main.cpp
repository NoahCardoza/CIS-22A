//
//  main.cpp
//  lab05 - Monthly House Costs
//  email - noahcardoza@gmail.com
//
//  Created by Noah Cardoza on 11/12/18.
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>

#define PROPERTY_TAX_RATE (0.0125 / 12.0) // (monthly) 1.25% / 12
#define COST_OF_UTILITIES 300.00
#define COST_OF_INSURANCE (550.00 / 12.0) // (monthly)

using namespace std;

double calculateMorgagePayment(double, double, int);
void initializeVariables(double&, double&, int&);
void subCalculation(double&, double&, double&, double, double, int);
void calculations(double&, double&, double&, double, double&, double, int, double&);
void output(double, double, double, double, double, double, int, double);

int main() {
  // Declare All Variables
  double loanAmount, interestRate,
    morgage, propertyTax, downPayment, sellingPrice, total;
  int years;
  
  // Execute The Main Functions
  initializeVariables(sellingPrice, interestRate, years);
  calculations(morgage, propertyTax, downPayment, sellingPrice, loanAmount, interestRate, years, total);
  output(morgage, propertyTax, downPayment, sellingPrice, loanAmount, interestRate, years, total);
  
  // Send A Sucessful Exit Code
  return 0;
}

void subCalculation(double& downPayment, double& loanAmount, double& morgage, double interestRate, double sellingPrice, int years){
  const double  PERCENTAGE_OF_DOWN_PAYMENT = 0.2; // 20%
  /*
   Pre     :
     downPayment  - reference to the down payment not to be included in the loan
     loanAmount   - reference to the amount of loan
     morgage      - reference to the morgage rate paid per month
     interestRate - rate of interest per compounding period (annual rate / 12)
     sellingPrice - the total price of the house
     years        - number of compounding periods in years
   Post    : N/A
   Purpose : calculates the downPayment, loanAmount, and morgage values
   */
  downPayment = sellingPrice * PERCENTAGE_OF_DOWN_PAYMENT;
  loanAmount = sellingPrice - downPayment;
  morgage = calculateMorgagePayment(loanAmount, interestRate, years);
}

void calculations(double& morgage, double& propertyTax, double& downPayment, double sellingPrice, double& loanAmount, double interestRate, int years, double& total){
  /*
   Pre     :
     morgage      - reference to the morgage rate paid per month
     propertyTax  - reference to the tax to be paid on the selling price of the house per year
     downPayment  - reference to the down payment not to be included in the loan
     sellingPrice - the total price of the house
     loanAmount   - reference to the amount of loan
     interestRate - rate of interest per compounding period (annual rate / 12)
     years        - number of compounding periods in years
     total        - reference to the the total the new home owner will pay
   Post    : N/A
   Purpose : calculates preforms all the required calculations
   */
  
  subCalculation(downPayment, loanAmount, morgage, interestRate, sellingPrice, years);
  propertyTax = sellingPrice * PROPERTY_TAX_RATE;
  total = morgage + COST_OF_UTILITIES + COST_OF_INSURANCE + propertyTax;
}

void initializeVariables(double& sellingPrice, double& interestRate, int& years){
  /*
   Pre     :
     sellingPrice - reference to the cost of the house
     interestRate - reference to the interest rate
     years        - reference to the number of years
   Post    : N/A
   Purpose : Initalize the required variables with user input
   */
// The instructions stated that only the output function should generate output
// if you would like a more user friendly interface uncomment the lines below
//  cout << "What is the price of the house: ";
  cin >> sellingPrice;
//  cout << "What is the loan's interest rate: ";
  cin >> interestRate;
  interestRate /= 100.0;
//  cout << "How many years will the loan must be paid: ";
  cin >> years;
}

void output(double morgage, double propertyTax, double downPayment, double sellingPrice, double loanAmount, double interestRate, int years, double total){
  cout << setprecision(2) << fixed
    << "\nMONTHLY COST OF HOUSESELLING\n\n"
    << left << setw(30) << "PRICE"                    << right << "$" << setw(9) << sellingPrice << "\n"
    << left << setw(30) << "DOWN PAYMENT"             << right << "$" << setw(9) << downPayment  << "\n"
    << left << setw(30) << "AMOUNT OF LOAN"           << right << "$" << setw(9) << loanAmount   << "\n"
    << setprecision(1)
    << left << setw(30) << "INTEREST RATE"            << right << setw(9)  << interestRate * 100 << "%" << "\n"
    << left << setw(30) << "TAX RATE"                 << right << setw(9)  << PROPERTY_TAX_RATE * 100  << "%" << "\n"
    << setprecision(2)
    << left << setw(30) << "DURATION OF LOAN (YEARS)" << right << setw(10) << years              << "\n"
    << "MONTHLY PAYMENT\n"
    << left << setw(30) << "    MORTGAGE"             << right << "$" << setw(9) << morgage            << "\n"
    << left << setw(30) << "    UTILITIES"            << right << "$" << setw(9) << COST_OF_UTILITIES  << "\n"
    << left << setw(30) << "    PROPERTY TAXES"       << right << "$" << setw(9) << propertyTax        << "\n"
    << left << setw(30) << "    INSURANCE"            << right << "$" << setw(9) << COST_OF_INSURANCE  << "\n"
    << right << setw(40)<< "___________" << "\n"
    << right << setw(30)<< ""                         << right << "$" << setw(9) << total << "\n\n"
  << "Lab: 05 (Monthly House Costs)\nProgrammed By: Noah Cardoza\nEmail: noahcardoza@gmail.com" << endl;
}

double calculateMorgagePayment(double a, double i, int n) {
  /*
   Pre     :
     a - amount of loan
     i - rate of interest
     n - number of years
   Post    : monthly mortgage payments
   Purpose : calculates the monthly mortgage payments
   */
  i /= 12; // rate of interest per compounding period (annual rate / 12)
  n *= 12; // number of compounding periods (yrs * 12)
  return ((a * i * pow(1 + i, n)) / (pow(1 + i, n) - 1));
}

// I didn't see a request for output as a comment but I dicided to add it anyways ;)

/*
 600000
 4
 20
 
 MONTHLY COST OF HOUSESELLING
 
 PRICE                         $600000.00
 DOWN PAYMENT                  $120000.00
 AMOUNT OF LOAN                $480000.00
 INTEREST RATE                       4.0%
 TAX RATE                            0.1%
 DURATION OF LOAN (YEARS)              20
 MONTHLY PAYMENT
     MORTGAGE                  $  2908.71
     UTILITIES                 $   300.00
     PROPERTY TAXES            $   625.00
     INSURANCE                 $    45.83
                               ___________
                               $  3879.54
 
 Lab: 05 (Monthly House Costs)
 Programmed By: Noah Cardoza
 Email: noahcardoza@gmail.com
 */

/*
 40000
 4.2
 30
 
 MONTHLY COST OF HOUSESELLING
 
 PRICE                         $ 40000.00
 DOWN PAYMENT                  $  8000.00
 AMOUNT OF LOAN                $ 32000.00
 INTEREST RATE                       4.2%
 TAX RATE                            0.1%
 DURATION OF LOAN (YEARS)              30
 MONTHLY PAYMENT
     MORTGAGE                  $   156.49
     UTILITIES                 $   300.00
     PROPERTY TAXES            $    41.67
     INSURANCE                 $    45.83
                               ___________
                               $   543.99
 
 Lab: 05 (Monthly House Costs)
 Programmed By: Noah Cardoza
 Email: noahcardoza@gmail.com
 */
