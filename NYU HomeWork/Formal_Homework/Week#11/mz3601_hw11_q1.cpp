#include <iostream>
using namespace std;
void printTriangle(int n);
void printOpositeTirangles(int n);
void printRuler(int n);
int main(){
    cout<<"Recursive Function a: printTriangle\n";
    printTriangle(4);
    cout<<endl;

    cout<<"Recursive Function b: printOpositeTriangle\n";
    printOpositeTirangles(4);
    cout<<endl;

    cout<<"Recursive Function c: printRuler\n";
    printRuler(4);
    cout<<endl;

    return 0;
}
void printTriangle(int n){
    if(n ==1) 
      cout<<'*'<<endl;
    else{
        printTriangle(n-1);
        for(int i = 0; i < n; i++)
          cout<<'*';
        cout<<endl;
    }  
}
void printOpositeTirangles(int n){
    if(n == 1){
        cout<<'*'<<endl;
        cout<<'*'<<endl;}
    else{
        for(int i = 0; i < n; i++){
        cout<<'*';}
        cout<<endl; 
      printOpositeTirangles(n-1);
      for(int i = 0; i < n; i++)
        {cout<<'*';}
        cout<<endl;     
    }
}
void printRuler(int n){
  if(n == 1)
  cout<<'-'<<endl;
  else{
    printRuler(n-1);
    for(int i =0; i < n; i++){
      cout<<"- ";
    }
    cout<<endl;
    printRuler(n-1);
  }
}