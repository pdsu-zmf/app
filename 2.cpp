#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define PII pair<int, int>
#define endl "\n"
#define int long long

const int N = 2e5 + 10, mod =  998244353;
int f[N]; // f[i]表示分割到i的最大Hash值
//最长字串是单位为6    因为31^6 = 887,503,681
//此题不取模  因为答案最大为 998244353 * (2e5 / 6)    1e14左右   直接longlong就可 
int g(char c)
{
    if(c == 'a') return 1;
    if(c == 'e') return 2;
    if(c == 'h') return 3;
    if(c == 'n') return 4;
}
signed main()
{
    string s;
    cin >> s;
    int n  = s.size();
    s = " " + s + s;//因为是循环串所以复制两次
    for(int i = 1; i <= n * 2; i++)
    {
        int res = 0, t = 1;
        for(int j = i; j >= /*max(1ll, i - 5)*/1; j--)
        {
            res = res + g(s[j]) * t;
            if(res >= mod) continue;//超过变小了
            t *= 31;
            f[i] = max(f[i], f[j - 1] + res);
        }
    }
    int ans = 0;
    for(int i = n; i <= 2 * n; i++)
    {
        //cout << f[i] - f[i - n] << " ";
        ans = max(ans, f[i] - f[i - n]);
    }
    //cout << endl;
    cout << ans << endl;

    return 0;
}