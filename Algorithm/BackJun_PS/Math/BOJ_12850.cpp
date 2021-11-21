// <본대산책2> - BOJ_12850
// 분할정복을 이용한 거듭제곱(fast_pow), 인접행렬의 제곱(그래프 탐색)-수학,
// 인접행렬을 N제곱할 경우, adj[i][j]는 i에서 j까지 (N-1)개의 노드를 거쳐서 갈 수 있는 모든경로의 수 를 나타냄(노드i,j포함)
// 단, 노드 사이의 거리가 1로 일정하다고 가정

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7; // MOD_size
const int AS = 8; // Array_Size

ll adj[AS+1][AS+1]{}; // 초기 행렬
ll radj[AS+1][AS+1]{}; // result Adj
ll madj[AS+1][AS+1]{}; // multi Adj
ll t[AS+1][AS+1]{}; // tmp
ll N; // N제곱

//인접행렬 직접 초기화
/*******************************************/
inline void ip(ll a, ll b){
    adj[a][b]=1;
    adj[b][a]=1;
}
void init(){
    ip(1,2); ip(1,3);
    ip(2,3); ip(2,4);
    ip(3,4); ip(3,6);
    ip(4,5); ip(4,6);
    ip(5,6); ip(5,7);
    ip(6,8); ip(7,8);
}
/*******************************************/

//출력 확인용
void printAdj(ll (*a)[AS+1]){ // 깊은복사 아님
    for(int i=1; i<=AS; i++){
        for(int j=1; j<=AS; j++){
            cout<<a[i][j]<<' ';
        }cout<<'\n';
    }
}

// a=b; 수행
void setAdj(ll (*a)[AS+1], ll (*b)[AS+1]){ // 깊은복사 아님
    for(int i=1; i<=AS; i++){
        for(int j=1; j<=AS; j++){
            a[i][j] = b[i][j];
        }
    }
}

// t = a*b; 수행
void multiAdj(ll (*a)[AS+1], ll (*b)[AS+1]){ // 깊은복사 아님
    memset(t,0,sizeof(t));
    for(int i=1; i<=AS; i++){
        for(int j=1; j<=AS; j++){
            for(int k=1; k<=AS; k++){
                t[i][j] = (t[i][j] + (a[i][k]*b[k][j]))%MOD;
            }
        }
    }
}

// resultAdj(a), multiAdj(0), n : a^n (O(logn))
void powAdj(ll n){
    for(int i=1; i<=AS; i++) radj[i][i] = 1;
    setAdj(madj,adj);

    while(n>0){
        if(n%2 == 1) {
            multiAdj(radj,madj);
            setAdj(radj,t);
        }
        multiAdj(madj,madj);
        setAdj(madj,t);
        n /= 2;
    }
    //printAdj(radj);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    init(); // 인접행렬 초기화
    powAdj(N); // 행렬^N (O(logn))
    cout<<radj[1][1]; // N번의 간선으로 1로 다시 돌아오는 경우의 수
}