#include<bits/stdc++.h>
using namespace std;

bool sol(string s){
    vector<char>v;
    bool chk=true;
    for(char ch:s){
        if(ch=='('||ch=='{'||ch=='[')v.push_back(ch);
        else if(v.size()&&(v.back()=='('&&ch==')'||v.back()=='{'&&ch=='}'||v.back()=='['&&ch==']'))v.pop_back();
        else return false;
    }
    return v.empty();
}

char ch[]={'(','{','[',')','}',']'};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        if(sol(s)){
            cout<<"YES 0\n";
            continue;
        }

        bool chk=false;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            for(int j=0;j<6;j++){
                s[i]=ch[j];
                chk|=sol(s);
                if(chk){
                    cout<<"YES 1\n"<<i+1<<' '<<ch[j]<<'\n';
                    break;
                }
            }
            if(chk)break;
            s[i]=c;
        }
        if(!chk)cout<<"NO\n";
    }
}
