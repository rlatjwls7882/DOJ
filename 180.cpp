#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string s[1000];
int vis[1000][1000][4];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;

    int sx, sy, ex, ey;
    for(int i=0;i<n;i++) {
        cin >> s[i];
        for(int j=0;j<m;j++) {
            if(s[i][j]=='S') sx=i, sy=j;
            else if(s[i][j]=='T') ex=i, ey=j;
        }
    }

    memset(vis, -1, sizeof vis);
    queue<tuple<int, int, int>> q;
    for(int i=0;i<4;i++) {
        q.push({sx, sy, i});
        vis[sx][sy][i]=0;
    }
    while(!q.empty()) {
        auto [x, y, dir]=q.front(); q.pop();
        for(int i=0;i<4;i++) {
            for(int j=1;;j++) {
                int nx=x+dx[i]*j;
                int ny=y+dy[i]*j;
                if(nx<0 || nx>=n || ny<0 || ny>=m || s[nx][ny]=='#' || vis[nx][ny][i]!=-1) break;
                vis[nx][ny][i]=vis[nx][ny][(i+2)%4]=vis[x][y][dir]+1;
                q.push({nx, ny, i});
            }
        }
    }
    int res=INT_MAX;
    for(int i=0;i<4;i++) {
        if(vis[ex][ey][i]!=-1) res = min(res, vis[ex][ey][i]);
    }
    cout << (res==INT_MAX ? -1 : res);
}
