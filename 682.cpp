#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    cout << n-1-n/2 << ' ' << n/2 << '\n';
    for(int i=n/2-1;i>=1;i--) cout << i << ' ' << (n/2+i-1)/i*i << '\n';
    for(int i=1;i<=n/2;i++) cout<<i<<" "<<i+n/2<<'\n';
}
