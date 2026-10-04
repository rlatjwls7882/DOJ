#include<bits/stdc++.h>
using namespace std;

int preMn[500'002], suffMn[500'002], a[500'002];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    preMn[0]=suffMn[n+1]=n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        preMn[i]=min(preMn[i-1], a[i]);
    }
    for(int i=n;i>=1;i--) suffMn[i]=min(suffMn[i+1], a[i]);

    for(int i=1;i<=n;i++) {
        if(i%2 || preMn[i-1]<a[i] && suffMn[i+1]<a[i]) cout << "1 ";
        else cout << "0 ";
    }
}
