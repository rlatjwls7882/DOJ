#include<bits/stdc++.h>
using namespace std;

int a[1024][1024];

struct e {
    int mn, mx, dpMn, dpMx;
};

e score(int i, int j, int sz) {
    if(sz==1) return {a[i][j], a[i][j], a[i][j], a[i][j]};
    sz/=2;
    auto a = score(i, j, sz);
    auto b = score(i+sz, j, sz);
    auto c = score(i, j+sz, sz);
    auto d = score(i+sz, j+sz, sz);

    int dpMn = min({a.mn+b.dpMn+c.dpMn+d.dpMn, b.mn+a.dpMn+c.dpMn+d.dpMn, c.mn+a.dpMn+b.dpMn+d.dpMn, d.mn+a.dpMn+b.dpMn+c.dpMn});
    int dpMx = max({a.mx+b.dpMx+c.dpMx+d.dpMx, b.mx+a.dpMx+c.dpMx+d.dpMx, c.mx+a.dpMx+b.dpMx+d.dpMx, d.mx+a.dpMx+b.dpMx+c.dpMx});
    return {min({a.mn, b.mn, c.mn, d.mn}), max({a.mx, b.mx, c.mx, d.mx}), dpMn, dpMx};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int sz = 1<<n;
    for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) cin >> a[i][j];
    auto ret = score(0, 0, sz);
    cout << ret.dpMn << ' ' << ret.dpMx;
}
