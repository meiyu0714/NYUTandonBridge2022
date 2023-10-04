#include <iostream>
using namespace std;
int* findMissing(int arr[], int n, int& resArrSize);
int main(){
    int missingArrCount = 0;
    int arr[6] = {3, 1, 3, 0, 6, 4};
    int* missingArr = findMissing(arr, 6, missingArrCount);
    for(int i = 0; i < missingArrCount; i ++)
      cout<<missingArr[i]<<endl;
    delete[] missingArr;
    return 0;
}
int* findMissing(int arr[], int n, int& resArrSize){
    int* numbers = new int[n+1];
    for(int i = 0; i < n+1; i++)
        numbers[i] = i;
    for(int i = 0; i < n; i++){
        numbers[arr[i]] = -1;
    }    
    for(int i = 0; i < n+1; i++){
        if(numbers[i] > 0){
            resArrSize ++;
    }
    }
    int* missingArr = new int[resArrSize];
    int count = 0;
    for(int i =0; i < n+1; i ++){
        if(numbers[i]>0){
            missingArr[count] = i;
            count++;
        }
    }
    return missingArr;

    delete[] numbers;
}