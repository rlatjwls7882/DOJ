#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    while(q--) {
        int l, r; cin >> l >> r;
        if(s[l-1]!='T' && s[r-1]!='M') cout << "YES\n";
        else cout << "NO\n";
    }
}
