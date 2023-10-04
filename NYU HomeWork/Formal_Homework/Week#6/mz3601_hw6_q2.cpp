#include <iostream>
using namespace std;
void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);
int main(){
    char symbol;
    int num, lines, spaces;

    cout<<"Please enter the number of triangles in the tree: "<<endl;
    cin>>num;
    cout<<"Please enter the symbol you want to fill the triangle, eg. '*', '+', '$':"<<endl;
    cin>>symbol;

    printPineTree(num, symbol);

    return 0;
}
void printShiftedTriangle(int n, int m, char symbol){
   for(int k = 0; k < n; k ++){
    for(int i = 0; i < n + m -1 - k; i ++){
        cout<<' ';}
    for(int q = 0; q < 2*k +1; q ++){
        cout<<symbol;
    }
    cout<<endl;
   }
   
}
void printPineTree(int n, char symbol){
    for(int z = 2; z < n + 2; z ++){
        printShiftedTriangle(z, n - z +1, symbol);
    }
}

