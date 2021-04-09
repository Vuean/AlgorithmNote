# 第6章 C++标准模板库(STL)介绍

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

