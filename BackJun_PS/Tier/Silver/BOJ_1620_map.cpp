// <나는야 포켓몬 마스터 이다솜> - BOJ_1620
// stl map

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    map<string,int> strKey;
    map<int,string> intKey;

    for(int i=1; i<=n; i++) {
        string str; cin>>str;
        strKey.insert(make_pair(str,i));
        intKey.insert(make_pair(i,str));
    }

    for(int i=0; i<m; i++){
        string input; cin>>input;
        int chk = atoi(input.c_str());
        if(chk) {
            auto ans = intKey.lower_bound(chk);
            cout<<ans->second<<'\n';
        }
        else { 
            auto ans = strKey.lower_bound(input);
            cout<<ans->second<<'\n';
        }
    }
    
}