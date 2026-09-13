#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    vector<char> v;
    while(n--) {
        char ch; cin >> ch;
        if(ch=='H') cout << "H";
        else v.push_back(ch);
    }
    sort(v.begin(), v.end());
    for(auto e:v) cout << e;
}
