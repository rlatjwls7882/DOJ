#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll a[5000], len1[5000], cnt1[5000], len2[5000], cnt2[5000], res[5000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];

    ll l=0;
    for(int i=0;i<n;i++) {
        len1[i]=cnt1[i]=1;
        for(int j=i-1;j>=0;j--) {
            if(a[j]<a[i]) {
                if(len1[i]<len1[j]+1) {
                    len1[i]=len1[j]+1;
                    cnt1[i]=cnt1[j];
                } else if(len1[i]==len1[j]+1) {
                    cnt1[i]=(cnt1[i]+cnt1[j])%MOD;
                }
            }
        }
        l=max(l,len1[i]);
    }
    for(int i=n-1;i>=0;i--) {
        len2[i]=cnt2[i]=1;
        for(int j=i+1;j<n;j++) {
            if(a[j]>a[i]) {
                if(len2[i]<len2[j]+1) {
                    len2[i]=len2[j]+1;
                    cnt2[i]=cnt2[j];
                } else if(len2[i]==len2[j]+1) {
                    cnt2[i]=(cnt2[i]+cnt2[j])%MOD;
                }
            }
        }
        if(len1[i]+len2[i]-1==l) res[len1[i]-1]=(res[len1[i]-1]+cnt1[i]*cnt2[i]%MOD*a[i])%MOD;
    }
    for(int i=0;i<l;i++) cout << res[i] << ' ';
}
