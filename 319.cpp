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

struct Dinic {
    struct E {int v; ll c;};
    int S,T; vector<E> e; vector<vi> g; vi lv,it,q;
    Dinic(int n, int s, int t) : S(s), T(t), g(n), lv(n), it(n), q(n){}

    void edge(int u, int v, ll c) {
        g[u].push_back(sz(e)); e.push_back({v,c});
        g[v].push_back(sz(e)); e.push_back({u,0});
    }
    bool bfs() {
        fill(all(lv),-1); int l=0,r=0; q[r++]=S; lv[S]=0;
        while(l<r) {
            int u=q[l++];
            for(int i:g[u]) if(e[i].c&&lv[e[i].v]<0) lv[e[i].v]=lv[u]+1, q[r++]=e[i].v;
        }
        return lv[T]>=0;
    }
    ll dfs(int u, ll f) {
        if(u==T) return f;
        for(int&p=it[u];p<sz(g[u]);p++) {
            int i=g[u][p]; auto&[v,c]=e[i];
            if(c&&lv[v]==lv[u]+1) if(ll x=dfs(v,min(f,c))) return c-=x, e[i^1].c+=x, x;
        }
        return 0;
    }
    ll res() {
        ll r=0,f;
        while(bfs()) {
            fill(all(it),0);
            while((f=dfs(S,LINF))) r+=f;
        }
        return r;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,s,t;cin>>n>>m>>s>>t;
    Dinic d(n+1,s,t);
    while(m--){
        int u,v,c;cin>>u>>v>>c;
        d.edge(u,v,c);
    }
    cout<<d.res();
}
