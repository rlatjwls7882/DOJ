#include<bits/stdc++.h>
using namespace std;

int pw(int n, int x) {
    int r=1;
    while(x) {
        if(x&1) r*=n;
        n*=n;
        x>>=1;
    }
    return r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,s;cin>>n>>s;
    vector<int> bit;
    for(int i=0;i<31;i++) {
        if(s&(1<<i)) {
            bit.push_back(i);
        }
    }
    int k=bit.size();
    if(pw(2,k-1)<n) {
        cout << -1;
        return 0;
    }

    int sz=1;
    while(sz<k && pw(2,k-sz-1)>=n) sz++;
    
    cout << (k+sz-1)/sz << '\n';
    for(int i=0;i<k;i+=sz) {
        int cur=0;
        for(int j=i;j<min(i+sz, k);j++) cur|=(1<<j);
        int cnt=0;
        for(int j=0;cnt<n;j++) {
            if(j&cur) continue;
            cnt++;
            int nxt=0;
            for(int kk=0;kk<k;kk++) {
                if((1<<kk)&(cur|j)) nxt|=(1<<bit[kk]);
            }
            cout << nxt << ' ';
        }
        cout << '\n';
    }
}
