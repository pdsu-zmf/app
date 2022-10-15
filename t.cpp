#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> q[N];
int w[N];
int p[N];
int fa[N];//F[I]表示i的父节点
int ans[N];
int a[N];
int qsize[N];
int dfs_init(int u, int father)
{
    int res = 1;
    fa[u] = father;
    for(auto j : q[u])
    {
        if(j == father) continue;
        int t = dfs_init(j, u);
        res += t;
        if(u == p[0]) ans[0] = max(ans[0], t);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
        p[w[i]] = i;
    }
    for(int i = 2; i <= n; i++)
    {
        int fa;
        cin >> fa;
        q[fa].push_back(i);
        q[i].push_back(fa);
    }
    dfs_init(p[0], -1);//以权值为0的节点建树
    ans[n] = n;

    for(int i = n - 1; i > 0; i--)
    {
        int j = p[i];//权值为i的节点编号
        if(q[j].size() - qsize[j] == 1)
        {
            ans[i] = n - a[j] - 1;
        }
        else ans[i] = 0;
        //合并节点
        int father = fa[j];
        if(q[j].size() - qsize[j] == 1)
        {
            a[father] +=  a[j] + 1;
            qsize[father]++;//删除了几个边
        }
        else
        {
            for(auto k : q[j])//子节点
            {
                if(w[k] > w[j] || k == father)continue;
                q[father].push_back(k);
                fa[k] = father;
            }
            a[father] ++;
        }
    }
    for(int i = 0; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
/*
10
9 8 7 6 5 4 0 1 2 3
1 1 2 2 3 3 4 4 5

*/