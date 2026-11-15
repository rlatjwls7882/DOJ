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

int vis[200'002];
int x[200'002],y[200'002];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,r;cin>>n>>r;
    map<pii,int> conn;

    cin>>x[0]>>y[0]>>x[n+1]>>y[n+1];
    conn[{x[0],y[0]}]=0;
    conn[{x[n+1],y[n+1]}]=n+1;

    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        conn[{x[i],y[i]}]=i;
    }

    memset(vis,-1,sizeof vis);
    vis[0]=0;
    queue<int> q; q.push(0);
    while(!q.empty()){
        int cur=q.front();q.pop();
        if(cur==n+1)return!(cout<<vis[cur]);
        int cx=x[cur],cy=y[cur];

        for(int i=-r;i<=r;i++){
            for(int j=-r;j<=r;j++){
                if(i*i+j*j<=r*r&&conn.count({cx+i,cy+j})){
                    int nxt=conn[{cx+i,cy+j}];
                    if(vis[nxt]!=-1)continue;
                    int nx=x[nxt], ny=y[nxt];
                    vis[nxt]=vis[cur]+1;
                    q.push(nxt);
                }
            }
        }
    }
    cout<<-1;
}
