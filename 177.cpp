#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998'244'353;

ll expow(ll n, ll k) {
    ll ret=1;
    while(k) {
        if(k&1) ret=ret*n%MOD;
        k>>=1;
        n=n*n%MOD;
    }
    return ret;
}

int main() {
    ll n, m, p, t; cin >> n >> m >> p >> t;
    ll prob=1, res=0;
    while(t--) {
        ll succ = prob*n%MOD*expow(2*n+2, MOD-2)%MOD;
        ll fail = prob*(n+2)%MOD*expow(2*n+2, MOD-2)%MOD;
        if(m*2<p) m*=2, prob=succ;
        else m-=(p-m), prob=fail, res=(res+succ)%MOD;
    }
    cout << res;
}
