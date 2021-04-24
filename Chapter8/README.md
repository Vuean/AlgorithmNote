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
