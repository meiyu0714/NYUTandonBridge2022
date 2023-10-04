#include <iostream>
using namespace std;
int* findingMissing(int arr[], int n, int& resArrSize);
int main()
{
    int arr[6] = {3, 1, 3, 0, 6, 4};
    int ArrMissingSize = 1;
    int *arrMissing =findingMissing(arr, 6, ArrMissingSize);
    cout<<"Missing Array Size is "<<ArrMissingSize<<endl;
    cout<<"Missing Array contains: ";
    for(int i = 0; i < ArrMissingSize; i ++){
        cout<<arrMissing[i]<<", ";
    }

    return 0;
}
int* findingMissing(int arr[], int n, int& resArrSize){
    int* k = new int[n + 1]; 
    for(int i = 0; i < n+1; i ++){
        k[i] = i + 1;
    }
    
    int count = 0;
    for(int i = 0; i < n; i++){
        if(k[arr[i]-1] == arr[i]){
          k[arr[i] - 1] = -1;
          count ++;
        }
    }
    resArrSize = n + 1 - count;
    int count2 = 0;
    int* missing = new int [resArrSize];
    for(int i = 0; i < n+1; i ++){
        if(k[i] > 0){
            missing[count2]=k[i];
            count2 ++;
        }
    }    
    return missing;
}
