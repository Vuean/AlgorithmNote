# 第九章 提高篇(3)——数据结构专题(2)

## 9.1 树与二叉树

### 9.1.1 树的定义与性质

树是用来概括传递关系的一种数据结构。其中树根抽象为根结点(root)，且对一棵树来说最多存在一个根结点；把树叶概括为叶子结点(leaf)，且叶子结点不再延伸出新的结点；把茎干和树枝统一抽象为边(edge)，且一条边只用来连接两个结点(一个端点一个)。这样，树就被定义为由若于个结点和若干条边组成的数据结构，且在树中的结点不能被边连接成环。

> 树的概念与性质

1. 树可以没有结点，这种情况下把树称为**空树**(empty tree)。

2. 树的层次(layer)从根结点开始算起，即根结点为第一层，根结点子树的根结点为第二层，以此类推。

3. 把结点的子树棵数称为结点的度(degree)，而树中结点的最大的度称为树的度（也称为树的宽度）。

4. 由于一条边连接两个结点，且树中不存在环，因此对有n个结点的树，边数一定是n-1。且**满足连通、边数等于顶点数减1的结构一定是一棵树**。

5. 叶子结点被定义为度为0的结点，因此当树中只有一个结点（即只有根结点）时，根结点也算作叶子结点。

6. **结点的深度**(depth)是指从根结点(深度为1)开始自顶向下逐层累加至该结点时的深度值；**结点的高度**(height)是指从最底层叶子结点(高度为1)开始自底向上逐层累加至该结点时的高度值。**树的深度是指树中结点的最大深度**，**树的高度是指树中结点的最大高度**。**对树而言，深度和高度是相等的**。

7. 多棵树组合在一起称为森林(forest)，即森林是若干棵树的集合。

### 9.1.2 二叉树的递归定义

> 二叉树的定义

1. 要么二叉树没有根结点，是一棵空树。

2. 要么二叉树由根结点、左子树、右子树组成，且左子树和右子树都是二叉树。

> 二叉树与度为2的树的区别：

对树来说，结点的子树是不区分左右顺序的，因此度为2的树只能说明树中每个结点的子结点个数不超过2。而二叉树虽然也满足每个结点的子结点个数不超过2，但它的左右子树是严格区分的，不能随意交换左子树和右子树的位置，这就是二叉树与度为2的树最主要的区别。

> 特殊的二叉树

1. **满二叉树**：每一层的结点个数都达到了当层能达到的最大结点数。

2. **完全二叉树**：除了最下面一层之外，其余层的结点个数都达到了当层能达到的最大结点数，且**最下面一层只从左至右连续存在**若干结点，而这些连续结点右边的结点全部不存在。

### 9.1.3 二叉树的存储结构与基本操作

1. 二叉树的存储结构

    一般来说，二叉树使用链表来定义。和普通链表的区别是，由于二叉树每个结点有两条出边，因此指针域变成了两个一分别指向左子树的根结点地址和右子树的根结点地址。如果某个子树不存在，则指向NULL，其他地方和普通链表完全相同，因此又把这种链表叫作**二叉链表**，其定义方式如下：

    ```C++
        struct node{
            typename data;  // 数据域
            node* lchild;   // 指向左子树根结点的指针
            node* rchile;   // 指向右子树根结点的指针
        };
    ```

    由于在二叉树建树前根结点不存在，因此其地址一般设为NULL:

    ```C++
        node* root = NULL;
    ```

    新建结点：

    ```C++
        // 生成一个新结点，v为结点权值
        node* newNode(int v){
            node* Node = new node;
            Node->data = v;
            Node->lchild = Node->rchile = NULL;
            return Node;
        }
    ```

2. 二叉树结点的查找、修改

    查找操作是指在给定数据域的条件下，在二叉树中找到所有数据域为给定数据域的结点，并将它们的数据域修改为给定的数据域。常通过递归操作来完成查找、修改操作。

    ```C++
        void search(node* root, int x, int newdata){
            if(root == NULL){
                return;
            }
            if(root->data == x){
                root->data = newdata;
            }
            search(root->lchild, x, newdata);
            search(root->rchile, x, newdata);
        }
    ```

3. 二叉树结点的插入

    二叉树结点的插入位置就是数据域在二叉树中查找失败的位置。而由于这个位置是确定的，因此在递归查找的过程中一定是只根据二叉树的性质来选择左子树或右子树中的一棵子树进行递归，且最后到达空树（死胡同）的地方就是查找失败的地方，也就是结点需要插入的地方。由此可以得到二叉树结点插入的代码：

    ```C++
        // insert函数将在二叉树中插入一个数据域为x的新结点
        // 注意根结点指针root要使用引用，否则插入不会成功
        void insert(node* &root, int x){
            if(root == null){
                root = newNode(x);
                return;
            }
            if(由二叉树的性质，x应该插在左子树){
                insert(root->lchild, x);
            }else{
                insert(root->rchile, x);
            }
        }
    ```

    上述代码中，很关键的一点是根结点指针root使用了引用&。一般来说，如果函数中需要新建结点，即对二叉树的结构做出修改，就需要加引用；如果只是修改当前已有结点的内容，或仅仅是遍历树，就不用加引用。

