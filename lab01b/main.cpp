//
//  main.cpp
//  CIS 22A
//
//  Created by Noah Cardoza on 10/1/18.
//  Lab 01B: Grass
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//  Email: noahcardoza@gmail.com


#include <iostream>

using namespace std;

// Ask a question (q) and returns the user's input as an int
int askForInt(string q) {
  int input;
  
  cout << q << ": ";
  cin >> input;
  
  return input;
}

int main(int argc, const char * argv[]) {
    int yardLength, yardWidth, houseLength, houseWidth, areaToMow;

    // Ask for the dimensions of the yard
    yardLength = askForInt("Enter length of yard in feet");
    yardWidth = askForInt("Enter width of yard in feet");

    // Ask for the dimensions of the house
    houseLength = askForInt("Enter length of house in feet");
    houseWidth = askForInt("Enter width of house in feet");

    // Calculate the area of the lawn
    areaToMow = (yardLength * yardWidth) - (houseLength * houseWidth);

    cout << "\nArea to be mowed: " << areaToMow << endl;
    cout << "Time: " << areaToMow / 60 << " minutes and " << areaToMow % 60 << " seconds\n" << endl;


    cout << "Programmed by: Noah Cardoza" << endl;

    return 0;
}
/*
Enter length of yard in feet: 120
Enter width of yard in feet: 100
Enter length of house in feet: 60
Enter width of house in feet: 50

Area to be mowed: 9000
Time: 150 minutes and 0 seconds

Programmed by: Noah Cardoza
*/

