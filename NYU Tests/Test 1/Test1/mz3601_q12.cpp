//Name:  Meiyu Zhang 
//netID: mz3601
#include <iostream>

using namespace std;
const char ASTERISK = '*';
const char SPACE = ' ';
int main(){
    int num;
    cout<<"Please enter a positive integer:"<<endl;
    cin>>num;

    //Print line 0 
    for(int i = 0; i < 2*num; i ++){
        cout<<ASTERISK;
    }
    cout<<endl;
    //Test correct
    //Print the stars from line 1 - line n
    for(int i = 1; i <= num; i ++){ //line 1
        for(int k = 0; k < i; k++){
            cout<<ASTERISK;
        }
        for(int q = 0; q < 2*(num - i); q++)
          cout<<SPACE;
        for(int k = 0; k < i; k++){
            cout<<ASTERISK;
        }
        cout<<endl; 
    }
    //Print the lower part from line n+1 - 2n
    for(int s = num-1; s > 0; s--){
        for(int k = s; k > 0; k --){
            cout<<ASTERISK;
        }
        for(int q = 0; q < 2*(num - s); q ++){
            cout<<SPACE;
        }
        for(int k = s; k > 0; k --){
            cout<<ASTERISK;
        }
        cout<<endl;
    }
    //The last line 
    for(int i = 0; i < 2*num; i ++){
        cout<<ASTERISK;
    }
    cout<<endl;

    return 0;
}