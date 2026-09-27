#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,s;cin>>n>>m>>s;
    vector<pair<int,int>> v(s);
    for(int i=0;i<s;i++) cin>>v[i].first>>v[i].second;

    int r=0;
    for(int a=-n;a<=n;a++) {
        unordered_map<int,int> cnt;
        for(auto [x,y]:v) {
            y-=x*a;
            r=max(r,++cnt[y]);
            r=max(r,++cnt[y+1]);
            r=max(r,++cnt[y-1]);
        }
    }
    cout<<r;
}
