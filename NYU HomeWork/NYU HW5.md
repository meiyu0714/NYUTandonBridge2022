### Question One

```c++
#include <iostream>
#include <cmath>
using namespace std;

int fib(int n);
//Computes the n-th elements of 
//the Fibonacci sequence.
int main()
{
    int num, Fib_Value;
    
    cout<<"Please enter a positive interger: ";
    cin>>num;

    Fib_Value = fib(num);
    cout<<Fib_Value;
    
    return 0;
}

int fib(int n){
    int Fib_Value;
    
    Fib_Value = ( 1.0 / sqrt (5.0) ) *(pow((1.0 + sqrt(5.0)) / 2.0 , n) - pow((1.0 - sqrt(5.0) )/2.0, n));
    return Fib_Value;
}

```

+++

### Question Two

extremely confused for the question. Does it want us to print one tree(which need one function inside another function(highly prohibited from C++)) or does it want us to print out two trees. 

I will do two different answers.

```c++
#include <iostream>

using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
//To print an n-line triangle, filled with symbol characters
//Shifted m spaces from the left margin.
int main()
{
    int num_line, num_space, num_triangle;
    char symbol;
    cout<<"Please enter the number of lines that triangle would have:\n";
    cin>>num_line;
    cout<<"Please enter the number of spaces that triangle would shift from left margin\n";
    cin>>num_space>>endl;
    cout<<"Please enter the symbol you wish to use. eg. * or + or $\n";
    cin>>symbol;
  
    printShiftedTriangle(num_line, num_space, symbol);
    cout<<endl;
    cout<<endl;
    
    cout<<"Please enter the number of triangles you want:\n";
    cin>>
        
    
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol){
    for(int i = 1;i <= n; i++){
        for(int j = 1; j <= ( m + n - i); j ++)
         cout<<" ";
        for(int k = 1; k <= (2*i - 1); k++)
         cout<<symbol;
        cout<<endl;
    }

}
```

```c++
#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
//Print an n-line triangle, filled with symbol characters
//Shifted m spaces from the left margin.
void printPineTree(int n, char symbol);
//Print a sequence of n triangles of increasing sizes
//The triangles are filled with the symbol characters
int main()
{
    int num_line, num_space, num_triangle;
    char symbol_ShiftedTriangle, symbol_PineTree;
    
    cout<<"Please enter the number of lines that triangle would have:\n";
    cin>>num_line;
    cout<<"Please enter the number of spaces that triangle would shift from left margin:\n";
    cin>>num_space;
    cout<<"Please enter the symbol you wish to use. eg. * or + or $:\n";
    cin>>symbol_ShiftedTriangle;
    cout<<endl;
  
    printShiftedTriangle(num_line, num_space, symbol_ShiftedTriangle);
    cout<<endl;
    cout<<endl;
    
    cout<<"Please enter the number of triangles you want:\n";
    cin>>num_triangle;
    cout<<"Please enter the symbol you wish to use. eg. * or + or $:\n";
    cin>>symbol_PineTree;
    cout<<endl;
    
    printPineTree(num_triangle, symbol_PineTree);
    
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol){
    for(int i = 1;i <= n; i++){
        for(int j = 1; j <= ( m + n - i); j ++)
         cout<<" ";
        for(int k = 1; k <= (2*i - 1); k++)
         cout<<symbol;
        cout<<endl;
    }
}

void printPineTree(int n, char symbol){
    for(int a = 1;a <= n; a ++){
        for(int i = 1;i <= (a+1); i++){
        for(int j = 1; j <= ( n+1-i); j ++)
         cout<<" ";
        for(int k = 1; k <= (2*i - 1); k++)
         cout<<symbol;
        cout<<endl;
    }
    }
}
```

后一种为正确解法；

+++

### Question Three

a 

```c++
#include <iostream>
using namespace std;

const int DAYSPERWEEK = 7;
int printMonthCalendar(int numOfDays, int startingDay);
//Print a formatted monthly calendar of that month.
//Return a number 1-7 that represents the day in the 
//week of the last day in that month.
int main(){
    int numOfDays, startingDay, lastDay;
    
    cout<<"Please enter the number of days in the month:\n";
    cin>>numOfDays;
    
    cout<<"Please enter the starting day in the week(1 for Monday,";
    cout<<"2 for Tuesday, 3 for Wednesday, etc.:\n";
    cin>>startingDay;
    
    lastDay = printMonthCalendar(numOfDays, startingDay);
    
    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay){
    int lastDay, numOfWeeks;
    lastDay = (numOfDays + startingDay) % DAYSPERWEEK;
    
    cout<<"Mon"<<"\t"<<"Tue"<<"\t"<<"Wed"<<"\t"<<"Thr"
        <<"\t"<<"Fri"<<"\t"<<"Sat"<<"\t"<<"Sun"<<endl;
    
    for(int k = 1 ; k <= startingDay - 1; k++)
      cout<<" "<<"\t";
    for(int i=1;i<=numOfDays;i++){
        if((i+startingDay-1)%7 ==0)
            cout<<i<<"\t"<<endl;
        else
            cout<<i<<"\t";
    }
      
    return lastDay;
}
```

? 应该写成function? 交作业的时候查一下

b.

```c++
#include <iostream>
using namespace std;

bool leapYear(int year);
int main()
{
    int year;
    cout<<"Please enter the year in the Gregorian calendar system:\n";
    cin>>year;
    
    cout<<leapYear(year)<<endl;

    return 0;
}

bool leapYear(int year){
    return ((year % 400 ==0)||(year % 4 == 0 && year % 100 !=0));
}
```

c.

很奇怪 function里不能有function的。模范也没做这道题。等老师上课布置，其实不难；

+++

### Question 4

a + b 写一块儿了

```c++
#include <iostream>
#include <cmath>
using namespace std;

void printDivisions(int num);
int main()
{
    int integer;
    
    cout<<"Please enter a positive integer >=2: ";
    cin>>integer;
    
    if(integer<2)
     cout<<"Invalid Input\n";
    
    else
    printDivisions(integer);

    return 0;
}

void printDivisions(int num){
    for(int i = 1; i <= sqrt(num); i++){
      if(num % i == 0)
      cout<<i<<" ";
    }
    for(int k = sqrt(num); k >= 1; k --){
      if(num % k ==0 && k != sqrt(num)){
          cout<<num/k<<" ";
      }
    }
}
```

+++

### Question 5

a.

```c++
void analyzeDivisors(int num, int & outCountDivs, int & outSumDivs){
    outSumDivs = 0;
    outCountDivs = 0;
    for(int i=1;i<=sqrt(num);i++){
        if(num % i == 0){
            outCountDivs ++;
            outSumDivs += i;
        }
    }
    for(int k=sqrt(num);k>1;k--){
        if(num % k == 0)
        outCountDivs ++;
        outSumDivs += num/k;
    }
}
```

未检测

