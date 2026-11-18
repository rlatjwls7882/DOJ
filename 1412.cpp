#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;

    int mn=INT_MAX,mx=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mn=min(a[i],mn);
        mx=max(a[i],mx);
    }

    int L=n-1,R=0;
    for(int i=0;i<n;i++){
        if(a[i]==mn||a[i]==mx){
            L=min(L,i);
            R=max(R,i);
        }
    }

    int l=0,r=n-1;
    while(l<L&&a[0]==a[l])l++;
    while(r>R&&a[n-1]==a[r])r--;
    ll LL=count(a+l,a+L,a[0])+1, RR=count(a+R+1,a+r+1,a[n-1])+1;
    cout<<LL*RR;
}
