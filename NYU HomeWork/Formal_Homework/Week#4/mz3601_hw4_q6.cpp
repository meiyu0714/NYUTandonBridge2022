#include <iostream>

using namespace std;

int main()
{
    int num, num_copy,  i;
    cout<<"Please enter a positive integer: ";
    cin>>num;
    
    for(i = 1; i <= num; i ++){
        int i_copy = i;
        int count_even = 0, count_odd = 0;
        while(i_copy > 0){
            if(i_copy % 2 ==0){
                count_even ++;
            }
            else{
              count_odd ++;}
            i_copy = i_copy / 10;  
        }
            if(count_even > count_odd)
              cout<<i<<endl;
    }

    return 0;
}