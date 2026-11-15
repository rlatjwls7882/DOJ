#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[]={0,8,10,12,15};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h,m,n;cin>>h>>m>>n;
    if(n==5||n==6||n==10)m--;
    else if(n==9)m-=2;
    while(n>0){
        m+=a[min(4,n)];
        n-=4;
    }
    h+=m/60;m%=60;
    h%=24;
    cout<<h<<' '<<m;
}
