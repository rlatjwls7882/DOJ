#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a, b, A[20], r;

void dfs(int c, ll d) {
    if(a<=d && d<=b) r++;
    for(int i=c;i<n;i++) {
        if(d+A[i]<=b) {
            dfs(i+1, d+A[i]);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a >> b;
    for(int i=0;i<n;i++) cin >> A[i];
    dfs(0, 0);
    cout << r;
}
