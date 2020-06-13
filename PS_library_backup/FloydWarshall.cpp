#include<bits/stdc++.h>
using namespace std;

int n,dp[101][101]{};

int main(){
    //......
    //......
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                // 업데이트시 dp[i][j] = min(dp[i][j], 조건에 의해 계산된dp[i][j]); 를 확인해야 함.
                if(dp[i][k]+dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k]+dp[k][j];
            }
        }
    }
}

