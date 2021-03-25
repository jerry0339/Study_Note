// <외판원 순회> - BOJ_2098
// TSP-> 비트마스킹

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N;
int m[16][16]{};
int dp[1<<16][16]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>m[i][j];
            if(!m[i][j]) m[i][j]=INF;
        }
    }

    memset(dp,0x3f,sizeof(dp));
    dp[1][0] = 0; // 0번째를 첫번째 방문으로 고정
    for(int x=2; x<(1<<N); x++){
        if(!(x&1)) continue;
        for(int i=1; i<N; i++){
            if(!(x&(1<<i))) continue;
            int pre = x^(1<<i);

            for(int j=0; j<N; j++){
                // pre에서 j번째를 방문한 경우만 dp[pre][j]를 이용하여 계산할 수 있도록 함
                if(!(pre&(1<<j))) continue; // 이거 작성안해서 계속 오류남
                dp[x][i] = min(dp[x][i], dp[pre][j]+m[j][i]);
            }
        }
    }
    int res=INF;
    // 0번째를 첫방문으로 고정했으므로 (최소값 + 0번으로 가는 간선 가중치) 구해줌
    for(int i=1; i<N; i++)
        res = min(res, dp[(1<<N)-1][i] + m[i][0]);
    cout<<res;
}