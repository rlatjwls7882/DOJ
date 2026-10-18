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

int SZ=1,a[200'000*4];

int query(int l, int r){
    int ret=INF;
    for(l+=SZ,r+=SZ;l<=r;l>>=1,r>>=1){
        if(l&1)ret=min(ret,a[l++]);
        if(!(r&1))ret=min(ret,a[r--]);
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,q;cin>>n>>q;
    while(SZ<n)SZ<<=1;
    for(int i=0;i<n;i++)cin>>a[i+SZ];
    for(int i=SZ-1;i>0;i--)a[i]=min(a[i*2],a[i*2+1]);
    while(q--){
        int l,r;cin>>l>>r;
        cout<<query(l-1,r-1)<<'\n';
    }
}
