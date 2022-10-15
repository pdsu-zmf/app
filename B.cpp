#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define PII pair<int, int>
#define endl "\n"
#define int long long

const int N = 4e5 + 10, mod =  998244353, D = 16;
int f[N]; // f[i]表示分割到i的最大Hash值
//最长字串是单位为6    因为31^6 = 887,503,681
//此题不取模  因为答案最大为 998244353 * (2e5 / 6)    1e14左右   直接longlong就可 
int g(char c)
{
    if(c == 'a') return 1;
    if(c == 'e') return 2;
    if(c == 'h') return 3;
    if(c == 'n') return 4;
    return 0;
}
int solve(string s)
{
    int n  = s.size();
    s = " " + s;
    for(int i = 1; i <= n; i++)
    {
        f[i] = 0;
        int res = 0, t = 1;
        for(int j = i - 1; j >= max(0ll, i - D); j--) //最多循环7次
        {
            res = res + g(s[j + 1]) * t;
            t *= 31;
            f[i] = max(f[i], (f[j] + res) % mod);
        }
    }
    return f[n];
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    string l, r;
    int ans = 0;
    for(int i = 0; i < min(D, n); i++)
    {
        r = s.substr(i, n);
        ans = max(ans, solve(r + l));
        l += s[i];
    }
    cout << ans % mod << endl;
    return 0;
}