// <본대산책> - BOJ_12849
// 2차원 DP

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

vector<vector<int>> adj(10);
int dp[100001][10]{}; // [D분][node]
int N;
inline void ip(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void init(){
    ip(1,2); ip(1,3);
    ip(2,3); ip(2,4);
    ip(3,4); ip(3,6);
    ip(4,5); ip(4,6);
    ip(5,6); ip(5,7);
    ip(6,8); ip(7,8);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    init();
    dp[1][2] = 1;
    dp[1][3] = 1;
    for(int d=2; d<=N; d++){
        for(int i=1; i<=9; i++){
            for(auto val : adj[i]){
                dp[d][i] = (dp[d][i] + dp[d-1][val])%MOD;
            }
        }
    }
    
    cout<<dp[N][1];
}