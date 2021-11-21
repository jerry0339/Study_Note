// https://www.acmicpc.net/problem/3770

#include<bits/stdc++.h>
using namespace std;

int N,M;
bool m[101][101]{};

void printm(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout<<m[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        m[a][b] = true;
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(m[i][k] && m[k][j]) 
                    m[i][j] = true;
            }
        }
    }

    for(int i=1; i<=N; i++){
        int cnt = 0;
        for(int j=1; j<=N; j++){
            if(!m[i][j] && !m[j][i]) {
                if(i==j) continue;
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
}