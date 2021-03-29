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

[1818]()

### 5.2.2 最小公倍数

最小公倍数的求解在最大公约数的基础上进行。当得到a和b的最大公约数d之后，可以马上得到a和b的最小公倍数是ab/d。考虑到ab可能溢出，因此，更为恰当的写法是：a/db。

## 5.3 分数的四则运算

