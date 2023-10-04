#include <iostream>

using namespace std;

int main(){
    int num_a, num_b;
    
    //section a, use a while loop
    cout<<"section a"<<endl;
    cout<<"Please enter a positive integer: ";
    cin>>num_a;
    int i = 1;
    while(i<=num_a){
        cout<<2*i<<endl;
        i++;
    }
    cout<<endl;

    //section b, use a for loop
    cout<<"section b"<<endl;
    cout<<"Please enter a positive integer: ";
    cin>>num_b;
    for(int i =1; i <= num_b; i++){
        cout<<2*i<<endl;
    }
    
    return 0;
}    
