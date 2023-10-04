#include <iostream>
#include <string>
using namespace std;

const int I_VALUE = 1;
const int V_VALUE = 5;
const int X_VALUE = 10;
const int L_VALUE = 50;
const int C_VALUE = 100;
const int D_VALUE = 500;
const int M_VALUE = 1000;
int main()
{
    int number, number_copy;
    string Roman_Numeral_Number;
    

    cout<<"Enter decimal number:\n";
    cin>>number;
    if(number<=0){
      cout<<"Invalid Input";
      return 0;
    }
    else{
    number_copy = number;
    
    while(number - M_VALUE >= 0)
    {
        number -= M_VALUE;
        Roman_Numeral_Number += "M";
    }
    while(number - D_VALUE >= 0)
    {
        number -= D_VALUE;
        Roman_Numeral_Number += "D";
    }
    while(number - C_VALUE >= 0)
    {
        number -= C_VALUE;
        Roman_Numeral_Number += "C";
    }
    while(number - L_VALUE >= 0)
    {
        number -= L_VALUE;
        Roman_Numeral_Number += "L";
    }
    while(number - X_VALUE >= 0)
    {
        number -= X_VALUE;
        Roman_Numeral_Number += "X";
    }
    while(number - V_VALUE >= 0)
    {
        number -= V_VALUE;
        Roman_Numeral_Number += "V";
    }
    while(number - I_VALUE >= 0)
    {
        number -= I_VALUE;
        Roman_Numeral_Number += "I";
    }
    cout<<number_copy<<" is "<<Roman_Numeral_Number<<endl;
    
    return 0;
    }

}