# 第四章 入门篇(2)——算法初步

## 4.1 排序

### 4.1.1 选择排序

简单选择排序是指，对一个序列A中的元素`A[1] ~ A[n]`，令i从1到n枚举，进行n趟操作，每趟从待排序部分`[i, n]`中选择最小的元素，令其与待排序部分的第一个元素`A[i]`进行交换，这样元素`A[i]`就会与当前有序区间`[1, i - 1]`形成新的有序区间`[1, i]`。于是在n趟操作后，所有元素就会是有序的。

算法逻辑：总共需要进行n趟操作，每趟操作选出待排序部分`[i, n]`中最小的元素，令其与`A[i]`交换，总复杂度为`O(n^2)`。

> 代码示例:

```C++
    void selectSort()
    {
        for(int i = 0; i < n; i++)
        {
            int k = i;
            for(int j = i; j <= n; j++)
            {
                if(A[j] < A[k])
                    k = j;
            }
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
        }
    }
```

### 4.1.2 插入排序

直接插入排序是指，对序列A的n个元素`A[1] ~ A[n]`，令i从2到n枚举，进行`n - 1`趟操作。假设某一趟时，序列A的前`i - 1`个元素`A[1] ~ A[i - 1]`已经有序，而范围`[i, n]`还未有序，那么该趟从范围`[1, i - 1]`中寻找某个位置j，使得将`A[i]`插入位置j后（此时`A[j] ~ A[i - 1]`会后移一位至`A[j + 1] ~A[i]`），范围`[1, i]`有序。

插入排序是将待插入元素一个个插入初始已有序部分中的过程，而插入位置的选择遵循了使插入后仍然保持有序的原则，具体做法一般是从后往前枚举已有序部分来确定插入位置。

> 代码示例:

```C++
    int A[maxn], n; // n为元素个数，数组下标为0~n-1
    void insertSort()
    {
        for(int i = 1; i <= n-1; i++)
        {
            int temp = A[i], j = i;
            while(j > 0 && temp < A[j-1])
            {
                A[j] = A[j - 1];
                j--;
            }
            A[j] = temp;
        }
    }
```

### 4.1.3 排序题与sort函数的应用

1. cmp函数的编写

使用sort进行排序时，需要提供cmp函数实现的排序规则。比如，经常会出现类似这样的要求：对所有学生先按分数从高到低排序，分数相同的按姓名的字典序从小到大排序。

需要完成的排序规则可以等价表述如下：

1) 如果两个学生分数不相同， 那么分数高的排在前面。
2) 否则， 将姓名字典序小的排在前面。

> 代码示例:

```C++
    bool cmp(Student a, Student b)
    {
        if(a.score != b.score) return a.score > b.score;
        else return strcmp(a.name, b.name) < 0;
    }
```

`strcmp`函数是`string.h`头文件下用来比较两个`char`型数组的字典序大小的，其中`strcmp(str1, str2)`当`str1`的字典序小于`str2`时返回一个负数，当`str1`的字典序等于`str2`时返回0，当`str1`的字典序大于`str2`时返回—个正数。

> 练习1：

[PAT A1025](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4/Sec4Exa1A1025/main.cpp)

## 4.2 散列

### 4.2.1 散列的定义与整数散列

一般来说，散列(Hash)可以浓缩成一句话“将元素通过一个函数转换为整数，使得该整数可以尽量唯一地代表这个元素”。其中把这个转换函数称为**散列函数H**，也就是说，如果元素在转换前为key，那么转换后就是一个整数`H(key)`。

那么对key是整数的情况来说，常用的散列函数有**直接定址法(或是线性变换`H(key) = a * key + b`)**、**平方取中法**、**除留余数法**等。

其中，常用的为**除留余数法**，指把key出意一个数mod得到的余数作为hash值得方法，即：`H(key)=key % mod`。

