#include<bits/stdc++.h>
using namespace std;

bool vis[200'001];
vector<vector<int>> conn(200'001);

int dfs(int cur, int last=-1) { // len
    int len=1;
    for(int nxt:conn[cur]) if(nxt!=last) len=max(len, dfs(nxt, cur)+1);
    return len;
}

pair<int, int> bfs(int cur) { // sz, far node
    queue<int> q; q.push(cur);
    vis[cur]=true;
    int sz=0;
    while(!q.empty()) {
        cur=q.front(); q.pop();
        sz++;
        for(int nxt:conn[cur]) {
            if(!vis[nxt]) {
                vis[nxt]=true;
                q.push(nxt);
            }
        }
    }
    return {sz, cur};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            auto [sz, far]=bfs(i);
            int len=dfs(far);
            cnt+=(sz+len-1)/len;
        }
    }
    cout << cnt;
}
