#include <iostream>
#include <string>
using namespace std;



int main()
{
    string input;

    cout<<"Please enter a word: ";
    cin>>input; 
  
    if(isPalindrome(input) == true)
     cout<<input<<" is a palindrome";
    else
     cout<<input<<" is not a palindrome";
  
    return 0;
}

bool isPalindrome(string str){
    string reverse_str = "";
    
    for(int i = str.length() - 1; i >=0; i --)
        reverse_str += str[i];
    if(str == reverse_str)
      return true;
    else
      return false;
}