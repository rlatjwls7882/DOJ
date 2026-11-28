#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000][1000];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) {
        int aa;cin>>aa;
        a[i][j]|=aa;
        if(aa) {
            for(int k=0;k<4;k++) {
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<0||nx>=n||ny<0||ny>=n)continue;
                a[nx][ny]|=1;
            }
        }
    }

    ll aa=0,bb=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(!a[i][j]) {
                aa++;
                for(int k=0;k<4;k++) {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<0||nx>=n||ny<0||ny>=n||a[nx][ny])continue;
                    bb++;
                }
            }
        }
    }
    cout << aa*(aa-1)-bb;
}
