#include<bits/stdc++.h>
using namespace std;

int suff[200'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; string s;cin>>n>>s;

    for(int i=n-1;i>=0;i--) {
        suff[i]=suff[i+1];
        if(s[i]=='U') suff[i]++;
    }

    int mn=min(suff[0],n-suff[0]),r=0,cur=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='K') cur++;
        else {
            r+=cur/2;
            cur=0;
            mn=min(mn,r+suff[i+1]);
        }
    }
    cout<<mn;
}
