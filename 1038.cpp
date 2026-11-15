#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

pii pos[10000];
bool vis[100][100];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        int a;cin>>a;
        pos[a]={i,j};
    }

    int cur=0;
    deque<pii> q;q.push_back(pos[0]);
    while(!q.empty()){
        auto [x,y]=q.front();
        if(pos[cur]==make_pair(x,y)){
            if(vis[x][y]||cur>=n*n)return !(cout<<cur-1);
            cur++;
        }else{
            vis[q.back().first][q.back().second]=0;
            q.pop_back();
        }
        if(vis[x][y]||cur>=n*n)return !(cout<<cur-1);
        vis[x][y]=1;

        if(pos[cur].second<y){
            q.push_front({x,y-1});
        } else if(pos[cur].second>y){
            q.push_front({x,y+1});
        } else if(pos[cur].first<x){
            q.push_front({x-1,y});
        } else{
            q.push_front({x+1,y});
        }
    }
    cout<<cur-1;
}
