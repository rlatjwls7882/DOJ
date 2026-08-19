#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll s; cin >> s;

    string mx="0";
    ll a, b;
    for(ll i=1;i<s;i*=10) {
        string cur = to_string(s-i)+to_string(i);
        if(cur.length()>mx.length() || cur>mx) {
            mx=cur;
            a=s-i;
            b=i;
        }
    }
    cout << a << ' ' << b;
}
