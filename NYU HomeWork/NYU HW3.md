Write a program that computes how much a customer has to pay after purchasing two items. The price is calculated according to the following rules:

 • Buy one get one half off promotion: the lower price item is half price.

 • If the customer is club card member, additional 10% off.

 • Tax is added.

 

 Inputs to the program include:

 • Two items’ prices

 • Have club card or not (User enters ‘Y’ or ‘y’ for “yes”; ‘N’ or ‘n’ for “no”)

 • Tax rate (User enters the percentage as a number; for example they enter 8.25 if the tax

 rate is 8.25%)

 

 Program displays:

 • Base price - the price before the discounts and taxes

 • Price after discounts - the price after the buy one get one half off promotion and the

 member’s discount, if applicable

 • Total price – the amount of money the customer has to pay (after tax).

 

 Your program should interact with the user exactly as it shows in the following example:

 Enter price of first item: 10

 Enter price of second item: 20

 Does customer have a club card? (Y/N): y

 Enter tax rate, e.g. 5.5 for 5.5% tax: 8.25

 Base price: 30.0

 Price after discounts: 22.5

 Total price: 24.35625



```c++
#include <iostream>
using namespace std;

const double MEMBER_DISCOUNT = 0.1;
int main()
{
    double price1, price2, tax, base_price, DisPrice, TotalPrice;
    char member;
    

    cout<<"Enter price of first item:";
    cin>>price1;
    
    cout<<"Enter price of second item:";
    cin>>price2;
    
    cout<<"Does customer have a club card?";
    cin>>member;
    
    cout<<"Enter Tax rate, e.g. 5.5 fpr 5.5% tax:";
    cin>>tax;
    
    base_price = price1 + price2;
    
    if(price1 >= price2)
        price2 = price2 / 2;
    else
        price1 = price1 / 2;
    
    DisPrice = price1 + price2;
    if(member == 'y'||'Y')
        DisPrice = DisPrice * (1 - MEMBER_DISCOUNT);
    
    TotalPrice = DisPrice * (1 + tax /100); 
        
    cout<<"Base price: "<<base_price<<endl;
    cout<<"Price after discount: "<<DisPrice<<endl;
    cout<<"Total price: "<<TotalPrice<<endl;
    
    return 0;

}
```



+++

Write a program that:

 • Asks the user for their name.

 • Asks the user to input their graduation year.

 • Asks the user to input the current year.

 Assume the student is in a four-year undergraduate program. Display the current status the student is in. Possible status include: not in college yet, freshman, sophomore, junior, senior, graduated.

 

 Note: If graduation year equals to current year, status is ‘Graduated’; if graduation year is four years after current year, status is ‘Freshman’, etc.

 

 Your program should interact with the user exactly as it shows in the following example:

 Please enter your name: Jessica

 Please enter your graduation year: 2019

 Please enter current year: 2015

 Jessica, you are a Freshman

```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int Gyear, Cyear;
    string name;
    

    cout<<"Please enter your name:";
    cin>>name;
    
    cout<<"Please enter your graduation year: ";
    cin>>Gyear;
    
    cout<<"Please enter current year: ";
    cin>>Cyear;
    
    if(Gyear - Cyear > 4)
       cout<<name<<", you are not in college yet"<<endl;
    else if(Gyear - Cyear == 4)
       cout<<name<<", you are a Freshman"<<endl;
    else if(Gyear - Cyear == 3)
       cout<<name<<", you are a Sophomore"<<endl;
    else if(Gyear - Cyear == 2)
       cout<<name<<", you are a Junior"<<endl;   
    else if(Gyear - Cyear == 1)
       cout<<name<<", you are a Senior"<<endl;
    else
       cout<<name<<", you are graduated"<<endl;

    return 0;
}
```



+++

