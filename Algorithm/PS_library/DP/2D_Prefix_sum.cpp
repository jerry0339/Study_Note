// <구간 합 구하기 5> BOJ_11660
// prefix sum : 2차원배열

#include<bits/stdc++.h>
using namespace std;

int N,M;
int m[1025][1025]={0,};
int preSum[1025][1025]={0,};
int x,y,x2,y2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++){
            cin>>m[i][j];
            preSum[i][j] = m[i][j] + preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1];
        }
    }

    int sum_;
    for(int i=0; i<M; i++){
        cin>>x>>y>>x2>>y2;
        sum_ = preSum[x2][y2] - preSum[x-1][y2] - preSum[x2][y-1] + preSum[x-1][y-1];
        cout<<sum_<<'\n';
    }
}