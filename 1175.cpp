#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int e:v) {
        if(pq.empty() || pq.top()>e) pq.push(1);
        else {
            int t=pq.top(); pq.pop();
            pq.push(t+1);
        }
    }
    cout << pq.size();
}
