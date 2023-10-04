#include <iostream>
#include <string>
using namespace std;
string* createWordsArray(string sentence, int& outWordsArrSize);
int main(){
    string s;
    int wordsCount;
    cout<<"Please enter your sentence.\n";
    getline(cin, s);
    string* wordsArr = createWordsArray(s, wordsCount);
    for(int i = 0; i < wordsCount; i++){
        cout<<wordsArr[i]<<endl;
    }
    delete[] wordsArr;
    return 0;
}
string* createWordsArray(string sentence, int& outWordsArrSize){
    outWordsArrSize = 1;
    for(int i = 0; i < sentence.size(); i++){
        if(isspace(sentence[i]))
          outWordsArrSize ++;
    }
    string* WordsArray = new string[outWordsArrSize];
    int* WordsPauses = new int[outWordsArrSize +1];
    WordsPauses[0] = -1;
    WordsPauses[outWordsArrSize] = sentence.size();
    int space_count = 1;
    for(int i = 0; i < sentence.size();i++){
        if(isspace(sentence[i]))
        {
          WordsPauses[space_count] = i;
          space_count ++;
        }
    }
    for(int i = 0; i < outWordsArrSize; i ++){
        WordsArray[i] = sentence.substr(WordsPauses[i]+1, WordsPauses[i+1]-WordsPauses[i]-1);
    }
    return WordsArray;
}