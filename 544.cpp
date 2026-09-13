#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if(n==1) return !(cout << 1);

    vector<int> v(n);
    for(int i=0;i<n;i++) v[i]=i+1;
    while(v[0]==1) {
        for(int i=0;i<n;i++) cout << v[i];
        for(int i=0;i<n-1;i++) cout << v[i];
        next_permutation(v.begin(), v.end());
    }
}
