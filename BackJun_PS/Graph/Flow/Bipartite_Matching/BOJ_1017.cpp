// 소수 쌍
// 이분매칭 -> 한 그룹에서 이분매칭
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
    find_prime();
    cin>>N;
    int t;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(sieve[arr[i]+arr[j]]==-1) {
                adj[i].push_back(j); // 양쪽으로 간선 추가
                adj[j].push_back(i); // 양쪽으로 간선 추가
            }
        }
    }

    vector<int> ans;
    for(auto next : adj[0]){
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        int res = 1;
        A[0] = next;
        B[next] = 0;
        A[next] = 0;
        B[0] = next;
        for(int i=1; i<N; i++){
            if(A[i]==-1){
                memset(vi, 0, sizeof(vi));
                vi[0] = true;
                vi[next] = true;
                if(dfs(i)) res++;
            }
        }
        if(res==N/2) ans.push_back(arr[next]);
    }
    if(ans.size()==0) cout<<-1;
    else {
        sort(ans.begin(), ans.end());
        for(auto val : ans) cout<<val<<' ';
    }
}