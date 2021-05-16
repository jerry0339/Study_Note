#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, st=0, P;
int m[16][16]{};
int dp[1<<16]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,0x3f,sizeof(dp));
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>m[i][j];
        }
    }
    string str;
    cin>>str;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='Y') {
            st |= (1<<i);
        }
    }
    cin>>P;

    dp[st] = 0;
    for(int mask=st; mask<(1<<N); mask++){
        if(dp[mask]==INF) continue;
        for(int i=0; i<N; i++){
            if(!(mask&(1<<i))) continue;
            // i번째가 1일때만
            for(int j=0; j<N; j++){
                if(mask & (1<<j)) continue;
                // j번째가 0일때만
                int next = mask | (1<<j);
                dp[next] = min(dp[next], dp[mask] + m[i][j]);
            }
        }
    }

    int ans = INF;
    for(int mask=st; mask<(1<<N); mask++){
        if(__builtin_popcount(mask) >= P) {
            ans = min(ans, dp[mask]);
        }
    }

    if(ans==INF) cout<<-1;
    else cout<<ans;
}