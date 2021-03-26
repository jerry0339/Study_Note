// https://www.acmicpc.net/problem/3056

#include<bits/stdc++.h>
using namespace std;

int N;
double m[21][21]{};
double dp[1<<20]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>m[i][j];
        }
    }

    dp[0] = 100.0;
    for(int x=1; x<(1<<N); x++){
        int cnt = -1;
        for(int k=0; k<N; k++) if(x&(1<<k)) cnt++;
        for(int k=0; k<N; k++) {
            if(!(x&(1<<k))) continue; // 0비트면 넘김
            int pre = x^(1<<k);
            dp[x] = max(dp[x], dp[pre]*m[k][cnt]/100.0);
        }
    }

    cout.precision(6);
    cout<<fixed;
    cout<<dp[(1<<N)-1]<<'\n';
}