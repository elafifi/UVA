/**
* Author   : Ahmed Elafifi
* date     : 3/9/2018
* category : BFS
*/

#include <bits/stdc++.h>

using namespace std;
int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};
bool vis[10][10];
pair<int,int>ss,dd;
bool valid(int x, int y) {
    return x>=0 && x<8 && y>=0 && y<8;
}
int BFS()
{
    memset(vis,0,sizeof vis);
    queue<pair<int,int>>q;
    q.push(ss);
    vis[ss.first][ss.second] = 1;
    int sz = 0,dep = 0;
    if(ss == dd)
        return dep;
    for(;!q.empty();dep++,sz = q.size()){
        while(sz--)
        {
            int xx = q.front().first,yy = q.front().second;
            q.pop();

            for(int i = 0;i<8;i++)
            {
                int nx = xx+dx[i],ny = yy + dy[i];
                if(valid(nx,ny)&&(!vis[nx][ny]))
                {
                    vis[nx][ny] = 1;
                    if(nx == dd.first && ny == dd.second)
                        return dep;
                    q.push({nx,ny});
                }
            }

        }

    }
}
string s,d;
int main()
{
    while(cin>>s>>d) {
        ss = {s[1] - '1',s[0] - 'a'};
        dd = {d[1] - '1',d[0] - 'a'};
        printf("To get from %s to %s takes %d knight moves.\n", s.c_str(), d.c_str(), BFS());
    }
    return 0;
}
