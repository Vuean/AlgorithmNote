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

