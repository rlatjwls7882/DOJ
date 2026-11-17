#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin>>n>>k;

    ll mx=0, r=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        r+=max(a[i]-a[i-1],0LL);
    }
    cout<<max(mx,(r+k-1)/k);
}
