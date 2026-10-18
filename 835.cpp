#include<bits/stdc++.h>
using namespace std;

int c[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;string s; cin >> n >> s;
    for(char ch:s) c[ch-'a']++;

    int res=0;
    for(int i=0;i<26;i++) res+=(c[i]+1)/2;
    cout << res;
}
