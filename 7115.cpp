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

int vis[100'001],vis2[100'001];
vector<vector<pair<int,int>>> conn(100'001);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;cin>>n>>m>>k;
    int x,y,z;cin>>x>>y>>z;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        conn[u].push_back({v,i});
        conn[v].push_back({u,i});
    }

    memset(vis,-1,sizeof vis);
    vis[y]=0;
    queue<int> q;q.push(y);
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(auto [nxt,i]:conn[cur]){
            if(vis[nxt]!=-1)continue;
            q.push(nxt);
            vis[nxt]=vis[cur]+1;
        }
    }

    memset(vis2,-1,sizeof vis2);
    vis2[x]=0; q.push(x);
    while(!q.empty()){
        auto cur=q.front();q.pop();
        if(cur==z)return!(cout<<"Burning Love");
        for(auto [nxt,i]:conn[cur]){
            if(vis2[nxt]!=-1||i==k||vis[nxt]<=vis2[cur]+1)continue;
            q.push(nxt);
            vis2[nxt]=vis2[cur]+1;
        }
    }
    cout<<"GIVE ME CHOCO";
}
