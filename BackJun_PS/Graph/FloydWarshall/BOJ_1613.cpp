#include<bits/stdc++.h>
using namespace std;
int N,M,Q;
int m[402][402]{};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    memset(m,0x3f,sizeof(m));
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        m[a][b] = 1;
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(m[i][k]==1 && m[k][j]==1)
                    m[i][j] = 1;
            }
        }
    }
    
    cin>>Q;
    while(Q--){
        cin>>a>>b;
        if(m[a][b]==1) cout<<-1<<'\n';
        else if(m[b][a]==1) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}