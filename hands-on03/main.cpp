//Correct the errors in the following program
//Upload the .cpp file with your output copied
//& pasted at the bottom as a comment
//(Change my name to your name)
//Use 10 as the test data

#include <iostream>

// not sure if we am supposed to fix this since
// it isn't a compiler error but it seems logical

#define PI 3.1415926



using namespace std;

int main()
{
  // Declare variables
  double area, radius;
  
  // Input the radius
  
  cout << "Enter the radius: ";
  cin >> radius;
  
  // Compute the area
  area = PI * radius * radius;
  
  // Output the area
  cout << "Area of Circle: " << area << endl;
  cout << "\n\nNoah Cardoza\n\n";
  
  // NOTE: The environment in which this will be
  // executed doesn't inlcude a "pause" command
  system("pause");
  return 0;
}

/*
 Enter the radius: 10
 Area of Circle: 314.159
 
 
 Noah Cardoza
 
 sh: pause: command not found
*/

