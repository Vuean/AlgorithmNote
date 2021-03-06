# 第六章 C++标准模板库(STL)介绍

## 6.1 vector的常见用法

vector常用函数实例解析：

1. push_back():在vector后面添加一个元素x，时间复杂度为O(1)。

2. pop_back():删除vector的尾元素，时间复杂度为O(1)。

3. size():获得vector中元素的个数，时间复杂度为O(1)。

4. clear():清空vcetor中的所有元素，时间复杂度为O(N)。

5. insert(it, x):向vcetor的任意迭代器it处插入一个元素x，时间复杂度O(N)。

6. erase()：删除单个元素、删除一个区间内的所有元素。时间复杂度均为O(N)。

## 6.2 set的常见用法详解

set翻译为集合，是一个内部自动有序且不含重复元素的容器。

访问set容器内的元素，只能通过迭代器(iterator)访问。

set常用函数实例解析：

1. insert(x):将x插入set容器中，并自动递增排序和去重，时间复杂度为O(logN)。

2. find(value)：返回set中对应值为value的迭代器，时间复杂度为O(logN)。

3. erase()：删除单个元素、删除一个区间内的所有元素。删除一个元素时，时间复杂度为O(1)；删除一个区间内的元素时，时间复杂度为O(logN)。

4. size():用来获得set内元素的个数，时间复杂度为O(1)。

5. clear()：清空set中的所有元素，时间复杂度为O(N)。

set最主要的作用是**自动去重并按升序排序**，因此碰到需要去重但是却不方便直接开数组的情况，可以尝试用set解决。

