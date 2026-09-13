#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; string s; cin >> n >> s;
        vector<bitset<2001>> b(n); // b[i][j]: sk 가능 여부
        vector<bitset<2001>> c(n); // ske
        vector<bitset<2001>> d(n); // skee
        vector<bitset<2001>> e(n); // skeep
        vector<bitset<2001>> right(n); // e 열 -> 행

        for(int len=2;len<=n;len++) {
            for(int l=0;l+len-1<n;l++) {
                int r=l+len-1;
                if(len%4==2) if((e[l]&right[r]).any() || s[l]=='s' && right[r][l] || e[l][r-1] && s[r]=='k' || l+1==r && s[l]=='s' && s[r]=='k') b[l][r]=1;
                if(len%4==3) if((b[l]&right[r]).any() || b[l][r-1] && s[r]=='e') c[l][r]=1;
                if(len%4==0) if((c[l]&right[r]).any() || c[l][r-1] && s[r]=='e') d[l][r]=1;
                if(len%4==1) if((d[l]&right[r]).any() || d[l][r-1] && s[r]=='p') {e[l][r]=1; if(l) right[r][l-1]=1;}
            }
        }

        vector<int> dp(n);
        for(int i=0;i<n;i++) {
            if(i) dp[i]=max(dp[i], dp[i-1]);
            for(int j=i;j<n;j++) {
                if(e[i][j]) {
                    dp[j]=max(dp[j], dp[i]+(j-i)/4);
                }
            }
        }
        cout << dp[n-1] << '\n';
    }
}
