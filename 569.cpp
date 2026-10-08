#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        set<int,greater<int>>s;
        while(n--){
            int a;cin>>a;
            s.insert(a);
        }
        cout<<*next(s.begin())<<'\n';
    }
}
