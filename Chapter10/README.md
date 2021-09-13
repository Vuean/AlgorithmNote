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
