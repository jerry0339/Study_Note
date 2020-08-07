// <N으로 만들기> - BOJ_17255
// DFS, 문자열처리

#include<bits/stdc++.h>
using namespace std;

string N;
set<string> s;

void solve(string n, int st, int ed){
    if(st==0 && ed==N.size()) {s.insert(n); return;}
    string t = N.substr(st,ed-st);
    if(st!=0) solve(n+t+N[st-1],st-1,ed);
    if(ed!=N.size()) solve(n+t+N[ed],st,ed+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0; i<N.size(); i++) {
        string t = "";
        t += N[i];
        solve(t, i, i+1);
    }
    cout<<s.size();
}