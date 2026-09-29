#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        ll a=(s[0]-'0')*100+(s[2]-'0')*10+s[3]-'0';
        a*=n;

        priority_queue<int> pq;
        while(a) {
            if(a>=500) {
                pq.push(500);
                a-=500;
            } else {
                pq.push(a);
                if(a%100) pq={};
                a=0;
            }
        }
        while(pq.size() && pq.size()<n) {
            int t=pq.top(); pq.pop();
            if(t==100) {
                pq.push(t);
                break;
            }
            pq.push(100);
            pq.push(t-100);
        }

        if(pq.size()!=n) {
            cout << "-1\n";
        } else {
            while(!pq.empty()) {
                int t=pq.top(); pq.pop();
                cout << t/100 << ' ';
            }
            cout << '\n';
        }
    }
}
