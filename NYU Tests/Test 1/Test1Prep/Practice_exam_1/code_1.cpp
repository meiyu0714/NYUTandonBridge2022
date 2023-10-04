#include <iostream>

using namespace std;

int main(){
    int num;
    cout<<"Please enter a positive number:"<<endl;
    cin>>num;
    //a-e 正
    for(int i = 0; i <= num -1; i ++){
        char output = 'a' + i;
        for(int k = 0; k < num - i - 1; k ++){
            cout<<" ";}
        cout<<output;
        if(i == 0)
        cout<<endl;
        else{
        for(int q = 0; q < 2*i - 1; q ++){
            cout<<" ";
        }
        cout<<output<<endl;}
    }
    //d-a 
    for(int i = num - 2; i >= 0; i --){
        char output = 'a' + i;
        for(int k = 0; k < num - i - 1; k ++){
            cout<<" ";}
        cout<<output;
        if(i != 0){
            for(int q = 0; q < 2 * i - 1; q ++){
            cout<<" ";
        }
        cout<<output<<endl;
        }
        else
          cout<<endl;
        
    }
    return 0;
}