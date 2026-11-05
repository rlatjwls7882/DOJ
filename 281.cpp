#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    string s;cin>>s;
    for(auto e:s)cout<<((e-'0')^1);
    cout<<endl;
}
