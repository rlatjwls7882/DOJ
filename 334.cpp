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

struct Splay {
    struct N{
        int c[2]{},p=0,sz=0;
        ll v=0,sum=0,mn=0,mx=0,add=0,sv=0;
        bool rev=0,set=0;
    };
    vector<N>t{{}}; vi st; int rt;

    Splay(int n):st(n+2){
        rt=nn(0); int r=nn(0);
        t[rt].c[1]=r; t[r].p=rt; pull(rt);
    }
    int nn(ll v){
        t.push_back({}); int x=sz(t)-1;
        t[x].sz=1; t[x].v=t[x].sum=t[x].mn=t[x].mx=v;
        return x;
    }
    void pull(int x){
        t[x].sz=1; t[x].sum=t[x].mn=t[x].mx=t[x].v;
        for(int y:t[x].c) if(y){
            t[x].sz+=t[y].sz; t[x].sum+=t[y].sum;
            t[x].mn=std::min(t[x].mn,t[y].mn);
            t[x].mx=std::max(t[x].mx,t[y].mx);
        }
    }
    void Add(int x,ll v){
        if(!x) return;
        t[x].v+=v; t[x].sum+=v*t[x].sz;
        t[x].mn+=v; t[x].mx+=v;t[x].add+=v;
    }
    void Set(int x,ll v){
        if(!x) return;
        t[x].v=t[x].mn=t[x].mx=v;t[x].sum=v*t[x].sz;
        t[x].set=1; t[x].sv=v; t[x].add=0;
    }
    void Rev(int x){ if(x) swap(t[x].c[0],t[x].c[1]), t[x].rev^=1; }
    void push(int x){
        if(t[x].set){ Set(t[x].c[0],t[x].sv); Set(t[x].c[1],t[x].sv); t[x].set=0; }
        if(t[x].add){ Add(t[x].c[0],t[x].add); Add(t[x].c[1],t[x].add); t[x].add=0; }
        if(t[x].rev){ Rev(t[x].c[0]); Rev(t[x].c[1]); t[x].rev=0; }
    }
    void rot(int x){
        int p=t[x].p, g=t[p].p, d=x==t[p].c[1], y=t[x].c[d^1];
        t[p].c[d]=y; if(y) t[y].p=p;
        t[x].c[d^1]=p; t[p].p=x; t[x].p=g;
        if(g) t[g].c[p==t[g].c[1]]=x; else rt=x;
        pull(p); pull(x);
    }
    void splay(int x,int g=0){
        int n=0;
        for(int y=x;y!=g;y=t[y].p) st[n++]=y;
        if(g) st[n++]=g;
        while(n) push(st[--n]);
        while(t[x].p!=g){
            int p=t[x].p, pp=t[p].p;
            if(pp==g) rot(x);
            else if((x==t[p].c[0])==(p==t[pp].c[0])) rot(p), rot(x);
            else rot(x), rot(x);
        }
    }
    int kth(int k){
        int x=rt;
        while(1){
            push(x); int l=t[t[x].c[0]].sz;
            if(k<l) x=t[x].c[0];
            else if(k==l) break;
            else k-=l+1, x=t[x].c[1];
        }
        splay(x); return x;
    }
    int rg(int l,int r){
        int R=kth(r+1), L=kth(l-1);
        splay(R,L); return t[R].c[0];
    }
    void fix(){pull(t[rt].c[1]); pull(rt);}
    int minNode(int x){
        ll m=t[x].mn;
        while(1){
            push(x); int l=t[x].c[0];
            if(l&&t[l].mn==m) x=l;
            else if(t[x].v==m) return x;
            else x=t[x].c[1];
        }
    }

    void insert(int p,ll v){
        int L=kth(p-1), R=kth(p); splay(L); splay(R,L);
        int x=nn(v); t[R].c[0]=x; t[x].p=R; fix();
    }
    void erase(int p){ rg(p,p);t[t[rt].c[1]].c[0]=0;fix(); }
    void set(int l,int r,ll v){Set(rg(l,r),v);fix();}
    void add(int l,int r,ll v){Add(rg(l,r),v);fix();}
    void rev(int l,int r){Rev(rg(l,r));fix();}
    void shiftRight(int l,int r,int x){
        int n=r-l+1;x=(x%n+n)%n;
        if(!x)return;
        rev(l,r-x);rev(r-x+1,r);rev(l,r);
    }
    int minNode(int l,int r){return minNode(rg(l,r));}
    ll get(int p){return t[rg(p,p)].v;}
    ll sum(int l,int r){return t[rg(l,r)].sum;}
    ll min(int l,int r){return t[rg(l,r)].mn;}
    ll max(int l,int r){return t[rg(l,r)].mx;}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,q;cin>>n>>q;
    Splay sp(n+q+1);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        sp.insert(i,a);
    }
    while(q--){
        int op,a,b,c;cin>>op>>a>>b;
        if(op==1){
            cin>>c;
            sp.add(a,b,c);
        }else if(op==2){
            sp.rev(a,b);
        }else if(op==3){
            cin>>c;
            sp.shiftRight(a,b,c);
        }else{
            cout<<sp.sum(a,b)<<'\n';
        }
    }
}