但是通过除留余数法可能会有两个不同的数key1和key2的hash值相同，则会造成hash值冲突。可考虑采用**线性探查法**(**Linear Probing**)、**平方探查法**(**Quadratic probing**)、**链地址法**(**拉链法**)等三种方法，其中前两种均需要计算新的hash值，又称为**开放定址法**。

1. 线性探查法(Linear Probing)

当得到key的hash值`H(key)`，但是表中下标为`H(key)`的位置已经被某个其他元素使用了，那么就检查下一个位置`H(key) + 1` 是否被占，如果没有，就使用这个位置；否则就继续检查下一个位置（也就是将hash值不断加1)。如果检查过程中超过了表长，那么就回到表的首位继续循环，直到找到一个可以使用的位置，或者是发现表中所有位置都已被使用。显然，这个做法容易导致扎堆，即表中连续若干个位置都被使用，这在一定程度上会降低效率。

2. 平方探查法(Quadratic probing)

在平方探查法中，为了尽可能避免扎堆现象，当表中下标为`H(key)`的位置被占时，将按下面的顺序检查表中的位置：`H(key) + 1^2`, `H(key) - 1^2`, `H(key) + 2^2`, `H(key) - 2^2`, `H(key) + 3^2`, ...。如果检查过程中`H(key) + k^2`超过了表长TSize，那么就把`H(key) + k^2`对表长TSize取模；如果检查过程中出现`H(key) - k^2< 0`的情况（假设表的首位为0)，那么将`((H(key) - k^2) % TSize + TSize) % TSize`作为结果（等价于将`H(key) - k^2`不断加上TSize直到出现第一个非负数）。如果想避免负数的麻烦，可以只进行正向的平方探查。可以证明，如果k在`[0, TSize)`范围内都无法找到位置，那么当`k≥TSize`时，也一定无法找到位置。

3. 链地址法(拉链法)

链地址法不计算新的hash值，而是把所有`H(key)`相同的key连接
成一条单链表。这样可以设定一个数组`Link`，范围是`Link[0] ~ Link[mod]`，其中`Link[h]`存放`H(key) = h`的一条单链表，于是当多个关键字key的hash值都是h时，就可以直接把这些冲突的key直接用单链表连接起来，此时就可以遍历这条单链表来寻找所有`H(key) = h`的key。

以上即可构建一对键值对，同时也可通过标准库模板中的map实现。

### 4.2.2 字符串hash初步

字符串hash是指将一个字符串S映射为一个整数，使得该整数可以尽可能唯一地代表字符串S。本节只讨论将字符串转换为唯一的整数，进阶部分
在[12.1]()节。

假设字符串均由大写字母A~Z组成，则不妨将A~Z视为0~25，构成二十六进制，然后再将二十六进制转换为十进制，即可完成字符串到整数的映射。

> 代码示例:

```C++
    int hashFunc(char S[], int len) // hash函数，将字符串S转换为整数
    {
        int id = 0;
        for(int i = 0; i < len; i++)
        {
            id = id * 26 + (S[i] - 'A');
        }
        return id;
    }
```

显然，如果字符串S的长度比较长，那么转换成的整数也会很大，因此需要注意使用时len不能太长。如果字符串中出现了小写字母，那么可以把A ~ Z作为0 ~ 25，而把a ~ z作为26 ~ 51，这样就变成了五十二进制转换为十进制的问题，做法也是相同的：

> 代码示例:

```C++
    int hashFunc(char S[], int len) // hash函数，将字符串S转换为整数
    {
        int id = 0;
        for(int i = 0; i < len; i++)
        {
            if(S[i] >= 'A' && S[i] <= 'Z')
            {
                id = id * 52 + (S[i] - 'A');
            }
            else if(S[i] >= 'a' && S[i] <= 'z')
            {
                id = id * 52 + (S[i] - 'a') + 26;
            }
        }
        return id;
    }
```

而如果出现了数字，一般有两种处理方法：

1. 按照小写字母的处理方法，增大进制数至62；
2. 如果保证在字符串的末尾是确定个数的数字，那么就可以把前面英文字母的部分按上面的思路转换成整数，再将末尾的数字直接拼接上去。

