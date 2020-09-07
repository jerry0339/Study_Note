// <외판원 순회> - BOJ_2098
// Traveling salesman problem
// O(n^2*2^n)
// Top-Down
// Bottom-Up 코드는 코드 아래에 주석처리 (미완)

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
// 이 코드에서는 두 노드사이에 간선이 존재하지 않으면 0으로 표기함.

int N, start=0;
int dp[17][1<<16]{}, m[17][17]{};

int TSP(int now, int visit){
    visit |= (1 << now); // 현재노드(now)를 visit에 업데이트
    // 모든경로 다 돌았을때, 마지막경로에서 시작경로로 길이 있으면 리턴
    if(visit == (1<<N)-1) return m[now][start] ? m[now][start] : INF;

    // 방문체크
    int& ret = dp[now][visit];
    if(ret>0) return ret;
    ret = INF;

    for(int n=0; n<N; n++){ // n: next
        // 방문했거나 길이없으면 continue
        if( (visit&(1<<n))!=0 || m[now][n]==0 ) continue;
        ret = min(ret, TSP(n, visit) + m[now][n]); // min업데이트
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>m[i][j];
    int ans = TSP(0,0);

    // TSP함수는 순회하는 경로가 없으면 INF를 반환
    if(ans==INF) cout<<-1;
    cout<<ans;
}