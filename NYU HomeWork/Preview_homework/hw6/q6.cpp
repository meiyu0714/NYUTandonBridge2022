#include <iostream>
#include <string>

using namespace std;

int make_array(const string& s, int index[], int MAX);
/* preconditon: a line of text -string s, empty array index,
MAX: approximate max number of spaces
postcondition: array index of index where the space is*/

bool number_check(const string& s, int a, int b);
/* precondition: string s, a, b
If s[a] - s[b] all numbers, then function return true
else return false */

void change_to_x(string& s, int a, int b);
/*precondition: string s, a, b
change s[a]-s[b] to 'x'*/

void check_and_change(string& s, int a, int b);
/*precondition: string s, a, b
if between and including s[a] and s[b] are numbers, 
then change them to ' ' */ 
const int MAX = 20;//approximate max space numbers. Change if you want
int main(){
    string s;
    int index[MAX];
    int size;
    index[0] = -1;
    cout<<"Please enter a line of text: \n";
    getline(cin, s);

    size = make_array(s, index, MAX); //size 是关于space的array index[]的总量
    index[size] = s.length();
 
    for(int i = 0; i < size ;  i++){
        check_and_change(s, index[i]+ 1, index[i+1] -1);
    } //check between each spaces
    
    cout<<s;

    return 0;
}

int make_array(const string& s, int index[], int MAX){
   int k = 1;
   for(int i = 0; i < s.length(); i ++){
    if(isspace(s[i])){
        index[k] = i;
        k ++;}
   }
   return k; }

bool number_check(const string& s, int a, int b){
    for(int i = a; i <= b; i++){
        if(isdigit(s[i]) == false)
          return false;
    }
    return true;  
}

void change_to_x(string& s, int a, int b){
    for(int i = a; i <= b; i ++){
        s[i] = 'x';
    }
}

void check_and_change(string& s, int a, int b){
    bool k = number_check(s, a, b);
        if(k == true)
            change_to_x(s, a, b);
}
    
    