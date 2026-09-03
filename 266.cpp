#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; string s; cin >> n >> s;
    int r=0;
    for(int i=0;i<n-1;i++) r+=s[i]=='C' && '0'<=s[i+1] && s[i+1]<='9';
    cout<<r;
}
