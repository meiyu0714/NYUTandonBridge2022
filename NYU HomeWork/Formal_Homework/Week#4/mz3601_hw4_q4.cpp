#include <iostream>
#include <cmath>
using namespace std;

//tow different version of reading the integer sequence
int main()
{
    int num,  multi = 1;
    double mean,length;
    cout<<"section a"<<endl;
    cout<<"Please enter the length of the sequence: ";
    cin>>length;
    
    //section a: 1st read the length of the sequence
    cout<<"Please enter your sequence:"<<endl;
    for(int i = 1; i<= length; i++){
      cin>>num;
      multi *= num;
    }
    mean = pow(multi, 1.0/length);
    cout<<"The geometric mean is "<<mean<<endl;
    cout<<endl;
    
    //section b: keep reading the numbers until -1 is entered
    int num2, count = 0, multi2 = 1;
    double mean2; 
    cout<<"section b"<<endl;
    cout<<"Please enter a non-empty sequence of positive integers," 
    <<"each one in a separate line. End your sequence by typing -1:"<<endl;
    cin>>num2;
    
    while(num2 >0){
        count ++;
        multi2 *= num2;
        cin>>num2;
    }
    
    mean2 = pow(multi2, 1.0/count);
    cout<<"The geometric mean is "<<mean2<<endl;

    return 0;
}