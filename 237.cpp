#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int par[200'000];
int find(int x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
}

void merge(int x, int y) {
    x=find(x);
    y=find(y);
    if(x<y)par[y]=x;
    else par[x]=y;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)par[i]=i;
    while(m--){
        int a,b;cin>>a>>b;
        merge(a-1,b-1);
    }

    int cnt=0;
    for(int i=1;i<n;i++)cnt+=par[i]==i;
    cout<<cnt;
}
