#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void reverse(int& a, int& b);
int main()
{
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}
void reverseArray(int arr[], int arrSize){
    for(int i = 0; i <= arrSize/2; i ++)
        reverse(arr[i], arr[arrSize - 1 - i]);
}
void removeOdd(int arr[], int& arrSize){
    int count =0;
    for(int i = 0; i < arrSize; i ++){
        if(arr[i] % 2 == 0){
            arr[count] = arr[i];
            count ++;
        }
    }
    arrSize = count;
}
void splitParity(int arr[], int arrSize){
    int count_odd = 0;
    for(int i = 0;  i < arrSize; i ++){
       if(arr[i] % 2 == 1){
           reverse(arr[i], arr[count_odd]);
           count_odd ++;
       }
    }
}
void printArray(int arr[], int arrSize){
    int i;
    for(int i = 0; i < arrSize ; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void reverse(int& a, int& b){
    int k = a;
    a = b;
    b = k;
}