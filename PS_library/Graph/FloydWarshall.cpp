#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,dp[101][101]{};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cin>>n;
    memset(dp,0x3f,sizeof(dp));// memset을 항상 먼저 !!
    // 입력받을곳. 
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

