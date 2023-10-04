#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Please enter a positive number:"<<endl;
    cin>>n;

    //最上面那排##
    for(int i = 0; i < n; i ++ )
        cout<<'#';
    cout<<endl;

    for(int i = 0; i < n/2 - 1; i++){
        cout<<'#';//最左侧的#
    for(int k = 0; k < i; k++){
        cout<<" ";//#$之间的空格。注意第一个没有空格的情况
    } 
    cout<<'$';
    for(int q = 0; q < n-2*(i+2); q++){
    cout<<" ";}   
    cout<<"$";
    for(int k = 0; k < i; k++){
        cout<<" ";//#$之间的空格。注意第一个没有空格的情况
    } 
        cout<<'#'<<endl;//最右侧的#,endl
    }

    for(int i = 0; i < n/2 -1; i ++){
        cout<<'#';//最左侧的#
    for(int k = 0; k < n/2 -2-i; k++){
        cout<<" ";//#$之间的空格
    }    
    cout<<'$';
    for(int k =0; k<2*i; k++){
        cout<<" ";//$$zhi之间的空格
    }
    cout<<'$';
    for(int k = 0; k < n/2 - 2 -i; k++){
        cout<<' ';}
    cout<<'#'<<endl;    
    }

//最下面那排#
    for(int i = 0; i < n; i ++ )
        cout<<'#';
    cout<<endl;
    return 0;
}