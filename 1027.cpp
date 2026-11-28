#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];

    ll r=0;
    for(int i=n-2;i>=0;i--) {
        if(a[i]<a[i+1]) continue;
        ll mv=a[i]-a[i+1]+1;
        r+=mv/4*2;
        a[i]-=mv/4*4;
        while(a[i]>=a[i+1]) {
            if(a[i]%2)a[i]-=3;
            else a[i]--;
            r++;
        }
    }
    cout<<r;
}
