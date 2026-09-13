#include<bits/stdc++.h>
using namespace std;

char want[128];
string s[50];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int S=5000, E=5001;
vector<vector<int>> conn(5002); // [in, out]
int c[5002][5002];
int prv[5002];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i=0;i<n;i++) cin >> s[i];
    want['g']='o'; want['o']='r'; want['r']='i';
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            conn[(i*m+j)*2].push_back((i*m+j)*2+1);
            conn[(i*m+j)*2+1].push_back((i*m+j)*2);
            c[(i*m+j)*2][(i*m+j)*2+1]=1;
            if(s[i][j]=='g') {
                conn[S].push_back((i*m+j)*2);
                conn[(i*m+j)*2].push_back(S);
                c[S][(i*m+j)*2]=1;
            } else if(s[i][j]=='i') {
                conn[(i*m+j)*2+1].push_back(E);
                conn[E].push_back((i*m+j)*2+1);
                c[(i*m+j)*2+1][E]=1;
            }
            for(int k=0;k<4;k++) {
                int nx=dx[k]+i;
                int ny=dy[k]+j;
                if(nx<0 || nx>=n || ny<0 || ny>=m || want[s[i][j]]!=s[nx][ny]) continue;
                conn[(i*m+j)*2+1].push_back((nx*m+ny)*2);
                conn[(nx*m+ny)*2].push_back((i*m+j)*2+1);
                c[(i*m+j)*2+1][(nx*m+ny)*2]=1;
            }
        }
    }

    int flow=0;
    while(true) {
        queue<int> q; q.push(S);
        memset(prv, -1, sizeof prv);
        while(!q.empty()) {
            int cur=q.front(); q.pop();
            for(int nxt:conn[cur]) {
                if(c[cur][nxt] && prv[nxt]==-1) {
                    prv[nxt]=cur;
                    q.push(nxt);
                }
            }
        }
        if(prv[E]==-1) break;
        flow++;
        for(int i=E;i!=S;i=prv[i]) {
            c[prv[i]][i]--;
            c[i][prv[i]]++;
        }
    }
    cout << flow;
}
