#include <iostream>
using namespace std;

const int DIGIT_CHANGE = 10;
int main()
{
    int decimal_num, decimal_num_c,k;
    int binary_num = 0;
    int base = 1;
    cout<<"Enter decimal number:"<<endl;
    cin>>decimal_num;
    
    decimal_num_c = decimal_num;
    
    while(decimal_num_c != 0){
        k = decimal_num_c % 2;
        binary_num =binary_num + base * k;
        base *= DIGIT_CHANGE;
        decimal_num_c = decimal_num_c /2;
    }
    
    cout<<"The binary representation of "<<decimal_num<<" is "<<binary_num;

    return 0;
}