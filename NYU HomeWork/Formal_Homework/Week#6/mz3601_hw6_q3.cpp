#include <iostream>
using namespace std;
double eApprox(int n);
double factorial(int n);
int main(){


    cout.precision(30);

    for(int n = 1; n <= 15; n++){
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    
    return 0;
}

double eApprox(int n){
    double e = 1.0;
    for(int i = 1; i <= n; i++){
      e = e + 1/factorial(i);
    }
    return e;
}
double factorial(int n){
    double factorial = 1.0;
    for(double i = 1.0; i <= n; i++){
        factorial = factorial * i;
    }
    return factorial;
}