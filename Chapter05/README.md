# 第5章 入门篇(3)——数学问题

## 5.1 简单数学

[B1019/A1069](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter5/Chapter5/Sec1Exa1DigitalBlackHole/main.cpp)

## 5.2 最大公约数与最小公倍数

### 5.2.1 最大公约数

- 递归式：gcd(a, b) = gcd(b, a % b);

- 递归边界：gcd(a, 0) = a;

于是可以得到下面的求解最大公约数的代码：

```C++
    int gcd(int a, int b)
    {
        if(b == 0) return a;
        else return gcd(b, a % b);
    }
```

[1818](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter5/Chapter5/Sec2Exa1GreatestCommonDivisor/main.cpp)

### 5.2.2 最小公倍数

最小公倍数的求解在最大公约数的基础上进行。当得到a和b的最大公约数d之后，可以马上得到a和b的最小公倍数是ab/d。考虑到ab可能溢出，因此，更为恰当的写法是：a/db。

## 5.3 分数的四则运算

所谓分数的四则运算是指，给定两个分数的分子和分母，求它们加减乘除的结果。下面先介绍如何表示和化简一个分数。

### 5.3.1 分数的表示和化简

1. 分数的表示

    写成假分数形式，即无论分子比分母大或者小，都保留其原数。因此可以使用一个结构体来存储这种只有分子和分母的分数：

    ```C++
    struct Fraction{
        int up, down;   // 分子，分母
    };
    ```

    对这种表示制订三项规则：

    - 使down为非负数。如果分数为负，那么令分子up为负即可。

    - 如果该分数恰为0，那么规定其分子为0，分母为1。

    - 分子和分母没有除了1以外的公约数。

2. 分数的化简

    分数的化简主要用来使Fraction变量满足分数表示的三项规定，因此化简步骤也分为以下三步：

    - 如果分母down为负数，那么令分子up和分母down都变为相反数。

    - 如果分子up为0，那么令分母down为1。

    - 约分：求出分子绝对值与分母绝对值的最大公约数d，然后令分子分母同时除以d。

    代码如下：

    ```C++
    Fraction reduction(Fraction result)
    {
        if(result.down < 0){    // 分母为负数，令分子和分母都变为相反数
            result.up = -result.up;
            result.down = -result.down;
        }
        if(result.up == 0){
            result.down = 1;
        }
        else{
            int d = gcd(abs(result.up), abs(result.down));
            result.up /= d;
            result.down /= d;
        }
        return result;
    }
    ```

### 5.3.2 分数的四则运算

1. 分数的加法

    ```C++
    Fraction add(Fraction f1, Fraction f2)
    {
        Fraction result;
        result.up = f1.up * f2.down + f1.down * f2.up;
        result.down = f1.down * f2.down;
        return reduction(result);
    }
    ```

2. 分数的减法

    ```C++
    Fraction minu(Fraction f1, Fraction f2)
    {
        Fraction result;
        result.up = f1.up * f2.down - f1.down * f2.up;
        result.down = f1.down * f2.down;
        return reduction(result);
    }
    ```

3. 分数的乘法

    ```C++
    Fraction multi(Fraction f1, Fraction f2)
    {
        Fraction result;
        result.up = f1.up * f2.up;
        result.down = f1.down * f2.down;
        return reduction(result);
    }
    ```

4. 分数的除法

    ```C++
    Fraction divide(Fraction f1, Fraction f2)
    {
        Fraction result;
        result.up = f1.up * f2.down;
        result.down = f1.down * f2.up;
        return reduction(result);
    }
    ```

    除法有额外注意事项。如果读入的除数为0(只需判断f2.up是否为0)，那么应当直接特判输出题目要求的输出语句（例如输出Error、Inf之类）。只有当除数不为0时，才能用上面的函数进行计算。

### 5.3.3 分数的输出

分数的输出根据题目的需要根据题目的要求进行，但是大体上有以下几个注意点：

1. 输出分数前，需要先对其进行化简。

2. 如果分数r的分母down为1，说明该分数是整数，一般来说题目会要求直接输出分子，而省略分母的输出。

3. 如果分数r的分子up的绝对值大于分母down，说明该分数是假分数，此时应按带分数的形式输出，即整数部分为r.up/ r.down，分子部分为asb(r.up)%r.down，分母部分为r.down。

