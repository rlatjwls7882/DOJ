#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[100'002], pa[100'002], pb[100'002];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> c[i];
        pa[i]=pa[i-1];
        pb[i]=pb[i-1];
        if(c[i]==0) pa[i]++;
        else pb[i]++;
    }
    for(int i=1;i<n;i++) cout << min(pa[i], pb[n]-pb[i])+min(pb[i], pa[n]-pa[i]) << ' ';
    cout << '\n';
    for(int i=1;i<n;i++) cout << min(pa[i]-min(pa[i], pb[i]), (pb[n]-pb[i])-min(pb[n]-pb[i], pa[n]-pa[i]))+min(pb[i]-min(pa[i], pb[i]), pa[n]-pa[i]-min(pb[n]-pb[i], pa[n]-pa[i])) << ' ';
}
