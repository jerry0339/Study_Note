// <블록 정리> - BOJ_2937
// 2D prefix sum

#include<bits/stdc++.h>
using namespace std;

int N,M;
int m[101][101]{};
int ps[101][101]{};

inline int calSum(int a, int b, int c, int d){
    if(c>N || d>N) return 0;
    int x=a,y=b,x2=c,y2=d;
    int sum_ = ps[x2][y2] - ps[x-1][y2] - ps[x2][y-1] + ps[x-1][y-1];
    return sum_;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b;
    for(int i=0; i<M; i++) {
        cin>>a>>b;
        m[a][b]=1;
    }

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            ps[i][j] = m[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
    
    int ans = 1e9;
    for(int k=1; k<=M; k++){
        if(M%k) continue;
        int l = M/k;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                ans = min(ans,M-calSum(i, j, i+k-1, j+l-1));
            }
        }
    }
    cout<<ans;
}