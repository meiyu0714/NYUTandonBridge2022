#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

const int LETTER_NUMBER = 26;
void letters_count(const string& s, int a[]);
bool same_length_array_check(int a[], int b[], int size);
void print_result(bool k);
int main(){
    string s1, s2;

    cout<<"Please enter the first line"<<endl;
    getline(cin, s1);

    cout<<"Please enter the second line"<<endl;
    getline(cin, s2);

    int letters1[LETTER_NUMBER] = {0};
    int letters2[LETTER_NUMBER] = {0};
    int diff1, diff2;

    letters_count(s1, letters1);

    letters_count(s2, letters2);

    bool k = same_length_array_check(letters1, letters2, LETTER_NUMBER);

    print_result(k);

    return 0;
}
void letters_count(const string& s, int a[]){
    for(int i = 0; i < s.length(); i++){
        if(tolower(s[i])>='a' && tolower(s[i])<='z'){
            int diff = tolower(s[i]) - 'a';
            a[diff] ++;
        }
    }
}
void print_result(bool k){
    if(k == true)
      cout<<"line a and line b are anagrams";
    else  
      cout<<"line a and line b are not anagrams";  
}
bool same_length_array_check(int a[], int b[], int size){
    for(int i = 0; i < size; i++){
        if(a[i] != b[i])
            return false;
    }
    return true;
}