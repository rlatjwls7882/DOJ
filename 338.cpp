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

constexpr int SZ=10'000'000;
bool PrimeCheck[SZ+1];vector<int> Primes;
void Sieve(){
  Primes.clear();memset(PrimeCheck,true,sizeof PrimeCheck);
  PrimeCheck[0]=PrimeCheck[1]=false;
  for(int i=2;i<=SZ;i++){
    if(PrimeCheck[i])Primes.push_back(i);
    for(auto j:Primes){
      if(j>SZ/i)break;
      PrimeCheck[i*j]=false;if(i%j==0)break;
    }
  }
}
using ull=unsigned long long;
ull MulMod(ull a,ull b,ull c){return (__uint128_t)a*b%c;}
ull PowMod(ull a,ull b,ull c){
  ull res=1%c;a%=c;
  for(;b;b>>=1,a=MulMod(a,a,c))if(b&1)res=MulMod(res,a,c);
  return res;
}
bool MillerRabin(ull n,ull a){
  if(a%n==0)return true;
  int cnt=__builtin_ctzll(n-1);ull p=PowMod(a,n>>cnt,n);
  if(p==1||p==n-1)return true;
  while(cnt--)if((p=MulMod(p,p,n))==n-1)return true;
  return false;
}
bool IsPrime(ll n){
  if(n<2)return false;
  if(n<=SZ)return PrimeCheck[n];
  if(n%2==0||n%3==0||n%5==0||n%7==0||n%11==0)return false;
  for(int p:{2,325,9375,28178,450775,9780504,1795265022})if(!MillerRabin(n,p))return false;
  return true;
}
ll Rho(ll n){
  while(true){
    ll x=rand()%(n-2)+2,y=x,c=rand()%(n-1)+1;
    while(true){
      x=(MulMod(x,x,n)+c)%n;y=(MulMod(y,y,n)+c)%n;y=(MulMod(y,y,n)+c)%n;
      ll d=__gcd(abs(x-y),n);
      if(d==1)continue;
      if(IsPrime(d))return d;
      else{n=d;break;}
    }
  }
}
vector<pair<ll,ll>> Factorize(ll n){
  vector<pair<ll,ll>> v;int two=__builtin_ctzll(n);
  if(two>0)v.emplace_back(2,two),n>>=two;
  if(n==1)return v;
  while(!IsPrime(n)){
    ll d=Rho(n),cnt=0;while(n%d==0)cnt++,n/=d;
    v.emplace_back(d,cnt);if(n==1)break;
  }
  if(n!=1)v.emplace_back(n,1);
  return v;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    Sieve();
    while(t--){
        ll x;cin>>x;
        cout<<(IsPrime(x) ? "PRIME\n":"COMPOSITE\n");
    }
}
