#include<bits/stdc++.h>
using namespace std;

int query(int a, int x) {
    cout << "? " << (a==1 ? "first " : "second ") << x << endl;
    cin>>x;
    return x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<int, vector<int>> m;
    for(int i=1;i<=2*n-2;i+=2) {
        int a=query(1, i);
        int b=query(2, i+1);
        if(a!=b) {
            m[a].push_back(i);
            m[b].push_back(i+1);
        }
    }
    int a=query(1, 2*n-1);
    if(m.count(a)) {
        query(2, m[a][0]);
        m.erase(a);
        a=query(1, 2*n);
        query(2, m[a][0]);
        m.erase(a);
    } else {
        query(2, 2*n);
    }

    for(auto [a,b]:m) {
        query(1, b[0]);
        query(2, b[1]);
    }
}
