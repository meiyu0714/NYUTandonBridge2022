#include <iostream>
#include <cmath>
using namespace std;

void analyzeDivisors(int num, int & outCountDivs, int & outSumDivs);

int main()
{
    int num;
    int outCountDivs = 0; outSumDivs = 0;
    
    cout<<"Please enter a positve integer: ";
    cin>>num;
    
    analyzeDivisors(num, outCountDivs, outSumDivs);

    return 0;
}

void analyzeDivisors(int num, int & outCountDivs, int & outSumDivs){
    for(int i=1; i<sqrt(num);i++){
        if(num % i == 0)
          outCountDivs = outCountDivs +2 ;
          outSumDivs = i + num /i + outSumDivs;
    }
    if(num % sqrt(num) == 0)
          outCountDivs = outCountDivs + 1;
          outSumDivs = outSumDivs + sqrt(num);
}