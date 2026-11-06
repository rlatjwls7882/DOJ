#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[5000][5000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)cin>>p[i][j];

    int ri,rj,r=INT_MIN;
    for(int i=0;i<n;i++){
        vector<pair<int,int>> v;
        for(int j=0;j<m;j++)v.push_back({p[j][i],j+1});
        sort(v.begin(),v.end(),greater<pair<int,int>>());

        if(r<v[0].first+v[1].first){
            r=v[0].first+v[1].first;
            ri=v[0].second;
            rj=v[1].second;
        }
    }
    cout<<ri<<' '<<rj;
}
