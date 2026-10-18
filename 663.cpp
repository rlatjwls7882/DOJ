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

pii SS, EE;
int n,m,t;
string s[100];
int vis[100][100][6];
pii prv[100][100];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int Miria(){
    queue<pii> q;
    memset(vis,-1,sizeof vis);
    q.push(SS);
    vis[SS.x][SS.y][0]=0;
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny][0]!=-1||s[nx][ny]=='x'||s[nx][ny]=='#'||vis[x][y][0]+1>=t&&s[nx][ny]=='!')continue;
            vis[nx][ny][0]=vis[x][y][0]+1;
            q.push({nx,ny});
        }
    }
    if(vis[EE.x][EE.y][0]!=-1)return vis[EE.x][EE.y][0];

    memset(vis,-1,sizeof vis);
    q.push(SS);
    vis[SS.x][SS.y][0]=0;
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny][0]!=-1||s[nx][ny]=='x'||s[nx][ny]=='#')continue;
            vis[nx][ny][0]=vis[x][y][0]+1;
            q.push({nx,ny});
        }
    }
    return vis[EE.x][EE.y][0];
}

int Sherry(){
    queue<tuple<int,int,int>> q;
    memset(vis,-1,sizeof vis);
    q.push({SS.x,SS.y,0});
    vis[SS.x][SS.y][0]=0;
    while(!q.empty()){
        auto [x,y,b]=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny][b]!=-1||s[nx][ny]=='#'||vis[x][y][b]+1>=t&&s[nx][ny]=='!')continue;
            if(s[nx][ny]=='x'&&b<5||s[nx][ny]!='x'){
                if(s[nx][ny]=='x'){
                    q.push({nx,ny,b+1});
                    vis[nx][ny][b+1]=vis[x][y][b]+1;
                }else{
                    vis[nx][ny][b]=vis[x][y][b]+1;
                    q.push({nx,ny,b});
                }
            }
        }
    }
    int mn=INF;
    for(int i=0;i<=5;i++)if(vis[EE.x][EE.y][i]!=-1)mn=min(mn,vis[EE.x][EE.y][i]);
    return mn==INF?-1:mn;
}

int Hanna(){
    priority_queue<tuple<int,int,int>> pq;
    fill(&vis[0][0][0],&vis[100][0][0],INF);
    pq.push({0,SS.x,SS.y});
    while(!pq.empty()){
        auto [c,x,y]=pq.top();pq.pop();
        if(vis[x][y][0]<=-c)continue;
        vis[x][y][0]=-c;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m||s[nx][ny]=='x')continue;

            if(s[nx][ny]=='#'||s[x][y]=='#'){
                if(vis[nx][ny][0]>=-c+5){
                    if(-c+5>=t&&s[nx][ny]=='!')continue;
                    pq.push({c-5,nx,ny});
                }
            }else{
                if(vis[nx][ny][0]>=-c+1){
                    if(-c+1>=t&&s[nx][ny]=='!')continue;
                    pq.push({c-1,nx,ny});
                }
            }
        }
    }
    return vis[EE.x][EE.y][0]==INF?-1:vis[EE.x][EE.y][0];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>t;
    for(int i=0;i<n;i++)cin>>s[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='S')SS={i,j};
            else if(s[i][j]=='E')EE={i,j};
        }
    }

    int S=Sherry();
    if(S!=-1)cout<<"Sherry\n"<<S;
    else cout<<"Sherry\n-1";
    // int M=Miria();
    // if(M!=-1)cout<<"Miria\n"<<M;
    // else cout<<"Miria\n-1";
    // int H=Hanna();
    // if(H!=-1)cout<<"Hanna\n"<<H;
    // else cout<<"Hanna\n-1";
}
