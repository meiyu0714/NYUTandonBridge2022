#include <iostream>
#include <vector>
using namespace std;

void MaxMin(vector<int>& v){
    int min = v[0], max = v[0];
    for(int i = 0; i < v.size();i++){
        if(v[i] < min){
            min = v[i];
        }
        else if(v[i] > max){
            max = v[i];
        }
    }
    v[0] = min;
    v[1] = max;
    v.resize(2);
}

void findMaxMin(vector<int>& v, int begin, int end){
    if(begin >= (end - 1)){
        return;
    }
    int mid = begin + (end - begin)/2;
    findMaxMin(v,begin,mid);
    findMaxMin(v, mid+1,end);
    MaxMin(v);
}


int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
   
    
    findMaxMin(vec, 0, vec.size()-1);
    
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
    return 0;
}