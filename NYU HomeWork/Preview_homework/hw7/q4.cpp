#include <iostream>
#include <vector>
#include <string>

using namespace std;
string* createWordsArray(string setence, int& outWordsArrSize);
int main(){
    
    string* wordsArr;
    int WordsArrSize;
    string s;
    cout<<"Please enter your line: \n";
    getline(cin, s);
    wordsArr = createWordsArray(s, WordsArrSize); //check if this is right
    cout<<"WordsArrSize = "<<WordsArrSize<<endl;
    for(int i = 0; i < WordsArrSize; i++)
      cout<<wordsArr[i]<<endl;
    delete [] wordsArr;

    return 0;
}

string* createWordsArray(string setence, int& outWordsArrSize){

    //vector 列表记录每个空格出现index 
    //vector.size()+1 是word总和 vector.size()是空格总和
    vector<int> space_count;
    for(int i = 0; i < setence.length(); i++)
        if(setence[i] == ' ')
         space_count.push_back(i);  
    outWordsArrSize = space_count.size() + 1;

    //创建了空格vector序列 且完成了outWordsArrSize的反馈
    //接下来完成string* WordArr的建立和输出
    //现在建立一个关于

    vector<int> word_separator;
    word_separator.push_back(-1);
    for(int i = 0; i < space_count.size(); i++)
      word_separator.push_back(space_count[i]);
    word_separator.push_back(setence.length());  
//检测完毕，以上正确

//创立word的分割线-即空格所在的点位
    string* WordArr;
    WordArr = new string[outWordsArrSize];
    for(int i = 0; i < outWordsArrSize; i++)
        WordArr[i] = setence.substr(word_separator[i] + 1, word_separator[i+1]-(word_separator[i] + 1));

    return WordArr;
}