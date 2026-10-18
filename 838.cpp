#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll h[1'000'000], a[1'000'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n, v; cin >> n >> v;
    for(int i=0;i<n;i++) cin >> h[i];
    sort(h, h+n);

    int l=0, r=n-1;
    for(int i=0;i<n;i++) {
        if(i&1) a[i]=h[l++];
        else a[i]=h[r--];
    }

    ll res=accumulate(a, a+n, 0LL)*v;
    for(int i=1;i<n;i+=2) {
        ll cur=0;
        if(i-1>=0) cur+=a[i];
        if(i+1<n) cur+=a[i];
        res-=min(a[i]*v, cur);
    }
    cout << res;
}
