#include <iostream>
#include <string>
using namespace std;


int main()
{
    string Last_name, First_name, Middle_name;
    cout<<"Please enter your first name, middle name or initial,"
    <<" and last name, separated by space."<<endl;
    cin>>First_name;
    cin>>Middle_name;
    cin>>Last_name;
    
    cout<<Last_name<<','<<First_name<<' '<<Middle_name[0]<<'.';

    return 0;
}