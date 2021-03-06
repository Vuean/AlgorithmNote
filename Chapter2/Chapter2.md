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

### 2.5.1 一维数组

如果数组一开始没有赋初值，数组中的每个元素都可能会是一个随机，并不一定默认为0。因此，如果想要给整个数组都赋初值0，只需要把第一个元素赋为0，或者只用一个大括号来表示。

```C++
    int a[10] = {0};
    int a[10] = {};
```

### 2.5.2 冒泡排序

> 代码示例5：

```C++
    #include <stdio.h>
    int main()
    {
        int a[10] = {1, 3, 4, 5, 2};
        for(int i = 1; i <= 4; i++)
        {
            for(int j = 0; j < 5 - i; j++)
            {
                if(a[j] > a[j+1])
                {
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        for(int i = 0; i < 5; i++)
        {
            printf("%d ", a[i]);
        }
        return 0;
    }
```

>输出：

```C++
    1 2 3 4 5
```

### 2.5.3 二维数组

如果数组大小较大（大概10^6级别），则需要将其定义在主函数外面，否则会使程序异常退出，原因是函数内部申请的局部变量来自系统栈，允许申请的空间较小；而函数外部申请的全局变量来自静态存储区，允许申请的空间较大。

### 2.5.4 memset——对数组中每一个元素赋相同的值

一般来说，给数组中每一个元素赋相同的值有两种方法：`memset`函数和`fill`函数。

`memset`函数的格式为：`memset(数组名, 值, sizeof(数组名));`。

不过也要记住，使用`memset`需要在程序开头添加`string.h`头文件，且只建议初学者使用`memset`赋0或-l。这是因为`memset`使用的是按字节赋值，即对每个字节赋同样的值，这样组成`int`型的4个字节就会被赋成相同的值。而由于0的二进制补码为全0，-l的二进制补码为全1，不容易弄错。如果要对数组赋其他数字（例如1)，那么请使用`fill`函数（但`memset`的执行速度快）。

### 2.5.5 字符数组

1. 字符数组的初始化

和普通数组一样，字符数组也可以初始化，其方法也相同。字符数组也可以通过直接赋值字符串来初始化。

2. 字符数组的输入输出

