#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;cin>>n;
  ll sum=0;
  for(int i=1;i<=n;i++){
    ll a;cin>>a;
    sum+=a;
  }

  vector<ll> v={sum};
  while(v.size()<n)v.push_back(v.back()+v.back()/n);
  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    if(a==1){
      sum+=sum/n;
      v.push_back(sum);
    }else{
      cout<<v[b]%MOD<<endl;
    }
  }
}
