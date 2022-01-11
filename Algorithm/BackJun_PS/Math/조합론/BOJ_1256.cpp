// 다이나믹 프로그래밍과 파스칼의 삼각형을 이용한 combination계산
// 파스칼의 항등식 : nCr = n-1Cr-1 + n-1Cr

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 1;

int N,M,K;
ll dp[210][110]{};

ll comb(int n, int r) {
    if(n==r || r==0) return 1;
    ll &ret = dp[n][r];
    if(ret==0) {
        ll tmp = comb(n-1, r-1) + comb(n-1, r);
        ret = tmp >= INF ? INF : tmp;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    if(comb(N+M,M) < K) {cout<<-1; return 0;}
    
    int cn = N, cm = M, ck = K;
    for(int i=0; i<N+M; i++){
        if(cn==0) {cout<<'z'; continue;}
        ll now = comb(cn+cm-1, cn-1);
        if(now >= ck) {
            cout<<'a';
            cn--;
        } else {
            cout<<'z';
            ck -= now;
            cm--;
        }
    }
}