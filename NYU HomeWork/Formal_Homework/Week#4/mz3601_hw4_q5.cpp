#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cout<<"Please enter a positive integer: ";
    cin>>n;
    
    //create the upper half of the hourglass.
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= i - 1; k++)
            cout<<" ";
        for(int a = 1; a<= 2*n- 2*i + 1; a++)
            cout<<"*";
        cout<<endl;    
    }
    //create the other half of the hourglass.
    for(int i = n; i>0; i--){
        for(int k = 1; k < i; k++)
          cout<<" ";
        for(int a = 1; a <= 2*(n-i) + 1; a++)
          cout<<"*";
        cout<<endl;  
    }
    
    return 0;
}
