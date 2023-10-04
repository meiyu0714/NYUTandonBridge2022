#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name, status;
    int year_graduate, year_curr, year_diff;
    
    //get the inputs
    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your graduation year: ";
    cin>>year_graduate;
    cout<<"Please enter current year: ";
    cin>>year_curr;
    
    year_diff = year_graduate - year_curr;
    
    if(year_diff < 1)
     status = "Graduated";
    else if(year_diff > 4)
     status = "not in college yet";
    else{
     switch(year_diff){
        case 4:
         status = "a Freshman";
         break;
        case 3:
         status = "a Sophomore";
         break;
        case 2:
         status = "a Junior";
         break;
        case 1:
         status = "a Senior";
         break;
     }
    } 
    
    cout<<name<<", you are "<<status<<endl;
    
    

    return 0;
}