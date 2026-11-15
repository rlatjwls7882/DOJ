#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll p,x,y,q;cin>>p>>x>>y>>q;
    while(q--){
        ll k;cin>>k;
        if(k<=p*x&&k%x==0)cout<<k/x<<'\n';
        else if(k>p*x&&(k-p*x)%y==0)cout<<p+(k-p*x)/y<<'\n';
        else cout<<"-1\n";
    }
}
