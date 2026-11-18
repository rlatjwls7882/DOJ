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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q;cin>>q;
    while(q--){
        int n,t,x,y;cin>>n>>t>>x>>y;
        set<char> seet;
        while(n--){
            int xx,yy;char c;cin>>xx>>yy>>c;
            if(max(abs(xx-x),abs(yy-y))<=t){
                if(c=='W')seet.insert('R'),seet.insert('G'),seet.insert('B');
                else if(c=='M')seet.insert('R'),seet.insert('B');
                else if(c=='C')seet.insert('G'),seet.insert('B');
                else if(c=='Y')seet.insert('R'),seet.insert('G');
                else seet.insert(c);
            }
        }
        if(seet.contains('R')&&seet.contains('G')&&seet.contains('B'))cout<<"W\n";
        else if(seet.contains('R')&&seet.contains('B'))cout<<"M\n";
        else if(seet.contains('G')&&seet.contains('B'))cout<<"C\n";
        else if(seet.contains('R')&&seet.contains('G'))cout<<"Y\n";
        else if(seet.contains('B'))cout<<"B\n";
        else if(seet.contains('G'))cout<<"G\n";
        else if(seet.contains('R'))cout<<"R\n";
        else cout<<"K\n";
    }
}
