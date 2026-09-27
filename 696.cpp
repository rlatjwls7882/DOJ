#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int MAX=1'000'002;

bool chk[MAX];
int h[MAX], hh[MAX];
ll dp[MAX], dpP[MAX];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> h[i];
    hh[n+1]=INT_MAX;
    for(int i=n;i>0;i--) hh[i]=min(i-h[i], hh[i+1]);
    for(int i=1;i<=n;i++) chk[i]=i+1<=hh[i+1];

    if(1<=hh[1]) dp[0]=dpP[0]=1;
    for(int i=1;i<=n;i++) {
        int l=i-m;
        int r=i-1;
        dp[i]=(dpP[r]-(l-1>=0 ? dpP[l-1] : 0)+MOD)%MOD;
        dpP[i]=(dpP[i-1]+(chk[i] ? dp[i] : 0))%MOD;
    }
    cout << dp[n];
}
