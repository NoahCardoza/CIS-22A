//
//  main.cpp
//
//  Hands On #4 Functions (Tuition)
//
//  Created by Noah Cardoza on 10/21/18.
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <limits>

#define UNIT_COST 31

using namespace std;

// returns only one integer per line
void getNextDouble(istream &stream, double &n){
  stream >> n;
  stream.ignore(numeric_limits<int>::max(), '\n');
}

// asks a question and expects a interger in return
double askForInt(string q) {
  double n;
  cout << q;
  getNextDouble(cin, n);
  return n;
}

double calcTuition(double units, double studentFees){
  return studentFees + (units * UNIT_COST);
}

void output(double total){
  cout << "Total Cost: " << total << endl;
}

int main(int argc, const char * argv[]) {
  output(calcTuition(askForInt("How many units are you taking this quarter: "), askForInt("Other student fees: $")));
  
  cout << "\nProgrammed By: Noah Cardoza" << endl;
  cout << "CWID: 20319078" << endl;
  return 0;
}

/*
 How many units are you taking this quarter: 19
 Other student fees: $679.77
 Total Cost: 1268.77
 
 Programmed By: Noah Cardoza
 CWID: 20319078
 */
