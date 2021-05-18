#include<bits/stdc++.h>
using namespace std;
using tpi = tuple<int,int,int>;

int N,M,K,T;
bool vi[2][301][301];
int dy[8] = {-1,-2,-2,-1,1,2,2,1};
int dx[8] = {-2,-1,1,2,2,1,-1,-2};

void move(int t){
    queue<tpi> q;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        q.push({0,a,b});
        vi[0][a][b] = true;
    }

    while(t--){
        if(q.empty()) break;
        int cm, cy, cx;
        tie(cm, cy, cx) = q.front();
        q.pop();

        for(int i=0; i<8; i++){
            int nm = cm^1;
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
            if(vi[nm][ny][nx]) continue;
            q.push({nm, ny, nx});
            vi[nm][ny][nx] = true;
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