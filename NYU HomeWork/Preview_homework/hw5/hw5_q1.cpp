#include <iostream>
using namespace std;

int fib(int n);
int main()
{
    int num;
    
    //get the n
    cout<<"Please enter a positive integer:";
    cin>>num;
    
    cout<<fib(num);
    
    return 0;
}

//returns the n-th element of the Fibonacci sequence.
int fib(int n){
    
    int fib_value;
    int n_1 = 1, n_2 = 1;
    if(n < 3)
      n = 1;
    else{ 
        for(int k = 3; k <= n; k++){
            fib_value = n_1 + n_2;
            n_2 = n_1;
            n_1 = fib_value;
        }
    }  
    return fib_value;
}