#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int c[300'001], d[300'001], lastC[300'001];
vector<vector<int>> conn(300'001);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> c[i];
    while(m--) {
        int u,v;cin>>u>>v;
        conn[u].push_back(v);
        conn[v].push_back(u);
        d[u]++; d[v]++;
    }

    int g=1;
    vector<int> res(n+1, -1);
    map<int, pii> mm;
    map<pii, int> init;
    for(int i=1;i<=n;i++) {
        if(!init[{c[i], d[i]}]) init[{c[i], d[i]}]=g++;
        c[i]=init[{c[i], d[i]}];
        mm[c[i]].first++;
        mm[c[i]].second^=i;
    }

    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(mm[c[i]].first==1) {
            q.push(i);
            mm.erase(c[i]);
            res[i]=0;
        }
    }
    for(int t=1;!q.empty();t++) {
        map<pii, int> id;
        map<int, int> cur;
        while(!q.empty()) {
            int i=q.front(); q.pop();
            res[i]=t;
            for(int nxt:conn[i]) {
                if(res[nxt]!=-1) continue;
                cur[nxt]++;
            }
        }
        set<int> ss;
        for(auto [i, dd]:cur) {
            lastC[i]=c[i];
            mm[c[i]].first--;
            mm[c[i]].second^=i;
            ss.insert(c[i]);
            d[i]-=dd;
        }
        for(auto [i, dd]:cur) {
            pii key={lastC[i], d[i]};
            if(!id[key]) id[key]=g++;
            c[i]=id[key];
            mm[c[i]].first++;
            mm[c[i]].second^=i;
            ss.insert(c[i]);
        }
        for(int e:ss) {
            if(mm[e].first==1) {
                int i=mm[e].second;
                if(res[i]==-1) {
                    mm.erase(e);
                    q.push(i);
                    res[i]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout << res[i] << ' ';
}
