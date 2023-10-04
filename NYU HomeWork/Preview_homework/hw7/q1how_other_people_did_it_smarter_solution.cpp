#include <iostream>
#include <string>
 
using namespace std;
 
void analyzeSentence(string enteredText);
 
 
int main() {
 
    string enteredSentence;
 
    cout << "Please enter a line of text: " << endl;
    getline(cin,enteredSentence);
 
    analyzeSentence(enteredSentence);
 
    return 0;
}
 
void analyzeSentence(string enteredText){
 
    int letters[26] = {0};
    int c;
 
    for(int i=0; i < enteredText.length(); i++){
 
        if(tolower(enteredText[i]) >= 'a' && tolower(enteredText[i]) <= 'z'){
            c = tolower(enteredText[i]) - 'a';
            letters[c]++;
        }
    }
 
    for(int i=0 ; i < 26; i++){
        if(letters[i] > 0){
            cout << letters[i] << "\t" << char(i+'a') << endl;
        }
    }
 
}