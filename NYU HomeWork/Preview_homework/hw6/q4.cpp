/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int PIN_RANGE = 10;
const int TEM_PIN_RANGE = 5;
void assignNum(int arr[], int arrSize);
void temporaryPin(int num[], int temPin[], int pin[], int PIN_RANGE);
bool checkPin(int a[], int size, int inputPin);

int main(){
    int input;

    int pin[5] = {1,2,3,4,5};
    int num[PIN_RANGE];
    int temPin[TEM_PIN_RANGE];
    srand(time(0));
    assignNum(num, PIN_RANGE);
    
    cout<<"Please enter your PIN according to the following mapping:"<<endl;
    cout<<"PIN: "<<"0 1 2 3 4 5 6 7 8 9"<<endl;
    cout<<"NUM: "<<num[0]<<" "<<num[1]<<" "<<num[2]<<" "<<num[3]<<" "
    <<num[4]<<" "<<num[5]<<" "<<num[6]<<" "<<num[7]<<" "<<num[8]<<" "
    <<num[9]<<endl;
    cin>>input;
    
    temporaryPin(num, temPin, pin, TEM_PIN_RANGE);

    if(checkPin(temPin, TEM_PIN_RANGE, input) == true)
      cout<<"Your PIN is correct";
    else
      cout<<"Your PIN is not correct";

    return 0;
}

void assignNum(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i ++){

        arr[i] = (rand()% 3 + 1);
    }
}

bool checkPin(int a[], int size, int inputPin){
    int x;
    for(int i = size - 1; i >= 0; i--){
        x = inputPin % 10;
        inputPin = inputPin / 10;
        if(x != a[i]){
          return false;
        }
    }
    return true;
}

void temporaryPin(int num[], int temPin[], int pin[], int PIN_RANGE){
    int k;
    for(int i = 0; i<PIN_RANGE; i++){
        k = pin[i];
        temPin[i] = num[k];
    }
}