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

struct Trie{
    Trie *go[26]={};
    int fin=1;
    void push(const string&s, int i){
        Trie *cur=this;
        for(auto e:s){
            if(e<96)e+=32;
            if(!(cur->go[e-'a']))cur->go[e-'a']=new Trie;
            cur=cur->go[e-'a'];
            cur->fin=i;
        }
    }
    pair<int,int> chk(const string &s){
        int len=0;
        Trie *cur=this;
        int last=1;
        for(auto e:s){
            if(e<96)e+=32;
            if(cur->go[e-'a']){
                len++;
                cur=cur->go[e-'a'];
                last=cur->fin;
            }else{
                break;
            }
        }
        return {len,last};
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    Trie *a=new Trie,*b=new Trie,*c=new Trie,*d=new Trie;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        a->push(s,i);
        reverse(all(s));
        c->push(s,i);
    }
    int m;cin>>m;
    for(int i=1;i<=m;i++){
        string s;cin>>s;
        d->push(s,i);
        reverse(all(s));
        b->push(s,i);
    }
    int q;cin>>q;
    while(q--){
        string s;cin>>s;
        auto aa=a->chk(s);
        auto dd=d->chk(s);
        reverse(all(s));
        auto bb=b->chk(s);
        auto cc=c->chk(s);

        if(aa.x+bb.x>=s.length())cout<<"engo "<<aa.y<<" "<<bb.y<<'\n';
        else if(cc.x+dd.x>=s.length())cout<<"nihonese "<<dd.y<<" "<<cc.y<<'\n';
        else cout<<"unknown\n";
    }
}
