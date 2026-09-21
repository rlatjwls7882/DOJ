#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    ll m=0,c=0;
    while(n--) {
        ll a;cin>>a;
        c+=a;
        m=max(m,-c);
    }
    cout<<m;
}
