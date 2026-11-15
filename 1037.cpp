#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll res[200'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin>>n>>m;
    while(m--){
        int k,p,c;cin>>k>>p>>c;
        int need=c/k;
        res[p]-=c-need;
        while(k--){
            int a;cin>>a;
            if(a!=p)res[a]+=need;
        }
    }
    ll r=0;
    for(int i=1;i<=n;i++)if(res[i]>0)r+=res[i];
    cout<<r;
}
