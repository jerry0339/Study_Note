// <숨바꼭질 5> - BOJ_17071
// BFS + 빡구현
// 구현: 위치가 p일때 i*2초후 p로 다시 돌아올 수 있음을 이용(위치 -1,+1 또는 +1,-1 더하는식...)
//       따라서 i초일때 동생의 위치에 수빈이가 갈 수 있는지 없는지를 알아내려면 
//       수빈이가 해당 위치에 짝수or홀수 초에 갈 수 있는지 없는지를 알아내야 하므로 vi[2][MAX]와 같이 설정.
//       즉 vi[2][MAX]라고 설정했다는 것은, 0~MAX까지의 길을 2가지 방법으로 방문처리를 한다는 것을 나타냄.

#include<bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
typedef pair<int,int> pii;
const int MAX = 5e5;

int N,K;
int bro[MAX+1];
bool vi[2][MAX+1]={0,};
int minsec = MAX;

void bfs(int start) {
    queue<pii> q;
    q.push(make_pair(0,start));
    vi[0][start] = true;

    while(!q.empty()){
        int cdis = q.front().xx;
        int cpos = q.front().yy;
        q.pop();

        if(bro[cpos]!=-1 && bro[cpos]>= cdis){
            if((bro[cpos]-cdis)%2==0){
                minsec = min(minsec,bro[cpos]);
            }
        }

        int ndis = cdis+1;
        int npos[3] = {cpos*2, cpos-1, cpos+1};
        for(int i=0; i<3; i++) {
            if(npos[i]<0 || npos[i]>MAX) continue;
            if(vi[ndis%2][npos[i]]) continue;
            q.push(make_pair(ndis,npos[i]));
            vi[(ndis%2)][npos[i]] = ndis;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    memset(bro,-1,sizeof(bro));

    int t=K;
    for(int i=0; i<=MAX; i++){
        t += i;
        if(t>MAX) break;
        bro[t] = i;
    }

    bfs(N);

    if(minsec==MAX) cout<<"-1";
    else cout<<minsec;
}