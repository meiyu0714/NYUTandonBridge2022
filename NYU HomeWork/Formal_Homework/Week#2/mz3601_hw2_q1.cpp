#include <iostream>
using namespace std;

const int CENTS_PER_DOLLAR = 100;
const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKEL = 5;
const int CENTS_PER_PENNY = 1;
int main()
{
    int quarters_num, dimes_num, nickels_num, pennies_num;
    int total_cents;
    int dollars_output, cents_output;
    
    cout<<"Please enter number of coins:"<<endl;
    cout<<"# of quarters: ";
    cin>>quarters_num;
    cout<<"# of dimes: ";
    cin>>dimes_num;
    cout<<"# of nickels: ";
    cin>>nickels_num;
    cout<<"# of pennies: ";
    cin>>pennies_num;
    
    //calculate total cents with inputs.
    total_cents = quarters_num * CENTS_PER_QUARTER + dimes_num * CENTS_PER_DIME + nickels_num * CENTS_PER_NICKEL
    + pennies_num * CENTS_PER_PENNY;
    
    //calculate output dollars and cents.
    dollars_output = total_cents / CENTS_PER_DOLLAR;
    cents_output = total_cents % CENTS_PER_DOLLAR;
    
    cout<<"The total is "<<dollars_output<<" dollars and "
    <<cents_output<<" cents"<<endl;

    return 0;
}
