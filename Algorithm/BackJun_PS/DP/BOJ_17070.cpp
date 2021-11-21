// <파이프 옮기기1> - BOJ_17070
// DP

#include<bits/stdc++.h>
using namespace std;

int N;
int m[20][20]{};
int dp[20][20][3];

bool chk(int y, int x){
    if(y<1 || x<1 || y>N || x>N) return false;
    else return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin>>m[i][j];

    dp[1][2][0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(m[i][j]) continue;
            if(chk(i,j-1)) dp[i][j][0] += (dp[i][j-1][0] + dp[i][j-1][2]);
            if(chk(i-1,j)) dp[i][j][1] += (dp[i-1][j][1] + dp[i-1][j][2]);
            if(chk(i-1,j-1)) {
                if(m[i][j-1] || m[i-1][j]) continue;
                dp[i][j][2] += (dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]);
            }
        }
    }

    cout<<dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
}