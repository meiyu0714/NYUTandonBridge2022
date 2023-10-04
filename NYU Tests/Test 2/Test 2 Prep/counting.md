Permutation and combination(排列与组合) combination又叫subset



counting 是和probability不一样的又有关联的部分 

5 counting

product rule, sum rule

例题: 车牌长度可以是6,7,8 那么有多少种可能 hint 10+26 = 36

|A6 ∪ A7 ∪ A8| = |A6| + |A7| + |A8| = 366 + 367 + 368

bijection rule: p(A) = 2^(a里元素的个数)

k-to-1 rule: 数鞋子算孩子(k=2)

5.3 Generalized product rule

每个位置有多少可能，每个可能数相乘

P(n, r) 在一个集合A中有n个元素，取r个(不重复的选) 顺序很重要

![image-20220918173101946](C:\Users\zzhez\AppData\Roaming\Typora\typora-user-images\image-20220918173101946.png)

就是传统的10!9!8!7!

5.5 Counting subsets: 顺序不重要了  A subset of size r is called an **r-subset**

we are counting the different number of subsets from a class of size 20.

difference between p(n,n) and c(n,n)

p(n,n) = n!, c(n,n) = 1

c(n,r) n choose r 

n choose r =  n choose (n-r)

经典例题: 如何从a点走到b点。n = →数+向上数，r =  →数/向上数

排列和组合不同的经典题:

A teacher is distributing a set of four prizes to 10 students in his class. Each student can get at most one prize. how many ways if:

a) The prices are all identical.

b) The prizes are all different from each other.

一定要注意区分！！！！

错题:

5.6.2 Dave swims three times in the week. How many ways are there to plan his workout schedule (i.e. which days he will swim) for a given week?

Provide solutions in either the form "P(n, r)" or "n choose r" 

Counting possibilities by complement: 

例题：at least choose etc.

**Permutations with repetitions** 很有意思的议题

![image-20220918205208572](C:\Users\zzhez\AppData\Roaming\Typora\typora-user-images\image-20220918205208572.png)

例题：

Suppose that 9 desserts are handed out to 9 kids. Each kid gets one dessert. There are three ice cream sandwiches, four cupcakes and two bowls of pudding. How many ways are there to hand out the desserts to the kids?

at least 这种分情况看，是<= at least 的情况多 还是大于 at least的情况多。也就是 是P 多还是-P多。

不缺不漏。对于重复的情况一定要小心。

例题;

1) 2160共有多少个不同的正因数
2) A= {1,2,3,4,5,6} 共有多少个子集。

排列： n个， m个排成一列 AB != BA

组合：n个 m个 组合 无顺序

排列如何推导到组合：

1）选出：不知道顺序 2）排列：

cmn = Amn / Amm

什么是排列：选完之后还要排

什么是组合：选完之后不用排了

做应用题更重要的是共情，共情的去思考怎么去做。如果你是摄影师，你怎么去做，如果。。。你怎么去做

分解成步骤；乘法原理一乘就可

![image-20220922213821367](C:\Users\zzhez\AppData\Roaming\Typora\typora-user-images\image-20220922213821367.png)

拆成小步骤 怎么拆是真的难啊

