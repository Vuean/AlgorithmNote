# 第八章 提高篇(2)——搜索专题

## 8.1 深度优先搜索(DFS)

深度优先搜索是一种**枚举所有完整路径以遍历所有情况**的搜索方法。通常可以通过使用递归来很好地实现深度优先搜索。

例题1：有n件物品，每件物品的重量为w[i]，价值为c[i]。现在需要选出若干件物品放入一个容量为V的背包中，使得在选入背包的物品重量和不超过容量V的前提下，让背包中物品的价值之和最大，求最大价值。

```C++
    #include <cstdio>
    const int maxn = 30;
    int n, V, maxValue = 0; // 物品件数n，背包容量V，最大价值maxValue

    int w[maxn], c[maxn];   // w[i]为每件物品重量，V[i]为价值

    // DFS, index 为当前处理的物品编号
    // sumW 和sumC 分别为当前总重量和当前总价值

    void DFS(int index, int sumW, int sumC) {
        if (index == n) {   // 已经完成对n件物品的选择
            if (sumW <= V && sumC > maxValue) {
                maxValue = sumC;    // 不超过背包容量时更新最大价值maxValue
            }
            return;
        }
        // 岔路口
        DFS(index + 1, sumW, sumC);     // 不选第index件物品
        DFS(index + 1, sumW + w[index], sumC + c[index]);   // 选第index件物品
    }

    int main()
    {
        scanf_s("%d %d", &n, &V);
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &w[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &c[i]);   // 每件物品的价值
        }

        DFS(0, 0, 0);
        printf("%d\n", maxValue);
    }
```

由于每件物品有两种选择，因此上面代码的复杂度为O(2^n)。在上述代码中，总是把n件物品的选择全部确定之后才去更新最大价值，但是事实上忽视了背包容量不超过V这个特点。也就是说，完全可以把对sumW的判断加入“岔道口”中，只有当sumW≤v时才进入岔道，这样效率会高很多，代码如下：

```C++
    void DFS(int index, int sumW, int sumC) {
        if (index == n) {   // 已经完成对n件物品的选择
            return;
        }
        // 岔路口
        DFS(index + 1, sumW, sumC);     // 不选第index件物品
        // 只有加入第index件物品后未超过容量V, 才能继续
        if (sumW + w[index] <= V) {
            if (sumC + c[index] > maxValue) {
                maxValue = sumC + c[index]; // 更新最大价值maxValue
            }
        }
        DFS(index + 1, sumW + w[index], sumC + c[index]);   // 选第index件物品
    }
```

这种通过题目条件的限制来节省DFS计算量的方法称作**剪枝**。

例题2：给定N个整数（可能有负数），从中选择K个数，使得这K个数之和恰好等于一个给定的整数X；如果有多种方案，选择它们中元素平方和最大的一个。数据保证这样的方案唯一。

```C++
    // 序列A中n个数，选k数使得和为X，最大平方和为maxSumSqu
    int n, k, x, maxSumSqu = -1, A[maxn];
    // temp存放临时方案，ans存放平方和最大的方案
    vector<int> temp, ans;
    // 当前处理index号整数，当前已选整数个数为nowK
    // 当前已选整数之和为sum，当前已选整数平方和为sumSqu
    void DFS(int index, int nowK, int sum, int sumSqu){
        if(nowS == k && sum == x){  // 找到k个数的和为x
            if(sumSqu > maxSumSqu){ // 如果比当前找到的更优
                maxSumSqu = sumSqu; // 更新最大平方和
                ans = temp;
            }
            return;
        }
        // 已处理完n个数，或者超过k个数，或者和超过x，返回
        if(index == n || nowK > k || sum > x) return;
        // 选index号数
        temp.push_back(A[index]);
        DFS(index+1, nowK+1, sum+A[index], sumSqu + A[index]*A[index]);
        temp.pop_back();
        // 不选idnex号数
        DFS(index+1, nowK, sum, sumSqu);
    }
```

如果题目稍作修改：假设N个整数中的每一个都可以被选择多次，那么选择K个数，使得K个数之和恰好为X。

在上述代码的基础上只需要稍作修改，由于每个整数都可以被选择多次，因此当选择了index号数时，不应该直接进入index+1号数的处理。显然，应当能够继续选择index号数，直到某个时刻决定不再选择index号数，就会通过“不选index号数”这条分支进入index+1号数的处理。因此只需要把“选index号数”这条分支的代码修改为DFS(index, nowK + 1, nums + A[index], sumSqu + A[index] * A[index])即可。

## 8.2 广度优先搜索(BFS)

广度优先搜索(BFS)一般由队列实现，且总是按层次的顺序进行遍历，其基本写法如下（可作模板用）：

```C++
    void BFS(int s){
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            取出队首元素top;
            访问队首元素top;
            将队首元素出队;
            将top的下一层结点中未曾入队的结点全部入队，并设置为己入队;
        }
    }
```

具体说明如下：

1. 定义队列q，并将起点s入队；
2. 写一个while循环，循环条件是队列q非空；
3. 在while循环中，先取出队首元素top，然后访问它（访问可以是任何事情，例如将其输出）。访问完后将其出队；
4. 将top的下一层节点中所有未曾入队的结点入队，并标记它们的层号为now的层号加1，同时设置这些入队的结点已入过队。
5. 重复步骤2。

