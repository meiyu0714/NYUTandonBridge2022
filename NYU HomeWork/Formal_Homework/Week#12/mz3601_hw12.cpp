#include <iostream>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;
class Money{
public:
friend Money operator +(const Money& amount1, const Money& amount2);
//Precondition:amount1 and amount2 have been given values
//Returns the sum of the values of amount1 and amount2 
friend Money operator -(const Money& amount1, const Money& amount2);
//Preconditon: amount1 and amount2 have been given values
//Returns the difference of the values amount1 and amount2
friend bool operator ==(const Money& amount1, const Money& amount2);
//Preconditon: amount1 and amount2 have been given values
//Returns true if amount1 and amount2 have same value;
friend bool operator < (const Money& amount1, const Money& amount2);
//Preconditon: amount1 and amount2 have been given values
//Returns true if amount1 is smaller than amount2
friend istream& operator>>(istream& ins, Money& amount);
//Overload the >> operators so it can be used to input values of type Money.
//Notation for inputting negative amounts is as in -$100.00
friend ostream& operator<<(ostream& outs, const Money& amount);
//Overload the >> operators so it can be used to output values of type Money.
//Precedes each utput values of type Money with a dollar sign
Money(long dollars, int cents);
Money(double dollars):all_cents(dollars * 100){}
Money():all_cents(0){}
double get_value() const{return all_cents/100;} 

private:
double all_cents;
};
int digit_to_int(char c);
//Function declaration for function used in the definition of Money::input:
//Preconditon c is one of the digits '0' through '9'
//Returns the integer for the digit. digit_to_int('3') returns 3
class Checks{
public:
double get_checks_value() const{return amount.get_value();}
//get the amount value in double(dollars)
Money get_amount() const{return amount;}
//return Money amount
bool get_cashed() const{return checked;}
//Return checked. 
int get_number() const{return number;}
//Return Checks number
Checks():number(0),amount(),checked(0){}
Checks(bool cashed, int serial_number, double dollars);
void input();
//Set up the checks with input values
private:    
int number;
Money amount;
bool checked;
};
Money* record_deposits(int& total_checks_count, Money& total_count);
//Record all deposits and create the deposit array
void printSubCheckArr(Checks* arr, int count);
//print the cashed checks array and uncashed checks array
bool cmp(Checks a, Checks b);
//an help function for sort used in main
void printCheckArr(Checks* checkArr, int total_amount);
//print all checks including uncashed and cashed

int main()
{
    Money old_balance, balance_adding_deposits, total_deposits_value;
    cout<<"Please enter your orginal account balance(in the form $dd.cc):\n";
    cin>>old_balance;
    int total_deposits = 0;
    Money* deposits_arr = record_deposits(total_deposits, total_deposits_value);
    balance_adding_deposits = old_balance + total_deposits_value;
    cout<<"Updated balance(including all deposits) is: "<<balance_adding_deposits<<endl;
    cout<<"---------------------------------------------------------------\n"; //以上checked完毕
    
    int cashed = 0, total_checks;
    cout<<"Please enter the amount of total checks: ";
    cin>>total_checks;
    Checks* checkArr = new Checks[total_checks];
    for(int i = 0; i < total_checks; i ++){
        cout<<"For #"<<i + 1<<" check \n";
        checkArr[i].input(); 
        if(checkArr[i].get_cashed() == true)
          cashed ++;
    }
    sort(checkArr, checkArr + total_checks, cmp);
    int uncashed = total_checks - cashed; 
 
    int a = 0, b = 0;
    Money total_cashed_value, total_uncashed_value;
    Checks* cashed_arr = new Checks[cashed];
    Checks* uncashed_arr = new Checks[uncashed];
    
    for(int i = 0; i < total_checks; i++){
        if(checkArr[i].get_cashed() == true){
            cashed_arr[a] = checkArr[i];
            total_cashed_value = total_cashed_value + checkArr[i].get_amount();
            a ++;
        }
        else{
            uncashed_arr[b] = checkArr[i];
            total_uncashed_value = total_uncashed_value + checkArr[i].get_amount();
            b ++;
        }
    }    
    
    Money new_balance = balance_adding_deposits - total_cashed_value;
    cout<<endl;
    cout<<"-------------------------------------------------------------------\n";cout<<endl;
    cout<<"All Information Gathered. Your checkbook register is processing. \n";
    cout<<"-------------------------------------------------------------------\n";
    cout<<"\t Cashed Checks\n";
    printSubCheckArr(cashed_arr, cashed);
    cout<<endl;
    cout<<"Total of your cashed checks:"<<"\t"<<total_cashed_value<<endl;
    cout<<"-------------------------------------------------------------------\n";
    cout<<"Uncashed checks:\n";
    printSubCheckArr(uncashed_arr, uncashed);
    cout<<endl;
    cout<<"Total of your uncashed checks: "<<'\t'<<total_uncashed_value<<endl;
    cout<<"-------------------------------------------------------------------\n";
    printCheckArr(checkArr, total_checks);
    cout<<endl;
    
    cout<<"Total of your cashed checks: "<<'\t'<<total_cashed_value<<endl;
    cout<<"Total of your available balance:"<<new_balance<<endl;
    cout<<"Your checkbook balance is: "<<'\t'<<(new_balance - total_uncashed_value)<<endl;
    cout<<"-------------------------------------------------------------------\n";
    cout<<"Difference between available balance and checkbook balance: "<<total_uncashed_value<<endl;
    cout<<"Total of your uncashed checks: "<<total_uncashed_value<<endl;
    cout<<"----------------------------END-------------------------------------\n";
   
    return 0;
}

