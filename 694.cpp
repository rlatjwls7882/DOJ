#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    ll r=0, s=0;
    while(n--) {
        ll x,y,w; cin >> x >> y >> w;
        r+=s*w;
        s+=w;
    }
    cout<<r;
}