延伸：set中元素是唯一的，如果需要处理不唯一的情况，则需要使用multiset。另外，C++ 11标准中还增加了unordered_set，以散列代替set内部的红黑树(Red Black Tree, 一种自平衡二叉查找树）实现，使其可以用来处理只去重但不排序的需求，速度比set要快得多。

## 6.3 string的常见用法详解

> string中内容的访问

1. 通过下标访问：可以直接像字符数组那样去访问string；

2. 通过迭代器访问；

string常用函数实例解析

1. operator+=：string的加法，可以将两个string直接拼接起来。

2. compare operator：可以直接使用==、!=、<、<=、>、>=比较大小，比较规则是字典序。

3. lengthQ/size()：length()返回string的长度，即存放的字符数，时间复杂度为O(1)。size()与length()基本相同。

4. insert()：时间复杂度为O(N)。

   1. insert(pos, string)：在pos号位置插入字符串string。

   2. insert(it, it2, it3)：it为原字符串的欲插入位置，it2和it3为待插字符串的首尾迭代器，用来表示串[it2, it3)将被插在it的位置上。

5. erase()：删除单个元素、删除一个区间内的所有元素。时间复杂度为O(N)。

6. clear()：清空string中的所有元素，时间复杂度一般为O(1)。

7. substr(pos, len)：返回从pos号位开始，长度位len的子串，时间复杂度为O(len)。

8. string::npos：是一个常数，其本身的值为-1，作为find函数失配时的返回值。

9. find()：时间复杂度位O(nm)，n和m分别是str和str2的长度

    1. str.find(str2)：当str2是str的子串时，返回其在str中第一次出现的位置；如果不是，则返回string::npos。

    2. str.find(str2, pos)：从str的pos号位置开始匹配str2，返回值与上相同。

10. replace()：时间复杂度为O(str.length())

    1. str.replace(pos, len, str2)：把str从pos号位开始，长度为len的字串替换为str2；

    2. str.replace(it1, it2, str2)：把str的迭代器[it1, it2)范围内的子串替换为str2。

## 6.4 map的常用用法详解

map可以将任何基本类型(包括STL容器)映射到任何基本类型(包括STL容器)。

> map中内容的访问

1. 通过下标访问：和访问普通的数组是一样。

2. 通过迭代器访问：`map<typename1, typename2>::iterator it;`，通过`it->first`来访问键，通过`it->second`访问值。

map会以键从小到大的顺序自动排序，这是由于map内部是使用红黑树实现的(set也是)，在建立映射的过程中会自动实现从小到大的排序功能。

> map常用函数实例解析

常用函数解析：

1. find(key)：返回键为key的映射的**迭代器**，时间复杂度为O(logN)。

2. erase():删除单个元素、删除一个区间内的所有元素。

    1. 删除单个元素：

        - mp.erase(it)：it为需要删除的元素的迭代器，时间复杂度为O(1)。

        - mp.erase(key)：key为欲删除的映射的键，时间复杂度为O(logN)。

    2. mp.erase(first, last)：删除一个区间内的所有元素，其中first为需要删除的区间的起始迭代器，而last则为需要删除的区间的末尾迭代器的下一个地址，也即为删除左闭右开的区间[first, last)。时间复杂度为O(last-first)。

3. size()：获得map中映射的对数，时间复杂度为O(1)。

4. clear()：清空map中的所有元素，时间复杂度为O(N)。

> map的常见用途

常见用途：

1. 需要建立字符（或字符串）与整数之间映射的题目，使用map可以减少代码量。

2. 判断大整数或者其他类型数据是否存在的题目，可以把map当bool数组用。

3. 字符串和字符串的映射也有可能会遇到。

map的键和值是唯一的，而如果一个键需要对应多个值，就只能用multimap。另外，C++11标准中还增加了unordered_map，以散列代替map内部的红黑树实现，使其可以用来处理只映射而不按key排序的需求。

## 6.5 queue的常见用法详解

1. push(x)：将x进行入队，时间复杂度为O(1)；

2. front()、back()：分别获得队首元素和队尾元素，时间复杂度为O(1)；

3. pop()：令队首元素出队，时间复杂度为O(1)；

4. empty()：检测queue是否为空，返回true则空，返回false则非空。时间复杂度为O(1)；

5. size()：返回queue内元素的个数，时间复杂度为O(1)；

当需要实现广度优先搜索时，可以不用自己手动实现一个队列，而是用queue作为代替，以提高程序的准确性。

另外有一点注意的是，使用front()和pop()函数前，必须用empty()判断队列是否为空，否则可能因为队空而出现错误。

延伸：STL的容器中还有两种容器跟队列有关，分别是双端队列(deque)和优先队列(priority_queue)，前者是首尾皆可插入和删除的队列，后者是使用堆实现的默认将当前队列最大元素置于队首的容器。

## 6.6 priority_queue的常见用法详解

priority_queue又称为优先队列，其底层是用堆来进行实现的。在优先队列中，队首元素一定是当前队列中优先级最高的那一个。

和队列不一样的是，优先队列没有front()函数与back()函数，而只能通过top()函数来访问队首元素(也可以称为堆顶元素)，也就是优先级最高的元素。

> priority_queue常用函数实例解析

常用函数解析：

1. push(x)：令x入队，时间复杂度为O(logN)。

2. top()：获得队首元素(即堆顶元素)，时间复杂度为O(1)。

3. pop()：令队首元素(即堆顶元素)出队，时间复杂度为O(logN)。

4. empty()：检测优先队列是否为空，返回true则空，返回false则非空。时间复杂度为O(1)。

5. size()：返回优先队列内元素的个数，时间复杂度为O(1)；

> priority_queue内元素优先级的设置

如何定义优先队列内元素的优先级是运用好优先队列的关键，下面分别介绍基本数据类型(例如int、double、char)与结构体类型的优先级设置方法。

1. 基本数据类型的优先级设置

    此处指的基本数据类型就是int型、double型、char型等可以直接使用的数据类型，优先队列对它们的优先级设置一般是数字大的优先级越高，因此队首元素就是优先队列内元素最大的那个(如果char型，则是字典序最大的)。对基本数据类型来说，下面两种优先队列的定义是等价的(以int型为例，注意最后两个>之间有一个空格)：

    ```C++
        priotity_queue<int> q;
        priority_queue<int, vector<int>, less<int> > q;
    ```

    可以发现，第二种定义方式的尖括号内多出了两个参数：一个是`vector<int>`，另一个是`less<int>`。其中`vector<int>`(也就是第二个参数)填写的是来承载底层数据结构堆(heap)的容器，如果第一个参数是double型或char型，则此处只需要填写`vector<double>`或`vector<char>`；而第三个参数`less<int>`则是对第一个参数的比较类，`less<int>`表示数字大的优先级越大，而`greater<int>`表示数字小的优先级越大。

    因此，如果想让优先队列总是把最小的元素放在队首，只需进行如下定义：

    ```C++
        priority_queue<int, vector<int>, greater<int> > q;
    ```

2. 结构体的优先级设置

    ```C++
        struct fruit{
            string name;
            int price;
        };
    ```

    示例结构体，包含了水果的名称和价格。现在希望按水果的价格高的为优先级高，需要重载小于号“<”：

    ```C++
        struct fruit{
            string name;
            int price;

            friend bool operator<(fruit f1, fruit f2){
                return f1.price < f2.price;
            }
        };
    ```

    此时就可以直接定义fruit类型的优先队列，其内部就是以价格高的水果为优先级高，如下所示：

    ```C++
        priority_queue<fruit> q;
    ```

    **优先队列的这个函数与sort中的cmp函数的效果是相反的。**因为，优先队列本身默认的规则就是优先级高的放在队首。

    同时，也可以采用第二种方式定义优先队列：

    ```C++
        struct cmp{
            bool operator() (fruit f1, fruit f2){
                return f1.price > f2.price;
            }
        };
        priority_queue<fruit, vector<fruit>, cmp> q;
    ```

priority_queue可以解决一些贪心问题，也可以对Dijkstar算法进行优化。

有一点需要注意，使用top()函数前，必须用empty()判断优先队列是否为空，否则可能因为队空而出现错误。

## 6.7 stack的常见用法

stack翻译为栈，是STL中实现的一个后进先出的容器。

> stack容器内元素的访问

由于栈(stack)本身就是一种后进先出的数据结构，在STL的stack中只能通过top()来访问栈顶元素。

> stack常用函数实例解析

1. push(x)：将x入栈，时间复杂度为O(1)。

2. top()：获得栈顶元素，时间复杂度为O(1)。

3. pop()：弹出栈顶元素，时间复杂度为O(1)。

4. empty()：检测stack内是否为空，返回true为空，返回false为非空，时间复杂度为O(1)。

5. size()：返回stack内元素个数，时间复杂度为O(1)。

> stack的常见用途

stack用来模拟实现一些递归，防止程序对栈内存的限制而导致程序运行出错。一般来说，程序的栈内存空间很小。

6.8 pair的常见用法详解

pair可以将两个元素绑在一起作为一个合成元素。

> pair的定义

需添加头文件`#include <utility>`，由于map内部实现中涉及了pair，因此，在添加了map的头文件后，就不需要再添加utility头文件了。

pair有两个参数，分别对应first和second的数据类型，它们可以是任意基本数据类型或容器。

```C++
    pair<typename1, typename2> name;
```

如果想在定义pair时进行初始化，只需要跟上一个小括号，里面填写两个想要初始化的元素即可：

```C++
    pair<string, int> p("hello", 15);
```

想要在代码中临时构建一个pair，有如下两种方法：

- 将类型定义写在前面，后面用小括号内两个元素的方式：`pair<string, int>("hello", 5);`

- 使用自带的makepair函数：`make_pair("hello", 5);`

> pair中元素的访问

pair中只有两个元素，分别是first和second，只需要按正常结构体的方式去访问即可。

> pair常用函数实例解析

两个pair类型数据可以直接使用==、!=、<、<=、>、>=比较大小，比较规则是先以first的大小作为标准，只有当first相等时才去判别second的大小。

> pair的常见用途

关于pair有两个比较常见的例子：

1. 用来代替二元结构体及其构造函数，可以节省编码时间。

2. 作为map的键值对来进行插入。

## 6.9 algorithm头文件下的常用函数

### 6.9.1 max(), min()和abs()

`max(x, y)`和`min(x, y)`分别返回x和y中的最大值和最小值，且参数必须是两个(可以是浮点数)。如果想要返回三个数x、y、z的最大值，可以使用`max(x, max(y, z))`的写法。

`abs(x)`返回x的绝对值。注意：x必须是整数，浮点型的绝对值请用math头文件下的fabs。

### 6.9.2 swap()

`swap(x, y)`用来交换x和y的值。

### 6.9.3 reverse()

`reverse(it, it2)`可以将数组指针在[it, it2)之间的元素或容器的迭代器在[it, it2)范围内的元素进行反转。

### 6.9.4 next_permutation()

`next_permutation()`给出一个序列在全排列中的下一个序列。

```C++
    当n==3时的全排序列为：
    123
    132
    213
    231
    312
    321
```

这样231的下一个序列就是312。

```C++
    #include <cstdio>
    #include <algorithm>
    using namespace std;
    int main(){
        int a[10] = {1, 2, 3};
        do{
            printf("%d%d%d\n", a[0], a[1], a[2]);
        }while(next_permutation(a, a+3));
    }
```

使用do … while语句而不使用while语句是因为序列1 2 3本身也需要输出，如果使用while会直接跳到下一个序列再输出，这样结果会少一个123。

### 6.9.5 fill()

fill()可以把数组或容器中的某一段区间赋为某个相同的值。和memset不同，这里的赋值可以是**数组类型对应范围中的任意值**。

```C++
    #include <cstdio>
    #include <algorithm>
    using namespace std;
    int main() {
        int a[5] = {1, 2, 3, 4, 5};
        fill(a, a+5, 255);  // 将a[0]~a[4]赋值为244
        for(int i = 0; i < 5; i++){
            printf_s("%d ", a[i]);
        }
    }
```

### 6.9.6 sort()

1. 如何使用sort

    sort函数使用方式：`sort(首元素地址，尾元素的下一个地址，比较函数（非必填）);`

2. 如何实现比较函数cmp

    (1) 基本数据类型数组的排序

    若比较函数不填，则默认按照从小到大的顺序排序。若想要从大到小排序，则需要使用比较函数cmp。

    ```C++
        #include <iostream>
        #include <algorithm>
        using namespace std;
        bool cmp(int a, int b){
            return a > b;   // 可以理解为当a>b时，把a放在b前面
        }

        int main(){
            int a[] = {3, 1, 4, 2};
            sort(a, a+4, cmp);
            // sort(a, a+4);
            for(int i=0; i < 4; i++){
                cout << a[i] << " ";
            }
        }
    ```

    记忆方法：如果要把数据从小到大排列，那么就用“<”，因为“a < b”就是左小右大；如果要把数据从大到小排列，那么就用“>”，因为“a > b”就是左大右小。

    (2) 结构体数组的排序

    若定义结构体：

    ```C++
        struct node{
            int x, y;
        };
    ```

    若想按照结构体中的x进行从大到小排序：

    ```C++
        bool cmp(node a, node b){
            return a.x > b.x;
        }
    ```

    如果想先按x从大到小排序，但当x相等的情况下，按照y的大小从小到大来排序（即进行二级排序），那么cmp的写法是：

    ```C++
        bool cmp(node a, node b){
            if(a.x != b.x) return a.x > b.x;
            else return a.y < b.y; 
        }
    ```

    (3) 容器的排序

    在STL标准容器中，只有vector、string、deque是可以使用sort的。这是因为像set、map这种容器是用红黑树实现的，元素本身有序，故不允许使用sort排序。

### 6.9.7 lower_bound()和upper_bound()

`lower_bound()`和`upper_bound()`需要**用在一个有序数组或容器中**。

`lower_bound(first, last, val)`用来寻找在数组或容器的[first, last)范围内第一个值大于等于val的元素的位置，如果是数组，则返回该位置的指针；如果是容器，则返回该位置的迭代器。

`upper_bound(first, last, val)`用来寻找在数组或容器的[first, last)范围内第一个值大于val的元素的位置，如果是数组，则返回该位置的指针；如果是容器，则返回该位置的迭代器。

如果数组或容器中没有需要寻找的元素，则`lower_bound()`和`upper_bound()`均返回可以插入该元素的位置的指针或迭代器（ 即假设存在该元素时，该元素应当在的位置）。`lower_bound()`和`upper_bound()`的复杂度均为O(log(last-first))。
