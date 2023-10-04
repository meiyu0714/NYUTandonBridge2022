#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int TOTAL_GUESS = 5;
int main(){
    int myNum, guess, range_s = 1, range_b = 100;
    srand(time(0));
    myNum = (rand()%100) + 1;

    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;
    for(int i = TOTAL_GUESS; i > 1; i --){
        cout<<"Range: ["<<range_s<<", "<<range_b<<"], "
            <<"Number of guesses left: "<<i<<endl;
        cout<<"Your guess: ";
        cin>>guess;
        if(guess == myNum){
          cout<<"Congrats! You guessed my number in "<<TOTAL_GUESS + 1 - i<<" guesses.";
          return 0;
        }
        else if(guess > myNum){
            range_b = guess;
            cout<<"Wrong! My number is smaller."<<endl;
            cout<<endl;
        }
        else if(guess < myNum){
            range_s = guess;
            cout<<"Wrong! My number is bigger."<<endl;
            cout<<endl;
        }   
    }
    //the last guess
    cout<<"Range: ["<<range_s<<", "<<range_b<<"], "
        <<"Number of guesses left: 1"<<endl;
    cout<<"Your guess: ";
    cin>>guess;
    if(guess == myNum)
      cout<<"Congrats! You guessed my number in 5 guesses.";
    else  
      cout<<"Out of guesses! My number is "<<myNum;

    return 0;
}