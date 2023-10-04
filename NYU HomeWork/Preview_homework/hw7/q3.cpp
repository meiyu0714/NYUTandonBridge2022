#include <iostream>

using namespace std;
void oddsKeepEvensFlip(int arr[], int arrSize);
int main(){
    int arr[6] = {5, 2, 11, 7, 6, 4};
    oddsKeepEvensFlip(arr, 6);
    for(int i = 0; i < 6; i ++ ){
        cout<<arr[i]<<" ";
    }

    return 0;
}
void oddsKeepEvensFlip(int arr[], int arrSize){
    int arr_odd[arrSize];
    int arr_even[arrSize];
    int count_odd = 0, count_even = 0;
    for(int i = 0; i < arrSize; i ++){
        if(arr[i] % 2 != 0){
             arr_odd[count_odd] = arr[i];
             count_odd ++;
        }
        else {
            arr_even[count_even] = arr[i];
            count_even ++;
        }
    }

//确定 array_even 与array_odd 正确 
    for(int i = 0; i< count_odd; i++)
     arr[i] = arr_odd[i];
    for(int i = arrSize - 1, k = 0; i > arrSize - 1 - count_even && k < count_even; i = i-1, k ++)
         arr[i] = arr_even[k];      
}         