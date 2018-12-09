#include <iostream>
#include <iomanip>

using namespace std;


int countPassing(double arr[], int num);


//Write the the function definition including the function header for  countPassing() so that the number of values greater than or equal to 69.5 in arr[] is returned

int main()
{
  double happy[5] = { 69.7, 6967, 69.9, 80, 90};
  cout << countPassing(happy, 5) << endl;
  return 0;
}


int countPassing(double arr[], int num){
  int count = 0;
  while (--num >= 0) count += arr[num] >= 69.5;
  return count;
}

