#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define PII pair<int, int>
#define endl "\n"
#define int long long

const int N = 1e5 + 10, mod =  998244353;
struct Node
{
    int l, r;
    int ans;
    int l_x, r_x;
    int add;
}tr[N * 4];
int fact[N], infact[N];
int n, q, a[N];
string s;

int qmi(int a, int b = mod - 2)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ )
    {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i) % mod;
    }
}

int C(int a, int b)
{
    return fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void pushup(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    root.ans = left.ans + right.ans + (left.r_x >= right.l_x);
    root.l_x = left.l_x, root.r_x = right.r_x;
}

void build(int u, int l, int r)
{
    if(l == r)
    {
        tr[u] = {l, r, 0, a[l], a[l]};
        return ;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add)
    {
        if(left.l_x + root.add >= 4) left.ans--;
        if(left.r_x + root.add >= 4) left.ans++;
        left.add = (left.add + root.add) % 4, left.l_x = (left.l_x + root.add) % 4, left.r_x = (left.r_x + root.add) % 4;

        if(right.l_x + root.add >= 4) right.ans--;
        if(right.r_x + root.add >= 4) right.ans++;
        right.add = (right.add + root.add) % 4, right.l_x = (right.l_x + root.add) % 4, right.r_x = (right.r_x + root.add) % 4;

        root.add = 0;
    }
}

void add(int u, int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].ans = tr[u].ans - (tr[u].l_x == 3) + (tr[u].r_x == 3);
        tr[u].l_x = (tr[u].l_x + 1) % 4;
        tr[u].r_x = (tr[u].r_x + 1) % 4;
        tr[u].add = (tr[u].add + 1 ) % 4;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) add(u << 1, l, r); 
        if(r > mid) add(u << 1 | 1, l, r);
        pushup(u);
    }
}

pair<int, PII> query(int u, int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        return {tr[u].ans, {tr[u].l_x, tr[u].r_x}};
    }
    pushdown(u);
    int res = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    int ll = -1, rr = 4;
    if(l <= mid) 
    {
        auto t = query(u << 1, l, r);
        res += t.first;
        ll = t.second.second;
    }
    if(r > mid) 
    {
        auto t = query(u << 1 | 1, l, r);
        res += t.first;
        rr = t.second.first;
    }
    if(ll >= rr) res++;
    return {res, {tr[u].l_x, tr[u].r_x}};
}


signed main()
{
    init();
    cin >> n >> q >> s;
    for(int i = 1; i <= n; i++) a[i] = s[i - 1] - 'A';
    build(1, 1, n);
    /*for(int i = 1; i <= n * 2; i++)
        printf("[%lld, %lld], %lld, %lld, %lld\n", tr[i].l, tr[i].r, tr[i].ans, tr[i].l_x, tr[i].r_x);*/
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int l, r;
            cin >> l >> r;
            add(1, l, r);
        }
        else if(op == 2)
        {
            int l, r, k;
            cin >> l >> r >> k;
            int cnt = query(1, l, r).first;
            //cout << cnt << endl;
            cout << C(r - cnt - l, k - cnt - 1) << endl;
        }
        /*for(int i = 1; i <= n * 2; i++)
            printf("[%lld, %lld], %lld, %lld, %lld\n", tr[i].l, tr[i].r, tr[i].ans, tr[i].l_x, tr[i].r_x);*/
    }
    return 0;
}
/*
5 2
BACDA
1 2 3
2 1 5 4



10 10        
ABCBDCABBA
1 1 4
2 1 10 10
1 2 5    
2 1 10 10 
1 3 6 
2 1 10 10
*/