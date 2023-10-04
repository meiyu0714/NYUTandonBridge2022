#include <iostream>
using namespace std;

int jumpIt(int arr[], int arrSize);
int main(){

    cout<<"Test Case Arr One(case from book)\n";
    cout<<"Sample step costs: 0, 3, 80, 6, 57, 10\n";
    int arr1[6] = {0, 3, 80, 6, 57, 10};
    cout<<"The lowest cost is "<<jumpIt(arr1, 6);
    cout<<endl;

    cout<<"Test Case Arr Two\n";
    cout<<"Sample Step costs: 0, 98, 3, 26, 44, 7\n";
    int arr2[6] = {0, 98, 3, 26, 44, 7};
    cout<<"The lowest cost is "<<jumpIt(arr2, 6);

    return 0;
}
int jumpIt(int arr[], int arrSize){
    if(arrSize == 1 || arrSize == 2 || arrSize == 3)
      return arr[arrSize - 1];
    else{
        if(arr[arrSize - 2] > arr[arrSize - 3])
          return jumpIt(arr, arrSize -2) + arr[arrSize -1];
        else 
          return jumpIt(arr, arrSize -1) + arr[arrSize-1];  
    }  

}