例如对由三个字符加一位数字组成的字符串：

> 代码示例:

```C++
    int hashFunc(char S[], int len) // hash函数，将字符串S转换为整数
    {
        int id = 0;
        for(int i = 0; i < len -1; i++)
        {
            id = id * 26 + (S[i] - 'A');
        }
        id = id * 10 + (S[len-1] - '0');
        return id;
    }
```

给出N个字符串（由恰好三位大写字母组成），再给出M个查询字符串，问每个查询字符串在N个字符串中出现的次数。

> 练习2：

[练习2](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4/Sec4Exa2Hash/main.cpp)

## 4.3 递归

### 4.3.1 分治

**分治**(**divide and conquer**)的全称为“分而治之”，也就是说，分治法将原问题划分成若干个规模较小而结构与原问题相同或相似的子问题，然后分别解决这些子问题，最后合并子问题的解，即可得到为原问题的解。上面的定义体现出分治法的三个步骤：

1. **分解**：将原问题分解为若干和原问题拥有相同或相似结构的子问题；
2. **解决**：递归求解所有子问题。如果存在子问题的规模小到可以直接解决，就直接解决它；
3. **合并**：将子问题的解合并为原问题的解。

需要指出的是，分治法分解出的子问题应当是相互独立、没有交叉的。如果存在两个子问题有相交部分，那么不应当使用分治法解决。

分治法作为一种算法思想，既可以使用递归的手段去实现，也可以通过非递归的手段去实现，可以视具体情况而定，一般而言，通过递归实现比较容易。

### 4.3.2 递归

递归就在于反复调用自身函数，但是每次把问题范围缩小，直到范围缩小到可以直接得到边界数据的结果，然后再在返回的路上求出对应的解。从这点上看，递归很适合用来实现分治思想。

递归的逻辑中一般有两个重要概念：

1. 递归边界；
2. 递归式（或称递归调用）。

经典的例子：使用递归求解n的阶乘，则递归式可写成：`F(n)=F(n-1)*n`，而递归边界可设为：`F(0)=1`。

> 代码示例:

```C++
    #include <iostream>
    using namespace std;
    int F(int n)
    {
        if(n == 0) return 1;
        else return F(n-1) * n;
    }

    int main()
    {
        int N;
        cin >> N;
        cout << F(N) << endl;
        return 0;
    }
```

另一个经典例子：求Fibonacci数列的第n项。斐波那契数列的递归式可表示为：`F(n) = F(n-1) + F(n-2), (n≥2)`，递归边界为：`F(0) = 1`和`F(1) = 1`。

> 代码示例:

```C++
    #include <iostream>
    using namespace std;
    int F(int n)
    {
        if(n == 0 || n == 1) return 1;
        else return F(n-1) + F(n-2);
    }

    int main()
    {
        int N;
        cin >> N;
        cout << F(N) << endl;
        return 0;
    }
```

要实现递归，则必须要有递归边界和递归式，其中递归边界用来返回最简单底层的结果，递归式用来减少数据规模并向下一层递归。

**全排列**(**Full Permutation**)。一般把1~n这n个整数按某个顺序摆放的结果称为这n个整数的一个排列，而**全排列指这n个整数能形成的所有排列**。

从递归的角度去考虑，如果把问题描述成“输出1~n这n个整数的全排列”，那么它就可以被分为若干个子问题：“输出以1开头的全排列”“输出以2开头的全排列”“输出以3开头的全排列”...“输出以n开头的全排列”。于是不妨设定一个数组P，用来存放当前的排列；再设定一个散列数组`hashTable`，其中`hashTable[x]`当整数`x`已经在数组P中时为`true`。

现在按顺序往P的第1位到第n位中填入数字。不妨假设当前已经填好了`P[1] ~ P[index-1]`，正准备填`P[index]`。显然需要枚举1~n，如果当前枚举的数字x还没有在`P[1] ~ P[index - 1]`中(即`hashTable[x] = false`)，那么就把它填入`P[index]`，同时将`hashTable[x]`置为true，然后去处理P的第`Index+1`位（即进行递归）；而当递归完成时，再将`hashTable[x]`还原为false，以便让`P[index]`填下一个数字。

