# 第七章 提高篇(1)——数据结构专题(1)

## 7.1 栈的应用

栈(stack)是一种后进先出的数据结构。栈顶指针是始终指向栈的最上方元素的一个标记，当使用数组实现栈时，栈顶指针是一个int型的变量（数组下标从0开始），通常记为TOP；而当使用链表实现栈时，则是一个int*型的指针。栈空时，令TOP为-1。

栈得常见操作包括有：清空(clear)、获取栈内元素个数(size)、判空(empty)、进栈(push)、出栈(pop)、取栈顶元素(top)等。

出栈操作和取栈顶元素操作必须在栈非空的情形下才能使用，因此在使用pop()函数和top()函数之前必须先使用empty())函数判断栈是否为空。

STL中没有实现栈的清空，所以如果需要实现栈的清空，可以用一个while循环反复pop出元素直到栈空：

```C++
    while(!st.empty()){
        st.pop();
    }
```

[简单计算器](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter7/Chapter7/Sec1Exa1EasyCalculator/main.cpp)

## 7.2 队列的应用

队列(queue)是一种先进先出的数据结构，队列总是从队尾加入元素，而从队首移除元素。

当使用数组来实现队列时，队首指针front和队尾指针rear为int型变量（数组下标从0开始）；而当使用链表来实现队列时，则为int*型变量的指针。

队列的常用操作，包括清空(clear)、获取队列内元素的个数(size)、判空(empty)、入队(push)、出队(pop)、取队首元素(get_front)、取队尾元素(get_rear)等。

使用数组q[]来实现队列，而int型变量front存放队首元素的前一个元素的下标、rear存放队尾元素的下标（数组下标从0开始）。下面对常见操作进行示范实现：

1. clear()：清空

    使用数组来实现队列时，初始状态为front = -1、rear = -1

    ```C++
        void clear(){
            front = rear = -1;
        }
    ```

2. size()：获取队列内元素的个数

    rear-front即为队列内元素的个数。

3. empty()：判空

    当front == rear时为空。

4. push()：入队

    由于队尾指针rear指向队尾元素，因此把元素入队时，需要先把rear加1，然后再存放到rear指向的位置。

    ```C++
        void push(int x){
            q[++rear] = x;
        }
    ```

5. pop()：出队

    可以直接把队首指针加1，来实现出队的效果。

    ```C++
        void pop(){
            front++;
        }
    ```

6. get_front()：取出队首元素

    由于队首指针front指向的是队首元素的前一个元素，因此front + 1才是队首元素的位置。

    ```C++
        int get_front(){
            return q[front+1];
        }
    ```

7. get_rear()：取队尾元素

    由于队尾指针rear指向的是队尾元素，因此可以直接访问rear的位置。

    ```C++
        int get_rear(){
            return q[rear];
        }
    ```

## 7.3 链表处理

### 7.3.1 链表的概念

线性表是一类很常用的数据结构，分为**顺序表和链表**。其中顺序表可以简单地理解成前面介绍的“数组”这个概念。

链表由若干个结点组成（每个结点代表一个元素），且结点在内存中的**存储位置通常是不连续的**。除此之外，**链表的两个结点之间一般通过一个指针来从一个结点指向另一个结点**，因此链表的结点一般由两部分构成，即数据域和指针域：

```C++
    struct node{
        typename data;  // 数据域
        node*    next;  // 指针域
    };
```

链表可根据是否存在头结点，又可以把链表分为**带头结点的链表**和**不带头结点的链表**。头结点一般称为head，且其数据域data不存放任何内容，而指针域next指向第一个数据域有内容的结点(一般直接把这个结点叫作第一个结点)。

链表则是由若干个地址可能不连续的结点通过指针连接而成，且最后一个结点的next指针指向NULL，即空地址，表示一条链表的结尾。

### 7.3.2 使用malloc函数或new运算符为链表结点分配内存空间

1. malloc函数

    malloc函数是C语言中stdilb.h头文件下用于申请动态内存的函数，其返回类型是申请的同变量类型的指针，其基本用法如下：

    ```C++
        typename* p = (typename*) malloc(sizeof(typename));
    ```

