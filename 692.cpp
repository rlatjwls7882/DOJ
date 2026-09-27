#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int r=1;
        for(char c:s) {
            if(c=='I') r=r*2+1;
            else if(c=='O') r*=2;
        }
        cout << r << '\n';
    }
}
