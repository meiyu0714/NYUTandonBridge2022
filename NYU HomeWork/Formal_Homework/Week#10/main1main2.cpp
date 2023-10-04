#include <iostream>
#include <vector>
using namespace std;

void main1();
void main2();
void resizeArr(int*& arr, int currentSize, int newSize);
const int BAS_ARR_SIZE = 10;
int main()
{
    main1();
    main2();
    return 0;
}
void main1(){
    int input, search, newSize, search_num =0, size = BAS_ARR_SIZE;
    int  count = 0;
    int* arr = new int[size]; 
    cout<<"Please enter a sequence of positive integers, each in a separate line.\n";
    cout<<"End your input by typing -1.\n";
    cin>>input;
    
    while(input > 0){
        if(count < size){
            arr[count] = input;
            count ++;
        }
        else{
            newSize = 2 * size;
            resizeArr(arr, size, newSize);
            size = newSize;
            arr[count] = input;
            count ++;
        }
        cin>>input;
    }
    cout<<"Please enter a number you want to search.\n";
    cin>>search;
    int* searchArr = new int[BAS_ARR_SIZE];
    int search_size = BAS_ARR_SIZE, newSearchSize;
    for(int i = 0; i < count; i ++){
        if(arr[i] == search){
            if(search_num < search_size){
            searchArr[search_num] = i + 1;
            search_num ++;}
            else{
                newSearchSize = 2 * search_size;
                resizeArr(arr, search_size, newSearchSize);
                search_size = newSearchSize;
                searchArr[search_num] = i + 1;
                search_num ++;
            }
        }
    }
    cout<<search<<" shows in lines ";
    for(int i = 0; i < search_num; i++)
      cout<<searchArr[i]<<' ';
    delete[] arr;
    delete[] searchArr;
    cout<<endl;
}
void main2(){
    int input, find;
    vector<int> v;
    vector<int> index;
    cout<<"Please enter a sequence of positive integers, each in a separate line.\n";
    cout<<"End your input by typing -1.\n";
    cin>>input;
    while(input > 0){
        v.push_back(input);
        cin>>input;
    }
    cout<<"Please enter a number you want to search.\n";
    cin>>find;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == find){
            index.push_back(i);
        }
    }
    cout<<find<<" shows in lines ";
    for(int i = 0; i < index.size(); i ++){
        cout<<index[i]+1<<' ';
    }
}
void resizeArr(int*& arr, int currentSize, int newSize){
    int *temp = new int[newSize];
    for(int i =0; i < currentSize; i++)
      temp[i] = arr[i];
    delete[] arr;
    arr = temp;
}