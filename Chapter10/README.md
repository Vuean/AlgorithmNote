# 第十章 提高篇(4)——图算法专题

## 10.1 图的定义和相关术语

抽象出来看，图由顶点(Vertex)和边(Edge)组成，每条边的两端都必须是图的两个顶点（可以是相同的顶点）。而记号G(V, E)表示图G的顶点集为V、边集为E。

一般来说，图可分为有向图和无向图。有向图的所有边都有方向，即确定了顶点到顶点的一个指向；而无向图的所有边都是双向的，即无向边所连接的两个顶点可以互相到达。

顶点的度是指和该顶点相连的边的条数。特别是对于有向图来说，顶点的出边条数称为该顶点的出度，顶点的入边条数称为该顶点的入度。

顶点和边都可以有一定属性， 而量化的属性称为权值， 顶点的权值和边的权值分别称为点权和边权。

## 10.2 图的存储

一般来说，图的存储方式有两种：**邻接矩阵**和**邻接表**。

### 10.2.1 邻接矩阵

设图G(V,E)的顶点标号为0,1,.. ·,N-1，那么可以令二维数组G[N][N]的两维分别表示图的顶点标号，即如果G[i][j]为1，则说明顶点i和顶点j之间有边；如果G[i][j]为0，则说明顶点i和顶点j之间不存在边，而这个二维数组G[][]则被称为邻接矩阵。另外，如果存在边权，则可以令G[i][j]存放边权，对不存在的边可以设边权为0、-1或是一个很大的数。

### 10.2.2 邻接表

设图G(V, E)的顶点编号为0, 1,…, N- 1，每个顶点都可能有若干条出边，如果把同一个顶点的所有出边放在一个列表中，那么N个顶点就会有N个列表（没有出边，则对应空表）。这N个列表被称为图G的邻接表，记为Adj[N]，其中Adj[i]存放顶点i的所有出边组成的列表，这样Adj[0], Adj[1], ... , Adj[N-1]就分别都是一个列表。

## 10.3 图的遍历

图的遍历是指对图的所有顶点按一定顺序进行访问，遍历方法一般有两种：**深度优先搜索(DFS)**和**广度优先搜索(BFS)**。

### 10.3.1 采用深度优先搜索(DFS)法遍历图

1. 用DFS遍历图

    深度优先搜索以“深度”作为第一关键词，每次都是沿着路径到不能再前进时才退回到最近的岔道口。

2. DFS的具体实现

    首先介绍两个概念：

    - **连通分量**。在无向图中，如果两个顶点之间可以相互到达（可以是通过一定路径间接到达），那么就称这两个顶点连通。如果图G(V,E)的任意两个顶点都连通，则称图G为连通图；否则，称图G为非连通图，且称其中的极大连通子图为连通分量。

    - **强连通分量**。在有向图中，如果两个顶点可以各自通过一条有向路径到达另一个顶点，就称这两个顶点强连通。如果图G(V,E)的任意两个顶点都强连通，则称图G为强连通图；否则，称图G为非强连通图，且称其中的极大强连通子图为强连通分量。

    为方便叙述，将连通分量和强连通分量均称为连通块。

    可以想象，如果要遍历整个图，就需要对所有连通块分别进行遍历。所似DFS遍历图的基本思路就是将经过的顶点设置为己访问，在下次递归碰到这个顶点时就不再去处理，直到整个图的顶点都被标记为己访问。伪代码如下：

    ```C++
        DFS(u); // 访问顶点u
        vis[u] = true;  // 设置u已被访问
        for(从u出发能到达的所有顶点v)   // 枚举从u出发可以到达的所有顶点v
        {
            if(vis[v] == false) // 如果v未被访问
            {
                DFS(v); // 递归访问
            }
        }

        DFSTrave(G)
        {
            // 遍历图G
            for(G的所有顶点u)   // 对G的所有顶点u
            {
                if(vis[u] == false)
                {
                    DFS(u);
                }
            }
        }
    ```

    ```C++
        const int MAXV = 1000;      // 最大顶点数
        const int INF = 1000000000; // 设INF为一个很大的数
    ```

    1. 邻接矩阵版

        算法代码：

        ```C++
            int n, G[MAXV][MAXV];   // 设n为顶点数，MAXV为最大定点数
            bool vis[MAXV] = {false};   // 标识是否被访问

            void DFS(int u, int depth)  // u为当前访问的顶点标号，depth为深度
            {
                vis[u] = true;  // 设置u被访问
                // 如果需要对u进行一些操作，可以在这里进行
                // 面对所有从u出发能到达的分支顶点进行枚举
                for(int v = 0; v < n; v++)
                {
                    // 如果v未被访问，且u可到达v
                    if(vis[v] == false && G[u][v] != INF)
                    {
                        DFS(v, depth+1);// 访问v，深度加1
                    }
                }
            }

            void DFSTrave() // 遍历图G
            {
                for(int u = 0; u < n; u++)
                {
                    if(vis[u] == false)
                    {
                        DFS(u, 1);
                    }
                }
            }
        ```

    2. 邻接表版

        算法代码：

        ```C++
            vector<int> ADj[MAXV];  // 图G的邻接表
            int n;  // n为顶点数，MAXV为最大顶点数
            bool vis[MAXV] = {false};   // 标识是否被访问
            void DFS(int u, int depth)
            {
                vis[u] = true;  // 设置u被访问
                // 如果需要对u进行一些操作，可以在这里进行
                for(int i = 0; i < Adj[u].size(); i++)
                {
                    int v = Adj[u][i];
                    if(vis[v] == false)
                    {
                        DFS(v, depth+1);
                    }
                }
            }

            void DFSTrave()
            {
                for(int u = 0; u < n; u++)
                {
                    if(vis[u] == false)
                    {
                        DFS(u, 1);
                    }
                }
            }
        ```

