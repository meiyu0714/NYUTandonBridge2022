#include <iostream>
#include <string>
using namespace std;
const int LETTERS_TOTAL_NUMBER = 26;
void countAndPrint(int* arr, int arrSize, string s);
int main()
{
    string s;
    int arr[LETTERS_TOTAL_NUMBER] = {0};
    cout<<"Please enter a line of text\n";
    getline(cin,s);
    
    countAndPrint(arr, LETTERS_TOTAL_NUMBER, s);
   
    return 0;
}
void countAndPrint(int* arr, int arrSize, string s){
    int k, space_count = 0;
    for(int i = 0; i < s.length(); i ++){
        if(tolower(s[i]) >='a'&& tolower(s[i]) <= 'z' ){
            k = tolower(s[i])-'a';
            arr[k] ++;
        }
        else if(s[i] == ' '){
            space_count ++;
        }
    }
    char output;
    cout<<space_count + 1<<'\t'<<"words"<<endl;
    for(int i = 0; i < LETTERS_TOTAL_NUMBER; i++){
        if(arr[i] > 0)
            cout<<arr[i]<<'\t'<<char(i +'a')<<endl;
    }
}