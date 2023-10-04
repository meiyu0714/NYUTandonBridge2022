#include <iostream>
using namespace std;

//show the results of some basic calculations of 2 integers.
int main()
{
    int num1,num2;
    int add_num, sub_num, multiply_num, div_num, mod_num;
    double division_num;
    
    //get the inputs
    cout<<"Please enter two positive integers, separated by a space:"<<endl;
    cin>>num1>>num2;
    
    //calculate 
    add_num = num1 + num2;
    sub_num = num1 - num2;
    multiply_num = num1 * num2;
    division_num = (double)num1 / (double)num2;
    div_num = num1 / num2;
    mod_num = num1 % num2;
    
    //output the calculations
    cout<<num1<<" + "<<num2<<" = "<<add_num<<endl;
    cout<<num1<<" - "<<num2<<" = "<<sub_num<<endl;
    cout<<num1<<" * "<<num2<<" = "<<multiply_num<<endl;
    cout<<num1<<" / "<<num2<<" = "<<division_num<<endl;
    cout<<num1<<" div "<<num2<<" = "<<div_num<<endl;
    cout<<num1<<" mod "<<num2<<" = "<<mod_num<<endl;

    return 0;
}