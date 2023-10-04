#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;
int main()
{
    int rounding_method;
    double real_num;
    int rounded_num;
    
    //get the inputs
    cout<<"Please enter a Real number:"<<endl;
    cin>>real_num;
    cout<<"Choose your rounding method:"<<endl;
    cout<<"1. Floor round"<<endl;
    cout<<"2. Ceiling round"<<endl;
    cout<<"3. Round to the nearest whole number"<<endl;
    cin>>rounding_method;
    
    //switch different rounding method for positive inputs
    if(real_num >= 0){
    switch(rounding_method){
      case FLOOR_ROUND:
       rounded_num = (int)real_num;
       break;
      case CEILING_ROUND:
       rounded_num = (int)real_num + 1;
       break;
      case ROUND:
       rounded_num = (int)(real_num + 0.5);
       break;
    }
    }
    else{
    switch(rounding_method){
      case FLOOR_ROUND:
       rounded_num = (int)real_num - 1;
       break;
      case CEILING_ROUND:
       rounded_num = (int)real_num;
       break;
      case ROUND:
       rounded_num = (int)(real_num - 0.5);
       break;
    }
    }
    //display the result
    cout<<rounded_num;
    
    return 0;
    
}
