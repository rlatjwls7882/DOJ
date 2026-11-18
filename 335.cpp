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

struct OfflineConnectivity{
  int n,queries=0;vector<array<int,3>>op;
  OfflineConnectivity(int n):n(n){}
  void add(int u,int v){if(u>v)swap(u,v);op.push_back({0,u,v});}
  void remove(int u,int v){if(u>v)swap(u,v);op.push_back({1,u,v});}
  int ask(int u,int v){op.push_back({2,u,v});return queries++;}
  int ask_size(int u){op.push_back({3,u,0});return queries++;}
  int ask_components(){op.push_back({4,0,0});return queries++;}
  vi solve()const{
    int q=sz(op),S=1;if(!q)return {};
    while(S<q)S<<=1;vector<vector<pii>>seg(2*S);map<pii,pii>live;
    auto interval=[&](int l,int r,pii e){
      for(l+=S,r+=S;l<r;l>>=1,r>>=1){
        if(l&1)seg[l++].push_back(e);
        if(r&1)seg[--r].push_back(e);
      }
    };
    for(int t=0;t<q;t++){
      auto[type,u,v]=op[t];if(type>1)continue;
      auto&[cnt,start]=live[{u,v}];
      if(!type){if(!cnt++)start=t;}
      else if(!--cnt)interval(start,t,{u,v});
    }
    for(auto&[e,state]:live)if(state.x)interval(state.y,q,e);
    vi p(n,-1),ans;ans.reserve(queries);vector<array<int,4>>st;int components=n;
    auto root=[&](int u){while(p[u]>=0)u=p[u];return u;}; // rollback을 위해 경로 압축 없이 크기 기준 병합
    auto dfs=[&](auto&&self,int id)->void{
      int stamp=sz(st);
      for(auto[u,v]:seg[id]){
        u=root(u);v=root(v);if(u==v)continue;
        if(p[u]>p[v])swap(u,v);
        st.push_back({u,p[u],v,p[v]});p[u]+=p[v];p[v]=u;components--;
      }
      if(id>=S){
        int t=id-S;if(t<q){auto[type,u,v]=op[t];
          if(type==2)ans.push_back(root(u)==root(v));
          if(type==3)ans.push_back(-p[root(u)]);
          if(type==4)ans.push_back(components);
        }
      }else self(self,id*2),self(self,id*2+1);
      while(sz(st)>stamp){auto[u,a,v,b]=st.back();st.pop_back();p[u]=a;p[v]=b;components++;}
    };
    dfs(dfs,1);return ans;
  }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,q;cin>>n>>q;
    OfflineConnectivity oc(n+1);
    while(q--){
        int t,u,v;cin>>t>>u>>v;
        if(t==1)oc.add(u,v);
        else if(t==2)oc.remove(u,v);
        else oc.ask(u,v);
    }
    for(auto e:oc.solve())cout<<e<<'\n';
}
