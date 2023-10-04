#include <iostream>

using namespace std;

int main(){

    char inLetter, outletter;
    cout<<"Please enter a lower-case letter:"<<endl;
    cin>>inLetter;

    int k = inLetter - 'a'; //eg inLetter = e, int k = 4

    for(int i = 0; i < k + 1; i++){
        if(i % 2 == 0)
          outletter = 'a' + i;
        else 
          outletter = 'A' + i; 
        for(int j = 0; j< k - i; j ++)
          cout<<" ";
        for(int d = 0; d < 2*i + 1; d ++)  
          cout<<outletter;       
        cout<<endl;      
    }

    return 0;
}