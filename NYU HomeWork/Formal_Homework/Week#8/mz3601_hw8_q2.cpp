#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
int main()
{
    string str;
    cout<<"Please enter a word: ";
    cin>>str;
    
    if(isPalindrome(str) == true)
    cout<<str<<" is a palindrome";
    else 
    cout<<str<<" is not a palindrom";
    

    return 0;
}
bool isPalindrome(string str){
    int str_length = str.length();
    for(int i = 0; i < str_length/2; i ++){
      if(str[i] != str[str_length - 1 -i])
        return false;
    }
    return true;
}