递归边界为，当`index`达到`n+1`时，说明P的第1 ~ n位都已经填好了，此时可以把数组P输出，表示生成了一个排列，然后直接`return`即可：

> 代码示例:

```C++
    // 全排列(Full Permutation)
    #include <iostream>
    using namespace std;
    const int maxn = 11;

    // P为当前排列， hashTable记录整数x是否已经在P中
    int n, P[maxn], hashTable[maxn] = { false };

    // 当前处理排列的第index号位
    void generateP(int index)
    {
        if (n + 1 == index)	// 递归边界，已处理完排列的1~n位
        {
            for (int i = 1; i <= n; i++)
            {
                cout << P[i] << ' ';
            }
            cout << endl;
            return;
        }
        for (int x = 1; x <= n; x++)    // 枚举1~n，试图将x填入P[index]
        {
            if (false == hashTable[x])  // 如果x不在P[0]~P[index-1]中
            {
                P[index] = x;   // 令P的第index位位x，即把x加入当前排列
                hashTable[x] = true;    // 记住x已在P中
                generateP(index + 1);   // 处理排列的第index+1号位
                hashTable[x] = false;   // 已处理完P [ index]为x 的子问题， 还原状态
            }
        }
    }

    int main()
    {
        n = 3;
        generateP(1);   // 从P[1]开始填
        return 0;
    }
```

n皇后问题。n皇后问题是指在一个n*n的国际象棋棋盘上放置n个皇后，使
得这n个皇后两两均不在同一行、同一列、同一条对角线上，求合法的方案数。

对于这个问题，如果采用组合数的方式来枚举每一种情况（即从n^2个位置中选择n个位置），当n = 8时就是54502232次枚举，如果n更大，那么就会无法承受。

但是换个思路，考虑到每行只能放置一个皇后、每列也只能放置一个皇后，那么如果把n列皇后所在的行号依次写出，那么就会是1 ~ n的一个排列。于是就只需要枚举1 ~ n的所有排列，查看每个排列对应的放置方案是否合法，统计其中合法的方案即可。由千总共有n!个排列，因此当n = 8时只需要40320次枚举，比之前的做法优秀许多。

于是可以在全排列的代码基础上进行求解。由于当到达递归边界时表示生成了一个排列，所以需要在其内部判断是否为合法方案，即遍历每两个皇后，判断它们是否在同一条对角线上（不在同一行和同一列是显然的），若不是，则累计计数变器count即可。主要代码如下：

> 代码示例:

```C++
    #include <iostream>
    using namespace std;
    const int maxn = 11;
    int Count = 0;
    int n, P[maxn], hashTable[maxn] = { false };

    void generateP(int index)
    {
        if (index == n + 1) // 递归边界，生成一个排列
        {
            bool flag = true;   // flag为true表示当前排列为一个合法方案
            for (int i = 1; i <= n; i++)    // 边离任意两个皇后
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if(abs(i-j) == abs(P[i] - P[j]))    // 如果在一条对角线上
                        flag = false;
                }
            }
            if (flag) Count++;
            return;
        }
        for (int x = 1; x <= n; x++)
        {
            if (hashTable[x] == false)
            {
                P[index] = x;
                hashTable[x] = true;
                generateP(index + 1);
                hashTable[x] = false;
            }
        }
    }
```

这种枚举所有情况，然后判断每一种情况是否合法的做法是非常朴素的（因此一般把不使用优化算法、直接用朴素算法来解决问题的做法称为**暴力法**）。

一般来说，如果在到达递归边界前的某层，由于一些事实导致已经不需要往任何一个子问题递归，就可以直接返回上一层。一般把这种做法称为**回溯法**。下面的代码采用了回溯的写法：

> 代码示例:

