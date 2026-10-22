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

int SZ=1,a[111'111],b[111'111],seg[111'111*4];

void update(int i,int x){
    i+=SZ;
    seg[i]=max(seg[i],x);
    while(i>1){
        i>>=1;
        seg[i]=max(seg[i*2],seg[i*2+1]);
    }
}

int query(int x){
    int i=1;
    while(i<SZ){
        i<<=1;
        if(seg[i+1]>=x)i++;
    }
    return i-SZ;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,c;cin>>n>>c;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    while(SZ<111'111)SZ<<=1;
    update(0,c);

    for(int i=0;i<n;i++){
        if(seg[1]>=a[i]+b[i]){
            int idx=query(a[i]+b[i]);
            update(idx+1,b[i]);
        }
    }
    cout<<query(1);
}
