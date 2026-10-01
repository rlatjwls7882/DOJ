#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;
        vector<string>a(m+1),b(k+1),r;
        for(int i=1;i<m;i++)cin>>a[i];
        for(int i=1;i<=k;i++)cin>>b[i];
        int j=1;
        for(int i=1;i<=k;i++){
            if(a[j]==b[i])j++;
            else if(j==n)r.push_back(b[i]);
        }
        cout<<r.size()<<"\n";
        for(auto e:r)cout<<e<<"\n";
    }
}
