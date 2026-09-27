#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200'000][4];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    int t=-1;
    int b=-INT_MAX,c=-INT_MAX,d=INT_MAX,e=INT_MAX;
    for(int i=0;i<n;i++) {
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
        b=max(b,a[i][0]);
        c=max(c,a[i][1]);
        d=min(d,a[i][2]);
        e=min(e,a[i][3]);
        if(t==-1&&(b>d||c>e))t=i;
    }
    if(t==-1)return !(cout<<"1 "<<b<<' '<<c);

    for(int i=0;i<n;i++) {
        b=max(a[t][0],a[i][0]);
        c=max(a[t][1],a[i][1]);
        d=min(a[t][2],a[i][2]);
        e=min(a[t][3],a[i][3]);
        if(b>d||c>e)return !(cout<<"2 "<<t+1<<' '<<i+1);
    }
}
