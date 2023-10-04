#include <iostream>
using namespace std;

double eApprox(int n);
//user enter a positive integer n
//returns an approximation of e
//calculated by the sum of the first(n+1)
//addends of the infinite sum above
double factorial(int n);
//user enter a positive integer n
//returns the factorial of integer n
int main()
{
    int n;
    cout.precision(30);
    
    for(int n = 1; n<=15; n++){
        cout<<"n= "<<n<<'\t'<<eApprox(n)<<endl;
    }
    return 0;
}

double eApprox(int n){
    double e = 1;
    for(int i = 1; i <= n; i++){
        e = e + 1/factorial(i);
    }
    
    return e;
}

double factorial(int n){
    double s = 1;
    for(double i = 1; i <=n; i++)
        s = s * i;
    return s;    
}