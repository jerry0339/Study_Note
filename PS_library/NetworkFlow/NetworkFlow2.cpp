// 네트워크 플로우
// 에드몬드 카프(Edmonds-Karp) 알고리즘 -> brute force
// TC: O(VE^2)
// https://gseok.gitbooks.io/algorithm/content/b124-d2b8-c6cc-d06c-d50c-b85c-c6b0/d3ec-b4dc-d480-cee4-c2a828-ford-fulkerson-c560-b4dc-baac-b4dc-ce74-d50428-edmonds-karp.html

// Maximum Flow

#include<bits/stdc++.h>
#define MAX 52
using namespace std;
const int INF = 0x3f3f3f3f;

int N;
// flo: flow, cap: capacity
int flo[MAX][MAX]{}, cap[MAX][MAX]{}; 
vector<int> adj[MAX]{};

// 에드몬드 카프 Algorithm
// st: Source, ed: Sink
int networkFlow(int st, int ed){ 
    int totalFlow = 0;
    // 역추적, 방문처리 같이 처리
    int prev[MAX]; // prev는 예약어 이므로 전역변수로 선언하지 말기

    while(1){ // 증가경로(augmenting path) BFS로 찾기
        memset(prev, -1, sizeof(prev)); // 방문하지 않았으면 -1처리
        queue<int> q;
        q.push(st);

        while(!q.empty() && prev[ed]==-1){
            int cn = q.front();
            q.pop();
            if(cn == ed) break; 

            for(int i=0; i<adj[cn].size(); i++){
                int next = adj[cn][i];
                if(prev[next]!=-1) continue; // 방문체크
                // 흘러보낼 flow가 있다면 큐에 next노드 삽입
                if(cap[cn][next] - flo[cn][next] > 0) {
                    q.push(next);
                    prev[next] = cn;
                    if(next==ed) break; // sink도착 즉, 증가 경로를 찾았다면 break;
                }
            }
        }

        //BFS에서 증가경로를 발견하지 못했으면 경로찾기 종료
        if(prev[ed]==-1) break;

        // 증가경로 역추적하여 해당경로에서 min flow 찾기
        int flow = INF;
        for (int i=ed; i!=st; i=prev[i]){
            flow = min(flow, cap[prev[i]][i] - flo[prev[i]][i]);
        }
        
        // 증가경로에 해당하는 노드들 min flow 더해줌, 역방향은 빼줌(유량 보존의 법칙)
        for (int i=ed; i!=st; i=prev[i]) {
            flo[prev[i]][i] += flow;
            flo[i][prev[i]] -= flow;
        }

        // 모든 증가경로의 min flow를 더하면 최대유량이므로
        // 또는 Sink(ed)노드와 연결된 노드와의 flow를 모두 더해도 됨
        totalFlow += flow;
    }

    return totalFlow;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    char x,y;
    int a,b,k;
    for(int i=0; i<N; i++){
        cin>>x>>y>>k;
        if(x==y) continue; // self 경로 예외처리
        // 역방향 데이터가 존재하는 경우의 예외처리는 되어있지 않음
        // ex) capacity(a,b) = 3, 
        //     capacity(b,a) = 5 (역방향) : 그래프에 노드를 추가하여 간선을 연결해 주어야 함
        
        if(x>='a' && x<='z') a = x-'a'+26;
        else a = x-'A';
        if(y>='a' && y<='z') b = y-'a'+26;
        else b = y-'A';
        
        adj[a].push_back(b); 
        adj[b].push_back(a);
        cap[a][b] += k;
        cap[b][a] += k; // flow가 아니므로 +k
    }
    
    cout<<networkFlow(0,'Z'-'A');
    return 0;
}