4. 二叉树的创建

    二叉树的创建其实就是二叉树结点的插入过程，比较常用的写法是把需要插入的数据存储在数组中，然后再将它们使用insert函数一个个插入二叉树中，并最终返回根结点的指针root。更方便的是直接在建立二叉树的过程中边输入数据边插入结点。代码如下：

    ```C++
        // 二叉树的建立
        node* Create(int data[], int n){
            node* root = NULL;
            for(int i = 0; i < n; i++){
                insert(root, data[i]);
            }
            return root;
        }
    ```

5. 二叉树存储结构图示

    ![二叉树存储结构示意图](https://github.com/Vuean/AlgorithmNote/blob/main/Chapter9/%E4%BA%8C%E5%8F%89%E6%A0%91%E5%AD%98%E5%82%A8%E7%BB%93%E6%9E%84%E7%A4%BA%E6%84%8F%E5%9B%BE.png)

    通常在理解递归边界中`root = NULL`时，常会错误的理解为底`*root = NULL`。其实，`root = NULL`，表示地址是NULL，表示不存在这个结点。而*root的含义是获取地址root指向的空间的内容，但是这无法说明地址root是否位空，也即无法确定是否存在这个结点。

6. 完全二叉树的存储结构

    对一棵完全二叉树，如果给它的所有结点按从上到下、从左到右的顺序进行编号，可以观察到，完全二叉树的任何一个结点(设编号为x)，其左孩子的编号一定是2x，而右孩子的结点一定是2x+1。

    即完全二叉树可以通过建立一个大小为才的数组来存放所有结点的信息，其中k为完全二叉树的最大高度，且**1号位存放的必须是根结点**。

    除此之外，该数组中元素存放的顺序恰好为该完全二叉树的**层序遍历序列**。判断某个结点是否为叶结点的标志为：该结点(记下标为root)的左子结点的编号`root*2`大于结点总个数n；判断某个结点是否为空结点的标志为：该结点下标root大于结点总个数n。

## 9.2 二叉树的遍历

二叉树的遍历是指通过一定顺序访问二叉树的所有结点。遍历方法一般有四种：先序遍历、中序遍历、后序遍历及层次遍历，其中，前三种一般使用深度优先搜索(DPS)实现，而层次遍历一般用广度优先搜索(BFS)实现。

二叉树的结构可分为三部分：根结点、左子树、右子树，且对左子树和右子树同样进行这样的划分，这样对树的遍历就可以分解为对这三部分的遍历。无论是这三种遍历中的哪一种，左子树一定先于右子树遍历，且所谓的“先中后”都是指根结点root在遍历中的位置，因此先序遍历的访问顺序是根结点→左子树→右子树，中序遍历的访问顺序是左子树→根结点→右子树，后序遍历的访问顺序是左子树→右子树→根结点。

### 9.2.1 先续遍历

1. 先序遍历的实现

    对先序遍历来说，总是先访问根结点root，然后才去访问左子树和右子树，因此先序遍历的遍历顺序是根结点→左子树→右子树。

    ```C++
        void preorder(node* root){
            if(root == NULL){
                return; // 到达空树，递归边界
            }
            // 访问根结点root，例如输出数据
            cout << root->data << " ";
            // 访问左子树
            preorder(root->lchild);
            // 访问右子树
            preorder(root->rchild);
        }
    ```

2. 先序遍历序列的性质

    由于先序遍历先访问根结点，因此对一棵二叉树的先序遍历序列，**序列的第一个一定是根结点**。

### 9.2.2 中序遍历

1. 中序遍历的实现

    对中序遍历来说，总是先访问左子树，再访问根结点（即把根结点放在中间访问），最后访问右子树，因此中序遍历的遍历顺序是左子树→根结点→右子树。

    ```C++
        void inorder(node* root){
            if(root == NULL){
                return; // 到达空树，递归边界
            }
            // 访问左子树
            inorder(root->lchild);
            // 访问根结点root，例如输出数据
            cout << root->data << " ";
            // 访问右子树
            inorder(root->rchild);
        }
    ```

2. 中序遍历序列的性质

    由于中序遍历总是把根结点放在左子树和右子树中间，因此**只要知道根结点，就可以通过根结点在中序遍历序列中的位置区分出左子树和右子树**。

### 9.2.3 后序遍历

1. 后序遍历的实现

    对后序遍历来说，总是先访问左子树，再访问右子树，最后才访问根结点（即把根结点放在最后访问），因此后序遍历的遍历顺序是左子树→右子树→根结点。

    ```C++
        void postorder(node* root){
            if(root == NULL){
                return; // 到达空树，递归边界
            }
            // 访问左子树
            postorder(root->lchild);
            // 访问右子树
            postorder(root->rchild);
            // 访问根结点root，例如输出数据
            cout << root->data << " ";
        }
    ```

2. 后序遍历序列的性质

    后序遍历总是把根结点放在最后访问，这和先序遍历恰好相反，因此对后序遍历序列来说，**序列的最后一个一定是根结点**。

### 9.2.4 层序遍历

层序遍历是指按层次的顺序从根结点向下逐层进行遍历，且对同一层的结点为从左到右遍历。

层序遍历基本思路如下：

1. 将根结点root加入队列q。

2. 取出队首结点，访问它。

3. 如果该结点有左孩子，：将左孩子入队。

4. 如果该结点有右孩子，将右孩子入队。

5. 返回2，直到队列为空。

```C++
    // 层序遍历
    void LayerOrder(node* root){
        queue<node*> q; // 注意队列里是存地址
        q.push(root);   // 将根结点地址入队
        while(!q.empty()){
            node* now = q.front();  // 取出队首元素
            q.pop();
            cout << now->data << " ";
            if(now->lchild != NULL) q.push(now->lchild);    // 左子树非空
            if(now->rchild != NULL) q.push(now->rchild);    // 右子树非空
        }
    }
```

如果需要在层次遍历的时候，还需要计算出每个结点所处的层次，这时需要在二叉树结点的定义中添加一个记录层次layer的变量：

```C++
    struct node{
        int data;
        int layer;  // 层次
        node* lchild;
        node* rchild;
    };
```

```C++
    // 层次遍历
    void LayerOrder(node* root){
        queue<node*> q;
        root->layer = 1;
        q.push(root);
        while(!q.empty()){
            node* now = q.front();
            q.pop();
            cout << now->data << " ";
            if(now->lchild != NULL){
                now->lchild->layer = now->layer + 1;
                q.push(now->lchild);
            }
            if(now->rchild != NULL){
                now->rchild->layer = now->layer + 1;
                q.push(now->rchild);
            }
        }
    }
```

针对问题：给定一棵二叉树的先序遍历序列和中序遍历序列，重建这棵二叉树。

```C++
    // 当前先序序列区间为[preL, preR]，中序序列区间为[inL, inR]，返回根节点地址
    node* create(int preL, int preR, int inL, int inR){
        if(preL > preR){
            return NULL;    // 先序序列长度小于等于0时，直接返回
        }
        node* root = new node;  // 新建一个新的结点，用来存放当前二叉树的根结点
        root->data = pre[preL];// 新结点的数据域为根结点的值
        int k;
        for(k = inL; k <= inR; k++)){
            if(in[k] == pre[preL]){
                break;
            }
        }
        int numLeft = k - inL;  // 左子树的结点个数

        // 左子树的先序区间为[preL+1, preL+numLeft]，中序区间为[inL, k-1]
        // 返回左子树的根结点地址，赋值给root的左指针
        root->lchild = create(preL + 1, preL+numLeft, inL, k-1);

        // 右子树的先序区间为(preL + numLeft + 1, preR]，中序区间为[k+1, inR]
        // 返回右子树的根结点地址，赋值给root的右指针
        root->rchild = create(preL + numLeft + 1, preR, k+1, inR);

        return root;
    }
```

### 9.2.5 二叉树的静态实现

静态二叉链表是指，结点的左右指针域使用int型代替，用来表示左右子树的根结点在数组中的下标。为此需要建立一个大小为结点上限个数的node型数组，所有动态生成的结点都直接使用数组中的结点，所有对指针的操作都改为对数组下标的访问。于是，结点node的定义变为如下：

```C++
    struct node{
        typename data;  // 数据域
        int lchild;     // 指向左孩子树的指针域
        int rchild;     // 指向右孩子树的指针域
    } Node[maxn];
```

在这样的定义下，结点的动态生成就可以转变为如下的静态指定：

```C++
    int index = 0;
    int newNode(int v)
    {
        // 分配一个Node数组中的结点给新的结点，index为其下标
        Node[index].data = v;
        Node[index].lchild = -1;
        Node[index].rchild = -1;
        return index++;
    }
```

下面给出二叉树的查找、插入、建立的代码：

```C++
    // 查找， root为根结点在数组中的下标
    void search(int root, int x, int newdata){
        if(root == -1){
            // 用-1来代替NULL
            return;
        }
        if(Node[root].data == x){
            // 找到数据域为x的结点，把它修改成newdata
            Node[root].data = newdata;
        }
        search(Node[root].lchild, x, newdata);
        search(Node[root].rchild, x, newdata);
    }
```

```C++
    // 插入，root为根结点在数组中的下标
    void insert(int &root, int x){
        if(root == -1){
            // 空树，说明查找失败，也即插入位置
            root = newNode(x);
            return;
        }
        if(由二叉树的性质x应该插在左子树){
            insert(Node[root].lchild, x);
        }else{
            insert(Node[root].rchild, x);
        }
    }
```

```C++
    // 二叉树的建立，root为根结点在数组中的下标
    int Create(int data[], int n){
        int root = -1;
        for(int i = 0; i < n; i++){
            insert(root, data[i]);
        }
        return root;
    }
```

```C++
    // 先序遍历
    void preorder(int root){
        if(root == -1){
            return;
        }
        // 访问根结点root
        cout << Node[root].data << " ";
        preorder(Node[root].lchild);
        preorder(Node[root].rchild);
    }
    // 中序遍历
    void inorder(int root){
        if(root == -1){
            return;
        }
        inorder(Node[root].lchild);
        // 访问根结点root
        cout << Node[root].data << " ";
        inorder(Node[root].rchild);
    }
    // 后序遍历
    void postorder(int root){
        if(root == -1){
            return;
        }
        postorder(Node[root].lchild);
        postorder(Node[root].rchild);
        // 访问根结点root
        cout << Node[root].data << " ";
    }
    // 层序遍历
    void LayerOrder(int root){
        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            cout << Node[now].data << " ";
            if(Node[now].lchild != -1) q.push(Node[now].lchild);
            if(Node[now].rchild != -1) q.push(Node[now].rchild);
        }
    }
```

## 9.3 树的遍历

### 9.3.1 树的静态写法

通常一般意义上的树，即子结点个数不限且子结点没有先后次序的树。

树的静态写法：

```C++
    struct node{
        typename data;  // 数据域
        vector<int> child;  // 指针域，存放所有子节点的下标
    }Node[maxn];
```

与二叉树的静态实现类似，当需要新建一个结点时，就按顺序从数组中取出一个下标即可，如下所示：

```C++
    int intdex = 0;
    int newNode(int v){
        Node[index].data = v;
        Node[index].child.clear();
        return index++; // 返回结点下标，并令index自增
    }
```

### 9.3.2 树的先根遍历

对一棵一般意义的树来说，先根遍历即总是先访问根结点，再去访问所有子树。

```C++
    void PreOrder(int root){
        printf("%d", Node[root].data);
        for(int i = 0; i < Node[root].child.size(); i++){
            PreOrder(Node[root].child[i]);
        }
    }
```

### 9.3.3 树的层序遍历

总是从树根开始，一层一层地向下遍历。

```C++
    void LayerOrder(int root){
        queue<int> Q;
        Q.push(Node);           // 将根结点入队
        while(!Q.empty()){
            int front = Q.front();
            printf("%d", Node[root].data);
            Q.pop();
            for(int i = 0; i < Node[root].child.size(); i++){
                Q.push(Node[front].child[i]);
            }
        }
    }
```

同样的，如果需要对结点的层号进行求解，只需要在结构体node的定义中增加变量来记录结点的层号：

```C++
    struct node{
        int layer;
        int data;
        vector<int> child;
    };
```

```C++
    // 树的层次遍历
    void LayerOrder(int root){
        queue<int> Q;
        Q.push(Node);           // 将根结点入队
        Node[root].layer = 0;
        while(!Q.empty()){
            int front = Q.front();
            printf("%d", Node[root].data);
            Q.pop();
            for(int i = 0; i < Node[root].child.size(); i++){
                int child = Node[front].child[i];
                Node[child].layer = Node[front].layer + 1;
                Q.push(child);
            }
        }
    }
```

### 9.3.4 从树的遍历看DFS和BFS

1. 深度优先搜索(DFS)与先根遍历

    碰到一些可以用DFS做的题目，不妨把一些状态作为树的结点，然后问题就会转换为直观的对树进行先根遍历的问题。

2. 广度优先搜索(BFS)与层序遍历

    对所有合法的BFS求解过程，都可以像DFS中那样画出一棵树，并且将广度优先搜索问题转换为树的层序遍历的问题。

## 9.4 二叉查找树(BST)

### 9.4.1 二叉查找树的定义

二叉查找树(Binary Search Tree, BST)是一种特殊的二叉树，又称为**排序二叉树、二叉搜索树、二叉排序树**。二叉查找树的递归定义如下：

1. 要么二叉查找树是一棵空树。

2. 要么二叉查找树由根结点、左子树、右子树组成，其中左子树和右子树都是二叉查找树，且左子树上所有结点的数据域均小于或等于根结点的数据域，右子树上所有结点的数据域均大于根结点的数据域。

### 9.4.2 二叉查找树的基本操作

二叉查找树的基本操作有查找、插入、建树、删除。

1. 查找操作

    二叉查找树的性质决定了读者可以只选择其中一棵子树进行遍历，因此查找将会是从树根到查找结点的一条路径，故最坏复杂度是O(h)，其中h是二叉查找树的高度。于是可以得到查找操作的基本思路：

    1. 如果当前根结点root为空，说明查找失败，返回。

    2. 如果需要查找的值x等于当前根结点的数据域root->data，说明查找成功，访问之。

    3. 如果需要查找的值x小于当前根结点的数据域root->data，说明应该往左子树查找，因此向root->lchild递归。

    4. 说明需要查找的值x大于当前根结点的数据域root->data，则应该往右子树查找，因此向root->rchild递归。

    ```C++
        // search函数查找二叉查找树中数据域为x的结点
        void search(node* root, int x)
        {
            if(root == NULL){
                cout << "search failed" << endl;
                return;
            }
            if(x == root->data){
                cout << root->data << endl;
            }else if(x < root->data){
                search(root->lchild, x);
            }else{
                search(root->rchild, x);
            }
        }
    ```

    可以看到，和普通二叉树的查找函数不同，二叉查找树的查找在于对左右子树的选择递归。在普通二叉树中，无法确定需要查找的值x到底是在左子树还是右子树，但是在二叉查找树中就可以确定，因为二叉查找树中的数据域顺序总是左子树<根结点<右子树。

2. 插入操作

    对一棵二叉查找树来说，查找某个数据域的结点一定是沿着确定的路径进行的。因此，当对某个需要查找的值在二叉查找树中查找成功，说明结点已经存在；反之，如果这个需要查找的值在二叉查找树中查找失败，那么说明查找失败的地方一定是结点需要插入的地方。因此可以在上面查找操作的基础上，在root=NULL时新建需要插入的结点。显然插入的时间复杂度也是O(h)，其中h为二叉查找树的高度。

    ```C++
        // insert函数将在二叉树中插入一个数据域为x的新结点（注意参数root要加引用&）
        void insert(node* &root, int x){
            if(root == NULL){
                // 空树，说明查找失败，也即插入位置
                root = newNode(x);
                return;
            }
            if(x == root->data){
                // 查找成功，说明结点已存在，直接返回
                return;
            }else if(x < root->data){
                // 往左子树搜索x
                insert(root->lchild, x);
            }else{
                // 往右子树搜索x
                insert(root->rchild, x);
            }
        }
    ```

3. 二叉查找树的建立

    建立一棵二叉查找树，就是先后插入n个结点的过程，这和一般二叉树的建立是完全一样的，因此代码也基本相同：

    ```C++
        // 二叉查找树的建立
        node* Create(int data[], int n){
            node* root = NULL;
            for(int i = 0; i < n; i++){
                insert(root, data[i]);
            }
            return root;
        }
    ```

    需要注意的是，即便是一组相同的数字，如果插入它们的顺序不同，最后生成的二叉查找树也可能不同。

4. 二叉查找树的删除

    二叉查找树的删除操作一般有两种常见做法，复杂度都是O(h)，其中h为二叉查找树的高度。

    把以二叉查找树中**比结点权值小的最大结点称为该结点的前驱**，而把**比结点权值大的最小结点称为该结点的后继**。显然，结点的前驱是该结点左子树中的最右结点（也就是从左子树根结点开始不断沿着rchild往下直到rchild为NULL时的结点），而结点的后继则是该结点右子树中的最左结点（也就是从右子树根结点开始不断沿着lchild往下直到lchild为NULL时的结点）。下面两个函数用来寻找以root为根的树中最大或最小权值的结点，用以辅助寻找结点的前驱和后继：

    ```C++
        // 寻找以root为根结点的树中的最大权值结点
        node* findMax(node* root){
            while(root->rchild != NULL){
                root = root->rchild;
            }
            return root;
        }
        // 寻找以root为根结点的树中的最小权值结点
        node* findMin(node* root){
            while(root->lchild != NULL){
                root = root->lchild;
            }
            return root;
        }
    ```

    假设决定用结点N的前驱P来替换N，于是就把问题转换为在N的左子树中删除结点P，就可以递归下去了，直到递归到一个叶子结点，就可以直接把它删除了。

    因此删除操作的基本思路如下：

    1. 如果当前结点root为空，说明不存在权值为给定权值x的结点，直接返回。

    2. 如果当前结点root的权值恰为给定的权值x，说明找到了想要删除的结点，此时进入删除处理。

       - 如果当前结点root不存在左右孩子，说明是叶子结，直接删除。

       - 如果当前结点root存在左孩子，那么在左子树中寻找结点前驱pre，然后让pre的数据覆盖root，接着在左子树中删除结点pre。

       - 如果当前结点root存在右孩子，那么在右子树中寻找结点后继next，然后让next的数据稷盖root，接着在右子树中删除结点next。

    3. 如果当前结点root的权值小于给定的权值x，则在左子树中递归删除权值为x的结点。

    4. 如果当前结点root的权值大于给定的权值x，则在右子树中递归删除权值为x的结点。删除操作的代码如下（如果需要，可以在删除叶子结点的同时释放它的空间）：

    ```C++
        // 删除以root为根结点的树中权值为x的结点
        void deleteNode(node* &root, int x){
            if(root == NULL) return;    // 不存在权值为x的结点
            if(root->data == x){
                if(root->lchild == NULL && root->rchild == NULL){
                    // 叶子结点直接删除
                    root = NULL;
                }else if(root->lchild != NULL){
                    // 左子树不为空时
                    node* pre = findMax(node->lchild);  // 找root前驱
                    root->data = pre->data; // 用前驱覆盖root
                    deleteNode(root->lchild, pre->rchild);  // 在左子树中删除结点pre
                }else{
                    // 右子树不为空时
                    node* next = findMin(node->rchild); // 找root后继
                    root->data = next->data; //用后继覆盖root
                    deleteNode(root->rchild, next->data);   // 在右子树中删除结点next
                }
            }else if(root->data > x){
                deleteNode(root->lchild, x);
            }else{
                deleteNode(root->rchild, x);
            }
        }
    ```

    但是也要注意，总是优先删除前驱（或者后继）容易导致树的左右子树高度极度不平衡，使得二叉查找树退化成一条链。解决这一问题的办法有两种：一种是每次交替删除前驱或后继；另一种是记录子树高度，总是优先在高度较高的一棵子树里删除结点。

### 9.4.3 二叉查找树的性质

二叉查找树一个实用的性质：**对二叉查找树进行中序遍历，遍历的结果是有序的。**

这是由于二叉查找树本身的定义中就包含了左子树<根结点<右子树的特点，而中序遍历的访问顺序也是左子树→根结点→右子树，因此，所得到的中序遍历序列是有序的。

## 9.5 平衡二叉树(AVL树)

### 9.5.1 平衡二叉树的定义

平衡二叉树一般也称作AVL树。AVL树仍然是一棵二叉查找树，只是在其基础上增加了“平衡”的要求。所谓平衡是指，对AVL树的任意结点来说，其左子树与右子树的高度之差的绝对值不超过1，其中**左子树与右子树的高度之差称为该结点的平衡因子**。

只要能随时保证每个结点平衡因子的绝对值不超过1，AVL的高度就始终能保持O(logn)级别。由于需要对每个结点都得到平衡因子，可在树的结构中加入一个变量height，用来记录以当前结点为根结点的子树的高度：

```C++
    struct node {
        int v, height;  // v为结点权值，height为当前子树高度
        node *lchild, *rchild;
    };
```

在这种定义下，如果需要新建一个结点，就可以采用如下写法：

```C++
    // 个结点， 就可以采用如下写法：
    node* newNode(int v){
        node* Node = new node;
        Node->v = v;
        Node->height = 1;
        Node->lchild = Node->rchild = NULL;
        return Node;
    }
```

显然，可以通过下面的函数获取结点root所在子树的当前高度：

```C++
    // 获取以root为根结点的子树的当前height
    int getHeight(node* root)
    {
        if(root == NULL) return 0;
        return root->height;
    }
```

于是根据定义，可以通过下面的函数计算平衡因子：

```C++
    // 计算结点root的平衡因子
    int getBalanceFactor(node* root)
    {
        // 左子树高度减右子树高度
        return getHeight(root->lchild) - getHeight(root->rchild);
    }
```

因为没有办法通过当前结点的子树的平衡因子计算得到该结点的平衡因子，而需要借助子树的高度间接求得。显然，结点root所在子树的height等于其左子树的height与右子树的height的较大值加1，因此可以通过下面的函数来更新height：

```C++
    // 更新结点root的height
    void updateHeight(node* root){
        // max(左孩子的height, 右孩子的height) + 1
        root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
    }
```

### 9.5.2 平衡二叉树的基本操作

1. 查找操作

    由于AVL树是一棵二叉查找树，因此其查找操作的做法与二叉查找树相同，时间复杂度为O(logn)。

    ```C++
        // search函数查找AVL树中数据域为x的结点
        void search(node * root, int x)
        {
            if(root == NULL){
                // 空树，查找失败
                printf("search failed\n");
                return;
            }
            if(x == root->data){
                printf("%d\n", root->data);
            }else if(x < root->data){
                search(root->lchild, x);
            }else{
                search(root->rchild, x);
            }
        }
    ```

2. 插入操作

    左旋(Left Rotation)的调整步骤如下：

    - 让B的左子树成为A的右子树；

    - 让A称为B的左子树

    - 将根结点设定为结点B

    > 代码实现

    ```C++
        // 左旋(Left Rotation)
        void L(node* &root){
            node* temp = root->rchild;
            temp->lchild = root;
            updateHeight(root);
            updateHeight(temp);
            root = temp;
        }
    ```

    右旋(Right Rotation)的调整步骤如下：

    - 让A的右子树成为B的左子树

    - 让B成为A的右子树

    - 将根结点设为结点A

    > 代码实现

    ```C++
        // 右旋(Right Rotation)
        void R(node* &root){
            node* temp = root->lchild;
            temp->rchild = root;
            updateHeight(root);
            updateHeight(temp);
            root = temp;
        }
    ```

    基于左旋和右旋，再来讨论AVL树的插入操作。

    假设现在已有一棵平衡二叉树，那么可以预见到，在往其中插入一个结点时，一定会有结点的平衡因子发生变化，这样以该结点为根结点的子树就是失衡的，需要进行调整。显然，**只有在从根结点到该插入结点的路径上的结点才可能发生平衡因子变化**，因此只需对这条路径上失衡的结点进行调整。可以证明，只要把最靠近插入结点的失衡结点调整到正常，路径上的所有结点就都会平衡。

    根据插入结点后的树型不同，可分为四种类型：LL型、LR型、RR型、RL型，其各自的调整方法如下标所示：

    |树型|判定条件|调整方法|
    |:-:|:-|:-|
    |LL|BF(root)=2, BF(root->lchild)=1|对root进行右旋|
    |LR|BF(root)=2, BF(root->lchild)=-1|先对root->lchild进行左旋，再对root进行右旋|
    |RR|BF(root)=-2, BF(root->rchild)=-1|对root进行左旋|
    |RL|BF(root)=-2, BF(root->rchild)=1|先对root->rchild进行右旋，再对root进行右旋|

    现在考虑如何书写插入代码。首先，AVL树的插入代码是在二叉查找树的插入代码的基础上增加平衡操作的，因此，如果不考虑平衡操作，代码是下面这样的：

    ```C++
        // 插入权值为v的结点
        void insert(node* &root, int v)
        {
            if(root == NULL){
                root = newNode(v);
                return;
            }
            if(v < root->v){
                insert(root->lchild, x);
            }
            else{
                insert(root->rchild, x);
            }
        }
    ```

    在这个基础上，由于需要从插入的结点开始从下往上判断结点是否失衡，因此需要在每个insert函数之后更新当前子树的高度，并在这之后根据树型是LL型、LR型、RR型、RL型之一来进行平衡操作，代码如下：

    ```C++
        // 插入权值为v的结点
        void insert(node* &root, int v)
        {
            if(root == NULL)
            {
                root = newNode(v);
                return;
            }
            if(v < root->v)
            {
                insert(root->lchild, v);
                updateHeight(root);     // 更新树高
                if(getBalanceFactor(root) == 2){
                    if(getBalanceFactor(root->lchild) == 1){
                        // LL型
                        R(root);
                    }else if(getBalanceFactor(root->lchild) == -1){
                        // LR型
                        L(root->lchild);
                        R(root);
                    }
                }
            }
            else{
                // v比根结点的权值大
                insert(root->rchild, v);
                updateHeight(root);
                if(getBalanceFactor(root) == -2)
                {
                    if(getBalanceFactor(root->rchild) == -1)
                    {
                        // RR型
                        L(root);
                    }else if(getBalanceFactor(root->rchild) == 1)
                    {
                        // RL型
                        R(root->rchild);
                        L(root);
                    }
                }
            }
        }
    ```

3. AVL树的建立

    有了上面插入操作的基础，AVL树的建立就非常简单了，因为只需依次插入n个结点即可。

    ```C++
        // AVL树的建立
        node* Create(int data[], int n)
        {
            node* root = NULL;
            for(int i = 0; i < n; i++)
            {
                insert(root, data[i]);
            }
            return root;
        }
    ```

## 9.6 并查集

### 9.6.1 并查集的定义

并查集是一种**维护集合**的数据结构，它的名字中“并”“查”“集”分别取自Union（合并）、Find（查找）、Set（集合）这3个单词。也就是说，并查集支持下面两个操作：

1. 合并：合并两个集合。

2. 查找：判断两个元素是否在一个集合。

并查集通过数组来实现：`int father[N];`，其中，father[i]表示元素i的父亲节点，而父亲节点本身也是这个集合内的元素。例如father[1] = 2就表示元素1的父亲结点是元素2，以这种父系关系来表示元素所属的集合。另外，如果father[i] = i，则说明元素i是该集合的根结点，但对同一个集合来说只存在一个根结点，且将其作为所属集合的标识。

### 9.6.2 并查集的基本操作

并查集的使用需要先初始化father数组，然后再根据需要进行查找或合并的操作。

1. 初始化

    一开始，每个元素都是独立的一个集合，因此需要令所有father[i]等于i:

    ```C++
        for(int i = 1; i <= N; i++)
        {
            father[i] = i;  // 令father[i]=-1也可
        }
    ```

2. 查找

    由于规定同一个集合中只存在一个根结点，因此**查找操作就是对给定的结点寻找其根结点的过程**，即找到father[i] == i的结点。

    ```C++
        // 递推实现
        int findFther(int x)
        {
            while(x != father[x])   // 如果不是根结点，继续循环
            {
                x = father[x];      // 获得自己的父亲结点
            }
            return x;
        }

        // 递归实现
        int findFther(int x)
        {
            // 如果找到根结点，则返回根结点编号x
            if(x == father[x]) return x;
            // 否则，递归判断x的父亲结点是否是根结点
            else return findFther(father[x]);
        }
    ```

3. 合并

    **合并是指把两个集合合并成一个集合**，题目中一般给出两个元素，要求把这两个元素所在的集合合并。具体实现上一般是先判断两个元素是否属于同一个集合，只有当两个元素属于不同集合时才合并，而合并的过程一般是**把其中一个集合的根结点的父亲指向另一个集合的根结点**。

    合并思路：

    1. 对于给定的两个元素a、b，调用查找函数判断它们是否属于同一集合。

    2. 合并两个集合：在步骤1中已经获得了两个元素的根结点faA与faB，因此只需要把其中一个的父亲结点指向另一个结点。

    ```C++
        void Union(int a, int b)
        {
            int faA = findFther(a);     // 查找a的根结点，记为faA
            int faB = findFther(b);     // 查找b的根结点，记为faB
            if(faA != faB)
            {
                father[faA] = faB;      // 合并
            }
        }
    ```

    在合并的过程中，只对两个不同的集合进行合并，如果两个元素在相同的集合中，那么就不会对它们进行操作。这就保证了在同一个集合中一定不会产生环，即并查集产生的每一个集合都是一棵树。

### 9.6.3 路径压缩

如果只是为了查找根结点，可以把当前查询结点的路径上的所有结点的父亲都指向根结点，这样可将查询的复杂度降为O(1)。

转换过程可概括为两个步骤：

1. 按原先的写法获得x的根结点r。

2. 重新从x开始走一遍寻找根结点的过程，把路径上经过的所有结点的父亲全部改为根结点r。

```C++
    int findFther(int x)
    {
        // 由于x在下面的while中会变成根结点，因此先把原先的x保存一下
        int a = x;
        while(x != father[x])
        {
            x = father[x];
        }
        // 到这里，x存放的是根结点。下面把路径上的所有结点的father都改成根结点
        while(a != father[a])
        {
            int z = a;
            a = father[a];
            father[z] = x;  // 将原先的结点a的父亲改为根结点x
        }
        return x;
    }

    // 递归
    int findFather(int v)
    {
        if(v == father[v]) return v;
        else{
            int F = findFther(father[v]);
            father[v] = F;
            return F;
        }
    }
```

## 9.7 堆

### 9.7.1 堆的定义与基本操作

堆是一棵完全二叉树，树中每个结点的值都不小于（ 或不大于）其左右孩子结点的值。其中，如果父亲结点的值大于或等于孩子结点的值，那么称这样的堆为**大顶堆**，这时每个结点的值都是以它为根结点的子树的最大值；如果父亲结点的值小于或等于孩子结点的值，那么称这样的堆为**小顶堆**，这时每个结点的值都是以它为根结点的子树的最小值。堆一般用于优先队列的实现，而优先队列默认情况下使用的是大顶堆。

为实现完全二叉树，较简洁的方法是通过数组来存储完全二叉树，这样结点就按层序存储于数组中，其中第一个结点将存储于数组中的1号位，并且数组i号位表示的结点的左孩子就是2i号位，而右孩子则是(2i+1)号位。

```C++
    const int maxn = 100;
    // heap为堆，n为元素个数
    int heap[maxn], n = 10;
```

在建堆过程中，每次调整都是把结点从上往下调整，针对这种向下调整，调整方法是：总是将当前结点V与它的左右孩子比较（如果有的话），假如孩子中存在权值比结点V的权值大的，就将其中权值最大的那个孩子结点与结点V交换；交换完毕后继续让结点V和孩子比较，直到结点V的孩子的权值都比结点V的权值小或是结点V不存在孩子结点。其实现过程如下，时间复杂度为O(logn)。

```C++
    // 对heap数组在[low, high]范围进行向下调整
    // 其中low为欲调整结点的数组下标，high一般为堆的最后一个元素的数组下标
    void dowdAdjust(int low, int high)
    {
        int i = low, j = i * 2; // i为欲调整结点，j为其左孩子
        while(j <= high)
        {
            // 如果右孩子存在，且右孩子大于左孩子
            if(j + 1 <= high && heap[j+1] > heap[j])
            {
                j = j + 1;  // 让j存储右孩子下标
            }
            // 如果孩子中最大的权值比欲调整结点i大
            if(heap[j] > heap[i])
            {
                swap(heap[i], heap[j]);
                i = j;
                j = i * 2;
            }else
            {
                break;  // 孩子的权值均比欲调整结点i小，调整结束
            }
        }
    }
```

建堆过程中，假设序列元素的个数为n，由于完全二叉树的叶子节点个数为a = n/2(向下取整)，因此数组下标在[1, a]范围内的结点都是非叶子节点。于是可以从a(向上取整)位开始倒着枚举结点，对每个遍历到的结点i进行[i, n]范围内的调整。其中，倒着遍历的方法，可保证每个结点都是以其为根结点的子树中的权值最大的结点。

建堆代码如下，时间复杂度为O(n)：

```C++
    // 建堆
    void createHeap()
    {
        for(int i = n / 2; i >= 1; i--)
        {
            downAdjust(i, n);
        }
    }
```

另外，如果要删除堆中的最大元素（也就是删除堆顶元素），并让其仍然保持堆的结构，那么只需要最后一个元素稷盖堆顶元素，然后对根结点进行调整即可。代码如下，时间复杂度为O(logn)：

```C++
    I// 删除堆顶元素
    void deleteTop()
    {
        heap[1] = heap[n--];    // 用最后一个元素覆盖堆顶元素，并让元素个数减1
        downAdjust(1, n);
    }
```

若想添加新元素，可以把想要添加的元素放在数组最后（也就是完全二叉树的最后一个结点后面），然后进行向上调整操作。向上调整总是把欲调整结点与父亲结点比较，如果权值比父亲结点大，那么就交换其与父亲结点，这样反复比较，直到达堆顶或是父亲结点的权值较大为止。向上调整的代码如下，时间复杂度为O(logn)：

```C++
    // 对heap数组在[low, high]范围进行向上调整
    // 其中low一般设置为1，high表示要调整结点的数组下标
    void upAdjust(int low, int high)
    {
        int i = high, j = i / 2;    // i为欲调整结点，j为其父亲
        while(j >= low)
        {
            // 父亲权值小于欲调整结点i的权值
            if(heap[j] < heap[i])
            {
                swap(heap[j], heap[i]); // 交换父亲和欲调整结点
                i = j;  // 保持i为欲调整节点、j为i的父亲
                j = i / 2;
            }
            else
            {
                break;
            }
        }
    }
```

在此基础上就很容易实现添加元素的代码了：

```C++
    // 添加元素x
    void insert(int x)
    {
        heap[++n] = x;  // 让元素个数加1，然后将数组末位赋值为x
        upAdjust(1, n); // 向上调整新加入的结点n
    }
```

### 9.7.2 堆排序

堆排序是指使用堆结构对一个序列进行排序。此处讨论递增排序的情况。

考虑对一个堆来说，堆顶元素是最大的，因此在建堆完毕后，堆排序的直观思路就是取出堆顶元素，然后将堆的最后一个元素替换至堆顶，再进行一次针对堆顶元素的向下调整——如此重复，直到堆中只有一个元素为止。

```C++
    void heapSort()
    {
        createHeap();
        for(int i = n; i > 1; i--)
        {
            swap(heap[i], heap[1]);
            downAdjust(1, i-1);
        }
    }
```

## 9.8 哈夫曼树

### 9.8.1 哈夫曼树

树的**带权路径长度**(**Weighted Path Length of Tree, WPL**)等于它所有叶子结点的带权路径长度之和。

带权路径长度最小的树被称为哈夫曼树（又称为最优二叉树）。显然，对同一组叶子结点来说，哈夫曼树可以是不唯一的，但是最小带权路径长度一定是唯一的。

构造哈夫曼树：

1. 初始状态下共有n个结点（结点的权值分别是给定的n个数），将它们视作n棵只有一个结点的树。

2. 合并其中根结点权值最小的两棵树，生成两棵树根结点的父结点，权值为这两个根结点的权值之和，这样树的数量就减少了一个。

3. 重复操作2，直到只剩下一棵树为止，这棵树就是哈夫曼树。

可以看出，构造哈夫曼树也即反复选择两个最小元素，合并，直到只剩下一个元素。于是，一般可以用优先队列来实现。

```C++
    #include <cstdio>
    #include <queue>
    using namespace std;

    // 代表小顶堆的优先队列
    priority_queue<long long, vector<long long>, greater<long long>> q;

    int main()
    {
        int n;
        long long temp, x, y, ans;
        scanf_s("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf_s("%lld", &temp);
            q.push(temp);
        }
        while(q.size() > 1)
        {
            x=q.top();
            q.pop();
            y = q.top();
            q.push(x+y);
            ans += x + y;
        }
        printf("%lld\n", ans);
    }
```

### 9.8.2 哈弗曼编码
