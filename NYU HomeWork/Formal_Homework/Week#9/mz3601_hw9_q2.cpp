#include <iostream>
using namespace std;

const int LETTERS_TOTAL_NUMBER = 26;
void letterCount(string s, int* arr, int arrSize);
bool arr_compare(int* arr1, int* arr2, int size1);
int main()
{
    string s1, s2;
    cout<<"Please enter your first string:\n";
    getline(cin, s1);
    cout<<"Please enter your second string:\n";
    getline(cin, s2);
    
    int arr1[LETTERS_TOTAL_NUMBER] = {0}, arr2[LETTERS_TOTAL_NUMBER] = {0};
    
    letterCount(s1, arr1, LETTERS_TOTAL_NUMBER);
    letterCount(s2, arr2, LETTERS_TOTAL_NUMBER);
   
    bool result = arr_compare(arr1, arr2, LETTERS_TOTAL_NUMBER);
    
    if(result == true){
        cout<<"These two strings are anagrams";
    }
    else 
      cout<<"These two strings are not anagrams";

    return 0;
}
void letterCount(string s, int* arr, int arrSize){
    int k = 0;
     for(int i = 0; i < s.length(); i++){
        if(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z'){
            k = tolower(s[i]) -'a';
            arr[k] ++;
        }
    }
}
bool arr_compare(int* arr1, int* arr2, int size){
    for(int i = 0; i < size; i ++){
        if(arr1[i] != arr2[i])
          return false;
    }
    return true;
}