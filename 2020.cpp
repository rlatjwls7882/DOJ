#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n,m;string x;cin>>n>>m>>x;
  for(int i=1;i<=m;i++){
    if(n-i<0){
      for(int j=0;j<abs(n-i);j++)cout<<1;
    }
    for(int j=max(n-i,0);j<n;j++){
      cout<<((x[j]-'0')^1);
    }
    cout<<'\n';
  }
}
