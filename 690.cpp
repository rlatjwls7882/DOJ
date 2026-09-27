#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[25001][1<<12];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,h,w;cin>>n>>h>>w;
    int e=1<<(h*w);
    for(int i=1;i<=n;i++) {
        int x=0;
        for(int j=0;j<h;j++) {
            string s; cin >> s;
            for(int k=0;k<w;k++) if(s[k]=='1') x|=1<<(w*j+k);
        }
        for(int j=0;j<e;j++) cnt[i][j]=cnt[i-1][j] + ((x&j)==x);
    }

    int q; cin >> q;
    while(q--) {
        int l,r,x=0;cin>>l>>r;
        for(int i=0;i<h;i++) {
            string s; cin >> s;
            for(int j=0;j<w;j++) if(s[j]=='1') x|=1<<(w*i+j);
        }
        cout << cnt[r][x]-cnt[l-1][x] << '\n';
    }
}
