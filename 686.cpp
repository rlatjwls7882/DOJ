#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp1[10001], dp2[10001];
vector<vector<pair<int,int>>> v(1001);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a, b; cin >> n >> a >> b;
    for(int i=0;i<n;i++) {
        int t,d,e;cin>>t>>d>>e;
        v[t].push_back({d,e});
    }

    fill(dp1+1,dp1+10001,INT_MAX);
    for(int i=0;i<=1000;i++) {
        if(v[i].empty()) continue;
        fill(dp2,dp2+10001,INT_MAX);
        for(auto [d,e]:v[i]) {
            for(int j=0;j+d<=b;j++) {
                dp2[j+d]=min(dp2[j+d],dp1[j]+e);
            }
        }
        memcpy(dp1,dp2,sizeof dp1);
    }

    ll res=INT_MAX;
    for(int i=a;i<=b;i++) res=min(res,dp1[i]);
    cout << (res==INT_MAX ? -1 : res);
}