### 10.3.2 采用广度优先搜索(BFS)法遍历图

1. 用BFS遍历图

    广度优先搜索以“广度”作为关键词，每次以扩散的方式向外访问顶点。和树的遍历一样，使用BFS遍历图需要使用一个队列，通过反复取出队首顶点，将该顶点可到达的未曾加入过队列的顶点全部入队，直到队列为空时遍历结束。

2. BFS的具体实现

    如果要遍历整个图，则需要对所有连通块分别进行遍历。使用BFS遍历图的基本思想是建立一个队列，并把初始顶点加入队列，此后每次都取出队首顶点进行访问，并把从该顶点出发可以到达的未曾加入过队列（而不是未访问）的顶点全部加入队列，直到队列为空。

    伪代码如下：

    ```C++
        BFS(u){ // 遍历u所在的连通块
            queue q;    // 定义队列q
            q.push(u);  // 将u入队
            inq[u] = true;  // 设置u已入过队
            while(q非空){
                取出q的队首元素u进行访问；
                for(从u出发可达的所有顶点v)
                {
                    // 如果v未曾加入过队列
                    if(inq[v] == false){
                        q.push(v);      // 将v入队；
                        inq[v] = true;  // 设置v已被加入过队列
                    }
                }
            }
        }

        BFSTRave(G)
        {
            for(G的所有顶点u)
            {
                // 如果u未曾加入过队列
                if(inq[u] == false){
                    // 遍历u所在的连通块
                    BFS(u);
                }
            }
        }
    ```

    1. 邻接矩阵版

        ```C++
            int n, G[MAXV][MAXV];   // n为顶点数，MAXV为最大定点数
            bool inq[MAXV][MAXV];   // 记录顶点i是否入过队

            void BFS(int u)
            {
                queue<int> q;
                q.push(u);
                inq[u] = true;
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for(int v = 0; v < n; v++)
                    {
                        if(inq[v] == false && G[u][v] != INF)
                        {
                            q.push(v);
                            inq[v] = true;
                        }
                    }
                }
            }

            void BFSTrave()
            {
                for(int u = 0; u < n; u++)
                {
                    if(inq[u] == false)
                    {
                        BFS(u);
                    }
                }
            }
        ```

    2. 邻接表版

        ```C++
            vector<int> Adj[MAXV];  // 图G,Adj[u]存放从顶点u出发可以到达的所有顶点
            int n;  // n为顶点数，MAXV为最大顶点数
            bool inq[MAXV] = {false};

            void BFS(int u)
            {
                queue<int> q;
                q.push(u);
                inq[u] = true;
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for(int i = 0; i < Adj[u].size(); i++)
                    {
                        int v = Adj[u][i];
                        if(inq[v] == false)
                        {
                            q.push(v);
                            inq[v] = true;
                        }
                    }
                }
            }

            void BFSTrave()
            {
                for(int u = 0; u < n; u++)
                {
                    if(inq[u] == false)
                    {
                        BFS(u);
                    }
                }
            }
        ```

    如果需要存放顶点的层号，可以顶级结点结构体Node：

    ```C++
        struct Node
        {
            int v;      // 顶点编号
            int layer;  // 顶点层号
        };
        // 邻接表为：
        vector<node> Adj[N];
    ```

    则层号传递关系为：

    ```C++
        void BFS(int s)
        {
            queue<Node> q;
            Node start;     // 起始顶点
            start.v = s;    // 起始顶点编号
            start.layer = 0;// 起始顶点层号为0
            q.push(start);
            inq[start.v] = true;
            while(!q.empty())
            {
                Node topNode = q.front();
                q.pop();
                int u = topNode.v;
                for(int i = 0; i < Adj[u].size(); i++)
                {
                    Node next = Adj[u][i];
                    next.layer = topNode.layer + 1;
                    if(inq[next.v] == false)
                    {
                        q.push(next);
                        inq[next.v] = true;
                    }
                }
            }
        }
    ```

