// DP와 파스칼의 삼각형을 이용한 Combination 계산

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 1; 


int N,M,K;
// combination계산 결과로 1e9 이상의 값들은 INF처리하는 코드
// dp[n][r] = nCr
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

