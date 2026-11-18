#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> stk;
ll h[200'002], f1[200'002], f2[200'002], pSum[200'002];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for(int i=1;i<=n;i++) {
        cin >> h[i];
        pSum[i]=pSum[i-1]+h[i];
    }

    stk.push_back(0);
    for(int i=1;i<=n;i++) {
        while(stk.size()>1 && h[stk.back()]<=h[i]) stk.pop_back();
        f1[i]=f1[stk.back()]+h[i]*(i-stk.back());
        stk.push_back(i);
    }

    stk={}; stk.push_back(n+1);
    for(int i=n;i>=1;i--) {
        while(stk.size()>1 && h[stk.back()]<=h[i]) stk.pop_back();
        f2[i]=f2[stk.back()]+h[i]*(stk.back()-i);
        stk.push_back(i);
    }

    vector<vector<pair<ll, ll>>> query(n+1);
    for(int i=0;i<q;i++) {
        int l,r;cin>>l>>r;
        query[l].push_back({r,i});
    }

    vector<pair<ll, ll>> res(q);
    stk={}; stk.push_back(n+1);
    for(int i=n;i>=1;i--) {
        while(stk.size()>1 && h[stk.back()]<=h[i]) stk.pop_back();
        stk.push_back(i);
        for(auto [r, ii]:query[i]) {
            int p=*lower_bound(stk.begin(), stk.end(), r, greater<int>());
            ll left = f1[r]-f1[p]+h[p]*(p-i)-(pSum[r]-pSum[i]);
            ll right = f2[i]-f2[p]+h[p]*(r-p)-(pSum[r-1]-pSum[i-1]);
            if(left<right) res[ii]={r, right};
            else res[ii]={i, left};
        }
    }
    for(auto [a,b]:res) cout << a << ' ' << a << " 1000000000 " << b << '\n';
}
