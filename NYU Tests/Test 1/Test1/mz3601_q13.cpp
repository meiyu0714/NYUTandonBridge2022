//Name:  Meiyu Zhang 
//netID: mz3601
#include <iostream>

using namespace std;
const int THREE_DIGITS = 3;
const int FOUR_DIGITS = 4;
const int FIVE_DIGITS = 5;
const int SIX_DIGITS = 6;
const int SEVEN_DIGITS = 7;
int main(){
    int num, odd_digits, even_digits, digits, last_digit;
    int count_3_digits = 0, count_4_digits = 0, count_5_digits = 0, count_6_digits = 0;
    int count_7_digits = 0, count_more_odds = 0, count_equal_digits = 0;

    cout<<"Please enter a sequence of numbers (with at least 3-digits and ";
    cout<<"at most 7-digits), each one in a separate line. End your sequence by typing";
    cout<<"-1:"<<endl;
    cin>>num;

    while(num > 0){
        even_digits = 0;
        odd_digits = 0;
        digits = 0;
      while(num != 0){
        last_digit = num % 10;
        digits ++; //Count digits
        if(last_digit % 2 ==0){
          even_digits ++;
        }
        else
          odd_digits ++;  
        num = num / 10;
      }
      switch(digits){
        case THREE_DIGITS:{
            count_3_digits ++;
            break;
        }
        case FOUR_DIGITS:{
            count_4_digits ++;
            break;
        }
        case FIVE_DIGITS:{
            count_5_digits ++;
            break;
        }
        case SIX_DIGITS:{
            count_6_digits ++;
            break;
        }
        case SEVEN_DIGITS:{
            count_7_digits ++;
            break;
        }
      }
      if(odd_digits > even_digits){
        count_more_odds ++;
      }
      else if(odd_digits == even_digits){
        count_equal_digits ++;
      }
      cin>>num;  
    }

    cout<<"Total count of numbers in the 3-digits Number group: "<<count_3_digits<<endl;
    cout<<"Total count of numbers in the 4-digits Number group: "<<count_4_digits<<endl;
    cout<<"Total count of numbers in the 5-digits Number group: "<<count_5_digits<<endl;
    cout<<"Total count of numbers in the 6-digits Number group: "<<count_6_digits<<endl;
    cout<<"Total count of numbers in the 7-digits Number group: "<<count_7_digits<<endl;
    cout<<"Total count of numbers in the More Odd-digits group: "<<count_more_odds<<endl;
    cout<<"Total count of numbers in the Equal-digits group: "<<count_equal_digits<<endl;

    return 0;
}