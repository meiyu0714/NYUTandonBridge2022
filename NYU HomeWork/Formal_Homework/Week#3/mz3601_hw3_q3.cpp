#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double num_a, num_b, num_c; //inputs
    double k; // k= b^2 - 4ac
    double solu_1, solu_2; // variable for solutions
    
    cout<<"Please enter value of a: ";
    cin>>num_a;
    cout<<"Please enter value of b: ";
    cin>>num_b;
    cout<<"Please enter value of c: ";
    cin>>num_c;
    
    if(num_a == 0){
        if(num_b == 0 && num_c == 0)
          cout<<"This equation has infinite number of solutions";
        else if(num_b == 0 && num_c != 0)
          cout<<"This equation has no solution";
        else{
            solu_1 = - num_c / num_b;
            cout<<"This equation has a single real solution x= "<<solu_1;
        }
    }
    
    //a != 0
    else{
        k = num_b * num_b - 4*num_a*num_c;

        if(k < 0)
          cout<<"This equation has no real solution.";
        else if( k == 0){
          solu_1 = - num_b / 2 / num_a;
          cout<<"This equation has a single real solution x="<<solu_1;
        }
        else{
          solu_1 = - (num_b + sqrt(k)) / 2 / num_a;
          solu_2 = - (num_b - sqrt(k)) / 2 / num_a;
          cout<<"This equation has two real solutions x1="<<solu_1
              <<", x2="<<solu_2;
        }      
    }

    return 0;
}