## 10.4 最短路径

最短路径是图论中一个很经典的问题：给定图G(V,E)，求一条从起点到终点的路径，使得这条路径上经过的所有边的边权之和最小。

### 10.4.1 Dijkstra算法

Dijkstra算法用来解决单源最短路径问题，即给定图G和起点s，通过算法得到S到达其他每个顶点的最短距离。

Dijkstra算法的策略描述：设置集合S存放已被访问的顶点，然后执行n次下面的两个步骤（n为顶点个数）：

    1. 每次从集合V-S中选择与起点s的最短距离最小的一个顶点（记为u），访问并加入集合S。

    2. 之后，令顶点u为中介点，优化起点s与所有从u能到达的顶点v之间的最短距离。

Dijkstra算法的具体实现：实现过程主要包括集合S的实现、起点s到达顶点Vi的最短距离的实现：

    1. 集合S可以用一个bool型数组vis[]来实现，当vis[i]为true时表示顶点Vi已经被访问；

    2. 令int型数组d[]表示起点s到达顶点Vi的最短距离，初始时除了起点s的d[s]赋值为0，其余顶点都赋为一个极大值。

Dijkstra算法的伪代码实现：

```C++
    // G为图，一般设为全局变量；数组d为源点到达各点的最短路径长度，s为起点
    Dijkstra(G, d[], s)
    {
        初始化;
        for(循环n次)
        {
            u = 使d[u]最小的还未被访问的顶点的标号;
            记u已被访问;
            for(从u出发能到达的所有顶点v)
            {
                if(v未被访问&&以u为中介点使s到顶点v的最短距离d[v]更优)
                {
                    优化d[v];
                }
            }
        }
    }
```

由于图可以使用邻接矩阵或者邻接表来实现，因此也就会有两种写法，但是这两种写法都是以上面的伪代码为基础的，区别主要集中在枚举从u出发能到达的顶点v上面：邻接矩阵需要枚举所有顶点来查看v是否可由u到达；邻接表则可以直接得到u能到达的顶点v。

在写出具体函数之前，需要先定义MAXV为最大顶点数、INF为一个很大的数字：

```C++
    const int MAXV = 1000;          // 最大顶点数
    const int INF = 100000000;  // 设INF为一个很大的数
```

1. 邻接矩阵法：

    适用于点数不大的情况，相对较好写。

    ```C++
        int n, G[MAXV][MAXV];           // n为顶点数，MAXV为最大顶点数
        int d[MAXV];                            // 起点到达各点的最短路径长度
        bool vis[MAXV] = {false};   // 标记数组

        void Dijkstra(int s)            // s为起点
        {
            fill(d, d+MAXV, INF);       // fill函数将整个数组d赋值为INF
            d[s] = 0;                               // 起点s到达自身的距离为0
            for(int i = 0; i < n; i++)
            {
                int u = -1, MIN = INF;      //  u使d[u]最小，MIN存放最小的d[u]
                for(int j = 0; j < n; j++)
                {
                    if(vis[j] == false && d[j] < MIN)
                    {
                        u = j;
                        MIN = d[j];
                    }
                }
                // 找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
                if(u == -1) return;
                vis[u] = true;      // 标记u为己访问
                for(int v = 0; v < n; i++)
                {
                    // 如果v未访问 && u能到达v && 以u为中介点可以使d[v]更优
                    if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
                    {
                        d[v] = d[u] + G[u][v];
                    }
                }
            }
        }
    ```

    从复杂度来看，主要是外层循环O(V)（V就是顶点个数n）与内层循环（寻找最小的d[u]需要O(V)、枚举v需要O(V)）产生的，总复杂度为O(V* (V+V)) = O(V2)。

