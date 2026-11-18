#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

bool inQ[500];
ll h[200'000], d[1001], mn[500];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for(int i=0;i<n;i++) cin >> h[i];
    fill(d, d+1001, LINF);
    while(q--) {
        ll a,b;cin>>a>>b;
        d[a-b+500]=min(d[a-b+500], b);
    }
    ll p=LINF;
    for(ll i=501;i<=1000;i++) if(d[i]==0) p=min(p,i-500);
    if(p==LINF) {
        for(int i=0;i<n;i++) cout << "NO\n";
        return 0;
    }

    fill(mn+1, mn+p, LINF);
    inQ[0]=true;
    queue<int> qu; qu.push(0);
    while(!qu.empty()) {
        int cur=qu.front(); qu.pop();
        inQ[cur]=false;
        for(int i=0;i<=1000;i++) {
            if(d[i]!=LINF) {
                ll nxt=mn[cur] + (mn[cur]<d[i] ? (d[i]-mn[cur]+p-1)/p*p : 0) + i-500;
                if(nxt<mn[nxt%p]) {
                    mn[nxt%p]=nxt;
                    if(!inQ[nxt%p]) {
                        inQ[nxt%p]=true;
                        qu.push(nxt%p);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++) cout << (mn[h[i]%p]<=h[i] ? "YES\n" : "NO\n");
}
