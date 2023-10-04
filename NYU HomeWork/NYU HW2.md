**交之前记得run 一遍 ask TA 要不要写的复杂，test的时候是否可以自己run一遍去掉bug**

Write a program that asks the user to enter a number of quarters, dimes, nickels and pennies and then outputs the monetary value of the coins in the format of dollars and remaining cents.

 Your program should interact with the user exactly as it shows in the following example:

Please enter number of coins:

 \# of quarters: 13

 \# of dimes: 4

 \# of nickels: 11

 \# of pennies: 17

 The total is 4 dollars and 37 cents

```c++
#include <iostream>
using namespace std;

const int DOLLAR_TO_CENTS = 100;
const int VALUE_OF_A_QUARTER = 25;
const int VALUE_OF_A_DIME = 10;
const int VALUE_OF_A_NICKEL = 5;
const int VALUE_OF_A_PENNY = 1;
int main() 
{
   int quarters, dimes, nickels, pennies, dollars, cents,total_cents;

   cout<<"# of quarters:"<<endl;
   cin>>quarters;

   cout<<"# of dimes:"<<endl;
   cin>>dimes;

   cout<<"# of nickels:"<<endl;
   cin>>nickels;

   cout<<"# of pennies:"<<endl;
   cin>>pennies;

   total_cents = VALUE_OF_A_QUARTER * quarters + VALUE_OF_A_DIME * dimes + VALUE_OF_A_NICKEL * nickels + VALUE_OF_A_PENNY * pennies;

   cout<<"The total is "<<total_cents/DOLLAR_TO_CENTS<<" dollars and "<<(total_cents % DOLLAR_TO_CENTS)<<" cents."<<endl;

   return 0;
    
}
```

注意作业具体要求，注意检测

+++



Write a program that asks the user to enter an amount of money in the format of dollars and remaining cents. The program should calculate and print the minimum number of coins (quarters, dimes, nickels and pennies) that are equivalent to the given amount.

 

 Hint: In order to find the minimum number of coins, first find the maximum number of quarters that fit in the given amount of money, then find the maximum number of dimes that fit in the remaining amount, and so on.

 

 Your program should interact with the user exactly as it shows in the following example:

 

 Please enter your amount in the format of dollars and cents separated by a space:

 4 37

 4 dollars and 37 cents are:

 17 quarters, 1 dimes, 0 nickels and 2 pennies

```c++
#include <iostream>
using namespace std;

const int DOLLAR_TO_CENTS = 100;
const int VALUE_OF_A_QUARTER = 25;
const int VALUE_OF_A_DIME = 10;
const int VALUE_OF_A_NICKEL = 5;
int main() 
{
   int quarters, dimes, nickels, pennies, dollars, cents, total_cents;
   
   cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl; 
   cin>>dollars>>cents;
   
   total_cents = DOLLAR_TO_CENTS * dollars + cents;
   quarters = total_cents / VALUE_OF_A_QUARTER;
   total_cents = total_cents % VALUE_OF_A_QUARTER;
   dimes = total_cents / VALUE_OF_A_DIME;
   total_cents = total_cents % VALUE_OF_A_DIME;
   nickels = total_cents / VALUE_OF_A_NICKEL;
   total_cents = total_cents % VALUE_OF_A_NICKEL;
   pennies = total_cents;
   
   cout<<dollars<<" dollars and "<<cents<<" cents are:"<<endl;
   cout<<quarters<<" quarters, "<<dimes<<" dimes,"<<nickels<<" nickels and "<<pennies<<" pennies"<<endl;
   
   
   return 0;
    
}
```

**注意标注constants**

+++

Suppose John and Bill worked for some time and we want to calculate the total time both of them worked. Write a program that reads number of days, hours, minutes each of them worked, and prints the total time both of them worked together as days, hours, minutes.

Hint: Try to adapt the elementary method for addition of numbers to this use.

 Your program should interact with the user exactly as it shows in the following example:

 

 Please enter the number of days John has worked: 2

 Please enter the number of hours John has worked: 12

 Please enter the number of minutes John has worked: 15

 

 Please enter the number of days Bill has worked: 3

 Please enter the number of hours Bill has worked: 15

 Please enter the number of minutes Bill has worked: 20

 

 The total time both of them worked together is: 6 days, 3 hours and 35 minutes.

```c++
#include <iostream>
using namespace std;

const int HOUR_TO_MINUTES = 60;
const int DAY_TO_MINUTES = 1440;
int main() 
{
   int days_John, hours_John, minutes_John, days_Bill, hours_Bill, minutes_Bill, total_minutes, days, hours, minutes;

   cout<<"Please enter the number of days John has worked:";
   cin>>days_John;

   cout<<"Please enter the number of hours John has worked:";
   cin>>hours_John;

   cout<<"Please enter the number of minutes John has worked:";
   cin>>minutes_John;

   cout<<endl;

   cout<<"Please enter the number of days Bill has worked:";
   cin>>days_Bill;

   cout<<"Please enter the number of hours Bill has worked:";
   cin>>hours_Bill;

   cout<<"Please enter the number of minutes John has worked:";
   cin>>minutes_Bill;

   cout<<endl;

   total_minutes = DAY_TO_MINUTES * (days_John + days_Bill) + HOUR_TO_MINUTES * (hours_John + hours_Bill) + minutes_Bill + minutes_John;
   days = total_minutes / DAY_TO_MINUTES;
   total_minutes = total_minutes % DAY_TO_MINUTES;
   hours = total_minutes / HOUR_TO_MINUTES;
   minutes = total_minutes % HOUR_TO_MINUTES;

   cout<<"The total time both of them worked together is "<<days<<" days, "<<hours<<" hours, "<<minutes<<" minutes."<<endl;

   return 0;
    
}
```



+++

Write a program that reads from the user two positive integers, and prints the result of when we add, subtract multiply, divide, div and mod them.

 Your program should interact with the user exactly as it shows in the following example:

 Please enter two positive integers, separated by a space:

 14 4

 14 + 4 = 18

 14 – 4 = 10

 14 * 4 = 56

 14 / 4 = 3.5

 14 div 4 = 3

 14 mod 4 = 2



```c++
#include <iostream>
using namespace std;

int main() 
{
   int num1, num2;

   cout<<"Please enter two positive intergers, separated by a space:"<<endl;
   cin>>num1>>num2;

   cout<<num1<<" + "<<num2<<" = "<<num1 + num2<<endl;
   cout<<num1<<" - "<<num2<<" = "<<num1 - num2<<endl;
   cout<<num1<<" * "<<num2<<" = "<<num1 * num2<<endl;
   cout<<num1<<" / "<<num2<<" = "<<(float)num1 / (float)num2<<endl;
   cout<<num1<<" div "<<num2<<" = "<<num1 / num2<<endl;
   cout<<num1<<" mod "<<num2<<" = "<<num1 % num2<<endl;

   return 0;
    
}
```



+++



 