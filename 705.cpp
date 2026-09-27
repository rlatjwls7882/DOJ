#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        for(int i=s.length()-1;i>2;i--) {
            if(s[i]>='5') s[i-1]++;
        }
        cout << (s[2]>='5' ? "Yes\n" : "No\n");
    }
}
