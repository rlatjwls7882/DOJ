#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    string a,b;cin>>a>>b;

    int cnt=0;
    for(int i=1;i<n;i++)cnt+=abs(a[i]+b[i]-a[i-1]-b[i-1]);
    cout<<cnt;
}
