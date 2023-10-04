#include <iostream>
#include <string>
using namespace std;

//prices in different times
const double WEEKEND_PRI = 0.15;
const double WEEK_PRI_1 = 0.4;
const double WEEK_PRI_2 = 0.25;
int main()
{
    int length;
    int start_hr, start_minite; 
    string day_of_week;
    char colon;
    double price;

    //Inputs for day of the week, time of the day and length.
    cout<<"Please enter frist two character of day of the week, eg.Mo Tu We Th Fr Sa Su: "<<endl;
    cin>>day_of_week;
    cout<<"Enter the time you started the call in 24-hour notation (e.g. 1:30 P.M. is 13:30): "<<endl;
    cin>>start_hr>>colon>>start_minite;
    cout<<"Please enter length in minites: "<<endl;
    cin>>length;
    
    if(day_of_week == "Sa" ||  day_of_week == "Su" )
       price = length * WEEKEND_PRI; //Weekend Call $0.15/minite.
    else if(day_of_week == "Mo" ||day_of_week == "Tu"||day_of_week == "We"||day_of_week == "Th"||day_of_week == "Fr"){
        if(start_hr>=8 && start_hr <18) //Weekday call from 8:00 to 18:00
          price = length * WEEK_PRI_1; 
        else if(start_hr == 18 && start_minite == 0)  //Weekday call starts from exactly 18:00
          price = length * WEEK_PRI_1;   //Price $0.4 per minite
        else
          price = length * WEEK_PRI_2;   
          //Weekday calls before 8:00 - 18:00. $0.25 per minite
    }
    else{
      cout<<"Invalid Input for day of the week.";

      return 0;
    }

    cout<<"THe cost of your call is "<<price<<" dollars.";
    
    return 0;
}