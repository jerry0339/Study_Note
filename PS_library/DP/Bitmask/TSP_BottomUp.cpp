// <외판원 순회> - BOJ_2098
// TSP-> 비트마스킹
// K번째를 첫번째 방문으로 고정하여 작성한 코드

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

    int K = 0; // 입력, 조건 확인
    memset(dp,0x3f,sizeof(dp));
    dp[1<<K][K] = 0; // K번째를 첫번째 방문으로 고정

    for(int x=(1<<K)+1; x<(1<<N); x++){ //K방문을 전제조건으로 가지므로 마스크 탐색은 K방문 이후부터
        if(!(x&(1<<K))) continue; // 마스크가 K방문이 안되어 있으면 넘김
        for(int i=0; i<N; i++){
            if((i==K) || !(x&(1<<i))) continue; // pre계산위해 i번 비트가 K비트이거나 0비트라면 넘김
            int pre = x^(1<<i);
            for(int j=0; j<N; j++){
                // pre에서 j번째를 방문한 경우만 dp[pre][j]를 이용하여 계산할 수 있도록 함
                if(!(pre&(1<<j))) continue;
                dp[x][i] = min(dp[x][i], dp[pre][j]+m[j][i]);
            }
        }
    }

    int res=INF;
    // K번째를 첫방문으로 고정했으므로 (최소값 + K번으로 가는 간선 가중치) 구해줌
    for(int i=0; i<N; i++){
        if(i==K) continue;
        res = min(res, dp[(1<<N)-1][i] + m[i][K]);
    }
    cout<<res;
}