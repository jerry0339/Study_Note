#include<bits/stdc++.h>
using namespace std;
using tpi = tuple<int,int,int>;

int N,M,K,T;
bool vi[2][301][301];
int dy[8] = {-1,-2,-2,-1,1,2,2,1};
int dx[8] = {-2,-1,1,2,2,1,-1,-2};

void move(int k){
    queue<tpi> q1, q2;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        q1.push({0,a,b});
    }
    
    for(int t=1; t<=k; t++){
        queue<tpi> &q = t%2 ? q1 : q2;
        queue<tpi> &nq = t%2 ? q2 : q1;
        if(q.empty()) break;

        while(!q.empty()){
            int cm, cy, cx;
            tie(cm, cy, cx) = q.front();
            q.pop();

            for(int i=0; i<8; i++){
                int nm = cm^1;
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(ny<1 || nx<1 || ny>N || nx>N) continue;
                if(vi[nm][ny][nx]) continue;
                nq.push({nm, ny, nx});
                vi[nm][ny][nx] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K>>T;

    move(T);
    int a,b;
    for(int i=0; i<K; i++){
        cin>>a>>b;
        if(vi[T%2][a][b]) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}