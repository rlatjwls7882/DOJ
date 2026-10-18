#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll al[100'000], ar[100'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i=0;i<n;i++) cin >> al[i];
    for(int i=0;i<n;i++) cin >> ar[i];

    for(int i=1;i<n;i++) {
        ll m=(ar[n-1]-ar[0])*i;
        if(!((al[i]-al[0])*(n-1)<=m && m<=(ar[i]-al[0])*(n-1))) return !(cout << "NO");
    }
    cout << "YES";
}