2. new运算符

    new是C++中用来申请动态空间的运算符，其返回类型同样是申请的同变量类型的指针，其基本用法如下：

    ```C++
        typename* p = new typename;
    ```

3. 内存泄露

    内存泄露是指使用maollc与new开辟出来的内存空间在使用过后没有释放，导致其在程序结束之前始终占据该内存空间，这在一些较大的程序中很容易导致内存消耗过快以致最后无内存可分配。

    1. free函数

        free函数是对应maollc函数的，同样是在stdlib.h头文件下。其使用方法非常简单，只需要在free的参数中填写需要释放的内存空间的指针变量(不妨设为p)即可：`free(p);`

        free函数主要实现了两个效果：释放指针变量p所指向的内存空间；将指针变量p指向空地址NULL。

    2. delete运算符

        delete运算符是对应new运算符的，其使用方法和实现效果均与free相同。使用delete只需要在delete的参数中填写需要释放的内存空间的指针变量(不妨设为p)即可：`delete p;`

### 7.3.3 链表的基本操作

1. 创建列表

    通常利用循环来建立需要的链表：

    ```C++
        #include <cstdio>
        #include <cstdlib>

        struct node{
            int data;
            node* next;
        };

        node* create(int Array[]){
            node *p, *pre, *head;   // pre保存前驱，head为头结点
            head = new node;
            head->next = NULL;
            pre = head;
            for(int i = 0; i < 5; i++){
                p = new node;
                p->data = Array[i];
                p->next = NULL; // 新结点的指针域设为NULL
                pre->next = p;  // 前驱结点的指针域设为当前新建结点的地址
                pre = p;        // 把pre设为p, 作为下个结点的前驱结点
            }
            return head;
        }

        int main()
        {
            int Array[5] = {5, 3, 6, 1, 2};
            node* L = create(Array);
            L = L->next;    // 从第一个结点开始有数据域
            while(L != NULL){
                printf("%d", L->data);
                L = L->next;
            }
        }
    ```

2. 查找元素

    从第一个结点开始，不断判断当前结点的数据域是否等于x，如果等于，那么就给计数器count加1。这样当到达链表结尾时，count的值就是链表中元素x的个数。

    ```C++
        // 在以head为头结点的链表上计数元素x的个数
        int search(node* head, int x){
            int count = 0;
            node* p = head->next;
            while(p != NULL){
                if(p->data == x){
                    count++;
                }
                p = p->next;
            }
            return count;
        }
    ```

3. 插入元素

    对链表来说，插入元素是指在链表给定位置的地方插入一个结点。

    ```C++
        // 将x插入以head为头结点的链表的第pos个位置上
        void insert(node* head, int pos, int x){
            node* p = head->next;
            for(int i = 0; i < pos-1; i++){
                p = p->next;
            }
            node* q = new node;
            q->data = x;
            q->next = p->next;
            p->next = q;
        }
    ```

4. 删除元素

    对链表来说，删除元素是指删除链表上所有值为给定的数x。

    ```C++
        // 删除以head为头结点的链表中所有数据域为x的结点
        void del(node* head, int x){
            node* p = head->next;
            node* pre = head;
            while(p!= NULL){
                if(p->data == x){
                    pre->next = p->next;
                    delete p;
                    p = pre->next;
                }else{
                    pre = p;
                    p = p->next;
                }
            }
        }
    ```

7.3.4 静态链表

前面讲解的都是动态链表，即需要指针来建立结点之间的连接关系。而对有些问题来说，结点的地址是比较小的整数（例如5位数的地址），这样就没有必要去建立动态链表，而应使用方便得多的静态链表。

静态链表的实现原理是hash，即通过建立一个结构体数组，并令数组的下标直接表示结点的地址，来达到直接访问数组中的元素就能访问结点的效果。另外，由于结点的访问非常方便，因此静态链表是不需要头结点的。静态链表结点定义的方法如下：

```C++
    struct Node{
        typename data;  // 数据域
        int next;       // 指针域
    }node[size];
```

next是一个int型的整数，用以存放下一个结点的地址（事实上就是数组下标）。
