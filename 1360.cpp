#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[2000][2000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    if(n*m%3) return !(cout << -1);
    int cnt=1;
    if(n%3==0) {
        for(int i=0;i<n;i+=3) {
            for(int j=0;j<m;j+=2) {
                if(j+3==m) {
                    a[i][j]=a[i+1][j+1]=a[i+2][j]=cnt++;
                    a[i][j+1]=a[i+1][j]=a[i+1][j+2]=cnt++;
                    a[i][j+2]=a[i+2][j+1]=a[i+2][j+2]=cnt++;
                    j++;
                } else {
                    a[i][j]=a[i+1][j+1]=a[i+2][j]=cnt++;
                    a[i][j+1]=a[i+1][j]=a[i+2][j+1]=cnt++;
                }
            }
        }
    } else {
        for(int i=0;i<n;i+=2) {
            for(int j=0;j<m;j+=3) {
                if(i+1==n) break;
                if(i+3==n) {
                    a[i][j]=a[i+1][j+1]=a[i+2][j]=cnt++;
                    a[i][j+1]=a[i+1][j]=a[i+1][j+2]=cnt++;
                    a[i][j+2]=a[i+2][j+1]=a[i+2][j+2]=cnt++;
                } else {
                    a[i][j]=a[i+1][j+1]=a[i][j+2]=cnt++;
                    a[i+1][j]=a[i][j+1]=a[i+1][j+2]=cnt++;
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
