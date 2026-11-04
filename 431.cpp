#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int n;string s;cin>>n>>s;

        char ch='.';
        int cnt=1;
        for(char c:s){
            if(c!='.'){
                if(ch!='.'&&c!=ch){
                    cnt=0;
                    break;
                }
                ch=c;
            }
        }
        if(ch=='.')cnt=26;
        cout<<cnt<<'\n';
    }
}
