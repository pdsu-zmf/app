#include<bits/stdc++.h>
using namespace std;

int n;
string s;
//1-5   6-12 13-17
//5     7    5
/*

*/
int main()
{
    cin >> n >> s;
    int x = -1, l = 1e9;
    for(int j = 0; j < 26; j++)
    {
        char c = 'a' + j;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == c)
            {
                cnt++;
                if(cnt == 5)
                {
                    if(l > i)
                    {
                        l = i;
                        x = j;
                        break;
                    }
                }
            }
        }
    }
    if(l == 1e9)
    {
        cout << "none" << endl;
        return 0;
    }
    int xx = -1, ll = 1e9;
    for(int j = 0; j < 26; j++)
    {
        char c = 'a' + j;
        int cnt = 0;
        for(int i = l + 1; i < n; i++)
        {
            if(s[i] == c)
            {
                cnt++;
                if(cnt == 7)
                {
                    if(ll > i)
                    {
                        ll = i;
                        xx = j;
                        break;
                    }
                }
            }
        }
    }
    if(ll == 1e9)
    {
        cout << "none" << endl;
        return 0;
    }
    int xxx = -1, lll = 1e9;
    for(int j = 0; j < 26; j++)
    {
        char c = 'a' + j;
        int cnt = 0;
        for(int i = ll + 1; i < n; i++)
        {
            if(s[i] == c)
            {
                cnt++;
                if(cnt == 5)
                {
                    if(lll > i)
                    {
                        lll = i;
                        xxx = j;
                        break;
                    }
                }
            }
        }
    }
    if(lll == 1e9)
    {
        cout << "none" << endl;
        return 0;
    }
    for(int i = 1; i <= 5; i++) cout <<char('a' + x);
    for(int i = 1; i <= 7; i++) cout <<char('a' + xx);
    for(int i = 1; i <= 5; i++) cout <<char('a' + xxx);
    return 0;
}