/*
1. 
Proof: using induction on n.
Base case: n =1
When n = 1, 7^n-1 = 6 = 6*1. 
Therefore, when n =1, 6 evenly divides 7^n -1;
Inductive steps:
Assuming that for any positive integer k, 6 evenly divides 7^k-1, 
then we shall prove that for any positive integer k+1, 6 evenly divides
7^(k+1)-1
Because 6 evenly divides 7^k-1, therefore, 7^k-1 = 6m, m is a positive integer. 
Adding 1 to both sides of the equation. 7^k = 6m+1
Staring with 7^(k+1)-1
7^(k+1)-1 
= 7*7^7 - 1 by algebra
= 7*(6m+1) -1  by inductive hypothesis
= 6*7m -6
= 6*(7m-1)   by algebra
Because m is an integer, 7m-1 is an integer too. It means that 6 can evenly divides 7^(k+1) -1.  
Therefore, if and only if num is a multiple of 6, 6 evenly divides an integer num.

2. 
number of outcomes of a 4-digit pin code with repeated digits = 10^4
number of outcomes of exactly one digit appears one time = 10*9*8*7
number of choices of eactly one digit appears more than once = 10^4 - 10*9*8*7

3.a
p(1) = 1/36
p(2) = 3/36 = 1/12
p(3) = 5/36 
p(4) = 7/36 
p(5) = 9/36 = 1/4
p(6) = 11/36 
  .b
E[X] = (1*1+3*2+5*3+7*4+5*9+11*6)/36 = 161/36

4.
func1 T(n) = /theta(n^2)
func2 T(n) = /theta(n^2)


*/