2. 邻接表版：

    ```C++
        struct Node{
            int v, dis;         // v为边的目标顶点，dis为边权
        };

        vector<Node> Adj[MAXV];     // 图G，Adj[u]存放从顶点u出发可以到达的所有顶点
        int n;                  // n为顶点数，图G使用邻接表实现，MAXV为最大顶点数
        int d[MAXV];    // 起点到达各点的最短路径长度
        bool vis[MAXV] = {false};   // 标记数组

        void Diskstra(int s)
        {
            fill(d, d + MAXV, INF);
            d[s] = 0;           // 起点s到达自身的距离为0
            for(int i = 0; i < n; i++)
            {
                int u = -1, MIN = INF;
                for(int j = 0; j < n; j++)
                {
                    if(vis[j] == false && d[j] < MIN)
                    {
                        u = j;
                        MIN = d[j];
                    }
                }

                // 找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
                if(u == -1) return;
                vis[u] = true;      // 标记u为己访问

                // 只有下述for循环与邻接矩阵版不同
                for(int j = 0; j < Adj[u].size(); j++)
                {
                    int v = Adj[u][j].v;        // 通过邻接表直接获得u能到达的顶点v
                    if(vis[v] == false && d[u] + Adj[u][j].dis < d[v])
                    {
                        d[v] = d[u] + Adj[u][j].dis;
                    }
                }
            }
        }
    ```

    从复杂度来看，主要是外层循环O(V)与内层循环（寻找最小的d[u]需要O(V)、枚举v需要O(adj[u].size)) 产生的。又由于对整个程序来说，枚举v的次数总共为O(adj[u].size求和)= O(E)，因此总复杂度为O(V2 + E)。

Diskstra算法只能应对所有边权都是非负数的情况，如果边权出现负数，那么该算法可能会出错，这是最好适用SPFA算法。

为了在Diskstra算法中记录最短路径本身，可以设置数组pre[ ]，令pre[v]表示从起点s到顶点v的最短路径上v的前一个顶点（即前驱结点）的编号。这样，当优化d[v]的伪代码条件成立时，可以将u赋值给pre[v]，最终就能把最短路径上每一个顶点的前驱结点记录下：

```C++
    if(v未被访问&&以u为中介点使s到顶点v的最短距离d[v]更优)
    {
        优化d[v];
        令v的前驱为u;
    }
```

具体实现中，以邻接矩阵为例：

```C++
    int n, G[MAXV][MAXV];         // n为顶点数，MAXV为最大顶点数
    int d[MAXV];                          // 起点到达各点的最短路径长度
    int pre[MAXV]; // pre[v]表示从起点到顶点v的最短路径上v的前一个顶点
    bool vis[MAXV] = {false};   // 标记数组

    void Dijkstra(int s)            // s为起点
    {
        fill(d, d+MAXV, INF);       // fill函数将整个数组d赋值为INF
        for(int i = 0; i < n; i++) pre[i] = i;  // 初始状态每个点的前驱为自身
        d[s] = 0;                             // 起点s到达自身的距离为0
        for(int i = 0; i < n; i++)
        {
            int u = -1, MIN = INF;   //  u使d[u]最小，MIN存放最小的d[u]
            for(int j = 0; j < n; j++)
            {
                if(vis[j] == false && d[j] < MIN)
                {
                    u = j;
                    MIN = d[j];
                }
            }
            // 找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
            if(u == -1) return;
            vis[u] = true;      // 标记u为己访问
            for(int v = 0; v < n; i++)
            {
                // 如果v未访问 && u能到达v && 以u为中介点可以使d[v]更优
                if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
                {
                    d[v] = d[u] + G[u][v];
                    pre[v] = u;         // 记录v的前驱顶点是u
                }
            }
        }
    }
```

在最短路径的基础上，可能还会出现另一维度的标尺，例如：

1. 给每条边再增加一个边权（如花费），然后要求在最短路径有多条时要求路径上的花费之和最小；

2. 给每个点增加一个点权，然后要求在最短路径有多条时要求路径上的点权之和最大。

3. 直接问有多少条最短路径

