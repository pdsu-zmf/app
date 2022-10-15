#include<bits/stdc++.h>
using namespace std;

int n;
int main()
{
    cin >> n;
    if(n == 2 || n== 4) cout << -1 ;
    else if(n % 2 == 0)
    {
        cout << n / 2 << endl;
        cout << 0 << " ";
        for(int i = 2; i <= n / 2; i++) cout << i << " ";
    }
    else
    {
        cout << n / 2 + 1 << endl;
        cout << 0 << " ";
        for(int i = 1; i <= n / 2; i++) cout << i << " ";
    }
    return 0;
}