#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[1'000'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=n-1;i>0;i--) a[i]+=a[i+1];

    ll r=0;
    for(int i=1;i<=n;i++) r+=abs(a[i]*i);
    cout<<r;
}
