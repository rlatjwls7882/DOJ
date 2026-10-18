#include<bits/stdc++.h>
using namespace std;

int idx, res[200'000], vis[100'001];
vector<vector<pair<int, int>>> conn(200'001);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        conn[u].push_back({v, i});
        conn[v].push_back({u, i});
    }

    queue<int> q; q.push(1);
    while(!q.empty()) {
        int cur=q.front(); q.pop();
        for(auto [nxt, i]:conn[cur]) {
            if(!res[i]) {
                res[i]=++idx;
                if(!vis[nxt]) {
                    q.push(nxt);
                    vis[nxt]=1;
                }
            }
        }
    }
    for(int i=0;i<m;i++) cout << res[i] << ' ';
}
