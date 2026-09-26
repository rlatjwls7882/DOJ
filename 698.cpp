#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

int dist[1001][1001]; // {a, b}
bool vis[1001][1001];
int dx[]={-1,-1,1,0,0,1};
int dy[]={1,0,-1,-1,1,0};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c; cin >> a >> b >> c;
    int n=a+b+c;

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    fill(&dist[0][0], &dist[1001][0], INF);
    dist[n][0]=dist[0][n]=dist[0][0]=0;
    pq.push({0,n,0}); pq.push({0,0,n}); pq.push({0,0,0});
    while(!pq.empty()) {
        auto [co,a,b]=pq.top(); pq.pop();
        if(vis[a][b])continue;
        vis[a][b]=1;
        for(int i=0;i<6;i++) {
            int na=a+dx[i], nb=b+dy[i], nc=n-na-nb;
            if(na<0||nb<0||nc<0||na+nb+nc>n)continue;
            dist[na][nb]=min({dist[na][nb],3*na+4*nb,3*na+4*nc,2*(nb+nc)+abs(nb-nc)});
            if(na) dist[na][nb]=min(dist[na][nb],max(dist[na-1][nb+1],dist[na-1][nb])+1);
            if(nb) dist[na][nb]=min(dist[na][nb],max(dist[na+1][nb-1],dist[na][nb-1])+1);
            if(nc) dist[na][nb]=min(dist[na][nb],max(dist[na+1][nb],dist[na][nb+1])+1);
            pq.push({dist[na][nb],na,nb});
        }
    }
    cout<<dist[a][b];
}