对这三种出题方法，都只需要增加一个数组来存放新增的边权或点权或最短路径条数，然后在Dijkstra算法中修改优化d[v]的那个步骤即可，其他部分不需要改动。

1. 新增边权

    ```C++
        for(int v = 0; v < n; v++)
        {
            // 如果v未访问&&u能到达v
            if(vis[v] == false && G[u][v] != INF)
            {
                if(d[u] + G[u][v] < d[v])
                {
                    // 以u为中介点可以使d[v]更优
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                }
                else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v])
                {
                    c[v] = c[u] + cost[u][v];   // 最短距离相同时看能否使c[v]更优
                }
            }
        }
    ```

2. 新增点权

    ```C++
        for(int v = 0; v < n; v++)
        {
            // 如果v未访问&&u能到达v
            if(vis[v] == false && G[u][v] != INF)
            {
                if(d[u] + G[u][v] < d[v])
                {
                    // 以u为中介点可以使d[v]更优
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                }
                else if(d[u] + G[u][v] == d[v] && w[u] + weight[v] > w[v])
                {
                    w[v] = w[u] + weight[v];   // 最短距离相同时看能否使w[v]更优
                }
            }
        }
    ```

3. 求最短路径条数

    ```C++
        for(int v = 0; v < n; v++)
        {
            // 如果v未访问&&u能到达v
            if(vis[v] == false && G[u][v] != INF)
            {
                if(d[u] + G[u][v] < d[v])
                {
                    // 以u为中介点可以使d[v]更优
                    d[v] = d[u] + G[u][v];
                    num[v] = num[u];
                }
                else if(d[u] + G[u][v] == d[v] )
                {
                    num[v] += num[u];   // 最短距离相同时累加num
                }
            }
        }
    ```

这里介绍一种更通用、又模板化的解决此类问题的方式——**Dijkstra + DFS**。

回顾上面只使用Dijkstra算法的思路，会发现，算法中数组pre总是保持着最优路径，而这显然需要在执行Dijkstra算法的过程中使用严谨的思路来确定何时更新每个结点v的前驱结点pre[v]，实在容易出错。事实上更简单的方法是：先在Dijkstra算法中记录下所有最短路径（只考虑距离），然后从这些最短路径中选出一条第二标尺最优的路径（因为在给定一条路径的情况下，针对这条路径的信息都可以通过边权和点权很容易计算出来！）。

1. 使用Dijkstra算法记录所有最短路径。

    ```C++
        vector<int> pre[MAXV];
        void Dijkstra(int s)
        {
            fill(d, d+MAXV, INF);
            d[s] = 0;
            for(int i = 0; i < n; i++)  // 找到最小的d[u]
            {
                int u = -1, MIN = INF;
                if(vis[j] == false && d[j] < MIN)
                {
                    u = j;
                    MIN = d[j];
                }
            }
            if(u == -1) return;
            vis[u] = true;
            for(int v = 0; v < n; v++)
            {
                if(vis[v] == false && G[u][v] != INF)
                {
                    if(d[u] + G[u][v] < d[v])
                    {
                        d[v] = d[u] + G[u][v];
                        pre[v].clear();
                        pre[v].push_back(u);
                    }
                    else if(d[u] + G[u][v] == d[v])
                    {
                        pre[v].push_back(u);
                    }
                }
            }
        }
    ```

2. 遍历所有最短路径， 出一条使第二标尺最优的路径。

    计算第二标尺的最优值，必须要有：

    - 作为全局变量的第二标尺最优值optValue。
    - 记录最优路径的数组path（使用vector来存储）。
    - 临时记录DFS遍历到叶子结点时的路径tempPath（也使用vector存储）。

    ```C++
        int optvalue;           // 第二标尺最优值
        vector<int> pre[MAXV];      // 存放结点的前驱结点
        vector<int> path, tempPath; // 最优路径、临时路径
        void DFS(int v)
        {
            // 递归边界
            if(v == st)
            {
                // 如果到达了叶子结点st （即路径的起点）
                tempPath.push_back(v)
                int value;
                // 计算路径tempPath上的value值
                if(value 优于 optvalue)
                {
                    optvalue = value;
                    path = tempPath;
                }
                tempPath.pop_back();
                return;
            }
            // 递归式
            tempPath.push_back(v);      // 将当前访问结点加入临时路径tempPath的最后面
            for(int i = 0; i < pre[v].size(); i++)
            {
                DFS(pre[v][i]);
            }
            tempPath.pop_back();
        }
    ```

