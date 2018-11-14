//
//  main.cpp
//  Lab: 04 – Uber
//
//  Created by Noah Cardoza on 10/27/18.
//  Email: noahcardoza@gmail.com
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

void panic(string errorMessage);
double askForDouble(string prompt);
double askForDoubleGtZero(string prompt);
double askForDoubleGtOne(string prompt);
bool askForBool(string prompt);
char askForCharInRange(string prompt, string range);
string myGetline(string prompt);
double calculateFair(double time, double distance, char typeOfVehicle, double surge);
void outout(string name, double total);
  
int main() {
  // print output
  outout(
         // get the name of the rider
         myGetline("Enter name: "),
         // calculate the cost of the trip
         calculateFair(
                       // get the rest if the information
                       askForDoubleGtZero("Enter enter time in minutes: "),
                       askForDoubleGtZero("Enter enter distance: "),
                       askForCharInRange("Enter 'X' for uberX or 'S' for SUV or 'L' for luxury: ", "XSL"),
                       askForBool("Enter 'Y' if surge or 'N' if not: ") ?
                        askForDoubleGtOne("Enter surge multiplier: ") : 1)
         );
  // Terminate programm
  return 0;
}

void panic(string errorMessage) {
  /*
   Pre    : errorMessage - an error message
   Post   : nothing
   Purpose: deliver an error message to the user and terminate the program
   */
  cout << "ERROR: " << errorMessage << endl;
  exit(1);
}

double askForDouble(string prompt) {
  double in;
  cout << prompt;
  cin >> in;
  return in;
}

double askForDoubleGtZero(string prompt){
  /*
   Pre    : prompt - a prompt to diplay to the user
   Post   : returns user input as a double
   Purpose: to validate user input only allowind doubles > 0
   */
  double in = askForDouble(prompt);
  if (in <= 0) panic("This value must be greater than 0");
  return in;
}

double askForDoubleGtOne(string prompt){
  /*
   Pre    : prompt - a prompt to diplay to the user
   Post   : returns user input as a double
   Purpose: to validate user input only allowind doubles > 1
   */
  double in = askForDouble(prompt);
  if (in <= 1) panic("This value must be greater than 1");
  return in;
}

bool askForBool(string prompt){
  /*
   Pre    : prompt - a prompt to diplay to the user
   Post   : returns true or flase based on user input
   Purpose: to validate user input and accept 'Y' as true and 'N' as false
   */
//  char in = askForCharInRange(prompt, "YN");
//  cout << prompt;
//  cin >> in;
//  in = toupper(in);
//  if (!(in == 'Y' or in == 'N'))
//    panic("This value must 'Y' or 'N'");
  
  return (askForCharInRange(prompt, "YN") == 'Y');
}

char askForCharInRange(string prompt, string range) {
  /*
   Pre    : prompt  - a prompt to diplay to the user
   range   – acceptable characters
   Post   : returns a char from range
   Purpose: to validate user input only allowing characters within range to be inputed by the user
   */
  char in;
  cout << prompt;
  cin >> in;
  in = toupper(in);
  if (range.find(in) == string::npos)
    panic("This value must be one of these characters: '" + range + "'");
  return in;
}

string myGetline(string prompt){
  /*
   Pre    : prompt - a prompt to diplay to the user
   Post   : returns a line of user input
   Purpose: to validate user input only allowing strings with characters in them
   */
  string in;
  cout << prompt;
  getline(cin, in);
  if (in.length() == 0)
    panic("This value must contain at least one character");
  return in;
}

void outout(string name, double total) {
  /*
   Pre    : name  - the rider's name
            total - the total cost of service
   Post   : N/A
   Purpose: to output information to the screen
   */
  cout << fixed << setprecision(2);
  
  cout << "\nRider’s name: " << name << endl;
  cout << "Total: $ " << total << endl;
  
  cout << "\nProgrammed By: Noah Cardoza" << endl;
  cout << "Email: noahcardoza@gmail.com" << endl;
  cout << "Lab: 04 Uber" << endl;
}

double calculateFair(double time, double distance, char typeOfVehicle, double surge){
  /*
   Pre    : time          - time in minutes of drive
            distance      - distance in miles of drive
            typeOfVehicle - type of vehicle driven in (X or S or L)
            surge         - surge multiplier
   Post   : total cost of ride
   Purpose: calculate the cost of a ride with the given parameters
   */
  

  double
    baseFair,
    perMinute,
    perMile,
    minimumFare;
  
  switch (typeOfVehicle) {
    case 'X':
      baseFair = 2;
      perMinute = .22;
      perMile = 1.15;
      minimumFare = 6.55;
      break;
    case 'S':
      baseFair = 15;
      perMinute = .9;
      perMile = 3.75;
      minimumFare = 25;
      break;
    case 'L':
      baseFair = 5;
      perMinute = .5;
      perMile = 2.75;
      minimumFare = 10.55;
      break;
    default:
      panic("Not sure how you got this far but you did something wrong!");
      return 0;
  }
  
  // either return the total or the minimumFare, whichever is larger
  return max((baseFair * surge) + (perMinute * time) + (perMile * distance), minimumFare);
}
/*
 NOTE: lines with '>>' denote extra information note outputted by this program
 1)>---------------------------------------------------
 Enter name: Mary Pape
 Enter enter time in minutes: 34.6
 Enter enter distance: 25.5
 Enter 'X' for uberX or 'S' for SUV or 'L' for luxury: X
 Enter 'Y' if surge or 'N' if not: Y
 Enter surge multiplier: 1.9
 
 Rider’s name: Mary Pape
 Total: $ 40.74
 
 Programmed By: Noah Cardoza
 Email: noahcardoza@gmail.com
 Lab: 04 Uber
 >> Program ended with exit code: 0
 2)>-----------------------------------------------------
 Enter name: Taylor Swift
 Enter enter time in minutes: 15
 Enter enter distance: 16.8
 Enter 'X' for uberX or 'S' for SUV or 'L' for luxury: L
 Enter 'Y' if surge or 'N' if not: N
 
 Rider’s name: Taylor Swift
 Total: $ 58.70
 
 Programmed By: Noah Cardoza
 Email: noahcardoza@gmail.com
 Lab: 04 Uber
 >> Program ended with exit code: 0
 3)>-----------------------------------------------------
 Enter name: Jason Rider
 Enter enter time in minutes: 45
 Enter enter distance: 13.8
 Enter 'X' for uberX or 'S' for SUV or 'L' for luxury: C
 ERROR: This value must be one of these characters: 'XSL'
 >> Program ended with exit code: 1
 */
