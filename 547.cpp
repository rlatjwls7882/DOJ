#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

tuple<ll, ll, ll> GCD(ll a, ll b) {
    if(!b) return {a, 1, 0};
    auto [g, x, y] = GCD(b, a%b);
    return {g, y, x-a/b*y};
}

ll ceil(ll a, ll b) {
    if(a>0) return (a+b-1)/b;
    return -((-a)/b);
}

ll floor(ll a, ll b) {
    if(a>0) return a/b;
    return -((-a+b-1)/b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        ll a, b, c, d, ex, ey; cin >> a >> b >> c >> d >> ex >> ey;
        ll div=a*d-b*c;
        if(div) {
            ll aa=d*ex-c*ey;
            ll cc=a*ey-b*ex;
            if(aa%div==0 && cc%div==0 && aa/div>=0 && cc/div>=0) cout << aa/div+cc/div << '\n';
            else cout << "-1\n";
        } else {
            auto [g, x, y] = GCD(a, c);
            if(a*ey-b*ex || ex%g) {
                cout << "-1\n";
                continue;
            }
            x*=ex/g;
            y*=ex/g;
            ll dx=c/g;
            ll dy=a/g;
            ll mn = ceil(-x, dx);
            ll mx = floor(y, dy);
            if(mn>mx) {
                cout << "-1\n";
                continue;
            }
            if(c>a) {
                x+=mn*dx;
                y-=mn*dy;
            } else {
                x+=mx*dx;
                y-=mx*dy;
            }
            cout << x+y << '\n';
        }
    }
}
