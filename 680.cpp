#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x1[2000],y1_[2000],x2[2000],y2[2000],prv[2000],dp[2000];
ll sq(ll x) {return x*x;}

bool line(ll x1, ll y1_, ll x2, ll y2, ll x3, ll y3) {
    return (x1-x3)*(x2-x3)+(y1_-y3)*(y2-y3)==0;
}

bool chk(int i, int j) {
    ll d=sq((x1[i]+x2[i])-(x1[j]+x2[j]))+sq((y1_[i]+y2[i])-(y1_[j]+y2[j]));
    ll r1=sq(x1[i]-x2[i])+sq(y1_[i]-y2[i]);
    ll r2=sq(x1[j]-x2[j])+sq(y1_[j]-y2[j]);
    ll aa=sq(d-r1-r2);
    ll bb=4*r1*r2;
    bool a=line(x1[i], y1_[i], x2[i], y2[i], x1[j], y1_[j]);
    bool b=line(x1[i], y1_[i], x2[i], y2[i], x2[j], y2[j]);
    bool c=line(x1[j], y1_[j], x2[j], y2[j], x1[i], y1_[i]);
    bool dd=line(x1[j], y1_[j], x2[j], y2[j], x2[i], y2[i]);
    if(d==0 && r1==r2) return true;

    int cnt=a+b+c+dd;
    cnt-=a&&c&&x1[j]==x1[i]&&y1_[j]==y1_[i];
    cnt-=a&&dd&&x1[j]==x2[i]&&y1_[j]==y2[i];
    cnt-=b&&c&&x2[j]==x1[i]&&y2[j]==y1_[i];
    cnt-=b&&dd&&x2[j]==x2[i]&&y2[j]==y2[i];
    if(aa<bb) return cnt<=1;
    if(aa==bb) return cnt==0;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>x1[i]>>y1_[i]>>x2[i]>>y2[i];

    int mx=0, idx=0;
    for(int i=0;i<n;i++) {
        dp[i]=1;
        prv[i]=-1;
        for(int j=0;j<i;j++) {
            if(chk(i, j)) {
                if(dp[j]+1>dp[i]) {
                    dp[i]=dp[j]+1;
                    prv[i]=j;
                }
            }
        }
        if(mx<dp[i]) {
            mx=dp[i];
            idx=i;
        }
    }
    vector<int> v;
    for(int i=idx;i!=-1;i=prv[i]) v.push_back(i);
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(auto e:v) cout << e+1 << ' ';
}
