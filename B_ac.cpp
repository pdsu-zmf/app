#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define PII pair<int, int>
#define endl "\n"
#define int long long
const int N = 2e5 + 10, mod =  998244353, D = 13;
int f[N];

int g(char c)
{
    if(c == 'a') return 1;
    else if(c == 'e') return 2;
    else if(c == 'h') return 3;
    else return 4;
}
int dp(string s)
{
    int n = s.size();
    s = " " + s;
    for(int i = 0; i <= n; i++) f[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        int res = 0, t = 1;
        for(int j = i; j >= max(1ll, i - D); j--)
        {
            res = (res + t * g(s[j])) % mod; 
            t = (t * 31) % mod;
            f[i] = max(f[i], f[j - 1] + res % mod); 
        }
    }
    /*for(int i = 1; i <= n; i++)
        cout << f[i] << " ";
    cout << endl;*/
    return f[n];
}


signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();

    int ans = 0;
    for(int i = 0; i < min(n, D); i++)
    {
        string t = s.substr(i) + s.substr(0, i);
        ans = max(ans, dp(t));
    }
    cout << ans << endl;
    
    return 0;
}