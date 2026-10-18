#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll r[1'000'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> a(3); cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++) cin >> r[i];
    sort(r, r+n);

    ll res=0;
    do {
        ll tot=0, idx=-1, cur=0;
        for(int i=0;i<3;i++) {
            while(idx+1<n && r[idx+1]<=a[i]/(cur+1)) {
                idx++;
                cur++;
            }
            tot+=cur;
            cur=0;
        }
        res=max(res,tot);
    } while(next_permutation(a.begin(), a.end()));
    cout << res;
}
