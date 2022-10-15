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
    int ans[4];
    int l_x[4], r_x[4];
    int len;
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
    for (int i = 1; i <= 1e5; i ++ )
    {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i) % mod;
    }
}

int C(int a, int b)
{
    return fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void pushup_build(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    for(int i = 0; i < 4; i++)
    {
        root.ans[i] = left.ans[i] + right.ans[i] + (left.r_x[i] >= right.l_x[i]);
        root.l_x[i] = left.l_x[i], root.r_x[i] = right.r_x[i];
    }
}

void pushup(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    root.ans[root.len] = left.ans[left.len] + right.ans[right.len] + (left.r_x[left.len] >= right.l_x[right.len]);
    root.l_x[root.len] = left.l_x[left.len], root.r_x[root.len] = right.r_x[right.len];
}

void build(int u, int l, int r)
{
    if(l == r)
    {
        tr[u] = {l, r, 0, 0, 0 ,0 , a[l], (a[l] + 1) % 4, (a[l] + 2) % 4, (a[l] + 3) % 4, a[l], (a[l] + 1) % 4, (a[l] + 2) % 4, (a[l] + 3) % 4, 0, 0};
        return ;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup_build(u);
}

void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add)
    {
        left.add = (left.add + root.add) % 4, left.len = (left.len + root.add) % 4;
        right.add = (right.add + root.add) % 4, right.len = (right.len + root.add) % 4;
        root.add = 0;
    }
}

void add(int u, int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].len = (tr[u].len + 1) % 4;
        tr[u].add = (tr[u].add + 1) % 4;
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
        return {tr[u].ans[tr[u].len], {tr[u].l_x[tr[u].len], tr[u].r_x[tr[u].len]}};
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
    return {res, {tr[u].l_x[tr[u].len], tr[u].r_x[tr[u].len]}};
}


signed main()
{
    //ios::sync_with_stdio(0);cin.tie(0);
    init();
    cin >> n >> q >> s;
    for(int i = 1; i <= n; i++) a[i] = s[i - 1] - 'A';
    build(1, 1, n);
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
            cout << C(r - l - cnt, k - cnt - 1) << endl;
        }
    }
    return 0;
}