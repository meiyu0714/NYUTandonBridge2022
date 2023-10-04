#include <iostream>
#include <cmath>
using namespace std;

void analyzeDivisors(int num, int & outCountDivs, int & outSumDivs);
//enter a positive integer num
//calculate numbers of num's proper divisors and their sum;
bool isPerfect(int num);
//user should enter a positive integer num
//determines if num is perfect number or not;
//return True or False
int main()
{
    int M;
    int outSumDivs = 0, outCountDivs = 0;

    cout<<"Please enter a positve integer M(>=2): ";
    cin>>M;
    
    if(M < 2)
      cout<<"Invalid Output";
    else{
        cout<<"perfect numbers between 2 and M: ";
        for(int i=2; i <=M; i ++){
            if(isPerfect(i) == true)
              cout<<i<<" ";}
        cout<<endl;      
        }

       for(int i=2; i <= M; i ++){
           int cout_i = 0, sum_i = 0;
           analyzeDivisors(i, cout_i, sum_i);
           if(sum_i<=M ){
               int k = sum_i;
               int count_k = 0, sum_k = 0;
               analyzeDivisors(k, count_k, sum_k);
               if(sum_k == i && k !=i && k <i)
                 cout<<k<<" and "<<i<<" are amicable numbers"<<endl;
           }
         
       } 
    
    return 0;
}

void analyzeDivisors(int num, int & outCountDivs, int & outSumDivs){
    int sq = (int)sqrt(num);
        for(int i=1; i <= sq;i++){
          if(num % i == 0){
            outCountDivs = outCountDivs + 2;
            outSumDivs = outSumDivs + i + (num/i);
           }
        }
        if(sq * sq == num){
            outCountDivs = outCountDivs -2;
            outSumDivs = outSumDivs - sq - num;
        }
        else{
        outCountDivs = outCountDivs - 1;
        outSumDivs = outSumDivs - num;
        }
}

bool isPerfect(int num){
    int outSumDivs = 0, outCountDivs = 0;
    analyzeDivisors(num, outCountDivs, outSumDivs);
    if(num == outSumDivs)
        return true;
    else
      return false;
}