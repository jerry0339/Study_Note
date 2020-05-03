// <킹세종> - BOJ_8193
// 완전그래프, BFS, 구현
// [참고](https://chris2tg.tistory.com/18)

#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> adj;
bool vi[40001]={1,1,1,0};
int dis[40001]={0,0,3,}; // 1과 2로부터의 거리: 거리가 1or2 이면 1과의 거리가 1,2/ 거리가 4or5이면 2와의 거리가 1,2
long long A=0, B=0, C=0, D=0; // 4구역으로 몰아넣기위한 변수

void search(int HomeOrPC){
    queue<int> q;
    q.push(HomeOrPC);

    while(!q.empty()){
        int n = q.front();
        if(dis[n]==2 || dis[n]==5) break; // node1로부터 거리가2인노드가 2, node2로부터 거리가2인 노드는 5
        q.pop();
        for(auto val : adj[n]){
            if(vi[val]) continue;
            q.push(val);
            dis[val] = dis[n] + 1;
            vi[val] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    adj.resize(N+1);

    for(int i=0; i<M; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    search(1);
    search(2);
    int t=0;

    for(int i=3; i<=N; i++){
        if(dis[i]==1) A++;
        else if(dis[i]==2) B++;
        else if(dis[i]==5) C++;
        else if(dis[i]==4) D++;
        else t++;
    }
    A>D ? B+=t : C+=t; // 거리가0(node1과 node2로부터 거리가 2보다 큰 노드들)인 노드들을 B or C에 몰아넣음(더 많은쪽으로)
    
    long long sum = A+A*B+B*C+C*D+D+A*(A-1)/2+B*(B-1)/2+C*(C-1)/2+D*(D-1)/2; // 완전그래프 간선 총개수
    cout<<sum-M;
}
