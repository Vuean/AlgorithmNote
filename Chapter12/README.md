# 第十二章 提高篇(6) ——字符串专题

## 12.1 字符串hash进阶

字符串hash是指将一个字符串S映射为一个整数，使得该整数可以尽可能唯一地代表字符串S。通常做法，对只有大写字母的字符串，它将字符串当作二十六进制的数，然后将其转换为十进制，也就是下式：`H[i] = H[i-1]*26+index(str[i])`。这样，当i取遍0~len-1之后，得到的H[len-1]就是整个字符串的hash值。

但是上述会存在的问题就是，当字符串长度较长时，产生的整数会非常大，没办法用一般的数据类型保存。为了应对这种情况，只能舍弃一些“唯一性”，将产生的结果对一个整数mod取模，也就是使用下面的散列函数：`H[i] = (H[i-1]*26+index(str[i]))%mod`。

通过这种方式把字符串转换成范围上能接受的整数。但这又会产生另外的问题，也就是可能有多个字符串的hash值相同，导致冲突。不过幸运的是，在实践中发现，在int数据范围内，如果把进制数设置为一个10^7级别的素数p(例如10000019)，同时把mod设置为一个10^9级别的素数(例如1000000007)，如下所示，那么冲突的概率将会变得非常小，很难产生冲突：`H[i] = (H[i-1]*p+index(str[i]))%mod`。

针对问题：“给出N个只有小写字母的字符串，求其中不同的字符串的个数”。

对这个问题，如果只用字符串hash来做，那么只需要将N个字符串使用字符串hash函数转换为N个整数，然后将它们排序去重即可，代码如下（当然也可以用set或者map直接一步实现，但是速度比字符串hash会慢一点点）：

```C++
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    using namespace std;

    const int MOD = 1000000007;
    const int P = 10000019;
    vector<int> ans;

    // 字符串hash
    long long hashFunc(string str)
    {
        long long H = 0;
        for(int i = 0; i < str.length(); i++)
        {
            H = (H * P + str[i]- 'a') % MOD;
        }
        return H;
    }

    int main()
    {
        string str;
        while(getline(cin, str), str != "#")    // 输入str直到#时停止
        {
            long long id = hashFunc(str);
            ans.push_back(id);
        }

        sort(ans.begin(), ans.end());
        int count = 0;
        for(int i = 0; i < ans.size(); i++)
        {
            if(i == 0 || ans ans[i] != ans[i-1])
            {
                count++;
            }
        }
        cout << count << endl;
    }
```

接着考虑求解字符串的子串的hash值，也就是求解H[i...j]。为了讨论问题方便，暂时去掉求解H[i]时对mod的取模操作，于是散列函数如下所示：`H[i]=H[i-1]*p+index(str[i])`。

通过分析可得到子串str[i...j]的hash值：`H[i...j]=H[j]-H[i-1]*p^(j-1+1)`，以及取模操作后的结果：`H[i...j] = (H[j]-H[i-1]*p^(j-1+1))%mod`。

由于括号内部可能小于0，因此为了使结果非负，需要先对结果取模，然后加上mod后再次取模，以得到正确的结果：`H[i...j] = ((H[j]-H[i-1]*p^(j-1+1))%mod+mod)%mod`。

然后来看一个问题：输入两个长度均不超过1000的字符串，求它们的最长公共子串的长度。

对这个问题，可以先分别对两个字符串的每个子串求出hash值（同时记录对应的长度），然后找出两堆子串对应的hash值中相等的那些，便可以找到最大长度，时间复杂度为O(n^2+m^2)，其中n和m分别为两个字符串的长度。代码如下：