### 10.4.2 Bellman-Ford算法和SPFA算法

Bellman-Ford算法可解决单源最短路径问题，但也能处理有负权边的情况。与Dijkstra算法相同，Bellman-Ford算法设置一个数组d，用来存放从源点到达各个顶点的最短距离。同时Bellman-Ford算法返回一个bool值：如果其中存在从源点可达的负环，那么函数将返回false；否则，函数将返回true，此时数组d中存放的值就是从源点到达各顶点的最短距离。

Bellman-Ford算法的主要思路如下述伪代码所示。

```C++
    for(i = 0; i < n-1; i++)    // 执行n-1轮操作，其中n为顶点数
    {
        for(each eage u->v)     // 每轮操作都遍历所有边
        {
            if(d[u] + length[u->v] < d[v])  // 以u为中介点可以使d[v]更小
            {
                d[v] = d[u] + length[u->v]; // 松弛操作
            }
        }
    }
```

### 10.4.3 Floyd算法

Floyd算法用来解决全源最短路问题，即对给定的图G(V,E)，求任意两点U，V之间的最短路径长度，时间复杂度是O(n3)。由于n3的复杂度决定了顶点数n的限制约在200以内，因此使用邻接矩阵来实现Floyd算法是非常合适且方便的。

```C++
    #include <cstdio>
    #include <string>
    #include <algorithm>
    using namespace std;
    const int MAXV = 200;
    const int INF = 100000000000000;
    int n, m;
    int dis[MAXV][MAXV];        // dis[i][j]表示顶点i和j的最短距离

    void Floyd(){
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
    }

    int main()
    {
        int u, v, w;
        fill(dis[0], dis[0]+MAXV*MAXV, INF);
        scanf_s("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            dis[i][j] = 0;
        }

        for(int i = 0; i < m; i++)
        {
            scnaf_s("%d%d%d", &u, &v, &w);
            dis[u][v] = w;
        }
        Floyd();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                printf("%d", dis[i][j]);
            }
            printf("/n");
        }
    }
```

## 10.5 最小生成树

### 10.5.1 最小生成树及其性质

最小生成树(Minimum Spanning Tree, MST)是在一个给定的无向图G(V,E)中求一棵树T，使得这棵树拥有图G中的所有顶点，且所有边都是来自图G中的边，并且满足整棵树的边权之和最小。

最小生成树有3个性质需要掌握：

- 最小生成树是树，因此其边数等于顶点数减1，且书内一定不会有环。

- 对给定的图G(V,E)，其最小生成树可以不唯一，但其边权之和一定是唯一的。

- 由于最小生成树是在无向图上生成的，因此其根结点可以是这棵树上的任意一个结点。

### 10.5.2 prim算法

Prim算法用来解决最小生成树问题，其基本思想是对图G(V,E)设置集合S，存放已被访问的顶点，然后每次从集合V-S中选择与集合S的最短距离最小的一个顶点（记为u），访问并加入集合S。之后，令顶点u为中介点，优化所有从u能到达的顶点v与集合S之间的最短距离。这样的操作执行n次（n为顶点个数），直到集合S已包含所有顶点 。

prim算法的基本思想是对图G(V, E)设置集合S来存放已被访问的顶点，然后执行n次下面的两个步骤（n为顶点个数）：

1. 每次从集合V-S（即未攻占的城市）中选择与集合S最近的一个顶点（记为u），访问u并将其加入集合S，同时把这条离集合S最近的边加入最小生成树中。

2. 令顶点u作为集合S与集合V-S连接的接口，优化从u能到达的未访问顶点v与集合S的最短距离。

prim算法需要实现两个关键的概念，即集合S的实现、顶点vi(O≤i≤n-1)与集合S的最短距离。

prim算法的伪代码实现：

```C++
    // G为图，一般设成全局变量数；数组d为顶点与集合S的最短距离
    prim(G, d[])
    {
        初始化；
        for(循环n次)
        {
            u = 使d[u]最小的还未被访问的顶点的标号;
            记u已被访问;
            for(从u出发能到达的所有顶点v)
            {
                if(v未被访问&&以u未中介点使得v与集合S的最短距离d[v]更优)
                {
                    将G[u][v]赋值给v与集合S的最短距离d[v];
                }
            }
        }
    }
```

1. 邻接矩阵版实现：