4. 以上均不满足时说明分数r是真分数，按原样输出即可。

```C++
    void showResult(Fraction r)
    {
        r = reduction(r);
        if(r.down == 1) cout << r.up;
        else if(abs(r.up) > r.down)
        {
            printf("%d %d/%d", r.up / r.down, abs(r.up)%r.down, r.down);
        }
        else
        {
            printf("%d／%d", r.up, r.down);
        }
    }
```

## 5.4 素数

本节将解决两个问题：1.如何判断给定的正整数n是否是质数；2.如何在较短的时间内得到1~n内的素数表。

### 5.4.1 素数的判断

如果直接遍历判断n是否为素数，则复杂度为O(n)。通过进一步优化，可发现可将判断区间限制在2~sqrt(n)之间，即算法复杂度为O(sqrt(n))。

```C++
    bool isPrime(int n)
    {
        if(n <= 1) return false;
        int sqr = (int)sqrt(1.0 * n);
        for(int i = 2; i <= sqr; i++)
        {
            if(n % i == 0) return false;
        }
        return true;    // n是素数
    }
```

由于sqrt的参数要求是浮点数，因此在n前面乘以1.0来使其成为浮点型。

### 5.4.2 素数表的获取

从1~n 进行枚举，判断每个数是否是素数，如果是素数则加入素数表。这种方法的枚举部分的复杂度是O(n)，而判断素数的复杂度是O($\sqrt{n}$)，因此总复杂度是O(n$\sqrt{n}$)。

由上面的例子可以发现，当从小到大到达某数a时，如果a没有被前面步骤的数筛去，那么a一定是素数。这是因为，如果a不是素数，那么a一定有小于a的素因子，这样在之前的步骤中a一定会被筛掉，所以，如果当枚举到a时还没有被筛掉，那么a一定是素数。

至于“筛”这个动作的实现，可以使用一个bool型数组p来标记，如果a被筛掉，那么p[ a ]为true；否则，p[ a ]为false。在程序开始时可以初始化p数组全为false。

素数筛法的代码如下，复杂度为O(nloglogn)：

```C++
    const int maxn = 101;   // 表长
    int prime[maxn], pNum = 0;  // Prime数组存放所有素数，pNum为素数个数
    bool p[maxn] = {0}; // 如果i为素数，则p[i]为false; 否则，p[i]为true
    void Find_Prime()
    {
        for(int i = 2; i < maxn; i++)
        {
            if(p[i] == fasle)
            {
                prime[pNum++] = i;
                for(int j = i + i; j < maxn; j += i)
                {
                    // 筛去所有i的倍数，循环条件不能写成j<=maxn
                    p[j] = true;
                }
            }
        }
    }
```

