#include <iostream>
using namespace std;

int fib(int n);
int main(){
    int num;
    cout<<"Please enter a positive integer: ";
    cin>>num;
    cout<<fib(num);
    return 0;
}
int fib(int n){
  int output, sequence_1 = 1, sequence_2 = 1;
  if(n == 1 || n == 2){
        output = 1;
    }
    else{
        for(int i = 0; i < n -2; i ++){
            output = sequence_1 + sequence_2;
            sequence_1 = sequence_2;
            sequence_2 = output;
    }
    }
    return output;
}