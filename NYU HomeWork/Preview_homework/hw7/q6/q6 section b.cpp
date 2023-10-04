#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int num, num_search;
    cout<<"Please enter a sequence of positive integers, end in a separate line."<<endl;
    cout<<"End you input by typing -1."<<endl;
    cin>>num;
    while(num > 0){
        v.push_back(num);
        cin>>num;
    }
    cout<<"Please enter a number you want to search."<<endl;
    cin>>num_search;
    //Find num_search
    vector<int> index;
    for(int i = 0; i < v.size();i++){
        if(num_search == v[i]){
            index.push_back(i);}
    }
    //Print out vector array index:
    switch (index.size()){
     case 0: {
        cout<<num_search<<" does not show in lines.";
        break;
     }
     case 1: {
        cout<<num_search<<" shows in line ";
        cout<<index[0] + 1<<'.';
        break;
     }
     default: {
        cout<<num_search<<" shows in lines "<<index[0] + 1;
        for(int i = 1; i < index.size(); i ++){
            cout<<", "<<index[i] + 1;
        }
        cout<<'.';
        break;
     }
    }

    return 0;
}