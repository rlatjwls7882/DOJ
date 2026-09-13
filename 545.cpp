#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

string ho="hobanwoo";
ll sc[128], dp[200'000][8];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; string s; cin >> n >> s >> sc['h'] >> sc['o'] >> sc['b'] >> sc['a'] >> sc['n'] >> sc['w'];

    fill(&dp[0][0], &dp[200'000][0], -LINF);
    for(int i=0;i<n;i++) {
        if(s[i]=='h') dp[i][0]=sc['h'];
        if(i) {
            for(int j=0;j<8;j++) {
                dp[i][j]=max(dp[i][j], dp[i-1][j]);
                if(s[i]==ho[j]) {
                    if(j && dp[i-1][j-1]!=-LINF) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+sc[s[i]]);
                    if(dp[i-1][j]!=-LINF) dp[i][j]=max(dp[i][j], dp[i-1][j]+sc[s[i]]);
                }
            }
        }
    }
    if(dp[n-1][7]==-LINF) cout << "No";
    else cout << "Yes\n" << dp[n-1][7];
}
