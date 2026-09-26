#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 200'002;

int n, a[MAX], isLeader[MAX], moveGood[MAX], pMin1[MAX], pMin2[MAX], idxPMin1[MAX], sMax1[MAX], sMax2[MAX], idxSMax1[MAX];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n==1) return !(cout << 1);

    fill(pMin1, pMin1+MAX, INF);
    fill(pMin2, pMin2+MAX, INF);
    for(int i=1;i<=n;i++) {
        pMin1[i]=pMin1[i-1];
        pMin2[i]=pMin2[i-1];
        idxPMin1[i]=idxPMin1[i-1];
        if(pMin1[i]>a[i]) {
            pMin2[i]=pMin1[i];
            pMin1[i]=a[i];
            idxPMin1[i]=i;
        } else if(pMin2[i]>a[i]) {
            pMin2[i]=a[i];
        }
    }

    for(int i=n;i>=1;i--) {
        sMax1[i]=sMax1[i+1];
        sMax2[i]=sMax2[i+1];
        idxSMax1[i]=idxSMax1[i+1];
        if(sMax1[i]<a[i]) {
            sMax2[i]=sMax1[i];
            sMax1[i]=a[i];
            idxSMax1[i]=i;
        } else if(sMax2[i]<a[i]) {
            sMax2[i]=a[i];
        }
    }

    // moveGood[i] : i를 최적으로 움직였을때 추가로 리더가 생기는 개수
    int cnt=0; // 안움직여도 리더인 경우
    for(int i=1;i<=n;i++) {
        if(a[i]<=pMin1[i] || a[i]>=sMax1[i]) {
            cnt++;
            isLeader[i]=true;
            continue;
        }
        if(pMin2[i]>=a[i]) moveGood[idxPMin1[i]]++;
        if(sMax2[i]<=a[i]) moveGood[idxSMax1[i]]++;
    }

    int res=0;
    for(int i=1;i<=n;i++) res = max(res, cnt+moveGood[i]+(!isLeader[i]));
    cout << res;
}
