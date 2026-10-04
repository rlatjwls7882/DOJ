#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        ll r,g,k;cin>>r>>g>>k;
        ll a=(r+1)/2;
        ll b=(g+1)/2;
        if(a>b+1) b=a-1;
        else if(b>a+1) a=b-1;
        cout << (a<=r && b<=g && a+b-1<=k ? "Yes\n" : "No\n");
    }
}
