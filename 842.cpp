#include<bits/stdc++.h>
using namespace std;

int a[1'000'000], t[1'000'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> stk;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        t[i]=1;
        while(!stk.empty() && a[stk.back()]<a[i]) {
            t[i]=max(t[i], t[stk.back()]+1);
            stk.pop_back();
        }
        stk.push_back(i);
        cout << t[i] << ' ';
    }
}
