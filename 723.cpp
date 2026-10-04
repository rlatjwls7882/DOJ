#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int v=0;
        for(int i=0;i<n;i++) {
            cin >> a[i];
            v^=a[i];
        }

        int mx=0;
        for(int i=0;i<n;i++) mx=max(mx, a[i]&v);
        cout << mx << '\n';
    }
}
