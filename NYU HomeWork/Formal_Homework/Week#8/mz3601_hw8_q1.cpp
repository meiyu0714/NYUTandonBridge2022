#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
void print_min(int arr[], int arrSize, int min);
int main()
{
    int min_value, arr[20];
    cout<<"Please enter 20 integers separated by a space:\n";
    for(int i = 0; i < 20; i ++){
        cin>>arr[i]; 
    }
    min_value = minInArray(arr, 20);
    cout<<"The minimum value is "<<min_value<<", and it is " 
    <<"located in the following indices:";
    print_min(arr, 20, min_value);

    return 0;
}
int minInArray(int arr[], int arrSize){
    int min_value = arr[0];
    for(int i = 1; i < arrSize; i++){
        if(arr[i] < min_value)
          min_value = arr[i];
    }
    return min_value;
}
void print_min(int arr[], int arrSize, int min){
    for(int i = 0; i < arrSize; i ++){
        if(arr[i] == min)
          cout<<' '<<i;
    }
}