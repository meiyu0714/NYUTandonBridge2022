#include <iostream>
using namespace std;

const int MINUTES_PER_DAY = 1440;
const int MINUTES_PER_HOUR = 60;
int main()
{
    int days_John, hours_John, minutes_John;
    int days_Bill, hours_Bill, minutes_Bill;
    int minutes_total;
    int days_op, hours_op, minutes_op;
    int minutes_left;
    
    cout<<"Please enter the number of days John has worked: ";
    cin>>days_John;
    cout<<"Please enter the number of hours John has worked: ";
    cin>>hours_John;
    cout<<"Please enter the number of minutes John has worked: ";
    cin>>minutes_John;
    
    cout<<"\n";
    
    cout<<"Please enter the number of days Bill has worked: ";
    cin>>days_Bill;
    cout<<"Please enter the number of hours Bill has worked: ";
    cin>>hours_Bill;
    cout<<"Please enter the number of minutes Bill has worked: ";
    cin>>minutes_Bill;
    
    cout<<"\n";
    
    //calculate total minutes.
    minutes_total = (days_John + days_Bill) * MINUTES_PER_DAY + 
    (hours_John + hours_Bill) * MINUTES_PER_HOUR + (minutes_John + minutes_Bill);
    
    //calculate the outputs.
    days_op = minutes_total / MINUTES_PER_DAY;
    minutes_left = minutes_total % MINUTES_PER_DAY;
    hours_op = minutes_left / MINUTES_PER_HOUR;
    minutes_left = minutes_left % MINUTES_PER_HOUR;
    minutes_op = minutes_left;
    
    cout<<"The total time both of them worked together is:"<<days_op<<" days, "<<hours_op<<" hours and "
    <<minutes_op<<" minutes."<<endl;

    return 0;
}