```C++
    #include <iostream>
    #include <cstdio>
    #include <string>
    #include <vector>
    #include <map>
    #include <algorithm>
    using namespace std;
    typedef long long LL;
    const LL MOD = 1000000007;
    const LL P = 10000019;
    const LL MAXN = 1010;       // MAXN 为字符串最长长度

    // powP[i]存放P^i%MOD，H1和H2分别存放str1和str2的hash值
    LL powP[MAXN], H1[MAXN] = {0}, H2[MAXN] = {0};
    // pr1存放str1的所有<子串hash值，子串长度>，pr2同理
    vector<pair<int, int>> pr1, pr2;
    
    // init函数初始化powP函数
    void init(int len)
    {
        powP[0] = 1;
        for(int i = 1; i <= len; i++)
        {
            powP[i] = (powP[i-1] * P) % MOD;
        }
    }

    // calH函数计算字符串str的hash值
    void calH(LL H[], string& str)
    {
        H[0] = str[0];
        for(int i = 1; i < str.length(); i++)
        {
            H[i] = (H[i-1] * P + str[i]) % MOD;
        }
    }

    // calSingleSubH计算H[i...j]
    int calSingleSubH(LL H[], int i, int j)
    {
        if(i == 0) return H[j];
        return ((H[j] - H[i-1]*powP[j - i + 1]) % MOD + MOD) % MOD;
    }

    // calSubH计算所有子串的hash值，并将＜子串hash值， 子串长度＞存入pr
    void calSubH(LL H[], int len, vector<pair<int, int>>& pr)
    {
        for(int i = 0; i < len; i++)
        {
            for(int j = i; j < len; j++)
            {
                int hashValue = calSingleSubH(H, i, j);
                pr.push_back(make_pair(hashValue, j-i+1));
            }
        }
    }

    // 计算pr1和pr2中相同的hash值，维护最大长度
    int getMax()
    {
        int ans = 0;
        for(int i = 0; i < pr1.size(); i++)
        {
            for(int j = 0; j < pr2.size(); j++)
            {
                if(pr1[i].first == pr2[j].first)
                {
                    ans = max(ans, pr1[i].second);
                }
            }
        }
        return ans;
    }

    int main()
    {
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);
        init(max(str1.length(), str2.length()));
        calH(H1, str1);
        calH(H2, str2);
        calSubH(H1, str1.length(), pr1);
        calSubH(H2, str2.length(), pr2);
        printf("ans = %d\n", getMax());
    }
```

再考虑解决最长回文子串，这里将用字符串hash + 二分的思路去解决它，时间复杂度为O(nlogn)，其中n为字符串的长度。

## 12.2 KMP算法

本节主要讨论字符串的匹配问题，也就是说，如果给出两个字符串text和pattern，需要判断字符串pattern是否是字符串text的子串。一般把字符串text称为**文本串**，而把字符串pattern称为**模式串**。

暴力的解法非常简单，只要枚举文本串的起始位置i，然后从该位开始逐位与模式串进行匹配，如果匹配过程中每一位都相同，则匹配成功；否则，只要出现某位不同，就让文本串的起始位置变为计1，并从头开始模式串的匹配。这种做法的时间复杂度为O(nm)，其中n和m分别是文本串与模式串的长度。显然，当n和m都达到10^5级别的时候完全无法承受。

而通过KMP算法，时间复杂度为O(n+m)。

### 12.2.1 next数组

假设有一个字符串s（下标从0开始），那么它以i号位作为结尾的子串就是s[O...i]。对该子串来说，长度为k+1的前缀和后缀分别是s[O...k]与s[i-k...i]。现在定义一个int型数组next（请先不要在意名字），其中next[i]表示使子串s[O...i]的前缀s[O...k]等于后缀s[i-k...i]的最大的k（注意前缀跟后缀可以部分重叠，但不能是s[O...i]本身）；如果找不到相等的前后缀，那么就令next[i] = -1。显然，**next[i]就是子串s[0...i]最长相等前后缀中前缀最后一位的下标**。

next数组求解过程：

1. 初始化next数组，令j=next[0] = -1；

2. 让i在1~len-1范围遍历，对每个i执行步骤3和步骤4，以求解next[i]；

3. 不断令j=next[j]，直到j回退为-1，或是s[i] = s[j+1]成立；

4. 如果s[i] == s[j+1]，则next[i] = j+1，否则next[i] = j。

```C++
    // getNext求解长度为len的字符串s的next数组
    void getNext(char s[], int len)
    {
        int j = -1;
        next[0] = -1;       // 初始化j = next[0] = -1
        for(int i = 1; i < len; i++)
        {
            while(j != -1 && s[i] != s[j+1])
            {
                j = next[j];    // 反复令j = next[j]
            }   // 直到j回退到-1，或者s[i] == s[j+1]

            if(s[i] == s[j+1])
            {
                j++;        // next[i] = j+1，先令j指向这个位置
            }
            next[i] = j;
        }
    }
```

### 12.2.2 KMP算法



