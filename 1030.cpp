#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll dp[81][82][6401]; // dp[i][j][k] i까지 사용했을 때, j가 짝이 없는 개수, 합은 k

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin>>n>>k;

    dp[0][0][0]=1;
    for(int i=1;i<=2*n;i++){
        for(int j=0;j<=n;j++){
            for(int kk=0;kk<=k;kk++){
                if(kk-i>=0&&j-1>=0) dp[i][j][kk]+=dp[i-1][j-1][kk-i]; // 새 짝
                dp[i][j][kk]+=(j+1)*dp[i-1][j+1][kk]; // 기존 짝
                dp[i][j][kk]%=MOD;
            }
        }
    }
    for(int i=1;i<=n;i++)dp[2*n][0][k]=dp[2*n][0][k]*i%MOD;
    for(int i=1;i<=n;i++)dp[2*n][0][k]=dp[2*n][0][k]*2%MOD;
    cout<<dp[2*n][0][k];
}