(1) scanf输入，printf输出
`scanf`对字符类型有`%c`和`%s`两种格式(`printf`同理，下同），其中`%c`用来输入单个字符`%s`用来输入一个字符串并存在字符数组里。`%c`格式能够识别空格跟换行并将其输入，而`%s`通过空格或换行来识别一个字符串的结束。

(2) getchar输入，putchar输出
`getchar`和`putchar`分别用来输入和输出单个字符。

(3) gets输入，puts输出
`gets`用来输入一行字符串（注意：`gets`识别换行符`\n`作为输入结束，因此`scanf`完一个整数后，如果要使用`gets`，需要先用`getchar`接收整数后的换行符），并将其存放于一维数组（或二维数组的一维）中；`puts`用来输出一行字符串，即将一维数组（或二维数组的一维）在界面上输出，并紧跟一个换行。

3. 字符数组的存放方式

由于字符数组是由若干个`char`类型的元素组成，因此字符数组的每一位都是一个`char`字符。除此之外，在一维字符数组（或是二维字符数组的第二维）的末尾都有一个空字符`\0`，以表示存放的字符串的结尾。空字符`\0`在使用`gets`或`scanf`输入字符串时会自动添加在输入的字符串后面，并占用一个字符位，而`puts`与`printf`就是通过识别`\0`作为字符串的结尾来输出的。

### 2.5.6 string.h头文件

1. strlen()

`strlen`函数可以得到字符数组中第一个`\0`前的字符的个数：`strlen(字符数组);`

2. strcmp()

`strcmp`函数返回两个字符串大小的比较结果，比较原则是按字典序：`strcmp(字符数组1， 字符数组2);`

* 如果字符数组1 < 字符数组2 ，则返回一个负整数（不同编译器处理不同，不一定是-l）;
* 如果字符数组1 == 字符数组2，则返回0；
* 如果字符数组l > 字符数组2，则返回一个正整数（不同编译器处理不同，不一定是+1）。

3. strcpy()

`strcpy`函数可以把一个字符串复制给另一个字符串，：
`strcpy(字符数组1, 字符数组2);`
注意：是把字符数组2复制给字符数组1，这里的“复制”包括了结束符`\0`。

4. strcat()

`strcat()`可以把一个字符串接到另一个字符串后面：``stacat(字符数组1， 字符数组2);`
注意：是把字符数组2接到字符数组1后面。

### 2.5.7 sscanf与sprintf

假定定义了一个`char`数组`str[100]`，`sscanf`写法的作用是把字符数组str中的内容以"%d"的格式写到n中（还是从左至右），而`sprintf`写法的作用是把n以"%d"的格式写到str字符数组中（还是从右至左）。

## 2.6 函数

### 2.6.1 函数定义

(1) 全局变量

全局变量是指在定义之后的所有程序段内都有效的变量（即定义在所有函数之前）；

(2) 局部变量

与全局变量相对，局部变量定义在函数内部，且只在函数内部生效，函数结束时局部变量销毁

### 2.6.2 再谈main函数

### 2.6.3 以数组作为函数参数

函数的参数也可以是数组，且数组作为参数时，参数中数组的第一维不需要填写长度（如果是二维数组，那么第二维需要填写长度），实际调用时也只需要填写数组名。

### 2.6.4 函数的嵌套调用

### 2.6.5 函数的递归调用

函数的递归调用是指一个函数调用该函数自身。

## 2.7 指针

### 2.7.1 什么是指针

在计算机中，每个变量都会存放在内存中分配的一个空间，而每种类型的变量所占的空间又是不一样的，例如int型的变量占用4Byte，而long long型的变量占用8Byte。

每个字节（即房间号）都会有一个地址（即房间号），这里的地址就起房间号的作用，即变量存放的位置，而计算机就是通过地址找到某个变量的。变量的地址一般指它占用的字节中第一个字节的地址，也就是说，一个int型的变量的地址就是它占用的4Byte当中第一个字节的地址。

### 2.7.2 指针变量

指针变量用来存放指针。

### 2.7.3 指针和数组

C 语言中，数组名称也作为数组的首地址使用。

### 2.7.4 使用指针变量作为函数参数

指针类型也可以作为函数参数的类型，这时视为把变量的地址传入函数。如果在函数中对这个地址中的元素进行改变，原先的数据就会确实地被改变。

### 2.7.5 引用

## 2.8 结构体的使用

### 2.8.1 结构体的定义

### 2.8.2 访问结构体内的元素

### 2.8.3 结构体的初始化

## 2.9 补充

### 2.9.1 cin与cout

如果同时读入多个变量也是一样的写法，只需要往后面使用>>进行扩展即可:`cin >> n >> db >> c >> str;`。

如果想要读入一整行，则需要使用getline函数：`char str[100]; cin.getline(str, 100);`。

但cin和cout的效果没有scanf和printf效果好。

### 2.9.2 浮点数比较

当两个数差值量级为约10^-8时，表示两个数相等。

### 2.9.3 复杂度

1. 时间复杂度

简单地说，时间复杂度是算法需要执行基本运算的次数所处的等级，其中基本运算就是类似加减乘除这种计算机可以直接实现的运算。时间复杂度是评判算法时间效率的有效标准。

2. 空间复杂度

空间复杂度表示算法需要消耗的最大数据空间。

3. 编码复杂度

编码复杂度是一个定性的概念，并没有什么量化的标准。对一个问题来说，如果使用了冗长的算法思想，那么代码量将会非常巨大，其编码复杂度就会非常大。

## 2.10 黑盒测试

黑盒测试是指：系统后台会准备若干组输入数据，然后让提交的程序去运行这些数据，如果输出的结果与正确答案完全相同（字符串意义上的比较），那么就称通过了这道题的黑盒测试，否则会根据错误类型而返回不同的结果。其中，根据黑盒测试是否对每组测试数据都单独测试或是一次性测试所有测试数据，又可以分为单点测试和多点测试。

### 2.10.1 单点测试

从代码编写上来说，单点测试只需要按正常的逻辑执行一遍程序即可，是“一次性”的写法，即程序只需要对一组数据能够完整执行即可。

### 2.10.2 多点测试

与单点测试相对，多点测试要求程序能一次运行所有数据，并要求所有输出结果都必须完全正确，才能算作这题通过；而只要有其中一组数据的输出错误，本题就只能得0分。

对多点测试来说，由于要求程序能运行所有数据，因此必须保证程序有办法反复执行代码的核心部分，这就要用到循环。而题目一般会有3种输入的格式，需要采用不同的输入方式。

(1) while...EOF型

如果题目没有给定输入的结束条件，那么就默认读取到文件末尾。虽然`scanf`函数平时可以直接作为一条语句使用，但它也是有返回值的，`scanf`函数的返回值为其成功读入的参数的个数。这就是说，如果语句`scanf("%d", &n)`成功读入了一个整数n，那么`scanf`的返回值就是1；如果语句`scanf("%d%d", &n, &m)`成功读入了两个整数n、m，那么`scanf`的返回值就是2。

在读取文件时到达文件末尾导致的无法读取现象，会产生读入失败。这个时候，`scanf`函数会返回-l而不是0，且C语言中使用`EOF(End Of File)来代表-1。

因此，当题目没有说明有多少数据需要读入时，就可以利用`scanf`的返回值是否为`EOF`来判断输入是否结束:

```C++
    while(scanf("%d", &n) != EOF)
    {
        ...
    }
```

上述代码的含义是：只要`scanf`的返回值不为`EOF`（即文件中的数据没有读完），就反复读入n，执行`while`函数体的内容；当读入失败（到达文件末尾）时，结束`while`循环。

(2) while...break型

(3) while(T--)型
