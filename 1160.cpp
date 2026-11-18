#include<bits/stdc++.h>
using namespace std;

int a[200'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    int mn=a[0], mx=0;
    for(int i=0;i<n;i++) {
        if(i>=n-k) mx=max(mx, a[i]);
        else mn=min(mn, a[i]);
    }
    cout << max(mn, mx);
}
