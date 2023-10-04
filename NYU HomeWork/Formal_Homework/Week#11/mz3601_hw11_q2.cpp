#include <iostream>
using namespace std;
int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
int main(){

    int testArr[6] = {3,2,5,7,3,1};
    int testArrSize = 6;
    
    cout<<"Function sumOfSquares:\n";
    cout<<"The sum of the squares of each of the values in array is ";
    cout<<sumOfSquares(testArr, testArrSize)<<'.'<<endl;

    cout<<"Function isSorted:\n";
    if(isSorted(testArr, testArrSize))
      cout<<"The elements in array are sorted in an ascending order";
    else
      cout<<"The elements in array are not sorted in an ascending order.";

    return 0;
}
int sumOfSquares(int arr[], int arrSize){
    if(arrSize == 1)
      return arr[0] * arr[0];
    else 
      return arr[arrSize - 1]*arr[arrSize - 1] + sumOfSquares(arr, arrSize-1);
}
bool isSorted(int arr[],int arrSize){
    if(arrSize == 2)
      return (arr[1] >= arr[0]);
    else
      return (arr[arrSize - 1] >= arr[arrSize-2])&&(isSorted(arr, arrSize-1));
}