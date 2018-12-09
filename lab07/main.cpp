//
//  main.cpp
//  lab07 : CIS Department Fill Rates
//
//  Email: noahcardoza@gmail.com
//  Created by Noah Cardoza on 12/2/18.
//  Copyright © 2018 Noah Cardoza. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

#define MAX_CLASS_NUMBER 100
#define USE_FILE
//#define DEBUG_ON

using namespace std;

void trim(string &str);
void putRow(ostream &out,
            string CRN,
            string klass,
            int enrollment,
            int maxEnrollment,
            int waitList,
            double fillRate);
void output(
            ostream &out,
            string  CRNs[],
            string  classes[],
            int     enrollment[],
            int     maxEnrollment[],
            int     waitList[],
            double  fillRate[],
            int classNumber);
int getData(string  filename,
            string  CRNs[],
            string  classes[],
            int     enrollment[],
            int     maxEnrollment[],
            int     waitList[],
            double  fillRate[]);
void filterClasses(ostream &out,
                   string  CRNs[],
                   string  classes[],
                   int     enrollment[],
                   int     maxEnrollment[],
                   int     waitList[],
                   double  fillRate[],
                   int classNumber);
double averageFillRate(double fillRates[], int classNumber);
int findClassByCRN(string crn, string CRNs[], int classNumber);
void sortClasses(string  CRNs[],
                 string  classes[],
                 int     enrollment[],
                 int     maxEnrollment[],
                 int     waitList[],
                 double  fillRate[],
                 int classNumber);

int main() {
  #ifdef USE_FILE
    ofstream out;
    out.open("output.txt");
  #else
    ostream &out = cout;
  #endif
  // Declare variables
  string  CRNs[MAX_CLASS_NUMBER];
  string  classes[MAX_CLASS_NUMBER];
  int     enrollment[MAX_CLASS_NUMBER];
  int     maxEnrollment[MAX_CLASS_NUMBER];
  int     waitList[MAX_CLASS_NUMBER];
  double  fillRate[MAX_CLASS_NUMBER];
  int     classNumber;
  string  crnLookUp;
  int     crnIndex;
  
  // Set formatting
  cout << fixed << setprecision(1);
  out  << fixed << setprecision(1);
  
  // Main program
  classNumber = getData("fillrates.txt", CRNs, classes, enrollment, maxEnrollment, waitList, fillRate);
  output(out, CRNs, classes, enrollment, maxEnrollment, waitList, fillRate, classNumber);
  cout << "Average fill rate: " << averageFillRate(fillRate, classNumber) << endl;
  filterClasses(out, CRNs, classes, enrollment, maxEnrollment, waitList, fillRate, classNumber);
  cout << "Look up class by CRN: ";
  cin >> crnLookUp;
  crnIndex = findClassByCRN(crnLookUp, CRNs, classNumber);
  if (crnIndex == -1) {
    cout << "NO SUCH CLASS!";
  } else {
    cout << classes[crnIndex] << " " << fillRate[crnIndex];
  }
  cout << "\nSorting classes by fill rate in ascending order..." << endl;
  sortClasses(CRNs, classes, enrollment, maxEnrollment, waitList, fillRate, classNumber);
  output(out, CRNs, classes, enrollment, maxEnrollment, waitList, fillRate, classNumber);
  
  // Assignment/author details
  cout << "Programmed By: Noah Cardoza\nlab07 : CIS Department Fill Rates\nEmail: noahcardoza@gmail.com" << endl;

  #ifdef USE_FILE
    // Clean up
    out.close();
  #endif
  return 0;
}

void trim(string &str) {
  //  Pre     :
  //    str          - a string
  //  Post    : N/A
  //  Purpose : to trim or strip whitespace from both ends of a string
  while (isspace(str.front())) str.erase(0, 1);
  while (isspace(str.back())) str.pop_back();
}

void putRow(ostream &out,
            string CRN,
            string klass,
            int enrollment,
            int maxEnrollment,
            int waitList,
            double fillRate){
  //  Pre     :
  //    out           - reference to an output stream to be used
  //    CRNs          - a class CRNs
  //    klass         - a class name
  //    enrollment    - number of students enrolled
  //    maxEnrollment - max student enrollment allowed
  //    waitList      - number of students on the waitlist
  //    fillRate      - percentage of the class filled
  //  Post    : N/A
  //  Purpose : output a single row of class data to specific output stream
  out << setw(8) << left <<  CRN << setw(20) << klass << setw(2) << right << enrollment << setw(16) << maxEnrollment << setw(15) << waitList << setw(16) << fillRate << endl;
}

void output(
            ostream &out,
            string  CRNs[],
            string  classes[],
            int     enrollment[],
            int     maxEnrollment[],
            int     waitList[],
            double  fillRate[],
            int classNumber) {
  //  Pre     :
  //    out           - reference to an output stream to be used
  //    CRNs          - array of class CRNs
  //    classes       - array of class names
  //    enrollment    - array of student enrollment
  //    maxEnrollment - array of max student enrollment per class
  //    waitList      - array of number of students on the waitlist
  //    fillRate      - array of percentage of class filled
  //    classNumber   - number of classes read into memory
  //  Post    : N/A
  //  Purpose : output table of class data to specific output stream
  out << "CRN     Course           Current         Max            Number on      Fill"   << endl;
  out << "                         Enrollment      Enrollment     Wait-list      Rate %" << endl;
  
  for (int n = 0; n < classNumber; n++) {
    putRow(out, CRNs[n], classes[n], enrollment[n], maxEnrollment[n], waitList[n], fillRate[n]);
  }
}

