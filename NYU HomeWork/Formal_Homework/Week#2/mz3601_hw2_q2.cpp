#include <iostream>
using namespace std;

const int CENTS_PER_DOLLAR = 100;
const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKEL = 5;
const int CENTS_PER_PENNY = 1;
int main()
{
    int dollars_input, cents_input;
    int total_cents, left_cents;
    int quarters_num, dimes_num, nickels_num, pennies_num;
    
    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollars_input>>cents_input;
    
    total_cents = dollars_input * CENTS_PER_DOLLAR + cents_input;
    
    //calculate outpus with their values to cents
    quarters_num = total_cents / CENTS_PER_QUARTER;
    left_cents = total_cents % CENTS_PER_QUARTER;
    
    dimes_num = left_cents / CENTS_PER_DIME;
    left_cents = left_cents % CENTS_PER_DIME;
    
    nickels_num = left_cents / CENTS_PER_NICKEL;
    left_cents = left_cents % CENTS_PER_NICKEL;
    
    pennies_num = left_cents;
    
    cout<<dollars_input<<" dollars and "<<cents_input<<" cents are:"<<endl;
    cout<<quarters_num<<" quarters, "<<dimes_num<<" dimes, "<<nickels_num<<" nickels and "<<pennies_num<<" pennies"<<endl;

    return 0;
}
