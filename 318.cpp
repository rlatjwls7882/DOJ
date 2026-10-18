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

struct GeneralMatching{
  int N,stamp=0;vi Match,Par,Chk,Prv,Vis;vector<vi>G;
  GeneralMatching(int n):N(n),Match(n+1),Par(n+1),Chk(n+1),Prv(n+1),Vis(n+1),G(n+1){}
  void addEdge(int u,int v){G[u].push_back(v);G[v].push_back(u);}
  int Find(int x){return x==Par[x]?x:Par[x]=Find(Par[x]);}
  int LCA(int u,int v){
    for(++stamp;Vis[u]!=stamp;swap(u,v))if(u)Vis[u]=stamp,u=Find(Prv[Match[u]]);
    return u;
  }
  void Blossom(int u,int v,int rt,queue<int>&q){ // 홀수 사이클을 rt로 축약
    for(;Find(u)!=rt;u=Prv[v]){
      Prv[u]=v;Par[u]=Par[v=Match[u]]=rt;
      if(Chk[v]&1)q.push(v),Chk[v]=2;
    }
  }
  bool Augment(int u){ // 미매칭 정점 u에서 교대 경로 탐색
    iota(all(Par),0);fill(all(Chk),0);
    queue<int>q;q.push(u);Chk[u]=2;
    while(!q.empty()){
      u=q.front();q.pop();
      for(auto v:G[u]){
        if(Chk[v]==0){
          Prv[v]=u;Chk[v]=1;q.push(Match[v]);Chk[Match[v]]=2;
          if(!Match[v]){
            for(;u;v=u)u=Match[Prv[v]],Match[Match[v]=Prv[v]]=v;
            return true;
          }
        }else if(Chk[v]==2){
          int l=LCA(u,v);Blossom(u,v,l,q);Blossom(v,u,l,q);
        }
      }
    } return false;
  }
  int Run(){int r=0;for(int i=1;i<=N;i++)if(!Match[i])r+=Augment(i);return r;}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin>>n>>m;
    GeneralMatching t(n+1);
    while(m--){
        int u,v;cin>>u>>v;
        t.addEdge(u,v);
    }
    cout<<t.Run();
}
