#include <iostream>
using namespace std;

//days of different monthes and per week.
const int DAYS_PER_WEEK = 7;
const int DAYS_JAN = 31;
const int DAYS_FEB_LEAP = 29;
const int DAYS_FEB_NORM = 28;
const int DAYS_MAR = 31;
const int DAYS_APRIL = 30;
const int DAYS_MAY = 31;
const int DAYS_JUNE = 30;
const int DAYS_JULY = 31;
const int DAYS_AUG = 31;
const int DAYS_SEP = 30;
const int DAYS_OCT = 31;
const int DAYS_NOV = 30;
const int DAYS_DEC = 31;
bool leap_year(int year);
int printMonthCalender(int numOfDays, int startingDay);
/*Precondition: numOfDays(number of days in the month)
startingDay - a number 1-7 that represents the day in the week
Postcondition: Print a formatted monthly calendar of that month
Return a number 1-7 that represents the day in the week of the last 
day in that month */
void printYearCalender(int year, int startingDay);
/* Precondition: year, starting day represented by number 1-7
Postcondition: print a formatted yearly calendar of that year */
int main()
{
    int year, startingDay;
    
    cout<<"Please enter the year: ";
    cin>>year;
    
    cout<<"Please enter a number 1-7 that represents the starting day: ";
    cin>>startingDay;
    
    printYearCalender(year, startingDay);

    return 0;
}

bool leap_year(int year){
    if( year % 4 == 0 && year % 100 !=0){
     return true;}
    else{
        if(year % 400 ==0){
            return true;}
        else{ 
         return false;}
    }
}

int printMonthCalender(int numOfDays, int startingDay){
  int last_day, k;
    
    cout<<"Mon"<<"\t"<<"Tue"<<"\t"<<"Wed"<<"\t"<<"Thr"<<"\t"
        <<"Fri"<<"\t"<<"Sat"<<"\t"<<"Sun"<<endl;
    for(int i = 1; i <= startingDay -1; i++){
        cout<<" "<<"\t";} //对的
    for(k = 1; k < numOfDays ; k ++){
        int x = k + startingDay -1;
        if( x % DAYS_PER_WEEK == 0)
        cout<<k<<"\t"<<endl;
        else
        cout<<k<<"\t";
    }    
    cout<<k<<endl;
    
    return last_day = (numOfDays + startingDay) % 7;
            cout<<endl;
}        


void printYearCalender(int year, int startingDay){
    string month;
    int numOfDays, last_day;
    bool leap = leap_year(year);
     for (int monthNum = 1; monthNum <= 12; monthNum ++){
        switch (monthNum) {
            case 1: 
              month = "January"; 
              numOfDays = DAYS_JAN;
              break;
            case 2:
              month = "February";
              if ( leap = true)
                numOfDays = DAYS_FEB_LEAP;
              else
                numOfDays = DAYS_FEB_NORM;
              break;    
            case 3:
              month = "March";
              numOfDays = DAYS_MAR;
              break;
            case 4:
              month = "April";
              numOfDays = DAYS_APRIL;
              break;
            case 5: 
              month = "May";
              numOfDays = DAYS_MAY;
              break;
            case 6:
              month = "June";
              numOfDays = DAYS_JUNE;
              break;
            case 7:
              month = "July";
              numOfDays = DAYS_JULY;
              break;
            case 8:
              month = "August";
              numOfDays = DAYS_AUG;
              break;
            case 9:
              month = "September";
              numOfDays = DAYS_SEP;
              break;
            case 10:
              month = "October";
              numOfDays = DAYS_OCT;
              break;
            case 11: 
              month = "Noverber";
              numOfDays = DAYS_NOV;
              break;
            case 12:
              month = "December";
              numOfDays = DAYS_DEC;
              break;
        }  
             cout<<month<<" "<<year<<endl;
            startingDay = printMonthCalender(numOfDays, startingDay);
            if(startingDay == 0)
            startingDay =7;
            else
            startingDay = startingDay;
            cout<<endl;
     }
     
}