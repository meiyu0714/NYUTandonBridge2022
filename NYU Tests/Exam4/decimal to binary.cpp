#include <iostream>

using namespace std;

int main(){
    // int num, reminder, output;
    // int that = 1;

    // cout << "Please enter the num you want to change: ";
    // cin >> num;

    // while(num != 0){
    //     reminder = num % 2;
    //     output = output + that * reminder;
    //     that = that * 10;
    //     num = num/2;
    // }
    // cout << "binary form is: " << output;

// int num;
// int final_output = 1;
// cout << "2^ output, enter output: ";
// cin >> num;
// for(int i = 0; i < num; i++){
//     final_output = 2 * final_output;
// }
// cout << "answer is " << final_output;

    int num, reminder, output;
    int that = 1;

    cout << "Please enter the num you want to change: ";
    cin >> num;

    while(num != 0){
        reminder = num % 2;
        output = output + that * reminder;
        that = that * 10;
        num = num/2;
    }
    cout << "binary form is: " << output;


    return 0;
}