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

struct MCMF{
    struct E{int v;ll c,w;};
    int n,S,T; bool neg=0;
    vector<E>e; vector<vi>g; vll d,h; vi pre;
    MCMF(int n,int s,int t):n(n),S(s),T(t),g(n),d(n),h(n),pre(n){}
    void edge(int u,int v,ll c,ll w){
        g[u].push_back(e.size()); e.push_back({v,c,w});
        g[v].push_back(e.size()); e.push_back({u,0,-w}); neg|=c&&w<0;
    }
    void pot(){
        fill(h.begin(),h.end(),LINF); vector<char>in(n); queue<int>q;
        h[S]=0; q.push(S); in[S]=1;
        while(q.size()){
            int u=q.front(); q.pop(); in[u]=0;
            for(int i:g[u]){
                auto&[v,c,w]=e[i];
                if(c&&h[v]>h[u]+w){
                    h[v]=h[u]+w;
                    if(!in[v])q.push(v),in[v]=1;
                }
            }
        }
        for(ll&x:h) if(x==LINF)x=0;
    }
    pll res(ll lim=LINF){
        if(neg)pot();
        ll flow=0,cost=0;
        while(flow<lim){
            fill(d.begin(),d.end(),LINF); fill(pre.begin(),pre.end(),-1);
            priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>q;
            d[S]=0; q.push({0,S});
            while(q.size()){
                auto [du,u]=q.top(); q.pop();
                if(du!=d[u])continue;
                for(int i:g[u]){
                    auto&[v,c,w]=e[i];
                    if(c&&d[v]>du+w+h[u]-h[v]) d[v]=du+w+h[u]-h[v],pre[v]=i,q.push({d[v],v});
                }
            }
            if(pre[T]<0)break;
            for(int i=0;i<n;i++) if(d[i]<LINF) h[i]+=d[i];
            ll f=lim-flow;
            for(int v=T;v!=S;v=e[pre[v]^1].v) f=min(f,e[pre[v]].c);
            for(int v=T;v!=S;v=e[pre[v]^1].v){int i=pre[v]; e[i].c-=f; e[i^1].c+=f; cost+=f*e[i].w;}
            flow+=f;
        }
        return {flow,cost};
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin>>n>>m;
    MCMF mcmf(n+1,1,n);
    while(m--){
        int u,v,c1,c2;cin>>u>>v>>c1>>c2;
        mcmf.edge(u,v,c1,c2);
    }
    auto e=mcmf.res();
    cout<<e.x<<' '<<e.y;
}