Write a program that does the following:

 • Ask user to input three Real numbers a, b and c. They represent the parameters of a

 quadratic equation 𝑎𝑥# + 𝑏𝑥 + 𝑐 = 0

 • Classify to one of the following:

  \- ’Infinite number of solutions’ (for example, 0𝑥# + 0𝑥 + 0 = 0 has infinite number of solutions)

  \- ’No solution’ (for example, 0𝑥# + 0𝑥 + 4 = 0 has no solution)

  \- ’No real solution’ (for example, 𝑥# + 4 = 0 has no real solutions)

  \- ’One real solution’

  \- ’Two real solutions’

 • In cases there are 1 or 2 real solutions, also print the solutions.

 

 Notes:

 \1. If 𝑎 ≠ 0 and there are real solutions to the equation, you can get these solutions using

 the following formula: *quadratic formula*

 

 The number of solutions depends on whether (b2 -4ac) is positive, zero, or negative.

 

 \2. In order to calculate the square root of a number (of type double), you should call the sqrt function, located in the cmath library.

 

  Follow the syntax as demonstrated in the code below:

  \#include <iostream>

  \#include <cmath>

  using namespace std;



```c++
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, x, x1, x2, discriminant;
    

    cout<<"Please enter value of a: ";
    cin>>a;
    
    cout<<"Please enter value of b: ";
    cin>>b;
    
    cout<<"Please enter value of c: ";
    cin>>c;
        
        discriminant = b*b - (4 * a * c);
        if(b == 0 && c == 0 && a == 0)
          cout<<"This equation has infinite number of solutions\n";
        else if(a == 0 && b == 0 && c != 0)
          cout<<"This equation has no solution\n";
        else if(a == 0 && b != 0 ){
            x = - c / b;
          cout<<"This equation has a single real solution x="<<x<<endl;}
        else if(a != 0 && discriminant > 0)
           {
             x1 = (-b + sqrt(discriminant)) / 2 / a;
             x2 = (-b - sqrt(discriminant)) / 2 / a;
             cout<<"This equation has two real solutions x1= "<<x1<<", x2= "<<x2<<endl;   
            } 
        else if(a != 0 && discriminant == 0){
             x = (-b + sqrt(discriminant)) / 2 / a;
             cout<<"This equation has a single real solution x="<<x<<endl;
            }
        else if(a!=0&&discriminant < 0)
            cout<<"This equation has no real solution\n";
            
    return 0;

}
```



+++

Define the following constants:

 const int FLOOR_ROUND = 1;

 const int CEILING_ROUND = 2;

 const int ROUND = 3;

 

 Write a program that asks the user to enter a Real number, then it asks the user to enter the method by which they want to round that number (floor, ceiling or to the nearest integer). The program will then print the rounded result.

 

 Your program should interact with the user exactly as it shows in the following example:

 Please enter a Real number:

 4.78

 Choose your rounding method:

 \1. Floor round

 \2. Ceiling round

 \3. Round to the nearest whole number

 2

 5

 

 Implementation requirement: Use a switch statement.



```c++
#include <iostream>
#include <cmath>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;
int main()
{
    int method;
    double number;

    cout<<"Please enter a Real number:\n";
    cin>>number;
    
    cout<<"Choose your rounding method:\n";
    cout<<"1.Floor round\n";
    cout<<"2.Ceiling round\n";
    cout<<"3.Round to the nearest whole number\n";
    cin>>method;
    
    switch(method){
        case FLOOR_ROUND:
          cout<<floor(number)<<endl;
          break;
        case CEILING_ROUND:
          cout<<ceil(number)<<endl;
          break;
        case ROUND:
          cout<<round(number)<<endl;
          break;
        default:
          cout<<"Illegal method";
          break;
    }
    return 0;

}
```



+++

Body mass index (BMI) is a number calculated from a person’s weight and height using the following formula: 𝑤𝑒𝑖𝑔h𝑡/h𝑒𝑖𝑔h𝑡#. Where 𝑤𝑒𝑖𝑔h𝑡 is in kilograms and h𝑒𝑖𝑔h𝑡 is in meters.

 

 According to the Centers for Disease Control and Prevention, the BMI is a fairly reliable indicator of body fatness for most people. BMI does not measure body fat directly, but research has shown that BMI correlates to direct measures of body fat, such as underwater weighing and dual-energy X-ray absorptiometry.

 

 The following table gives the weight status in respect to the BMI value:

  BMI Range   Weight Status

  Below 18.5   Underweight

  [18.5, 25)   Normal

  [25, 30)    Overweight

  30 and above  Obese

 

 Write a program that prompts for weight (in pounds) and height (in inches) of a person, and prints the weight status of that person.

 

 Your program should interact with the user exactly as it shows in the following example:

 Please enter weight (in pounds): 135

 Please enter height (in inches): 71

 The weight status is: Normal

 

 Note: 1 pound is 0.453592 kilograms and 1 inch is 0.0254 meters.

```c++
#include <iostream>
#include <string>
using namespace std;

const double pound_to_kilogram = 0.453592;
const double inch_to_meter = 0.0254;
int main()
{
    double weight_in_pounds, weight_in_kilograms, height_in_inches, height_in_meters;
    double BIM;
    string weight_status;
    

    cout<<"Please enter weight(in pounds): ";
    cin>>weight_in_pounds;
    cout<<"Please enter height(in inches): ";
    cin>>height_in_inches;
    
    weight_in_kilograms = weight_in_pounds * pound_to_kilogram;
    height_in_meters = height_in_inches * inch_to_meter;
    
    BIM = weight_in_kilograms / (height_in_meters * height_in_meters);
    
    if(BIM <18.5)
       weight_status = "Underweight";
    else if(BIM >=18.5 && BIM <25)
       weight_status = "Normal";
    else if(BIM >= 25 && BIM <30)
       weight_status = "Overweight";
    else
       weight_status = "Obese";
    
    cout<<"The weight status is: "<<weight_status<<endl;
    
    return 0;

}
```



+++

Write a program that computes the cost of a long-distance call. The cost of   the call is determined according to the following rate schedule:

 • Any call started between 8:00 A.M. and 6:00 P.M., Monday through Friday, is billed at a

 rate of $0.40 per minute.  

 • Any call starting before 8:00 A.M. or after 6:00 P.M., Monday through Friday, is charged

 at a rate of $0.25 per minute.  

 • Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.   The input will consist of the day of the week, the time the call started, and the length of the call in minutes.

 The output will be the cost of the call.

 Notes:

 \1. The time is to be input in 24-hour notation, so the time 1:30 P.M. is input as   13:30  

 \2. The day of the week will be read as one of the following two character string: Mo Tu

 We Th Fr Sa Su

 \3. The number of minutes will be input as a positive integer.

```c++
#include <iostream>
#include <string>
using namespace std;

const double MONDAY_TO_FRIDAY1 = 0.40;
const double MONDAY_TO_FRIDAY2 = 0.25;
const double SATURDA_TO_SUNDAY = 0.15;
int main()
{
    int call_in_minutes, hour, minutes;
    double price;
    char k;
    string day_of_the_week;
    

    cout<<"Please enter the first two character of the day of the week\n";
    cout<<"The first character to be uppercase and the second to be lowercase\n";
    cout<<"eg. Mo, Tu, etc.\n";
    cin>>day_of_the_week;
    
    cout<<"Please enter the length of the call in minutes: ";
    cin>>call_in_minutes;
    
    cout<<"Please enter the time in 24-hour notion, eg.12:59: ";
    cin>>hour>>k>>minutes;
    
    if(day_of_the_week == "Sa"||"Su") 
          price = call_in_minutes * SATURDA_TO_SUNDAY;
    if(day_of_the_week == "Mo"||"Tu"||"We"||"Th"||"FR")
          if(hour > 8 && hour < 18)
            price = call_in_minutes * MONDAY_TO_FRIDAY1;
          else
            price = call_in_minutes * MONDAY_TO_FRIDAY2;
    
    cout<<"The price is $"<<price<<"."<<endl;
    
    return 0;

}
```

