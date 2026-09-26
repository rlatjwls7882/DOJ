#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    ll extra=0;
    for(int i=n-2;i>0;i--) {
        if(a[i]>=a[i+1]) {
            a[i-1]+=a[i]-a[i+1]+1;
            a[i]=a[i+1]-1;
        } else {
            ll l=a[i], r=a[i+1]-1;
            while(l<r) {
                ll m=l+r+1>>1;
                ll curNeed = (a[i+1]-m-1)*(n-1-i) - (m-a[i]) + extra;
                if(curNeed>=0) l=m;
                else r=m-1;
            }
            extra += (a[i+1]-l-1)*(n-1-i) - (l-a[i]);
            a[i]=l;
        }
    }
    // for(int i=0;i<n;i++) cout << a[i] << ' '; cout << '\n';

    for(int i=0;i<n-1;i++) {
        if(a[i]>=a[i+1]) return !(cout << "No");
    }
    cout << "Yes";
}