例题1：给出一个m x n的矩阵，矩阵中的元素为0或1。称位置(x, y)与其上下左右四个位置(x, y+1)、(x, y-1)、(x+1 , y)、(x-1, y)是相邻的。如果矩阵中有若干个1是相邻的（不必两两相邻），那么称这些1构成了一个“块”。求给定的矩阵中“块”的个数。

```C++
    #include <cstdio>
    #include <queue>
    using namespace std;

    const int maxn = 100;
    struct node {
        int x, y;
    }Node;

    int n, m;   // 矩阵大小为n*m
    int matrix[maxn][maxn];             // 01矩阵
    bool inq[maxn][maxn] = { false };   // 记录(x, y)是否已入过队
    int X[4] = { 0, 0, 1, -1 };
    int Y[4] = {1, -1, 0, 0};

    bool judge(int x, int y) {
        // 判断坐标(x, y) 是否需要访问
        // 越界返回false
        if (x >= n || x < 0 || y > m || y < 0) return false;
        // 当前位置为0, 或（x, y) 已入过队，返回false
        if (matrix[x][y] == 0 || inq[x][y] == true) return false;
        return true;
    }

    // BFS 函数访问位置(x, y)所在的块， 
    // 将该块中所有“ 1 " 的inq都设置为true
    void BFS(int x, int y) {
        queue<node> Q;
        Node.x = x, Node.y = y; // 当前结点的坐标为(x, y)
        Q.push(Node);           // 将结点Node入队
        inq[x][y] = true;       // 设置(x, y)已入过队
        while (!Q.empty()) {
            node top = Q.front();   // 取出队首元素
            Q.pop();            // 队首元素出队
            for (int i = 0; i < 4; i++) {
                int newX = top.x + X[i];
                int newY = top.y + Y[i];
                if (judge(newX, newY)) {
                    // 如果新位置(newX, newY)需要访问
                    // 设置Node 的坐标为(newX, newY)
                    Node.x = newX, Node.y = newY;
                    Q.push(Node);       // 将结点Node 加入队列
                    inq[newX][newY] = true;
                }
            }
        }
    }

    int main()
    {
        scanf_s("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf_s("%d", &matrix[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 如果元素为1, 且未入过队
                if (matrix[i][j] == 1 && inq[i][j] == false) {
                    ans++;      // 块数加1
                    BFS(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
```

例题2：给定一个`n*m`大小的迷宫，其中*代表不可通过的墙壁，而“.”代表平地，S表示起点，T代表终点。移动过程中，如果当前位置是(x, y)（下标从0开始），且每次只能前往上下左右(x, y+1)、(x, y-1)、(x-1,y)、（x+1, y)四个位置的平地，求从起点S到达终点T的最少步数。

```C++
    #include <cstdio>
    #include <string>
    #include <queue>
    using namespace std;

    const int maxn = 100;
    struct node {
        int x, y;
        int step;   // step为从起点S到达该位置的最少步数（即层数）
    }S, T, Node;

    int n, m;   // n为行，m为列
    char maze[maxn][maxn];  // 迷宫信息
    bool inq[maxn][maxn] = { false };   // 记录是否已入队
    int X[4] = { 0, 0, 1, -1 };
    int Y[4] = { 1, -1, 0, 0 };

    bool test(int x, int y) {
        if (x >= n || x < 0 || y > m || y < 0) return false;
        if (maze[x][y] == '*') return false;
        if (inq[x][y] == true) return false;
        return true;
    }

    int BFS() {
        queue<node> q;
        q.push(S);
        while (!q.empty()) {
            node top = q.front();
            q.pop();
            if (top.x == T.x && top.y == T.y) {
                return top.step;
            }
            for (int i = 0; i < 4; i++) {
                int newX = top.x + X[i];
                int newY = top.y + Y[i];
                if (test(newX, newY)) {
                    // 位置(newX, newY)有效
                    // 设置Node 的坐标为(newX, newY)
                    Node.x = newX, Node.y = newY;
                    Node.step = top.step + 1;
                    q.push(Node);       // 将结点Node 加入队列
                    inq[newX][newY] = true;
                }
            }
        }
        return -1;  // 无法到达终点T时返回－1
    }

    int main()
    {
        scanf_s("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            getchar();  // 过滤掉每行后面的换行符
            for (int j = 0; j < m; j++) {
                maze[i][j] = getchar();
            }
            maze[i][m + 1] = '\0';
        }
        scanf_s("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
        S.step = 0;
        printf("%d\n", BFS());
    }
```

再强调一点，在BFS中设置的inq数组的含义是判断结点是否已入过队，而不是结点是否已被访问。区别在于：如果设置成是否已被访问，有可能在某个结点正在队列中（但还未访问）时由于其他结点可以到达它而将这个结点再次入队，导致很多结点反复入队，计算量大大增加。因此BFS中让每个结点只入队一次，故需要设置inq数组的含义为结点是否已入过队而非结点是否已被访问。
