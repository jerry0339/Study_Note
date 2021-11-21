// <플로이드2> - BOJ_11780
// 플로이드 와샬, 재귀(트리 느낌)

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N,M;
int m[101][101]{};
int m2[101][101]{};
vector<int> v;

void solve(int i, int j){ 
    int mid = m2[i][j];
    if(mid==0) {
        v.push_back(i);
        v.push_back(j);
        return;
    }
    solve(i,mid);
    v.pop_back();
    solve(mid,j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b,c;
    memset(m,0x3f,sizeof(m));
    for(int i=1; i<=N; i++) m[i][i] = 0;
    while(M--){
        cin>>a>>b>>c;
        if(m[a][b]==INF) {
            m[a][b] = c;
        }else{
            m[a][b] = min(m[a][b],c);
        }
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(m[i][j] > m[i][k] + m[k][j]) {
                    m[i][j] = m[i][k] + m[k][j];
                    m2[i][j] = k;
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout<<m[i][j]<<' ';
        }cout<<'\n';
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(m[i][j]==0 || m[i][j]==INF) {cout<<0<<'\n'; continue;}
            v.clear();
            solve(i,j);
            cout<<v.size()<<' ';
            for(auto val : v) cout<<val<<' ';
            cout<<'\n';
        }
    }
}