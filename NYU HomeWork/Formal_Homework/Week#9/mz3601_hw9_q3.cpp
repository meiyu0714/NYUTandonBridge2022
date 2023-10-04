#include <iostream>
using namespace std;

int* getPosNumsl(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArr(int* arr, int arrSize);
void switchInt(int& a, int& b);
int main()
{
    int arr1[6] = {3, -1, -3, 0, 6, 4};
    int arr1NewSize = 0;
    int* newArr1 = NULL;
    newArr1 = getPosNumsl(arr1, 6, arr1NewSize);
    printArr(newArr1, arr1NewSize);

    int arr2[6] = {3, -1, -3, 0, 6, 4};
    int arr2NewSize = 0;
    int* newArr2 = NULL;
    newArr2 = getPosNums2(arr2, 6, &arr2NewSize);
    printArr(newArr2, arr2NewSize);
    
    int arr3[6] = {3, -1, -3, 0, 6, 4};
    int arr3NewSize = 0;
    int* newArr3 = NULL;
    getPosNums3(arr3, 6, newArr3, arr3NewSize);
    printArr(newArr3, arr3NewSize);

    int arr4[6] = {3, -1, -3, 0, 6, 4};
    int arr4NewSize = 0;
    int* newArr4 = nullptr;
    getPosNums4(arr4, 6, &newArr4, &arr4NewSize);
    printArr(newArr4, arr4NewSize);

    return 0;
}
int* getPosNumsl(int* arr, int arrSize, int& outPosArrSize){
    int k = 0;
    for(int i = 0; i < arrSize; i ++){
     if(arr[i] > 0){
         swap(arr[i], arr[k]);
         k ++;
     }   
    }
    outPosArrSize = k;
    return arr;
}
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int k = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            swap(arr[i], arr[k]);
            k ++;
        }
    }
    *outPosArrSizePtr = k;
    return arr;
}
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int k = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            swap(arr[i], arr[k]);
            k ++;
        }
    }
    outPosArr = arr;
    outPosArrSize = k;
}
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int k = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            swap(arr[i], arr[k]);
            k ++;
        }
    }
    *outPosArrPtr = arr;
    *outPosArrSizePtr = k;
}
void printArr(int* arr, int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}