```C++
    // 回溯法
    void generateP2(int index)
    {
        if (index == n + 1)// 递归边界， 生成一个合法方案
        {
            Count++;
            return;
        }
        for (int x = 1; x <= n; x++)    // 第x行
        {
            if (hashTable[x] == false)  // 如果第x行没有皇后
            {
                bool flag = true;   //flag 为true 表示当前皇后不会和之前的皇后冲突
                for (int pre = 1; pre < index; pre++)   // 遍历之前的皇后
                {
                    // 第index列皇后的行号为X , 第pre 列皇后的行号为P[pre]
                    if (abs(index - pre) == abs(x - P[pre]))
                    {
                        flag = false;   // 与之前的皇后在一条对角线， 冲突
                        break;
                    }
                }
                if (flag)   // 如果可以把皇后放在第x 行
                {
                    P[index] = x;   // 令第index 列皇后的行号为x
                    hashTable[x] = true;    // 第x 行已被占用
                    generateP2(index + 1);  // 递归处理第index+l 行皇后
                    hashTable[x] = false;   // 递归完毕，还原第x行为未占用
                }
            }
        }
    }
```

## 4.4 贪心

### 4.4.1 简单贪心

贪心法是求解一类最优化问题的方法，它总是考虑在当前状态下局部最优（或较优）的策略，来使全局的结果达到最优（或较优）。

严谨使用贪心法来求解最优化问题需要对采取的策略进行证明。证明的一般思路是使用反证法及数学归纳法，即假设策略不能导致最优解，然后通过一系列推导来得到矛盾，以此证明策略是最优的，最后用数学归纳法保证全局最优。

> PATB1020 月饼：

[PATB1020](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4/Sec4Exa5MoonCake/main.cpp)

> PATB1023 组个最小数：

[PATB1023](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4/Sec4Exa6MinNum/main.cpp)

### 4.4.2 区间贪心

进一步来学习稍微复杂的问题，即区间不相交问题：给出N个开区间(x, y)，从中选择尽可能多的开区间，使得这些开区间两两没有交集。例如对开区间(1, 3), (2, 4), (3, 5), (6, 7)来说，可以选出最多三个区间(1, 3), (3, 5), (6, 7)，它们互相没有交集。

首先考虑最简单的情况，如果开区间I1被开区间I2包含，那么显然选择I1是最好的选择，因为如果选择I1，那么就有更大的空间去容纳其他开区间。

接下来把所有开区间按左端点x从大到小排序，如果去除掉区间包含的情况，那么一定有y1 > y2 > ··· > yn成立。现在考虑应当如何选取区间。通过观察会发现，I1的右边有一段是一定不会和其他区间重叠的，如果把它去掉，那么I1的左边剩余部分就会被I2包含，应当选择I1。因此对这种情况，**总是先选择左端点最大的区间**。

> N开区间：

[N开区间](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4/Sec4Exa7NOpenInterval/main.cpp)

总的来说，贪心是用来解决一类最优化问题，并希望由局部最优策略来推得全局最优结果的算法思想。贪心算法适用的问题一定满足最优子结构性质，即一个问题的最优解可以由它的子问题的最优解有效地构造出来。显然，不是所有问题都适合使用贪心法，但是这并不妨碍贪心算法成为一个简洁、实用、高效的算法。

### 4.4.3 配套练习

> A1033. To Fill or Not to Fill

[A1033](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4Exe/Sec4Exe1FillOrNot/main.cpp)

> A1037. Magic Coupon

[A1037](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4Exe/Sec4Exe2MagicCoupon/main.cpp)

## 4.5 二分

### 4.5.1 二分查找

二分查找是基于**有序序列**的查找算法。

> 猜数字

[猜数字](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4/Sec5Exa8GuessNumber/main.cpp)

第一小问：求序列中的第一个大于等于x的元素的位置。

第二小问：求序列中第一个大于x的元素的位置。

程序中的`lower_bound`函数和`upper_bound`函数都在解决这样一个问题：寻找有序序列中第一个满足某条件的元素的位置。

