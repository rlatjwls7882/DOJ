#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=2'000'000'000'000'000'002;

ll a[200'001], pa[200'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,k,s;cin>>n>>k>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pa[i]+=pa[i-1]+a[i];
    }

    ll L=0,R=INF;
    while(L<R){
        ll M=L+(R-L>>1);
        deque<int> mxd,mnd,pd;
        bool chk=false;
        int l=1;
        for(int r=1;r<=n;r++){
            while(!mxd.empty()&&a[r]>=a[mxd.back()])mxd.pop_back();
            mxd.push_back(r);
            while(!mnd.empty()&&a[r]<=a[mnd.back()])mnd.pop_back();
            mnd.push_back(r);
            while(!mxd.empty()&&!mnd.empty()&&a[mxd.front()]-a[mnd.front()]>M){
                while(!mxd.empty()&&mxd.front()<=l)mxd.pop_front();
                while(!mnd.empty()&&mnd.front()<=l)mnd.pop_front();
                l++;
            }
            while(!pd.empty()&&pd.front()<l)pd.pop_front();

            int st=r-k+1;
            if(st>=l){
                while(!pd.empty()&&pa[st-1]<=pa[pd.back()-1])pd.pop_back();
                pd.push_back(st);
            }
            if(!pd.empty()&&pa[r]-pa[pd.front()-1]>=s){
                chk=true;
                break;
            }
        }
        if(chk)R=M;
        else L=M+1;
    }
    cout<<(L==INF?-1:L);
}
