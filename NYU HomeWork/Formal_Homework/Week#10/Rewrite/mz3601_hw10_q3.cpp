#include <iostream>
#include <vector>
using namespace std;
void main1();
void main2();
void resize(int*& arr, int& size);
const int ARR_SIZE = 10; 
int main(){
    main1();
    main2();

    return 0;
}
void main1(){
    int input, num;
    int* inputArr = new int[ARR_SIZE];
    int size = 10, count = 0;
    cout<<"Please enter a sequence of positive integers, each in a separate line.\n";
    cout<<"End you input by typing -1.\n";
    cin>>input;
    while(input > 0){
        if(count == size){
            resize(inputArr, size);
        }
        inputArr[count] = input;
        count ++;
        cin>>input;
    }

    cout<<"Please enter a number you want to search.\n";
    cin>>num;
    int* index = new int[ARR_SIZE];
    int index_count = 0, index_size = 10;
    for(int i = 0; i < count; i++){
        if(inputArr[i] == num){
            if(index_count == index_size)
              resize(index, size);
            index[index_count] = i+1;
            index_count ++;  
        } 
    }
    if(index_count == 0)
      cout<<num<<" does not show at all in the sequence.\n";
    else if(index_count == 1)
      cout<<num<<" shows in line "<<index[0]<<endl;
    else{
        cout<<num<<" shows in lines ";
        for(int i = 0; i < index_count -1; i ++){
            cout<<index[i]<<", ";
        }
        cout<<index[index_count -1]<<'.'<<endl;
    }    

    delete[] inputArr;
    delete[] index;
}
void main2(){
    int num, input;
    vector<int> v;
    cout<<"Please enter a sequence of positive integers, each in a separate line.\n";
    cout<<"End you input by typing -1.\n";
    cin>>input;
    while(input > 0){
      v.push_back(input);
      cin>>input;
    }
    cout<<"Please enter a number you want to search.\n";
    cin>>num;
    int count = 0; 
    vector<int> lines;
    for(unsigned int i = 0; i < v.size(); i++){
        if(v[i] == num){
            count ++;
            lines.push_back(i+1);
        }
    }
    if(count == 0 ){
       cout<<num<<" does not show at all in the sequence.";
    }
    else{
        if(count == 1)
          cout<<num<<" shows in line "<<lines[0]<<'.';
        else  
          cout<<num<<" shows in lines ";
          for(unsigned int i = 0; i < lines.size()-1; i ++){
            cout<<lines[i]<<", ";
          cout<<lines[lines.size()-1]<<'.';  
          }  
    }
}
void resize(int*& arr, int& size){
    size = 2 * size;
    int* newArr = new int[size];
    for(int i = 0; i < size/2; i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}