#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; string s; cin >> n >> s;

    int cnt=0;
    for(int i=0;i<2*n;i+=2) cnt+=s[i]!=s[i+1];
    cout << (cnt+1)/2;
}
