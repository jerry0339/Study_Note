#include<bits/stdc++.h>
using namespace std;

int N;
int m[2001]{};
int presum[2001]{};
int dp[2001][2001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>m[i];
        if(i==1) continue;
        presum[i] = presum[i-1] + abs(m[i]-m[i-1]);
    }

    for(int i=1; i<N; i++) {
        for(int j=i+1; j<=N; j++){
            if(i==j-1) {
                int minv = presum[i];
                for(int k=1; k<i; k++)
                    minv = min(minv, dp[k][i] + abs(m[j]-m[k]));
                if(minv==1e9) continue;
                dp[i][j] = minv;
            } else {
                dp[i][j] = dp[i][j-1] + abs(m[j]-m[j-1]);
            }
        }
    }
    
    int ans = 1e9;
    for(int i=1; i<N; i++) {
        ans = min(ans, dp[i][N]);
    }

    if(ans==1e9) cout<<0;
    else cout<<ans;
}