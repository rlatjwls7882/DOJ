#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; string s; cin >> n >> k >> s;

    ll b=0, d=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') b++;
        if(i+1<n && s[i]=='1' || s[i+1]=='1') d++;
    }

    while(k--) {
        b+=d;
        d*=2;
    }
    cout << b;
}