[数素数](https://github.com/Vuean/AlgorithmNote/tree/main/Chapter5/Chapter5/Sec4Exa1NumberOfPrimes)

## 5.5 质因子分解

由于每个质因子都可以不止出现一次，因此不妨定义结构体factor，用来存放质因子及其个数，如下所示：

```C++
    struct factor{
        int x, cnt; // x为质因子，cnt为其个数
    } fac[10];
```

其中，考虑到2x3x5x7x11x13x17x19x23x29就已经超过了int范围，因此对一个int型范围的数来说，fac数组的大小只需要开到10就可以了。

前面提到过，对一个正整数n来说，如果它存在1和本身之外的因子，那么一定是在sqrt(n)的左右成对出现。而这里把这个结论用在“质因子”上面，会得到一个强化结论：**对一个正整数n来说，如果它存在[2, n]范围内的质因子，要么这些质因子全部小于等于sqrt(n)，要么只存在一个大于sqrt(n)的质因子，而其余质因子全部小于等于sqrt(n)**。

求解思路是：

1. 枚举1~aqrt(n)范围内的所有质因子p，判断p是否是n的因子

    - 如果p是n的因子，那么给fac数组中增加质因子p，并初始化其不数为0。然后，只要p还是n的因子，就让n不断除以p，每次操作令p的个数加1，直到p不再是n的因子为止。

    - 如果p不是n的因子，就直接跳过。

    ```C++
        if(n % prime[i] == 0){
            fac[num].x = prime[i];
            fac[num].cnt = 0;
            while(n % prime[i] == 0){
                fac[num].cnt++;
                n /= prime[i];
            }
            num++;
        }
    ```

2. 如果在上面步骤结束后n仍然大于1，说明n有且仅有一个大于sqrt(n)的质因子（有可能是n本身），这时需要把这个质因子加入fac数组，并令其个数为1。

    ```C++
        if(n != 1){ // 如果无法被根号n以内的质因子除尽
            fac[num].x = n; // 那么一定有一个大于根号n的质因子
            fac[num++].cnt = 1;
        }
    ```

[A1059](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter5/Chapter5/Sec5Exa1PrimeFactors/main.cpp)

## 5.6 大整数运算

### 5.6.1 大整数的存储

大整数的存储很简单，使用数组即可。例如定义in 型数组d[1000]，那么这个数组中的每一位就代表了存放的整数的每一位，且整数的高位存储在数组的高位。

为了方便随时获取大整数的长度，一般都会定义一个int型变量len来记录其长度，并和d数组组合成结构体：

```C++
    struct bign{
        int d[1000];
        int len;

        // 初始化
        bign(){
            memset(d, 0, sizeof(d));
            len = 0;
        }
    };
```

输入大整数时，一般都是先用字符串读入，然后再把字符串另存为至bign结构体。由于使用char数组进行读入时，整数的高位会变成数组的低位，而整数的低位会变成数组的高位，因此为了让整数在bign中是顺位存储，需要让字符串倒着赋给d[]数组：

```C++
    bign change(char str[]){    // 将整数转换为bign
        bign a;
        a.len = strlen(str);    // bign的长度就是字符串的长度
        for(int i = 0; i < a.len; i++){
            a.d[i] = str[a.len - i - 1] - '0';
        }
        return a;
    }
```

比较两个bign变量的大小，规则也很简单：先判断两者的len大小，如果不相等，则以长的为大；如果相等，则从高位到低位进行比较，直到出现某一位不等，就可以判断两个数的大小。下面的代码直接依照了这个规则：

```C++
    int compare(bign a, bign b){
        if(a.len > b.len) return 1;
        else if(a.len < b.len) return -1;
        else{
            for(int i = a.len-1; i>= 0; i--){
                if(a.d[i] > b.d[i]) return 1;
                else if(a.d[i] < b.d[i]) return -1
            }
        }
        return 0;   // 两者相等
    }
```

接下来主要介绍四个运算：1.高精度加法，2.高精度减法，3.高精度与低精度的乘法，4.高精度与低精度的除法。

### 5.6.2 大整数的四则运算

1. 高精度加法

    将该位上的两个数字和进位相加，得到的结果取个位数作为该位结果，取十位数作为新的进位：

    ```C++
        bign add(bign a, bign b){
            bign c;
            int carry = 0;
            for(int i = 0; i < a.len || a < b.len; i++){
                int temp = a.d[i] + b.d[i] + carry;
                c.d[c.len++] = temp % 10;
                carry = temp / 10;
            }
            if(carry != 0){
                // 如果最后进位不为0,则直接赋给结果的最高位
                c.d[c.len++] = carry;
            }
            return c;
        }
    ```

    下面是完整的A + B 的代码：

    ```C++
        #include <cstdio>
        #include <string>
        struct bign{
            int d[1000];
            int len;
            bign(){
                memset(d, 0, sizeof(d));
                len = 0;
            }
        };

        bign change(char str[]){
            bign a;
            a.len = strlen(str);
            for(int i = 0; i < a.len; i++){
                a.d[i] = str[a.len-i-1] - '0';
            }
            return a;
        }

        bign add(bign a, bign b){
            bign c;
            int carry = 0;
            for(int i = 0; i < a.len || a < b.len; i++){
                int temp = a.d[i] + b.d[i] + carry;
                c.d[c.len++] = temp % 10;
                carry = temp / 10;
            }
            if(carry != 0){
                c.d[c.len++] = carry;
            }
            return c;
        }

        void print(bign a){
            for(int i = a.len - 1; i >= 0; i--){
                cout << a.d[i];
            }
        }

        int main()
        {
            char str1[1000], str2[1000];
            cin >> str1 >> str2;
            bign a = change(str1);
            bign b = change(str2);
            print(add(a, b));
        }
    ```

2. 高精度减法

    对某一步，比较被减位和减位，如果不够减，则令被减位的高位减1、被减位加10再进行减法；如果够减，则直接减。最后一步要注意减法后高位可能有多余的0，要忽视它们，但也要保证结果至少有一位数。

    ```C++
        bign sub(bign a, bign b){
            bign c;
            for(int i = 0; i < a.len || i < b.len; i++){
                if(a.d[i] < b.d[i]){
                    a.d[i+1]--;
                    a.d[i] += 10;
                }
                c.d[c.len++] = a.d[i] - b.d[i];
            }
            while(c.len - 1 >= 1 && c.d[len-1] == 0){
                c.len--;    // 去除高位的0，同事至少保留一位最低位
            }
            return c;
        }
    ```

    需要指出，使用sub函数前要比较两个数的大小，如果被减数小于减数，需要交换两个变量，然后输出负号，再使用sub函数。

3. 高精度与低精度的乘法

    取bign的某位与int型整体相乘，再与进位相加，所得结果的个位数作为该位结果，高位部分作为新的进位。

    ```C++
        bign multi(bign a, int b){
            bign c;
            int carry = 0;  // 进位
            for(int i = 0; i < a.len; i++){
                int temp = a.d[i] * b + carry;
                c.d[c.len++] = temp % 10;
                carry = temp / 10;
            }
            while(carry != 0){
                c.d[c.len++] = carry % 10;
                carry /= 10;
            }
            return c;
        }
    ```

    如果a和b中存在负数，需要先记录下其负号，然后取它们的绝对值代入函数。

4. 高精度与低精度的除法

    上一步的余数乘以10加上该步的位，得到该步临时的被除数，将其与除数比较：如果不够除，则该位的商为0；如果够除，则商即为对应的商，余数即为对应的余数。最后一步要注意减法后高位可能有多余的0，要忽视它们，但也要保证结果至少有一位数。

    ```C++
        bign divide(bign a, int b, int& r){ // r为余数
            bign c;
            // 被除数的每一位和商的每一位是一一对应的，因此先令长度相等
            c.len = a.len;
            for(int i = a.len - 1; i>= 0; i--){
                r = r * 10 + a.d[i];
                if(r < b) c.d[i] = 0;
                else {
                    c.d[i] = r / b;
                    r = r % b;
                }
            }
            while(c.len - 1 >= 1 && c.d[len-1] == 0){
                // 去除高位的0，同时至少保留一位最低位
                c.len--;
            }
            return c;
        }
    ```

## 5.7 扩展欧几里得算法

### 5.7.1 扩展欧几里得算法

### 5.7.2 方程ax + by = c的求解

### 5.7.3 同余式ax = c(mod m)的求解

### 5.7.4 逆元的求解以及(b / a)%m的计算

## 5.8 组合数

### 5.8.1 关于n!的一个问题

n!表示n的阶乘，并且有n!= 1 x 2 x ... x n成立。我们讨论一下关于它的一个问题：求n!中有多少个质因子p。

对这个问题，直观的想法是计算从1 ~ n的每个数各有多少个质因子p，然后将结果累加，时间复杂度为O(nlogn)，如下面的代码所示：

```C++
    int cal(int n, int p){
        int ans = 0;
        for(int i = 2; i <= n; i++){
            int temp = i;
            while(temp % p == 0){
                ans++;
                temp /= p;
            }
        }
        return ans;
    }
```

但是这种做法对n很大的情况是无法承受的，经过推理可以发现n!中有(n/p + n/p^2 + n/p^3 + ...)个质因子p，其中除法均为向下取整。于是便得到O(logn)的算法。

```C++
    // 计算n!中有多少个质因子
    int cal(int n, int p){
        int ans = 0;
        while(n){
            ans += n/p; // 累加n/p^k
            n /= p;
        }
        return ans;
    }
```

利用这个算法，可以很快计算出n!的末尾有多少个零：由于末尾0的个数等于n!中因子10的个数，而这又等于n!中质因子5的个数，因此只需要代入cal(n, 5)就可以得到结果。

换一种思路，n!中质因子p的个数，实际上等于1~n中p的倍数的个数n/p加上(n/p)!中质因子p的个数，这和之前的代码是吻合的。但是从这个结论中又可以看到递归的影子，因此也可以写出如下的递归版本：

```C++
    int cal(int n, int p){
        if(n < p) return 0;
        return n/p + cal(n / p, p);
    }
```

### 5.8.2 组合数的计算
