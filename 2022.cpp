#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;

const ll MOD = 998244353;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  ll n,m;cin>>n>>m;
  vector<pair<ll,ll>> v;

  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    v.push_back({a,b});
  }
  ll t;cin>>t;

  for(int i=0;i<n;i++){
    ll mn=min(v[i].y-v[i].x>>1,t);
    v[i].x+=2*mn;
    t-=mn;
  }

  for(int i=0;i<n;i++){
    if(t>=2&&v[i].x+1==v[i].y&&v[i].y+1<=m){
      t-=2;
      v[i].x+=2;
      v[i].y++;
    }
  }

  for(int i=0;i<n;i++){
    int mn=min((m-v[i].y)/2,t/3);

    t-=3*mn;
    v[i].x+=mn*2;
    v[i].y+=mn*2;
  }

  for(int i=0;i<n;i++){
    int mn=min(m-v[i].y,t);

    t-=mn;
    v[i].y+=mn;
  }

  for(int i=0;i<n;i++){
    int mn=min(v[i].y-v[i].x+1>>1,t);

    t-=mn;
    v[i].x=min(v[i].y,v[i].x+mn*2);
  }

  ll sum=0;
  for(int i=0;i<n;i++){
    sum+=v[i].y*2-(v[i].y-v[i].x);
  }
  cout<<sum;
}
