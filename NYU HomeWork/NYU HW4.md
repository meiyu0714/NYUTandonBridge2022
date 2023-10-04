### Question 1:

#### 1）while解

```c++
#include <iostream>
using namespace std;

int main()
{
    int n, count;

    cout<<"Please enter a positive interger: ";
    cin>>n;
    
    count = 0;
    while(count ++ < n)
    {
        cout<<(2*count)<<endl;
    }
        
    return 0;

}
```

**问ta的问题，书上P141 对于number++是之后在++ 但为什么这里number++就是number++后的值了？**

#### 2）for解

```c++
#include <iostream>
using namespace std;

int main()
{
    int n, count;
    
    cout<<"Please enter a positive interger: ";
    cin>>n;
    
    for(count = 1; count<=n; count++)
    {
        cout<<(2*count)<<endl;
    }
        
    return 0;
}
```

+++

### Question 2: 

```c++
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
    int number;
    string Roman_Numeral_Number;
    

    cout<<"Enter decimal number\n";
    cin>>number;
    
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
    cout<<number<<" is "<<Roman_Numeral_Number<<endl;
    return 0;

}
```



+++

### Question 3

```c++
#include <iostream>
#include <string>
using namespace std;


int main()
{
    int d_number;
    string binary_representation, string;
    cout<<"Enter Decimal number:\n";
    cin>>d_number;
    

    while(d_number >= 1)
    {
        string = to_string(d_number % 2);
        binary_representation = string + binary_representation;
        d_number = d_number / 2;
    }
    cout<<binary_representation<<endl;
    
    return 0;

}
```



+++

### question 4

a) 

```c++
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double length, input;
    int count = 0;
    double sum = 0;
    double geometric_mean;
    

    cout<<"Please enter the length of the sequence:\n";
    cin>>length;
    cout<<"Please enter your sequence:\n";
    
    for(count = 0; count < length; count++){
        cin>>input;
        sum += input;
    }
    geometric_mean = pow(sum, (1/length));
    cout<<"The geometric mean is: "<<geometric_mean<<endl;
    
    return 0;
}
```

b)

```c++
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double input;
    double sequence = 0;
    double sum = 0;
    double geometric_mean;
    

    cout<<"Please enter a non-empty sequence of positive integers, each one in a seperate line. End your\nsequence by typing -1:\n";
    cin>>input;
    while(input != -1)
    {
        sum = sum + input;
        cin>>input;
        sequence ++;
    }
    
    geometric_mean = pow(sum, (1/sequence));
    cout<<"The geometric mean is:"<<geometric_mean<<endl;
    
    return 0;

}
```

+++

### Question 5

```c++
#include <iostream>
using namespace std;

int main()
{
    int Num_column, Num_space, Num_star, Num_input;
    
    cout<<"Please enter a positive interger: \n";
    cin>>Num_input;
    
    for(Num_column = 1; Num_column <= Num_input; Num_column ++){
      for(Num_space = 1; Num_space < Num_column; Num_space++)
        cout<<" ";
      for(Num_star = 1; Num_star <= ( 2 * (Num_input - Num_column) + 1); Num_star ++)
        cout<<"*";
      cout<<endl;}
    
    for(Num_column = 1; Num_column <= Num_input; Num_column ++){
        for(Num_space = 1; Num_space<= Num_input - Num_column; Num_space ++)
          cout<<" ";
        for(Num_star = 1; Num_star <= (2* Num_column-1); Num_star ++)  
          cout<<"*";
        
        cout<<endl;
    }  
    return 0;
}
```

+++

### Question 6

```c++
#include <iostream>
using namespace std;

int main()
{
    int Num_input, i, oddCount, evenCount, i_dup;
    
    cout<<"Please enter a positive interger: \n";
    cin>>Num_input;
    
    for(i = 1; i <= Num_input; i ++){
      i_dup = i;
      oddCount = evenCount = 0;
        while(i_dup > 0){
        if(i_dup % 2 ==0)
         evenCount ++;
        else
         oddCount ++;
        i_dup = i_dup / 10;}
        if(evenCount > oddCount)
         cout<<i<<endl;}
    
    return 0;

}
```

第一遍没做出来最优解。注意这个老师上课案例

![4](C:\Users\zzhez\Desktop\程序员+=\代码截图\C++\NYU Preparatory C++ Course\4.JPG)

+++

### Question 7

```c++
#include <iostream>
using namespace std;

int main()
{
    int Num_input, i, Num_Column;
    

    cout<<"Please enter a positive interger: \n";
    cin>>Num_input;
    
    for(Num_Column = 1; Num_Column <= Num_input; Num_Column++){
      for(i=1; i<=Num_input; i++)
        cout<<(i*Num_Column)<<"\t";
    cout<<endl;
    }
    
    return 0;
}
```

**注意“\t”的用法**

+++

### question 8

```c++
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int My_Number, guess, input, count = 0;
    int range_big = 100, range_small = 1; 

    srand(time(0));
    My_Number = (rand() % 100) + 1;
    
    cout<<"I thought of a number between 1 and 100! Try to guess it.\n";
    
    while(++count <= 4)
    {
        cout <<"Range:["<<range_small<<","<<range_big<<"], Number of guesses left:"
             <<(6 - count)<<endl;
        cout <<"Your guess: ";
        cin  >> guess;
     
        if(guess == My_Number){
          cout<<"Congrates!You guessed my number in "<<count<<" guesses.";
          break;}
        
        else if(guess > My_Number){
        cout << "Wrong! My number is smaller.\n";
         if (guess < range_big)
           range_big = guess;}
        
        else if(guess < My_Number){
        cout <<"Wrong! My number is bigger. \n";
          if(guess > range_small)
          range_small = guess;}
    }
    
    cout <<"Range:["<<range_small<<","<<range_big<<"], Number of guesses left:1\n";
        cout <<"Your guess: ";
        cin  >> guess;
        
    if(guess == My_Number)
      cout<<"Congrates! You guessed my number in 5 guesses."<<endl;
    else if(guess != My_Number)  
    cout<<"Out of guesses! My number is "<<My_Number<<endl;
    
    return 0;
}
```

注意在c++中的= 是==；今天做这道题的时候错了。特别注意 for里面的条件

