#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void swap(int& a, int& b);
int main()
{
    int arr[8] = {2, 1, 4, 7, 5, 0, 3, 8};
    oddsKeepEvensFlip(arr, 8);
    for(int i = 0; i < 8; i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}
void oddsKeepEvensFlip(int arr[], int arrSize){
    int count_odd = 0; 
    for(int i = 0; i < arrSize; i ++){
        if(arr[i] %2 == 1){
            swap(arr[i], arr[count_odd]);
            count_odd ++;
        }
    }
    int start = count_odd;
    int end = arrSize;
    while(start < end){
        end --;
        swap(arr[start], arr[end]);
        start ++;
    }
}
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}