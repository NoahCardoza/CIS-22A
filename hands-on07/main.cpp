#include <iostream>
using namespace std;

void backwards(int[], int);
void swap(int&, int&);

int main()
{
  int arr[] = {2,8,17,3,5,16}; int i;
  
  backwards(arr,6);
  
  for (i = 0; i< 6; i++)
    cout<<arr[i]<<endl;
  
  //system("pause");
  return 0;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void backwards(int array[], int n) {
  /*
   Pre      :
   array[] - array of integers
   number  - number of elements in the array that have values
   Post     : Nothing
   Purpose  : Reverse the order of the elements of an array
   */
  int range = n / 2;
  for (int i = 0; i < range; i++)
    swap(array[i], array[n - i - 1]);
}
