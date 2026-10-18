#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    s.push_back('0');

    int l=0;
    while(l<n && s[l]=='1') l++;

    ll res=0, cnt=0, last=0;
    for(int i=l;i<=n;i++) {
        if(s[i]=='0') {
            if(last%2) return !(cout << -1);
            res+=last/2*cnt;
            cnt++;
            last=0;
        } else {
            last++;
        }
    }
    cout << res;
}
