// BOJ_1017 소수 쌍 문제 변형한 코드
// 이분매칭 : 한 그룹에서의 이분매칭

// 추가해야 할 부분 주석처리 했음

#include<bits/stdc++.h>
#define MAX 2000
using namespace std;

int N;
int arr[50]{};
int sieve[MAX+1];
vector<int> adj[51]{};
int A[51]{};
int B[51]{};
bool vi[51]{};

void find_prime(){
    memset(sieve, -1, sizeof(sieve));
    for(int i=2; i*i<=MAX; ++i)
        if(sieve[i] == -1)
            for(int j=i*i; j<=MAX; j+=i)
                if(sieve[j] == -1)
                    sieve[j] = i;
}

bool dfs(int cur){
    if(vi[cur]) return false;
    vi[cur] = true;
    for(auto next : adj[cur]){
        if(B[next]==-1 || dfs(B[next])){
            A[cur] = next; // 양쪽으로 매칭
            B[next] = cur; // 양쪽으로 매칭
            A[next] = cur; // 양쪽으로 매칭
            B[cur] = next; // 양쪽으로 매칭
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    find_prime();
    int t;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(sieve[arr[i]+arr[j]]==-1) { // 매칭 가능한 조건: ex) arr[i]와 arr[j]를 더하면 소수인가 ?
                adj[i].push_back(j); // 양쪽으로 간선 추가
                adj[j].push_back(i); // 양쪽으로 간선 추가
            }
        }
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    int ans = 0;
    for(int i=0; i<N; i++){
        if(A[i]==-1){ // 양쪽으로 추가되면서 뒤의 인덱스i도 매칭될 수 있으므로 방문확인
            memset(vi, 0, sizeof(vi));
            if(dfs(i)) ans++;
        }
    }
    cout<<ans;
}

/*
24
752 5 686 93 402 403 784 279 612 137 622 139 680 995 562 987 152 411 564 993 528 29 802 997

*/