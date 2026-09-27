#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    string s1(n,'H'),s2(n,'H');
    for(int i=1;i<=n*2/3;i++) {
        if(i&1)s1[i]='K';
        else s2[i]='K';
    }
    for(int i=0;i<n;i+=2)s1[i]='S';
    int rem=n/6;
    if(rem)s2[0]='S';
    for(int i=n-1;i>=0&&rem-->1;i--)s2[i]='S';
    cout<<s1<<'\n'<<s2;
}
