#include<bits/stdc++.h>
using namespace std;

int N,M;
int par[100001]{};
int sum[100001]{};
int dp[100001]{};

int solve(int n){
    if(n==-1) return 0;
    if(dp[n]!=-1) return dp[n];
    else dp[n] = sum[n];
    return dp[n] += solve(par[n]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b;
    for(int i=1; i<=N; i++){
        cin>>a;
        par[i] = a;
    }
    for(int i=0; i<M; i++){
        cin>>a>>b;
        sum[a] += b;
    }
    
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=N; i++){
        cout<<solve(i)<<' ';
    }

}