```C++
    int n, G[MAXV][MAXV];   // n为顶点数，MAXV为最大顶点数
    int d[MAXV];                   // 顶点与集合S的最短距离
    bool vis[MAXV] = {false};   // 标记数组

    iniprim()  // 默认0号未初始点，函数返回最小生成树和边权之和
    {
        fill(d, d+MAXV, INF);
        d[0] = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int u = -1, MIN = INF;
            for(int j = 0; j < n; j++)
            {
                if(vis[j] == false && d[j] < MIN)
                {
                    u = j;
                    MIN = d[j];
                }
            }

            // 找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
            if(u == -1) return;
            vis[u] = true;      // 标记u为己访问
            ans += d[u];
            for(int v = 0; v < n; v++)
            {
                // 如果v未访问&&u能到达v&&以u为中介点可以使v离集合S更近
                if(vis[v] == false && G[u][v] != INF && G[u][v] < d[v])
                {
                    d[v] = G[u][v];
                }
            }
        }
        return ans;
    }
```

2. 邻接表版实现：

```C++
    struct Node{
        int v, dis;
    };

    vector<Node> Adj[MAXV];     // 图G，Adj[u]存放从顶点u出发可以到达的所有顶点
    int n;                  // n为顶点数，
    int d[MAXV];
    bool vis[MAXV] = {false};   // 标记数组

    intprim() // 默认0号未初始点，函数返回最小生成树和边权之和
    {
        fill(d, d+MAXV, INF);
        d[0] = 0;
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int u = -1, MIN = INF;
            for(int j = 0; j < n; j++)
            {
                if(vis[j] == false && d[j] < MIN)
                {
                    u = j;
                    MIN = d[j];
                }
            }

            // 找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
            if(u == -1) return;
            vis[u] = true;      // 标记u为己访问
            ans += d[u];

            // 只有下面这个for与邻接矩阵的写法不同
            for(int j= 0; j < Adj[u].size(); j++)
            {
                int v = Adj[u][j].v;
                if(vis[v] == false && Adj[u][j].dis < d[v])
                {
                    d[v] = G[u][v];
                }
            }
        }
        return ans;
    }
```

### 10.5.3 Keusal算法

kruskal算法同样是解决最小生成树问题的一个算法。和prim算法不同，kruskal算法采用了边贪心的策略，其思想极其简洁，理解难度比prim算法要低很多。

kruskal算法的基本思想为：在初始状态时隐去图中的所有边，这样图中每个顶点都自成一个连通块。之后执行下面的步骤：

1. 对所有边按边权从小到大进行排序。

2. 按边权从小到大测试所有边，如果当前测试边所连接的两个顶点不在同一个连通块中，则把这条测试边加入当前最小生成树中；否则，将边舍弃。

3. 执行步骤2，直到最小生成树中的边数等于总顶点数减1或是测试完所有边时结束。而当结束时如果最小生成树的边数小于总顶点数减1，说明该图不连通。

kruskal算法实现伪代码：

```C++
    int kruskal()
    {
        令最小生成树的边权之和为ans、最小生成树的当前边数Num Edge;
        将所有边按边权从小到大排序;
        for(从小到大枚举所有边){
            if(当前测试边的两个端点在不同的连通块中){
                将该测试边加入最小生成树中;
                ans +＝ 测试边的边权;
                最小生成树的当前边数Num Edge加1;
                当边数Num Edge等于顶点数减1时结束循环;
            }
        }
        return ans;
    }
```

并查集可以通过查询两个结点所在集合的根结点是否相同来判断它们是否在同一个集合，而合并功能恰好可以把上面提到的第二个细节解决，即只要把测试边的两个端点所在集合合并，就能达到将边加入最小生成树的效果。

```C++
    struct edge {
        int u, v;   // 边的两个端点编号
        int cost;  // 边权
    }E[MAXE];

    bool cmp(edge a, edge b)
    {
        return a.cost < b.cost;
    }

    int father[N];          // 并查集数组
    int findFther(int x){
        // 并查集查询函数
    }

    // Kruskal数返回最小生成树的边权之和，参数n为顶点个数，m为图的边数
    int kruskal(int n, int m)
    {
        // ans为所求边权之和，Num_Edge为当前生成树的边数
        int ans = 0, Num_Edge = 0;
        for(int i = 1; i <= n; i++)
        {
            // 假设顶点范围是[1, n]
            father[i] = i;  // 并查集初始化
        }
        sort(E, E+m, cmp);      // 所有边权从小到大排序
        for(int i = 0; i < m; i++)
        {
            // 枚举所有便
            int faU = findFther(E[i].u);    // 查询测试边两个端点所在集合的根节点
            int faV = findFather(E[i].v);
            if(faU != faV)
            {
                // 如果不在一个集合中
                father[faU] = faV;      // 合并集合
                ans += E[i].cost;       // 边权之和增加测试边的边权
                Num_Edge++;
                if(Num_Edge == n-1) break;
            }
        }
        if(Num_Edge != n-1) return -1;
        else return ans;
    }
```

