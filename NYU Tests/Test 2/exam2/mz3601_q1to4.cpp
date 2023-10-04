/*
1.
Proof: 
By using induction on n.
Base case: n = 0
When n = 0, the left side = 3^0 = 1 = (3^(n+1)-1)/2 = right side
Therefore, when n = 0, 1+...+3^n = (3^(n+1)-1)/2
Inductive steps:
Assuming that for an integer k(k>=0), 1+...+3^k = (3^(k+1)-1)/2
We shall prove that for the integer k+1, 1+...+3^(k+1) = (3^(k+1+1)-1)/2
Starting from the left side of the equation:
  1+3+9+27+...+3^(k+1)
= (1+3+9+27+...+3^k)+3^(k+1)  by seperating the last term
= (3^(k+1)-1)/2 + 3^(k+1)     by inductive hypothesis
= (3^(k+1))/2 + 2*3^(k+1)/2 - 1/2
= (3*3^(k+1))/2 - 1/2 
= (3^(k+2)-1)/2
= (3^(k+1+1)-1)/2    by algebra
Therefore, for all integers n>=0, 1+3+9+27+...+3^n= (3^(n+1)-1)/2

2.
a)
According to the question, the committee is in a size of five. 
And in that committee, there should be 3 sophomores and 2 freshmen.
Apparently the order within the committee does not affect the overall result.
The knowledge of permutation does not need for this question.
Therefore, there are (20 choose 3) possible ways for choosing the sophormores
And there are (15 choose 2) possible ways for choosing the freshmen.
Overall, there are (20 choose 3)*(15 choose 2) possible ways for the committee.

b)
There are 256 different bit strings of length 12 begin with 11 and end with 10.

Because the string is length 12. And it should begine with 11 and end with 10. 
Only 12-2-2 = 8 bits can be changed. For all bit string, a single bit can be 0/1.
It means for one single bit, there are two ways for it to change.
So for 8 bits, the different ways to form it is 2^8 = 256

3.
a)
Let A = the number on the ball drawn is greater than or equal to 3.
|A| = 5
p(a) = |A|/8 = 0.625

b)
Let A = the sum of numbers on two dies getting a sum of six
B = the number on the green die is odd
A \cap B = 3 = {(1,5),(3,2),(5,1)}
B = 3 * 6 = 18
p(A|B) = (A \cap B)/B = 3/18 = 1/6

4.
a) function1
Apparently when (n%2 == 0), which means when n is an even number,
the function1 will calculate in a higher growth speed than when 
the n is an odd number.(n*=3 vs n*=2) Therefore, we will look at when n is an 
even number and calculate the running time.

When n is an even number. 
If there is only one loop and the condition be
for(i =1; i<=n; i*=2), the running time would be logN.
If there is only one loop and the condition be
for(j = 1; j <=n; j++), the running time would be n.
Looking at the nested loop combining these two conditions,
and inside the loop, there is a sum += (i+j)
The running time would be 2NlogN
Overall, the running time would be \theta(NlogN) for function1.

b)function2
If there is only one loop and it is for(k=1;k<=n;k+=1)
the running time would be \theta(n)
If there is only one loop and it is for(i=1;i<=n;i*=3)
the running time would be \theta(log3N)
Inside the for(i=1;i<=n;i*=3) loop, there is another while loop
while(j>1){
    sum+=1; j/=3;
} the single running time would be log3N
Overall, the running time would be \theta(Nlog9N)

*/