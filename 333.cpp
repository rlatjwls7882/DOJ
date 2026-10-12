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

struct LiChao {
    struct Line { ll a=0,b=LLONG_MIN; ll operator()(ll x)const{return a*x+b;} };
    struct Node { Line f; int ch[2]={-1,-1}; };
    ll L,R;
    vector<Node> t{{}};
    LiChao(ll l,ll r):L(l),R(r){}
    int son(int p,int k) {
        int v=t[p].ch[k];
        if(v==-1) { v=t.size(); t[p].ch[k]=v; t.push_back({}); }
        return v;
    }
    void add(Line f,int p,ll l,ll r) {
        ll m=l+(r-l)/2;
        if(f(m)>t[p].f(m)) swap(f,t[p].f);
        if(l==r||f.a==t[p].f.a) return;
        int k=f.a>t[p].f.a;
        ll x=k?r:l;
        if(f(x)>t[p].f(x)) add(f,son(p,k),k?m+1:l,k?r:m);
    }
    void add(Line f,ll ql,ll qr,int p,ll l,ll r) {
        if(qr<l||r<ql) return;
        if(ql<=l&&r<=qr) { add(f,p,l,r); return; }
        ll m=l+(r-l)/2;
        if(ql<=m) add(f,ql,qr,son(p,0),l,m);
        if(qr>m) add(f,ql,qr,son(p,1),m+1,r);
    }
    void update(Line f) { add(f,0,L,R); }
    void update(Line f,ll l,ll r) { if(l<=r) add(f,l,r,0,L,R); }
    ll query(ll x) const {
        ll res=LLONG_MIN,l=L,r=R;
        for(int p=0;p!=-1;) {
            res=max(res,t[p].f(x));
            if(l==r) break;
            ll m=l+(r-l)/2;
            if(x<=m) r=m,p=t[p].ch[0];
            else l=m+1,p=t[p].ch[1];
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int c,q;cin>>c>>q;
    LiChao li(1, c);
    while(q--){
        int op;cin>>op;
        if(op==1){
            int l,r,a,b;cin>>l>>r>>a>>b;
            li.update({a,b},l,r);
        }else{
            int x;cin>>x;
            auto ret=li.query(x);
            if(ret==LLONG_MIN)cout<<"EMPTY\n";
            else cout<<ret<<'\n';
        }
    }
}
