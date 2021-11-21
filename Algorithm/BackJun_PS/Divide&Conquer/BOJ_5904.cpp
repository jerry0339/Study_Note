// <Moo 게임>
// 재귀 분할정복 DP

#include<bits/stdc++.h>
using namespace std;

int N;
int s[29]{};

void solve(int n){
    if(N<=s[n]) { // 분할1
        solve(n-1);
    } else if(N>s[n]) { // 분할2
        if(N<=s[n]+n+3){
            if(N==s[n]+1) {cout<<'m'; exit(0);}
            else {cout<<'o'; exit(0);}
        } else {
            N -= s[n]+n+3;
            solve(n-1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    s[1] = 3;
    for(int i=1; i<29; i++){ // DP
        s[i] = s[i-1]*2 + i+2;
    }
    solve(28);
}