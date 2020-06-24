// <조합> - BOJ_2407
// 파스칼의 삼각형 이용
// N범위가 100 -> 100C50 -> 30자리수로 1e19까지 표현가능한 long long범위를 벗어남.
// 따라서 dp[102][102][2]와 같이 선언하여 [0]에15자리까지, [1]에 16~30자리까지 담아서 출력함.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long dp[102][102][2]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    N++; M++;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            if(j==1) dp[i][j][0]=(ll)1;
            else if(j==i)dp[i][j][0]=(ll)1;
            else{
                ll t = dp[i-1][j][0] + dp[i-1][j-1][0];
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j-1][0])%(ll)1e16;
                dp[i][j][1] += t/(ll)1e16;
                dp[i][j][1] += (dp[i-1][j][1] + dp[i-1][j-1][1]);
            }
        }
    }
    
    if(dp[N][M][1]) cout<<dp[N][M][1];
    cout<<dp[N][M][0];
}