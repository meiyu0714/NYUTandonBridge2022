#include <iostream>
#include <string>
using namespace std;

void reverseArray(int arr[], int arrSize);
//it takes an array of integers arr, 
//and its size, arrSize.
//When called, it reorders the elements of 
//the array to appear in reverse order.

void removeOdd(int arr[], int& arrSize);
/*It taks arr, an array of integers and its size, arrSize.
When called, the function alters arr so that only numbers in it
at the end are the even numbers. It also updates arrSize so it
contains the new logical size of the array after removing the odd
numbers*/

void splitParity(int arr[], int arrSize);
/*It takes arr, an array of integers, and its size, arrSize. 
When called, the function changes the order of numbers in arr 
so that all the odd numbers will apear first, and all the even numbers 
will apear last. The inner order of odd and even numbers doesn't matter.*/

void printArray(int arr[], int arrSize);
int main (){
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    
    reverseArray (arr1, arr1Size);
    printArray(arr1, arr1Size);
    
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void reverseArray(int arr[], int arrSize){
    for(int i = 0; i <(arrSize / 2) ; i ++){
        int k = arr[i];
        arr[i] = arr[arrSize- 1- i];
        arr[arrSize - 1 -i] = k;
    }
}

void removeOdd(int arr[], int& arrSize){
    int k = 1;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] % 2 == 0 ){
            arr[k - 1] = arr[i];
            k ++;
        }
    }
    arrSize = k-1;
} //我觉得这个我做对了，缺点是必须单独陈列arrSize这个函数，在print的时候必须只能print到arrSize之前。arrSize之后的arr不能被我写的代码覆盖
//对于这个函数的理解，问问老师 -已问，期待回复。
//本来写错loop，用纸写一遍就对了，要多参加office hr多和老师 TA沟通。

void splitParity(int arr[], int arrSize){
    int middle, k = 0;
    for(int i = 0; i < arrSize; i ++){
        if(arr[i] % 2 == 1){
            middle = arr[k];
            arr[k] = arr[i];
            arr[i] = middle;
            k++;
        }
    }    
}

void printArray(int arr[], int arrSize){
    int i;
    
    for(i = 0; i< arrSize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
