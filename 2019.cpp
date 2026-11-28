#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  map<string, int> maap;
  int n;cin>>n;
  while(n--){
    string s;int a;cin>>s>>a;
    maap[s]=a;
  }
  for(int i=0;i<10;i++){
    string s;cin>>s;
    maap.erase(s);
  }

  int mx=-1;
  string res;
  for(auto [a,b]:maap){
    if(b>mx){
      mx=b;
      res=a;
    }
  }
  cout<<res;
}
