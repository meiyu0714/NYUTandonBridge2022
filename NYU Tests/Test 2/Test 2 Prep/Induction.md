### **Question 1:**

Prove that the sum of the n first odd positive integers is n^2 , ie. 1 + 3+ 5+ 7 +...+ (2n -1) = n^2 

Proof: 

By induction on n.

Base case: n = 1

When n = 1, the left side = 1 = 1^2 = the right side of the equation. Therefore, the theorem is true when n=1.

Inductive steps：

 Suppose that for positive integer k, 1 + 3 + 5+7 + 9 + 11 +..+2k-1 = k^2 is true, then we will show that 1 + 3+ 5+ ..+ 2(k+1)-1 = (k+1)^2 

Starting with the left side of the equation to be proven:

1 + 3 + 5 + 7 + ... + 2k-1 + (2(k+1) -1)

= (1+3+...+2k-1) + (2(k-1)-1) by separating the last term

= k^2 + (2(k+1)-1) by inductive hypothesis

= k^2 + 2k + 1

=(k+1)^2 by algebra

 

other induction examples and clues: 

eg. one from the class: prove 7^(k+2) + 8^(2k-1) 指数分割很重要

--other example: how to prove 6 evenly divides 7^n-1 (from formal exam)

记住流程 关键词 by inductive hypothesis, by algebra, by....





