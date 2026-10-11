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

struct HopcroftKarp {
    int n,m; vector<vi> g; vi A,B,lv,it,q;
    HopcroftKarp(int n,int m):n(n),m(m),g(n),A(n,-1),B(m,-1),lv(n),it(n),q(n){}
    void edge(int u,int v) {g[u].push_back(v);}
    void bfs() {
        int l=0,r=0;
        for(int i=0;i<n;i++) A[i]<0 ? lv[i]=0,q[r++]=i : lv[i]=-1;
        while(l<r) {
            int u=q[l++];
            for(int v:g[u]) if(B[v]>=0&&lv[B[v]]<0) lv[B[v]]=lv[u]+1,q[r++]=B[v];
        }
    }
    bool dfs(int u) {
        for(int&p=it[u];p<sz(g[u]);p++) {
            int v=g[u][p];
            if(B[v]<0 || lv[B[v]]==lv[u]+1 && dfs(B[v])) return A[u]=v, B[v]=u, 1;
        }
        return 0;
    }
    int res() {
        int r=0,f;
        do{
            bfs(); fill(all(it),0); f=0;
            for(int u=0;u<n;u++) f+=A[u]<0&&dfs(u);
            r+=f;
        } while(f);
        return r;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int l,r,m;cin>>l>>r>>m;
    HopcroftKarp hk(l+1, r+1);
    while(m--){
        int a,b;cin>>a>>b;
        hk.edge(a,b);
    }
    cout<<hk.res();
}
