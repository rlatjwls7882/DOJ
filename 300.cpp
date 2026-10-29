#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool vis[1'000'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin>>n>>k;
    string s;cin>>s;

    vis[0]=1;
    for(int i=0;i<n;i++){
        if(vis[i]){
            if(i+1<n&&s[i+1]=='_')vis[i+1]=1;
            if(i+k<n&&s[i+k]=='_')vis[i+k]=1;
        }
    }
    cout<<(vis[n-1]?"YES":"NO");
}
