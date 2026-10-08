#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int n,s;cin>>n>>s;
        vector<ll>a={0},b={0};
        for(int i=0;i<n/2;i++){
            int c;cin>>c;
            int k=a.size();
            for(int j=0;j<k;j++)a.push_back(a[j]+c);
        }
        for(int i=n/2;i<n;i++){
            int c;cin>>c;
            int k=b.size();
            for(int j=0;j<k;j++)b.push_back(b[j]+c);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        ll l=0,r=b.size()-1,cnt=0;
        while(l<a.size()&&r>=0){
            ll c=a[l]+b[r];
            if(c<s)l++;
            else if(c>s)r--;
            else {
                ll L=0,R=0,A=a[l],B=b[r];
                while(l<a.size()&&a[l]==A)l++,L++;
                while(r>=0&&b[r]==B)r--,R++;
                cnt+=L*R;
            }
        }
        cout<<cnt<<'\n';
    }
}
