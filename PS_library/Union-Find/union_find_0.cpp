// BOJ_4195
// 집합의 크기 저장되어 있는 Union Find tree
// (루트노드의 parent에 집합의 크기 저장)

#include<bits/stdc++.h>
using namespace std;

int N,M,T;
int parent[200001]{}; // -1로 초기화 해야 함

// parent 가 -1이면 root로 자신을 반환
int find(int a){
	if(parent[a]<0) return a;
	return parent[a] = find(parent[a]);
}

// merge되는 노드중 루트노드의 parent에는 집합의 크기를,
// 다른 노드의 parent에는 root노드를 저장
void merge(int a, int b){
	a = find(a);
    b = find(b);
	if(a==b) return;
	if(parent[a] < parent[b]) swap(a,b);
	parent[b] += parent[a];
	parent[a] = b;
    // parent[b]에 해당 집합의 크기가 -로 들어가 있음 !
    // -parent[b]를 리턴하면 집합의 크기
}

map<string,int> m;
int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>T;
    
    while(T--){
        cin>>N;
        m.clear();
        memset(parent,-1,sizeof(parent));

        int idx = 0;
        string a,b;
        while(N--){
            cin>>a>>b;
            if(m.count(a)==0) m[a] = idx++;
            if(m.count(b)==0) m[b] = idx++;
            int x = m[a], y = m[b];
            merge(x, y);
            cout<<-parent[find(x)]<<'\n';
        }
    }
}
