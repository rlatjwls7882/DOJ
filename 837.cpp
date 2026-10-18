#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sq(ll x) {return x*x;}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        ll k; cin >> k;
        cout << sq((k+2)/3)+((k+2)/3)*((k+2)%3) << '\n';
    }
}
