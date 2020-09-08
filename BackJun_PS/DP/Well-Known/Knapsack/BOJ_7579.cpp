// <앱> BOJ_7579
// DP - 냅색

#include<bits/stdc++.h>
using namespace std;

int N,M,sum=0;
int m[101]{}, c[101]{};
int dp[2][10001]{};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++) cin>>m[i];
    for(int i=0; i<N; i++) {
        cin>>c[i];
        sum+=c[i];
    }

    // 아래처럼 j=0부터 인덱싱할때 dp를 1차원으로 사용하면,
    // dp[j-c[i]]에서 해당 인덱스는 이미 계산되어 업데이트 되어 있기때문에
    // dp배열을 2차원으로 주어 업데이트할때 따로 저장하여 계산
    for(int i=0; i<N; i++){
        for(int j=0; j<c[i]; j++) dp[!(i%2)][j] = dp[i%2][j]; // 밑의 for문이 c[i]부터 시작하므로 이전dp값들 저장
        for(int j=c[i]; j<=sum; j++){
            dp[!(i%2)][j] = max(dp[i%2][j],dp[i%2][j-c[i]]+m[i]);
        }
    }
    /*
    // j=sum 에서 j--로 뒤에서부터 인덱싱하여 DP하면 일차원dp배열로 해결 가능
    for(int i=0; i<N; i++){
        for(int j=sum; j>=c[i]; j--){
            dp[j] = max(dp[j], dp[j-c[i]]+m[i]);
        }
    }
    */

    for(int i=0; i<=sum; i++){
        if(dp[N%2][i]>=M) {cout<<i; break;}
    }

}