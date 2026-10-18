#include<bits/stdc++.h>
#pragma GCC target("fma")
using namespace std;
#define all(x) x.begin(), x.end()
#define compress(x) sort(all(x)), x.erase(unique(all(x)), x.end())
typedef long long ll;

const int MAX=500'001;
const ll MOD=1e9+7;

ll SZ=1, a[MAX], p[MAX];

struct node {
    ll cnt=0, v=0, vv=0;
} arr[MAX*4];

node merge(node a, node b) {
    return {a.cnt+b.cnt, a.v+b.v, a.vv+b.vv};
}

void add(int x, ll l) {
    x+=SZ;
    arr[x].cnt++;
    arr[x].v+=l;
    arr[x].vv+=l*l;
    while(x>1) {
        x>>=1;
        arr[x]=merge(arr[x*2],arr[x*2+1]);
    }
}

node query(int l, int r) {
    node ret;
    for(l+=SZ,r+=SZ;l<=r;l>>=1,r>>=1) {
        if(l&1) ret=merge(ret, arr[l++]);
        if(!(r&1)) ret=merge(ret,arr[r--]);
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    vector<ll> v;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        p[i]=p[i-1]+a[i];
        v.push_back(p[i]+a[i]);
    }
    compress(v);

    ll res=0;
    while(SZ<v.size()) SZ<<=1;
    for(ll i=1;i<=n;i++) {
        int r=lower_bound(all(v),p[i-1]-a[i])-v.begin();
        int l=lower_bound(all(v),p[i]+a[i])-v.begin();
        node ret=query(r, v.size()-1);
        res=(res+ret.cnt*(i-1)*(i-1)-2*ret.v*(i-1)+ret.vv+MOD)%MOD;
        add(l,i);
    }
    cout<<res;
}
