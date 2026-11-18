#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;

ll pos[200'001], dp[200'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        int a; cin >> a;
        pos[a]=i;
    }

    dp[1]=1;
    stack<int> stk; stk.push(1);
    for(int i=2;i<=n;i++) {
        while(!stk.empty() && pos[stk.top()]<pos[i]) stk.pop();
        int p=stk.empty() ? 0 : stk.top();
        dp[i]=(dp[i-1]+dp[p])%MOD;
        stk.push(i);
    }
    cout << dp[n];
}
