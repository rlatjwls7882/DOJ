#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("fma")
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define x first
#define y second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rep(x) for(int __i=(x);__i>0;--__i)
#define compress(x) sort(all(x)), x.erase(unique(all(x)), x.end())

typedef long long ll;
typedef long double ld;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> T sq(T x) { return x*x; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld PI = acosl(-1);
const ld EPS = 1e-10;

mt19937 rd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rnd_int(0, 0); // rnd_int(rd)
uniform_real_distribution<double> rnd_real(0, 1); // rnd_real(rd)

vector<vector<int>> gg(200'000);

struct element {
    int g, v;
    bool operator<(const element e) const {
        return v>e.v;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int g=0;
    priority_queue<element> pq;
    for(int i=1;i<=n;i++) {
        int a; cin >> a;
        while(a--) {
            if(pq.empty() || pq.top().v+1>=i) {
                gg[g].push_back(i);
                pq.push({g++, i});
            } else {
                auto top=pq.top(); pq.pop();
                top.v=i;
                gg[top.g].push_back(i);
                pq.push(top);
            }
        }
    }
    cout << g << '\n';
    for(int i=0;i<g;i++) {
        cout << gg[i].size();
        for(auto e:gg[i]) cout << ' ' << e;
        cout << '\n';
    }
}
