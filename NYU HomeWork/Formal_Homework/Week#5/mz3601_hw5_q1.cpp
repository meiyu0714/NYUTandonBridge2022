#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;

    for(int i = 1; i <= n * n; i++){
        if(i % n == 0)
          cout<<i<<'\t'<<endl;
        else 
          cout<<i<<'\t';
    }

    return 0;
}