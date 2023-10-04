#include <iostream>
#include <string>
#include <vector>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
int main()
{
    string s;
    cout<<"Please enter your sentence.\n";
    getline(cin, s);
    
    int wordsCount;
    string *words = createWordsArray(s, wordsCount);
    for(int i =0; i < wordsCount; i++){
        cout<<words[i]<<endl;
    }
    delete[] words;
   
    return 0;
}
string* createWordsArray(string sentence, int& outWordsArrSize){
    vector<int> v;
    v.push_back(-1);
    for(int i = 0; i<sentence.length(); i++){
        if(isspace(sentence[i])){
            v.push_back(i);
        }
    }
    v.push_back(sentence.length());
    
    outWordsArrSize = v.size() -1;
    
    string* words = new string[outWordsArrSize];
    
    int start, len;
    for(int i = 0; i < outWordsArrSize; i++){
        start = v[i]+1;
        len = v[i+1]-v[i] -1;
        words[i] = sentence.substr(start, len);
    }
    return words;
}
