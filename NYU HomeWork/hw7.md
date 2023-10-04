8.2.2

Give complete proofs for the growth rates of the polynomials below. You should provide specific values for c and n_0 and prove algebraically that the functions satisfy the definitions for O and Ω.

(b)

Give complete proofs for the growth rates of the polynomials below. You should provide specific values for c and n0 and prove algebraically that the functions satisfy the definitions for O and Ω.

f(n) = n^3 + 3^n2 + 4. Prove that f = Θ(n3).

According to the definition of Θ:

Let f(n) and g(n) be two functions mapping positive integers to non-negative real numbers.

We say that f(n) = Θ(g(n)) if f(n) = O(g(n)) and f(n) = Ω(g(n)).

In this task, f(n) = n^3 + 3n^2 + 4, g(n) = n^3;

Proof:

First of all, we shall prove that f = O(g)

Select c = 4 and n_0 = 1. We will show that for any n >= 1, f(n) <= 8*g(n).

For n >=1, n^2 <= n^3, so

 f(n) = n^3 + 3n^2 + 4 <= n^3 + 3n^3 + 4n^3 <= 8n^3 = 8*g(n)

and therefore, f(n) <= 8*g(n) which means that f = O(g). 

小黑方块

8.3.5 Worst-case time complexity

(a) 	

