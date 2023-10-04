#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string make_lower(const string& s);
//将string s变为只有小写的string s; 
//可包括小数点等，小数点不改变
//最好复制一下原本的string 用复制string去make_lower
void check_print(const string& s, int length, char a);
int main(){
    string s;

    cout<<"Please enter a line of text"<<endl;
    getline(cin, s);

    //count the words
    int words_count = 1;
    for(int i = 0; i<s.length(); i++){
        if(isspace(s[i]))
          words_count ++;
    }
    cout<<words_count<<'\t'<<"words"<<endl;
    
    s = make_lower(s);
    
    string k="abcdefghijklmnopqrstuvwxyz";
    for(int i =0; i < k.length(); i++){
        char a = k[i];
        check_print(s, s.length(), a);
    }
   
    return 0;
}

string make_lower(const string& s){
    string temp(s);
    for(int i = 0; i < s.length(); i++)
      temp[i] = tolower(s[i]);
    return temp;  
}

void check_print(const string& s, int length, char a){
    int count = 0;
    for(int i = 0; i < length; i ++)
        if(s[i] == a)
          count ++;
    if(count > 0)
      cout<<count<<'\t'<<a<<endl;
}