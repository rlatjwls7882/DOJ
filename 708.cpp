#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[500'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++) cin >> x[i];
    sort(x, x+n);

    int r=(x[n-1]-x[0]+1)/2;
    for(int i=0;i<n-1;i++) r=max(r, x[i+1]-x[i]);
    cout<<r;
}
