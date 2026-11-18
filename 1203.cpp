#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct element {
    ll u, v, w;
    bool operator<(const element& e) const {
        return w<e.w;
    }
    bool operator>(const element& e) const {
        return w>e.w;
    }
};

int par[200'001];

int find(int x) {
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}

bool merge(int x, int y) {
    x=find(x);
    y=find(y);
    if(x==y) return false;
    if(x<y) par[y]=x;
    else par[x]=y;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    if(n==1) {
        cout << "0\n";
        return 0;
    }
    for(int i=1;i<=n;i++) par[i]=i;
    vector<element> v(m);
    for(int i=0;i<m;i++) cin >> v[i].u >> v[i].v >> v[i].w;
    sort(v.begin(), v.end());

    ll r=0;
    priority_queue<element> used;
    priority_queue<element, vector<element>, greater<element>> notUsed;
    for(auto e:v) {
        if(merge(e.u, e.v)) {
            used.push(e);
            r+=e.w;
        } else {
            notUsed.push(e);
        }
    }

    while(n--) {
        if(notUsed.size()) {
            auto a=used.top(); used.pop();
            auto b=notUsed.top(); notUsed.pop();
            if(a.w<b.w) {
                used.push(a);
                notUsed.push(b);
            } else {
                used.push(b);
                notUsed.push(a);
                r+=b.w-a.w;
            }
        }
        cout << r << '\n';
    }
}
