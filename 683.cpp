#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool chk(char c) {
    return c!='O';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; string t; cin >> n >> t;
    bool a=1,b=1;
    for(auto e:t) a&=chk(e), b&=!chk(e);
    if(n==4 && a || n<=4 && b) cout << "hi";
    else cout << "bye";
}
