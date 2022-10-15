#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
string s[4];
int d[4][2] = {{0, 1}, {1, 0},{0, -1},{-1, 0}};//右下左上   0123
int dd[4][2] = {{0, -1}, {-1, 0}, {0, 1},{1, 0}};
int m, dx, dy, _x, _y;
bool st;
bool vis[4][N];
void dfs(int x, int y, int fx, bool flag)//flag代表是否选择过向左或向右走  fx表示方向
{
    //cout << x << " " << y << " " << flag << endl; 
    if(st) return ;
    vis[x][y] = 1;
    if(y < 1 || y  > m) return ;
    if(x == 0) return ;
    if(x == 3)
    {
        if(y == dy)
            st = 1;
        return ;
    }
    if(s[x][y] == 'I')
    {
        _x = x + d[fx][0], _y = y + d[fx][1];
        if(!vis[_x][_y]) dfs(_x, _y, fx, flag);
    }
    else
    {
        if(fx == 2 || fx == 0)  //左右进来  往上下走
        {
            _x = x + d[1][0], _y = y + d[1][1];
            if(!vis[_x][_y]) dfs(_x, _y, 1, flag);
            _x = x + d[3][0], _y = y + d[3][1];
            if(!vis[_x][_y]) dfs(_x, _y, 3, flag);
        }
        else  //上下进来  往左右走
        {
            if(!flag)
            {
                _x = x + d[0][0], _y = y + d[0][1];
                if(!vis[_x][_y]) dfs(_x, _y, 0, 1);
                _x = x + d[2][0], _y = y + d[2][1];
                if(!vis[_x][_y]) dfs(_x, _y, 2, 1);
            }
            else
            {
                if(y < dy)//往右
                {
                    _x = x + d[0][0], _y = y + d[0][1];
                    if(!vis[_x][_y]) dfs(_x, _y, 0, 1);
                }
                else
                {
                    _x = x + d[2][0], _y = y + d[2][1];
                    if(!vis[_x][_y]) dfs(_x, _y, 2, 1);
                }
            }
        }
    }
}
void dfs1(int x, int y, int fx, bool flag)//flag代表是否选择过向左或向右走  fx表示方向
{
    //cout << x << " " << y << " " << flag << endl;
    if(st) return ;
    vis[x][y] = 1;
    if(y < 1 || y  > m) return ;
    if(x == 0) return ;
    if(x == 3)
    {
        if(y == dy)
            st = 1;
        return ;
    }
    if(s[x][y] == 'I')
    {
        _x = x + dd[fx][0], _y = y + dd[fx][1];
        if(!vis[_x][_y]) dfs1(_x, _y, fx, flag);
    }
    else
    {
        if(fx == 2 || fx == 0)  //左右进来  往上下走
        {
            _x = x + dd[1][0], _y = y + dd[1][1];
            if(!vis[_x][_y]) dfs1(_x, _y, 1, flag);
            _x = x + dd[3][0], _y = y + dd[3][1];
            if(!vis[_x][_y]) dfs1(_x, _y, 3, flag);
        }
        else  //上下进来  往左右走
        {
            if(!flag)
            {
                _x = x + dd[0][0], _y = y + dd[0][1];
                if(!vis[_x][_y]) dfs1(_x, _y, 0, 1);
                _x = x + dd[2][0], _y = y + dd[2][1];
                if(!vis[_x][_y]) dfs1(_x, _y, 2, 1);
            }
            else
            {
                if(y < dy)//往右
                {
                    _x = x + dd[2][0], _y = y + dd[2][1];
                    if(!vis[_x][_y]) dfs1(_x, _y, 2, 1);
                }
                else
                {
                    _x = x + dd[0][0], _y = y + dd[0][1];
                    if(!vis[_x][_y]) dfs1(_x, _y, 0, 1);
                }
            }
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        st = 0;
        cin >> m >> dx >> dy;
        //起点是 0 dx ,终点是 3 dy
        /*for(int i = 1; i <= 2; i ++)
        {
            for(int j = 1; j <= m; j++)
            {
                s[i][j]='L';
            }
        }*/
        for(int i = 1; i <= 2 ; i++)
        {
            cin >> s[i];
            s[i] = " " + s[i];
        }
        dfs(1, dx, 1, 0);
        for(int i = 1; i <= m ; i++)
        {
            vis[0][i] = vis[1][i] = vis[2][i] = vis[3][i] = 0;
        }
        dfs1(1, dx, 1, 0);
        if(st) cout << "YES" << endl;
        else cout << "NO" << endl;
        for(int i = 1; i <= m ; i++)
        {
            vis[0][i] = vis[1][i] = vis[2][i] = vis[3][i] = 0;
        }
    }
    return 0;
}

/*
1
12 1 12
ILIIIILLLIII
LLLLIILLLIIL


1 
8 6 1
LLIIILIL
ILIIIIIL 

1 
8 3 8
LILIIILL
LIIIIILI
*/