Money operator +(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}
Money operator -(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}
bool operator ==(const Money& amount1, const Money& amount2){
    return (amount1.all_cents == amount2.all_cents);
}
bool operator < (const Money& amount1, const Money& amount2){
    return (amount1.all_cents < amount2.all_cents);
}
Money::Money(long dollars, int cents){
    if(dollars * cents < 0){
        cout<<"Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

ostream& operator<<(ostream& outs, const Money& amount){
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;
    
    if(amount.all_cents < 0)
      outs<<"- $"<<dollars<<'.';
    else
      outs<<'$'<<dollars<<'.';
    if(cents < 10)
      outs<<'0';
    outs<<cents;
    
    return outs;
}
istream& operator>>(istream& ins, Money& amount){
    char one_char, decimal_point, digit1, digit2;//digits for the amount of cents
    long dollars;
    int cents, a, b;
    bool negative;//set to true if input is negative
    
    ins>>one_char;
    if(one_char == '-'){
        negative = true;
        ins >> one_char; //read '$'
    }
    else negative = false;
    
    ins>>dollars>>decimal_point>>digit1>>digit2;
    
    if(one_char !='$'||decimal_point!='.'||!isdigit(digit1)||!isdigit(digit2)){
        cout<<"Error illegal form for money input\n";
        exit(1);
    }
    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if(negative){
        amount.all_cents = - amount.all_cents;
    }
    return ins;
}

int digit_to_int(char c){ return (static_cast<int>(c) - static_cast<int>('0')); }

void Checks::input(){
    cout<<"Please enter the number of the check #";
    cin>>number;
    if(number < 0){
        cout<<"Error illigal for the number of the check input.";
        exit(1);
    }
   
    cout<<"Please enter the check amount($bb.cc): ";
    cin>>amount;
    
    string temp_checked;
    cout<<"Has the check been cashed(enter yes or no only): ";
    cin>>temp_checked;
    if(temp_checked == "yes" || temp_checked == "Y")
        checked = true;
    else if(temp_checked == "no" ||temp_checked == "N")  
        checked = false;
    else{      
        cout<<"Error illegal for the check been cashed input.\n"; 
        exit(1);
    }   
}
Money* record_deposits(int& total_checks_count, Money& total_count){
    cout<<"Please enter the number of deposits in total: ";
    cin>>total_checks_count;
    
    Money* deposits = new Money(total_checks_count);
    
    for(int i = 0; i < total_checks_count; i ++){
        cout<<"Please enter the the amount of the #"<< i+1 <<" deposit($dd.cc): ";
        cin>>deposits[i];
        total_count = deposits[i] + total_count;
    }
    return deposits;
}
bool cmp(Checks a, Checks b){
    if(a.get_number() < b.get_number()) 
      return true;
    else return false;  
}
void printSubCheckArr(Checks* arr, int count){
    cout<<"No. \t Amount";
    for(int i = 0; i < count; i++){
        cout<<'#'<<arr[i].get_number()
            <<'\t'<<arr[i].get_amount()<<endl;
    }
}
void printCheckArr(Checks* checkArr, int total_amount){
    cout<<'\t'<<"All Checks\n"<<endl;
    cout<<"No. \t Amount"<<"\t Cashed"<<endl;
    for(int i = 0; i < total_amount; i++){
        cout<<'#'<<checkArr[i].get_number()
            <<'\t'<<checkArr[i].get_amount()
            <<'\t'<<checkArr[i].get_cashed()<<endl;
    }
}
Checks::Checks(bool cashed, int serial_number, double dollars)
:checked(cashed), number(serial_number), amount(Money(dollars)){}