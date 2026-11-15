#include<bits/stdc++.h>
using namespace std;

int cnt[]={5,4,3,2,1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    for(int i=1;i<n;i++)cnt[4-(i-1)%5]++;
    for(int i=0;i<5;i++)cout<<cnt[i]<<' ';
}
