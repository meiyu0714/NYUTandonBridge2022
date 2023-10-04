#include <iostream>
#include <string>
using namespace std;

const int INCHES_PER_FOOT = 12;
const int FEET_PER_YARD = 3;
int main(){
    int count = 1;
    int inches_input;
    int inches_total = 0, inches_op, feet_op, yard_op, inches_left;

    cout<<"Enter the number of inches the snail traveled in day #"<<count<<endl
        <<"or type -1 if they reached their destination:"<<endl;
    cin>>inches_input;

    while(inches_input >= 0){
       inches_total += inches_input;
       count ++;
       cout<<"Enter the number of inches the snail traveled in day #"<<count<<endl
           <<"or type -1 if they reached their destination:"<<endl;
       cin>>inches_input;
    }
    yard_op = inches_total / INCHES_PER_FOOT / FEET_PER_YARD;
    inches_left = inches_total % (INCHES_PER_FOOT * FEET_PER_YARD);
    feet_op = inches_left/INCHES_PER_FOOT;
    inches_op = inches_left % INCHES_PER_FOOT; 

    cout<<"In "<<count - 1<<" days, the snail traveled "<<yard_op<<" yards, "
        <<feet_op<<" feet and "<<inches_op<<" inches.";

    return 0;
}