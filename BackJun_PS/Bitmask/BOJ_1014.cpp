// <컨닝> - BOJ_1014
// 비트마스킹, DP

#include<bits/stdc++.h>
using namespace std;

int N,M,T;
int m[11]{};
int dp[11][1<<10]{};

int bitCount(int A){
  if(A == 0) return 0;
  return A%2 + bitCount(A / 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        memset(m,0,sizeof(m));
        cin>>N>>M;
        string str;
        for(int i=0; i<N; i++){
            cin>>str;
            for(int j=0; j<M; j++){
                if(str[j]=='x') m[i]+=(1<<j);
            }
        }

        for(int x=0; x<(1<<M); x++){
            for(int k=0; k<M; k++){
                if(!(x&(1<<k))) continue;
                if(k!=0 && x&(1<<(k-1))) {
                    for(int i=0; i<N; i++) dp[i][x]=-1;
                    break;
                }
                if(k!=M-1 && x&(1<<(k+1))) {
                    for(int i=0; i<N; i++) dp[i][x]=-1;
                    break;
                }
            }
        }

        for(int x=0; x<(1<<M); x++){ // 기저 -> 첫번째 줄(N-1) 계산
            if(m[N-1]&x) dp[N-1][x]=-1;
            if(dp[N-1][x]==-1) continue;
            int sum = 0;
            for(int k=0; k<M; k++) if((1<<k)&x) sum++; // 1비트 개수 계산
            dp[N-1][x] = sum;
        }

        //for(int x=0; x<(1<<M); x++) cout<<dp[N-1][x]<<' ';

        for(int i=N-2; i>=0; i--){ // cur row
            for(int x=0; x<(1<<M); x++){ // cur bit
                if(m[i]&x) dp[i][x]=-1;
                if(dp[i][x]==-1) continue;
                int sum = 0;
                for(int k=0; k<M; k++) if((1<<k)&x) sum++; // 1비트 개수 계산
                for(int y=0; y<(1<<M); y++){ // pre bit
                    if(dp[i+1][y]==-1) continue;
                    bool chk = true;
                    for(int k=0; k<M; k++){
                        if(!(y&(1<<k))) continue;
                        if(k!=0 && x&(1<<(k-1))) {chk = false; break;}
                        if(k!=M-1 && x&(1<<(k+1))) {chk = false; break;}
                    }
                    if(!chk) continue;
                    dp[i][x] = max(dp[i][x], dp[i+1][y]+sum);
                }
            }
        }
        
        int res=0;
        for(int x=0; x<(1<<M); x++) res = max(res, dp[0][x]);
        cout<<res<<'\n';
    }

}