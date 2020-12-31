# 第二章 C/C++快速入门

## 2.1 基本数据结构

### 2.1.1 变量的定义

变量的定义：`变量类型 变量名;`或者`变量类型 变量名 = 初值;`

变量名：

* 不能是C语言标识符；
* 变量名的第一个字符必须是字母或下画线， 除第一个字符之外的其他字符必须是字母、数字或下画线；
* 区分大小写。

### 2.1.2 变量类型

基本数据类型分为整型(short, int, long long)、浮点型(float, double)、字符型(char)、布尔型(bool)。

> 表2-1 四种基本数据类型

||类型|取值范围|大致范围|
|  ----  | :----:  |  :----:  | :----:  |
|整型|int|-2147483648 ~ +2147483647<br>(即-2<sup>31</sup> ~ +(2<sup>31</sup> -1))|-2x10<sup>9</sup> ~ 2x10<sup>9</sup>|
|整型|long long|-2<sup>63</sup> ~ +(2<sup>63</sup> -1)|-9x10<sup>18</sup> ~ 9x10<sup>18</sup>|
|浮点型|float|-2<sup>128</sup> ~ +(2<sup>128</sup> -1)|实际精度6~7位|
|浮点型|double|-2<sup>1024</sup> ~ +(2<sup>1024</sup> -1)|实际精度15~16位|
|字符型|char|-128 ~ +127|-128 ~ +127|
|布尔型|bool|0(false) or 1(true)|0(false) or 1(true)|

其中，字符常量使用ASCII码统一编码。标准ASCII码的范围是0~127，其中包含了控制字符或通信专用字符（不可显示）和常用的可显示字符。需要清楚**小写字母比大写字母的ASCII码值大32**。

转义字符：

* `\n`表示换行；
* `\0`代表空字符NULL，其ASCII为0；
* `\t`表示Tab键；

### 2.1.3 强制类型转换

强制类型转换的格式如下：`(新类型名)变量名`

### 2.1.4 符号常量和const常量

### 2.1.5 运算符

自增运算符有两种写法：`i++`或`++i`。区别在于`i++`是先使用`i`再将`i`加1，而`++i`则是先将`i`加1再使用`i`。

> 代码示例1：

```C++
    #include <cstdio>
    int main()
    {
        int a = 1, b = 1, n1, n2;
        n1 = a++;
        n2 = ++b;
        printf("%d", n1, a);
        printf("%d", n2, b);
        return 0;
    }
```

>输出：

```C++
    1 2
    2 2
```

## 2.2 顺序结构

### 2.2.1 赋值表达式

### 2.2.2 使用scanf和printf输入/输出

scanf是输入函数，其格式如下：`scanf("格式控制", 变量地址);`

> 表2-2 常见数据类型变量的scanf格式符

|数据类型|格式符|举例|
| :----:  |  :----:  | :----:  |
|int|%d|scanf("%d", &n);|
|long long|%lld|scanf("%lld", &n);|
|float|%f|scanf("%f", &fl);|
|double|%lf|scanf("%lf", &db);|
|char|%c|scanf("%c", &c);|
|字符串(char数组)|%s|scanf("%s", str);|

数组名称本身就代表了这个数组第一个元素的地址，所以不需要再加取地址运算符。

printf是输出函数，其格式如下：`printf("格式控制", 变量名称);`

> 表2-3 常见数据类型变量的printf格式符

|数据类型|格式符|举例|
| :----:  |  :----:  | :----:  |
|int|%d|printf("%d", n);|
|long long|%lld|printf("%lld", n);|
|float|%f|printf("%f", fl);|
|double|%f|printf("%f", db);|
|char|%c|printf("%c", c);|
|字符串(char数组)|%s|printf("%s", str);|

三种实用的输出格式：

(1) %md

**`%md`可以使不足m位的int型变量以m位进行右对齐输出，其中高位用空格补齐；如果变量本身超过m位，则保持原样**。

> 代码示例2：

```C++
    #include <cstdio>
    int main()
    {
        int a = 123, b = 1234567;
        printf("%5d\n", a);
        printf("%5d\n", b);
        return 0;
    }
```

>输出：

```C++
      123  
    1234567
```

(2) %0md

`%0md`只是在`%md`中间多加了0。和`%md`的唯一不同点在于，**当变量不足m位时，将在前面补足够数量的0而不是空格**。

> 代码示例3：

```C++
    #include <cstdio>
    int main()
    {
        int a = 123, b = 1234567;
        printf("%05d\n", a);
        printf("%05d\n", b);
        return 0;
    }
```

>输出：

```C++
    00123  
    1234567
```

(3) %.mf

`%.mf`可以让浮点数保留m位小数输出，

> 代码示例4：

```C++
    #include <cstdio>
    int main()
    {
        double dl = 12.3456;
        printf("%.0f\n", dl);
        printf("%.01d\n", dl);
        printf("%.02f\n", dl);
        printf("%.03d\n", dl);
        printf("%.04f\n", dl);
        return 0;
    }
```

>输出：

```C++
    12
    12.3
    12.34
    12.345
    12.3456
```

### 2.3.3 使用getchar和putchar输入/输出字符

`getchar`用来输入单个字符，`putchar`用来输出单个字符，在某些`scanf`函数使用不便的场合可以使用`getchar`来输入字符。**getchar可以识别换行符**。

### 2.3.4 注释

可以使用`/**/`和`//`注释。

### 2.3.5 typedef

typedef可以给复杂的数据类型起一个别名，这样在使用中就可以用别名来代替原来的写法。

### 2.3.6 常用math函数

如果需要使用数学函数，需加上头文件：`math.h`。

* fabs(double x); 取绝对值
* floor(double x); 向下取整
* ceil(double x); 向上取整
* pow(double r, double p); 求幂r<sup>p</sup>
* sqrt(double x); 求算数平方根
* log(double x); 求以自然对数为底的对数
* sin(double x)、cos(double x)、tan(double x); 三角函数，输入为弧度
* asin(double x)、acos(double x)、atan(double x); 反三角函数
* around(double x); 四舍五入函数

## 2.3 选择结构

### 2.3.1 if语句

### 2.3.2 if语句嵌套

### 2.3.3 switch语句

## 2.4 循环结构

### 2.4.1 while语句

while 条件判断的是真假，因此在条件语句中的小技巧在此同样适用：

* 如果表达式是`!= 0`，则可以省略`!= 0`；
* 如果表达式是`== 0`，则可以省略`== 0`，并在表达式前添加非运算符`!`。

### 2.4.2 do...while语句

do...while语句:

```C++
    do{
        ...
    }while(条件A);
```

`do...while`语句会先执行省略号中的内容一次，然后才判断条件A是否成立。如果条件A成立，继续反复执行省略号的内容，直到某一次条件A不再成立，则退出循环。

### 2.4.3 for语句

### 2.4.4 break和continue语句

## 2.5 数组

## 2.6 函数

## 2.7 指针

## 2.8 结构体

## 2.9 补充

## 2.10 黑盒测试