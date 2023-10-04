#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main(){
    int num;
    char symbol;
    
    cout<<"Please enter the number of triangles in the tree: ";
    cin>>num;
    cout<<"Please enter the character filling the tree: ";
    cin>>symbol;
    
    printPineTree(num, symbol);
    
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol){
    for(int i=1; i<= n; i ++){
        for(int k = 1; k <= m + n - i; k ++)
            cout<<' ';
            for(int g = 1; g <= 2*i - 1; g ++)
                cout<<symbol;
        cout<<endl;
    }
}

void printPineTree(int n, char symbol){
    for(int i=1; i <= n; i ++){
        printShiftedTriangle(i+1, n-i, symbol);
    }
}