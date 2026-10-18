#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;string s;cin>>n>>s;
    for(int i=0;i<n;i++) {
        if(s[i]=='1' || i+1>=n || s[i+1]=='0') cout << s[i];
        else cout << "@", i++;
    }
}
