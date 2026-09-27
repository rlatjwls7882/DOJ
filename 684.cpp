#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;

    int r=1;
    while(q--) {
        int a, b; cin >> a >> b;
        if(a==1) r=(r-b-1+n)%n+1;
        else if(a==2) r=(r+b-1)%n+1;
        else cout << (r+b-2+n)%n+1 << '\n';
    }
}
