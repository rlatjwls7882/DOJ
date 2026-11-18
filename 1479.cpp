#include<bits/stdc++.h>
using namespace std;

int outD[500'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for(int i=0;i<n-1;i++) {
        int u, v; cin >> u >> v;
        outD[u]^=1;
    }
    int even=0;
    for(int i=1;i<=n;i++) even+=!outD[i];

    while(q--) {
        int o, u, v; cin >> o >> u;
        if(o==1) {
            cin >> v;
            if(outD[u]) even++;
            else even--;
            outD[u]^=1;
            if(outD[v]) even++;
            else even--;
            outD[v]^=1;
        } else {
            if(outD[u]) {
                cout << (even+1)/2 << '\n';
            } else {
                cout << (even-1)/2 << '\n';
            }
        }
    }
}
