#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,d;cin>>n>>m>>d;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    
    ll r=0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(auto [a,b]:v) {
        if(pq.size()<m) {
            r+=a;
            pq.push(b);
        } else {
            ll t=pq.top(); pq.pop();
            r+=max(0LL, a-t);
            pq.push(max(t, b));
        }
    }
    for(int i=0;i<m-n;i++) r+=d;
    while(!pq.empty()) {
        ll t=pq.top();pq.pop();
        r+=d-t;
    }
    cout<<r;
}
