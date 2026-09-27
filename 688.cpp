#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int vis[50][50][5040];
string s[50];
int dx[]={0,0,1,-1,0};
int dy[]={1,-1,0,0,0};
tuple<int,int,int,int,int,int> can[50][50];

pair<int,int> pos(auto e,int t) {
    auto [x1,y1,x2,y2,p,d]=e;
    t=(p+t)%(2*d);
    t=min(t,2*d-t);
    return {x1+(x2>x1?t:x2<x1?-t:0), y1+(y2>y1?t:y2<y1?-t:0)};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<k;i++) {
        int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
        a--;b--;c--;d--;
        if(a!=c)for(int i=min(a,c);i<=max(a,c);i++)can[i][b]={a,b,c,d,e,abs(a-c)+abs(b-d)};
        else for(int i=min(b,d);i<=max(b,d);i++)can[a][i]={a,b,c,d,e,abs(a-c)+abs(b-d)};
    }

    memset(vis,-1,sizeof vis);
    vis[0][0][0]=0;
    queue<tuple<int,int,int>> q; q.push({0,0,0});
    while(!q.empty()) {
        auto [x,y,t]=q.front(); q.pop();
        for(int i=0;i<5;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nt=(t+1)%5040;
            if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny][nt]!=-1||s[nx][ny]=='1') continue;
            if(get<5>(can[nx][ny])) {
                auto a=pos(can[nx][ny],t);
                auto b=pos(can[nx][ny],nt);
                if(b==make_pair(nx,ny)||a==make_pair(nx,ny)&&b==make_pair(x,y)) continue;
            }
            vis[nx][ny][nt]=vis[x][y][t]+1;
            q.push({nx,ny,nt});
        }
    }
    int r=INT_MAX;
    for(int i=0;i<5040;i++)if(vis[n-1][m-1][i]!=-1)r=min(r,vis[n-1][m-1][i]);
    cout<<(r==INT_MAX?-1:r);
}
