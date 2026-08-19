#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1'000'001;

int groupCnt=1, group[MAX];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<ll> m;
    for(ll i=1;i*i<MAX;i++) {
        m.push_back(i*i);
        group[i*i]=1;
    }

    for(int i=2;i<MAX;i++) {
        if(group[i]) continue;
        groupCnt++;
        for(auto e:m) {
            if(e*i>=MAX) break;
            group[e*i]=groupCnt;
        }
    }
    vector<vector<int>> lst(groupCnt+1);

    int n; cin >> n;
    while(n--) {
        int a; cin >> a;
        lst[group[a]].push_back(a);
    }
    for(int i=1;i<=groupCnt;i++) sort(lst[i].begin(), lst[i].end());
    sort(lst.begin(), lst.end(), [](auto &a, auto &b){
        if(a.size()!=b.size()) return a.size()>b.size();
        return a<b;
    });
    cout << lst[0].size() << '\n';
    for(auto e:lst[0]) cout << e << ' ';
}
