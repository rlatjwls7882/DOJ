#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int maxVal=0, cnt=0, idx;
    for(int i=1;i<=15;i++) {
        int a; cin >> a;
        if(maxVal<a) {
            maxVal=a;
            cnt=1;
            idx=i;
        } else if(maxVal==a) {
            cnt++;
            idx=i;
        }
    }

    if(cnt>1 || idx!=15) cout << maxVal+1;
    else cout << maxVal;
}
