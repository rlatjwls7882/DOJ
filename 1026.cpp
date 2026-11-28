#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    for(int i=1;i<=2;i++)for(int j=1;j<=n;j++)cout<<(i-1)*n+j<<' '<<i<<' '<<j<<'\n';
}
