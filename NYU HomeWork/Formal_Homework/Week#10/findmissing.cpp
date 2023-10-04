#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
int main()
{
    int arr[6] = {3, 1, 3, 0, 6, 4};
    int resArrSize;
    int* num_missed = findMissing(arr, 6, resArrSize);
    for(int i = 0; i < resArrSize; i++){
        cout<<num_missed[i]<<' ';
    }
    delete[] num_missed;

    return 0;
}
int* findMissing(int arr[], int n, int& resArrSize){
    int* arr_n = new int[n+1];
    int temp;
    for(int i = 0; i < n+1; i++)
        arr_n[i] = i;
    for(int i = 0; i < n; i++){
        temp = arr[i];
        arr_n[temp] = -1;
    }    
    resArrSize = 0; 
    for(int i = 0; i < n+1; i++){
        if(arr_n[i] >= 0)
            resArrSize++;
    }
    int* missing = new int[resArrSize];
    int k = 0; 
    for(int i = 0; i < n+1; i++){
        if(arr_n[i] >= 0){
            missing[k] = arr_n[i];
            k ++;
        }
    }
    delete[] arr_n;
    return missing;
}