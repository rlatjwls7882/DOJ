#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    string s;cin>>s;

    int cnt=0;
    for(auto e:s)cnt+=e=='6';
    if(cnt<=n-cnt){
        for(auto e:s)if(e=='7')cout<<e;
    } else{
        for(auto e:s)if(e=='6')cout<<e;
    }
}