int getData(string  filename,
            string  CRNs[],
            string  classes[],
            int     enrollment[],
            int     maxEnrollment[],
            int     waitList[],
            double  fillRate[]) {
  //  Pre     :
  //    filename      - path to file to read
  //    CRNs          - array of class CRNs
  //    classes       - array of class names
  //    enrollment    - array of student enrollment
  //    maxEnrollment - array of max student enrollment per class
  //    waitList      - array of number of students on the waitlist
  //    fillRate      - array of percentage of class filled
  //  Post    : number of classes read into the program
  //  Purpose : read class data from a file
  ifstream in;
  int n = 0;
  
  in.open(filename);
  while (!in.eof() && n < MAX_CLASS_NUMBER) {
    in >> CRNs[n];
    getline(in, classes[n]);
    trim(classes[n]);
    in >> enrollment[n];
    in >> maxEnrollment[n];
    in >> waitList[n];
    fillRate[n] = (double) enrollment[n] / maxEnrollment[n] * 100;
#ifdef DEBUG_ON
    putRow(out, CRNs[n], classes[n], enrollment[n], maxEnrollment[n], waitList[n], fillRate[n]);
#endif
    n++;
  }
  return n;
}

void filterClasses(ostream &out,
                   string  CRNs[],
                   string  classes[],
                   int     enrollment[],
                   int     maxEnrollment[],
                   int     waitList[],
                   double  fillRate[],
                   int classNumber){
  //  Pre     :
  //    out           - reference to an output stream to be used
  //    CRNs          - array of class CRNs
  //    classes       - array of class names
  //    enrollment    - array of student enrollment
  //    maxEnrollment - array of max student enrollment per class
  //    waitList      - array of number of students on the waitlist
  //    fillRate      - array of percentage of class filled
  //    classNumber   - number of classes read into memory
  //  Post    : N/A
  //  Purpose : filters out classes below a fillRate specified by user input
  double filter;
  int rejected = 0;
  cout << "Filter fill rates under: ";
  cin >> filter;
  
  for (int n = 0; n < classNumber; n++) {
    if (fillRate[n] <= filter) {
      putRow(out, CRNs[n], classes[n], enrollment[n], maxEnrollment[n], waitList[n], fillRate[n]);
      rejected++;
    }
  }
  
  if (!rejected) out << "No class has a fill rate below " << filter << endl;
}

double averageFillRate(double fillRates[], int classNumber) {
  //  Pre     :
  //    fillRate      - array of percentage of class filled
  //    classNumber   - number of classes read into memory
  //  Post    : average fill rate
  //  Purpose : averages the fill rates
  double sum = 0;
  
  for (int i = 0; i < classNumber; i++) {
    sum += fillRates[i];
  }
  
  return sum / classNumber;
}

int findClassByCRN(string crn, string CRNs[], int classNumber) {
  //  Pre     :
  //    crn           - the crn to search for
  //    CRNs          - array of class CRNs
  //    classNumber   - number of classes read into memory
  //  Post    : the index of the crn or `-1` if not found
  //  Purpose : search for and retuen the index of a specified crn
  for (int i = 0; i < classNumber; i++) {
    if (crn == CRNs[i]) return i;
  }
  return -1;
}

void sortClasses(string  CRNs[],
                 string  classes[],
                 int     enrollment[],
                 int     maxEnrollment[],
                 int     waitList[],
                 double  fillRate[],
                 int classNumber){
  //  Pre     :
  //    CRNs          - array of class CRNs
  //    classes       - array of class names
  //    enrollment    - array of student enrollment
  //    maxEnrollment - array of max student enrollment per class
  //    waitList      - array of number of students on the waitlist
  //    fillRate      - array of percentage of class filled
  //    classNumber   - number of classes read into memory
  //  Post    : N/A
  //  Purpose : sorts class data in ascending order
  int j;
  for (int i = 1; i < classNumber; i++) {
    j = i;
    while ((fillRate[j - 1] > fillRate[j]) && j > 0){
      // Swap all index values across all 6 lists
      swap(fillRate[j - 1], fillRate[j]);
      swap(waitList[j - 1], waitList[j]);
      swap(maxEnrollment[j - 1], maxEnrollment[j]);
      swap(enrollment[j - 1], enrollment[j]);
      swap(classes[j - 1], classes[j]);
      swap(CRNs[j - 1], CRNs[j]);
      j--;
    }
  }
}


/*
 Average fill rate: 71.2
 Filter fill rates under: 0
 Look up class by CRN: 415
 NO SUCH CLASS!
 Sorting classes by fill rate in ascending order...
 Programmed By: Noah Cardoza
 lab07 : CIS Department Fill Rates
 Email: noahcardoza@gmail.com
 */