> 找第一个数字

[找数字](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4/Sec5Exa9FindtheFirstNumber/main.cpp)

### 4.5.2 二分法拓展

如何计算根号2的近似值：

> 寻找近似值

[近似值](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4/Sec5Exa10ApproximateValue/main.cpp)

装水问题：有一个侧面看去是半圆的储水装置，该半圆的半径为R，要求往里面装入高度为h的水，使其在侧面看去的面积与半圆面积的比例恰好为r。现在给定R和r，求高度h。

> 装水问题

[装水问题](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4/Sec5Exa11WaterProblem/main.cpp)

### 4.5.3 快速幂

给定三个正整数a，b，m（a<10^9, b<10^18, 1 < m < 10^9），求a^b%m。

如果用循环求a^b，显然O(b)的复杂度很难支持b这个10^18次方的量级。

这里可以使用快速幂的方法，基于二分的思想，因此也常称为二分幂：

1. 如果b是奇数，那么有a^b = a * a^(b-1)
2. 如果b是偶数，那么有a^b = a^(b/2) * a^(b/2)

显然，b是奇数的情况总能在下一步转换为b是偶数的情况，而b是偶数的情况叶总可以在下一步转换为b/2的情况。这样，在log(b)级别次数的转换后，就可以把b变为0，而任何正整数的0次方是1。

因此，结合递归的思想，可以得到快速幂的递归写法，时间复杂度为O(log(n))。

> 快速幂

```C++
    typedef long long LL;
    // 求a^b % m 递归写法
    LL binaryPow(LL a, LL b, LL m)
    {
        if(b == 0) return 1;
        // b为奇数
        if(b % 2 == 1) return a * binaryPow(a, b-1, m) % m;
        else
        {
            LL mu1 = binaryPow(a, b / 2, m);
            return mu1 * mu1 % m;
        }
    }
```

条件`if(b %2 = 1)`可以用`if(b & 1)`代替。这是因为`b & 1` 进行位与操作，判断b的末位是否为1，因此当b为奇数时`b & 1`返回1，if条件成立。这样写执行速度会快一点。

针对不同的题目，可能有两个细节需要注意：

1. 如果初始时a有可能大于等于m，那么需要在进入函数前就让a对m取模。
2. 如果m为1，可以直接在函数外部特判为0，不需要进入函数来计算。

再继续研究快速幂的迭代写法：

对于a^b来说，如果把b写成二进制，那么b就可以写成若干个二次幂之和。因此具体实现的时候可以：

1. 初始令ans等于1，用来存放累积的结果；
2. 判断b的二进制末尾是否为1，如果是的话，令ans乘上a的值；
3. 令a平方，并将b右移一位；
4. 只要b大于0，就返回2。

> 快速幂迭代法

```C++
    typedef long long LL;
    // 求a^b % m, 迭代写法
    LL binaryPow(LL a, LL b, LL m)
    {
        LL ans = 1;
        while(b > 0)
        {
            if(b & 1)   // 如果b的二进制末尾为1
            {
                ans = ans * a % m;
            }
            a = a * a % m;  // 令a平方
            b >>= 1;        // 将b的二进制右移1位，即b = b >> 1或b = b / 2
        }
        return ans;
    }
```

关于取余的运算法则：

公式：(ab)%c = [(a%c) x (b%c)] % c

公式：a^b % c = (a%c)^b % c

### 4.5.4 配套练习

> A1030/A1085. 完美数列

[完美数列](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4Exe/Sec5Exe1PerfectFunction/main.cpp)

> A1010. Radix

[A1010](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4Exe/Sec5Exe2Radix/main.cpp)

> A1044. Shopping in Mars

[A1044](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4Exe/Sec5Exe3ShoopinginMars/main.cpp)

> A1048. Find Coins

[A1048](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter4/Chapter4Exe/Sec5Exe4FindCoins/main.cpp)

## 4.6 two pointers

### 4.6.1 什么是two pointers

