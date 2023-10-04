#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int PIN_RANGE = 10;
const int PIN_ORIG = 12345;

void print_arr(int arr[], int arr_size);
void assignNum(int arr[], int arr_size);
int main()
{
    int input, k, new_pin = 0;
    int pin_num[PIN_RANGE];
    srand(time(0));
    assignNum(pin_num, PIN_RANGE);

    cout<<"Please enter your PIN according to the following mapping:\n";
    cout<<"PIN: "<<'\t'<<"0 1 2 3 4 5 6 7 8 9\n";
    cout<<"NUM: "<<'\t';
    print_arr(pin_num, PIN_RANGE);
    cin>>input;
    
    int count = 1;
    int pin_copy = PIN_ORIG;
    while(pin_copy > 0){
        k = pin_copy % 10;
        new_pin = pin_num[k] * count + new_pin;
        count = count * 10;
        pin_copy = pin_copy/10;
    }
    
    if(new_pin == input)
      cout<<"Your PIN is correct";
    else
      cout<<"Your PIN is not correct";

    return 0;
}
void print_arr(int arr[], int arr_size){
    for(int i = 0; i < arr_size; i ++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void assignNum(int arr[], int arr_size){
    for(int i = 0; i < arr_size; i ++)
      arr[i] = (rand()% 3 + 1);
}