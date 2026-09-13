#include<bits/stdc++.h>
using namespace std;

int dist[1001][1001][2];
int ddx[] = {0, 0, 1, -1};
int ddy[] = {1, -1, 0, 0};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, sx, sy, ex, ey, dx, dy, a, b, c; cin >> n >> m >> sx >> sy >> ex >> ey >> dx >> dy >> a >> b >> c;
    memset(dist, -1, sizeof dist);
    queue<tuple<int, int, int>> q; q.push({sx, sy, 0});
    dist[sx][sy][0]=0;
    while(!q.empty()) {
        auto [x, y, cc]=q.front(); q.pop();
        for(int i=0;i<2;i++) {
            int nx=x+ddx[i]*a;
            int ny=y+ddy[i]*a;
            int nc=cc|(nx==dx && ny==dy);
            if(nx<=0 || nx>n || ny<=0 || ny>m || dist[nx][ny][nc]!=-1) continue;
            dist[nx][ny][nc]=dist[x][y][cc]+1;
            q.push({nx, ny, nc});
        }
        for(int i=2;i<4;i++) {
            int nx=x+ddx[i]*b;
            int ny=y+ddy[i]*b;
            int nc=cc|(nx==dx && ny==dy);
            if(nx<=0 || nx>n || ny<=0 || ny>m || dist[nx][ny][nc]!=-1) continue;
            dist[nx][ny][nc]=dist[x][y][cc]+1;
            q.push({nx, ny, nc});
        }
        if(cc) {
            for(int i=0;i<4;i++) {
                int nx=x+ddx[i]*c;
                int ny=y+ddy[i]*c;
                int nc=cc|(nx==dx && ny==dy);
                if(nx<=0 || nx>n || ny<=0 || ny>m || dist[nx][ny][nc]!=-1) continue;
                dist[nx][ny][nc]=dist[x][y][cc]+1;
                q.push({nx, ny, nc});
            }
        }
    }
    if(dist[ex][ey][0]==-1) cout << dist[ex][ey][1];
    else if(dist[ex][ey][1]==-1) cout << dist[ex][ey][0];
    else cout << min(dist[ex][ey][0], dist[ex][ey][1]);
}
