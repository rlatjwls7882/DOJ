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

using P=pair<ll,ll>;
istream& operator>>(istream&in,P&p){return in>>p.x>>p.y;}
P operator+(P a,P b){return {a.x+b.x,a.y+b.y};}
P operator-(P a,P b){return {a.x-b.x,a.y-b.y};}
ll operator*(P a,P b){return a.x*b.x+a.y*b.y;} // 내적
ll operator/(P a,P b){return a.x*b.y-a.y*b.x;} // 외적
int Sign(ll x){return (x>0)-(x<0);}
ll Dist(P a,P b){return (a-b)*(a-b);} // 거리 제곱
ll SignedArea(P a,P b,P c){return (b-a)/(c-a);} // 부호 있는 넓이의 2배
int CCW(P a,P b,P c){return Sign(SignedArea(a,b,c));} // 시계/일직선/반시계: -1/0/1
int Half(P p){return p.y<0||(p.y==0&&p.x<0);} // 0: 위 반평면·+x축·원점, 1: 아래 반평면·-x축

vector<P> ConvexHull(vector<P>v){ // 사전순 최소점부터 CCW, 중복·공선 내부점 제외. 끝에 시작점을 반복하지 않음
  sort(all(v));v.erase(unique(all(v)),v.end());
  if(sz(v)<=1)return v;
  sort(v.begin()+1,v.end(),[&](P a,P b){
    int dir=CCW(v[0],a,b);
    return dir?dir>0:Dist(v[0],a)<Dist(v[0],b);
  });
  vector<P> hull;
  for(P cur:v){
    while(sz(hull)>=2&&CCW(hull[sz(hull)-2],hull.back(),cur)<=0)hull.pop_back();
    hull.push_back(cur);
  }
  return hull;
}

ll SignedPolygonArea(const vector<P>&v){ // 순서대로 주어진 단순 다각형의 넓이 2배, CCW 양수
  ll r=0;
  for(int i=0;i<sz(v);i++)r+=v[i]/v[(i+1)%sz(v)];
  return r;
}
ll PolygonArea(const vector<P>&v){return abs(SignedPolygonArea(v));}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    vector<P> v(n);
    for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
    auto hull=ConvexHull(v);
    cout<<hull.size()<<' '<<SignedPolygonArea(hull);
}
