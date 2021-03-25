#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,dp[101][101]{};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cin>>n;
    memset(dp,0x3f,sizeof(dp));// memset을 먼저 ! (INF있는 경우)
    // dp배열 입력받기
    // 간선 가중치로 0이 입력될 수 있는지 확인
    // 노드사이의 간선이 없을때 값으로 0이 들어온다면 INF로 초기화 ! (dp[i][i]=0 과 겹치므로)
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

