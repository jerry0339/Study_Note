// <이중 우선순위 큐> - BOJ_7662
// multimap 이용

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin>>T;
    
    while(T--){
        multiset<int> s;
        int t; cin>>t;
    
        char ch;
        while(t--){
            cin>>ch;
            if(ch=='I') {
                int n; cin>>n;
                s.insert(n);
            }
            else{
                int n; cin>>n;
                if(!s.size()) continue;
                if(n==1) s.erase(--s.end()); 
                else s.erase(s.begin());
            }
        }

        if(!s.size()) cout<<"EMPTY"<<'\n';
        else{
            cout<<*(s.rbegin())<<' '<<*(s.begin())<<'\n';
        }
    }
    
}