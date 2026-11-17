#include<bits/stdc++.h>
using namespace std;

int a[200'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];

    int mx=0;
    for(int i=1;i<n;i++)mx=max(mx,a[i]-a[i-1]);
    cout<<a[n-1]-a[0]-mx;
}
