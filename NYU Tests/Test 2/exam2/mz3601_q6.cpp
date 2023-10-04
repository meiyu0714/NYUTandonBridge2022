#include <iostream>
#include <vector>
#include <string>
using namespace std;
string remove_char(string s);
int main(){
    vector<string> inputs;
    string temp;
    cout<<"Please enter a non-empty sequence of Strings. Each string should\n" 
        <<"be in a separate line and consists of only lowercase English\n" 
        <<"letters and/or special characters @, #, $, !, &. To indicate the\n" 
        <<"end of the input, enter an empty string in one line."<<endl;
    getline(cin,temp);
    while(temp.length() > 0){
        inputs.push_back(temp);
        getline(cin, temp);
    }    
    vector<string> char_removed_string;
    string temp_removed;
    for(int i =0;i<inputs.size(); i++){
        temp_removed = remove_char(inputs[i]);
        char_removed_string.push_back(temp_removed);
    }
    int only_char_count = 0, only_lett_count = 0;
    for(int i = 0; i < inputs.size();i++){
        if(char_removed_string[i].size() == 0)
          only_char_count ++;
        if(char_removed_string[i].size()!=0)
          cout<<char_removed_string[i]<<endl;  
        if(char_removed_string[i] == inputs[i])
          only_lett_count ++;  
    }    
    cout<<"Number of Strings in the input sequence that contain only special\n" 
        <<"characters: "<<only_char_count<<endl;
    cout<<"Number of Strings in the input sequence that contain only lowercase\n" 
        <<"English letters:\n"<<only_lett_count<<endl;    
    return 0;
}
string remove_char(string s){
    string special_char = "@#$!&";
    string no_char;
    for(int i = 0; i < s.size(); i++){
        int k = special_char.find(s[i],0);
        if(k<0||k>special_char.size()){
            no_char.push_back(s[i]);
        }
    }
return no_char;
}