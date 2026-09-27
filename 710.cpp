#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll res[200'000], a[200'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];

    int tmp=m;
    vector<int> v;
    for(int i=2;i*i<=tmp;i++) {
        if(tmp%i==0) {
            while(tmp%i==0) tmp/=i;
            v.push_back(i);
        }
    }
    if(tmp!=1) v.push_back(tmp);

    fill(res, res+n, 1);
    for(int e:v) {
        vector<int> cnt;
        for(int i=0;i<n;i++) {
            int cur=0;
            while(a[i]%e==0) {
                a[i]/=e;
                cur++;
            }
            cnt.push_back(cur);
        }
        sort(cnt.begin(), cnt.end());
        for(int i=0;i<n;i++) while(cnt[i]--) res[i]*=e;
    }
    for(int i=0;i<n;i++) cout << res[i] << ' ';
}