可以看到，kruskal算法的时间复杂度主要来源于对边进行排序，因此其时间复杂度是O(ElogE)，其中E为图的边数。显然kruskal适合顶点数较多、边数较少的情况，这和prim算法恰好相反。于是可以根据题目所给的数据范围来选择合适的算法，即如果是稠密图（边多），则用prim算法；如果是稀疏图（边少），则用kruskal算法。

## 10.6 拓扑排序

### 10.6.1 有向无环图

如果一个有向图的任意顶点都无法通过一些有向边回到自身，那么称这个有向图为**有向无环图**(Directed Acyclic Graph, DAG)

### 10.6.2 拓扑排序

拓扑排序是将有向无环图G的所有顶点排成一个线性序列，使得对图G中的任意两个顶点u、v，如果存在边u->v，那么在序列中u一定在v前面。这个序列又被称为**拓扑序列**。

拓扑序列对应到图中，这个可抽象为以下步骤：

1. 定义一个队列Q，并把所有入度为0的结点加入队列；

2. 取队首结点，输出。然后删去所有从它出发的边，并令这些到达的顶点的入度减1，如果某个顶点的入度减为0，则将其加入队列。

3. 反复进行2步骤，直到队列为空。如果队列为空时入过队的结点数目恰好为N，说明拓扑排序成功，图G为有向无环图；否则，拓扑排序失败，图G中有环。

可使用邻接表实现拓扑排序。显然，由于需要记录结点的入度，因此需要额外建立一个数组inDegree[MAXV]，并在程序一开始读入图时就记录好每个结点的入度。接下来就只需要按上面所说的步骤进行实现即可，拓扑排序的代码如下：

```C++
    vector<int> G[MAXV];            // 邻接表
    int n, m, inDegree[MAXV];   // 顶点数，入度
    // 拓扑排序
    bool topologicalSort()
    {
        int num = 0;
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i = 0; i < G[u].size(); i++)
            {
                int v = G[u][v];        // u的后继节点v
                inDegree[v]--;          // 顶点V的入度减1
                if(inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
            G[u].clear();           // 清空顶点u的所有出边
            num++;
        }
        if(num == n) return true;
        else return false;
    }
```

拓扑排序的很重要的应用就是判断一个给定的图是否是有向无环图。正如上面的代码，如果topologicalSort()函数返回true，则说明拓扑排序成功，给定的图是有向无环图；否则，说明拓扑排序失败，给定的图中有环。

最后指出，如果要求有多个入度为0的顶点，选择编号最小的顶点，那么把queue改成priority_queue，并保持队首元素（堆顶元素）是优先队列中最小的元素即可（当然用set也是可以的）。

## 10.7 关键路径

### 10.7.1 AOV网和AOE网

顶点活动(Activity On Vertex, AOV)网是指**用顶点表示活动，而用边集表示活动间优先关系的有向图**。

边活动(Activity On Edge, AOE)网是指用带权的边集表示活动，而**用顶点表示事件的有向图，其中边权表示完成活动需要的时间**。

### 10.7.2 最长路径

对一个没有正环的图（指从源点可达的正环，下同），如果需要求最长路径长度，则可以把所有边的边权乘以-1，令其变为相反数，然后使用Bellman-Fodr算法或SPAF算法求最短路径长度，将所得结果取反即可。

显然，如果图中有正环，那么最长路径是不存在的。但是，如果需要求最长简单路径（也就是每个顶点最多只经过一次的路径），那么虽然最长简单路径本身存在，却没有办法通过Bellman-Fodr等算法来求解，原因是最长路径问题是NP-Hadr问题（也就是没有多项式时间复杂度算法的问题）。

### 10.7.3 关键路径

由于AOE网实际上是有向无环图，而关键路径是图中的最长路径，因此本节实际上给出了一种求解有向无环图(DAG)中最长路径的方法。

