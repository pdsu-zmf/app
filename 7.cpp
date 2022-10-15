#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
string s[N];
int n, m;
int q;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        bool flag = 0;
        for(int j = 1; j <= n; j++)
        {
            if(s[j][i] == '0')flag = 1;
        }
        if(!flag) ans++;
    }
    cin >> q;
    while(q--)
    {
        int i, j, l, r, p;
        cin >> i >> j >> l >> r >> p;
    }
    cout << ans << endl;
    return 0;
}