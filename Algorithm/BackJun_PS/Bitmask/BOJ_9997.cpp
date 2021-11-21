#include<bits/stdc++.h>
using namespace std;

int N;
int mask[25]{};
int ans = 0;

void solve(int n, int curMask){
    if(curMask==(1<<26)-1) ans++;

    for(int i=n+1; i<N; i++){
        int nextMask = (curMask | mask[i]);
        solve(i, nextMask);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            int t = s[j]-'a';
            mask[i] |= (1<<t);
        }        
    }

    solve(-1,0);
    cout<<ans;
}