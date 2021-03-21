#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,dp[101][101]{};

int main(){
    memset(dp,0x3f,sizeof(dp));
    // 입력 memset보다 항상 먼저
    for(int i=0; i<n; ++i) dp[i][i] = 0;
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                
                if(dp[i][k]+dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k]+dp[k][j];
            }
        }
    }
}

