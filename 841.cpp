#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q, k; cin >> q >> k;

    map<ll, int> cnt; cnt[0]++;
    while(q--) {
        ll o, x; cin >> o;
        if(o==1) {
            cin >> x;
            while(x) {
                cnt[x]++;
                x/=k;
            }
        } else if(o==2) {
            cin >> x;
            while(x) {
                if(--cnt[x]==0) cnt.erase(x);
                x/=k;
            }
        } else {
            cout << cnt.size() << '\n';
        }
    }
}
