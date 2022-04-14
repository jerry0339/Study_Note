// <집합의 표현> - BOJ_1717
// Union Find = 분리집합 = disjoint_set

#include<bits/stdc++.h>
using namespace std;

int N,M;
int parent[1000010]{};

// parent 배열을 이용하여 노드들을 트리 형태로 저장할 수 있음
int find(int k) {
    if (k == parent[k]) return k;
    else return parent[k] = find(parent[k]); // 경로 압축 최적화
    // find(k) 과정에서 탐색되는 노드들의 부모노드가 모두 최상위 노드로 설정됨 -> 경로 압축 최적화
    // 경로 압축 최적화가 안된 코드 : return find(parent[u])
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

// 사용예시
int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M;
    int a,b,c;
    for(int i=0; i<=N; i++) parent[i] = i;
    while(M--){
        cin>>a>>b>>c;
        if(a){
            find(b)==find(c) ? cout<<"YES\n" : cout<<"NO\n";
        }else{
            merge(b,c);
        }
    }

}

