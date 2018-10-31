//
//  main.cpp
//  testing-grounds
//
//  Created by Darwin on 10/12/18.
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int elements;
  double total = 0, temp;
  cin >> elements;
  ifstream file;
  file.open("numbers");
  for(;elements > 0;elements--){
    file >> temp;
    total += temp;
  }
  file.close();
  

//  int z; int x = 2;
//
//  z = ++x * 10;
//
//  cout << x << " and " ;
//
//  cout << z << endl;
//
//  return 0;
}
