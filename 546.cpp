#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool vis[200'000];
ll a[200'000], dp[200'000][2], res[30];
vector<vector<pair<ll, ll>>> conn(200'000);

ll dfs(int cur, int bit) {
    vis[cur]=true;
    ll ret=0, r1=0, r2=0;
    for(auto [nxt, nw]:conn[cur]) {
        if(!vis[nxt]) {
            ret=max(ret, dfs(nxt, bit));
            ll t1=dp[nxt][0], t2=dp[nxt][1];
            if(dp[nxt][0] || a[nxt] && !(a[nxt]&(1<<bit))) dp[cur][0]=max(dp[cur][0], dp[nxt][0]+nw), t1+=nw;
            if(dp[nxt][1] || a[nxt] && (a[nxt]&(1<<bit))) dp[cur][1]=max(dp[cur][1], dp[nxt][1]+nw), t2+=nw;
            if(a[cur] && a[cur]&(1<<bit)) ret=max(ret, t1);
            else if(a[cur]) ret=max(ret, t2);
            if(r1 && t2) ret=max(ret, r1+t2);
            if(r2 && t1) ret=max(ret, r2+t1);
            r1=max(r1,t1);
            r2=max(r2,t2);
        }
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n-1;i++) {
        int u, v, w; cin >> u >> v >> w;
        conn[u-1].push_back({v-1, w});
        conn[v-1].push_back({u-1, w});
    }
    for(int i=0;i<30;i++) {
        memset(vis, 0, sizeof vis);
        memset(dp, 0, sizeof dp);
        res[i]=dfs(0, i);
    }

    while(q--) {
        int w; cin >> w;
        ll r=-1;
        for(int i=0;i<30;i++) {
            if(w&(1<<i) && res[i]) {
                r=max(r, res[i]);
            }
        }
        cout << r << '\n';
    }
}
