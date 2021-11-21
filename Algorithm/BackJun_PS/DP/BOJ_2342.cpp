#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int n, i;
int dp[100001][5][5]{};

int calDist(int a, int b){
    if(a==b) return 1;
    if(a==0) return 2;
    a--, b--;
    if((a+1)%4==b || (a+3)%4==b) return 3;
    else if((a+2)%4 == b) return 4;
    else return INF;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;

    for(i=1; ; i++){
        cin>>n;
        if(n==0) break;
        for(int x=0; x<5; x++) {
            for(int y=0; y<5; y++){
                if(dp[i-1][x][y]>=INF) continue;
                int a = calDist(x,n);
                int b = calDist(y,n);
                dp[i][x][n] = min(dp[i][x][n], dp[i-1][x][y] + b); // y->n
                dp[i][n][y] = min(dp[i][n][y], dp[i-1][x][y] + a); // x->n
            }
        }
    }

    i--;
    int ans = INF;
    for(int x=0; x<5; x++){
        for(int y=0; y<5; y++){
            ans = min(ans, dp[i][x][y]);
        }
    }
    cout<<ans;
}