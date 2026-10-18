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

struct edge{
    int u,v,w;
    bool operator<(const edge e)const{
        return w<e.w;
    }
};

int par[200'000];

int find(int x){
    if(x==par[x])return x;
    return par[x]=find(par[x]);
}

bool merge(int x, int y) {
    x=find(x);
    y=find(y);
    if(x==y)return false;
    if(x<y)par[y]=x;
    else par[x]=y;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)par[i]=i;

    vector<edge> v(m);
    for(int i=0;i<m;i++)cin>>v[i].u>>v[i].v>>v[i].w;
    sort(all(v));

    ll r=0;
    for(auto [u,v,w]:v){
        if(merge(u-1,v-1)){
            r+=w;
        }
    }
    for(int i=1;i<n;i++)if(par[i]==i)return !(cout<<"IMPOSSIBLE");
    cout<<r;
}
