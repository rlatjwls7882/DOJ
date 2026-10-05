#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q;cin>>n>>q;
    ll a;cin>>a;
    while(q--){
        int o,l,r;cin>>o>>l>>r;
        if(o<=4){
            ll x;cin>>x;
            if(o==1)a+=x;
            else if(o==2)a/=x;
            else if(o==3)a=max(a,x);
            else a=min(a,x);
        }else if(o==7||o==8||o==9){
            cout<<a<<'\n';
        }else if(o==10){
            ll x;cin>>x;
            cout<<(a>=x?1:0)<<'\n';
        }else if(o==11){
            cout<<"0\n";
        }else if(o==12){
            cout<<"1\n";
        }else if(o==13){
            cout<<a<<'\n';
        }
    }
}
