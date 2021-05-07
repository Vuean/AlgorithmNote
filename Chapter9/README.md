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
