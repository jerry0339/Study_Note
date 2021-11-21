// <레드 블루 스패닝 트리> - BOJ_4792
// Diuven님 코드 참고함
// Union-Find

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int B[1010], R[1010];

int find(int x, int U[]){
    return x == U[x] ? x : U[x]=find(U[x],U); 
}

void unite(int x, int y, int U[]){
	x = find(x,U), y = find(y,U);
	U[y] = x;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	cin>>n>>m>>k;
	while(n+m+k>0){
		for(int i=1; i<=n; i++) B[i] = R[i] = i;
		for(int i=1; i<=m; i++){
			char c; int u, v; cin>>c>>u>>v;
			// U집합에는 B간선이 연결 되어 있는 노드들의 집합
			// V집합에는 R간선과 연결 되어 있는 노드들의 집합
			unite(u,v,(c=='B' ? B : R)); 
		}
		
		// R or B 간선의 개수는 최소0 , 최대 N-1 이지만
		// 집합에서 find(i) = i 인 노드가 반드시 한개 존재하므로 아래와 같이 초기화
		int x = -1, y = n;

		for(int i=1; i<=n; i++){
			x += find(i,R)==i; // R간선과 연결 안되어 있는 노드들의 개수 = 최소 B간선의 개수
			y -= find(i,B)==i; // B간선과 연결 안되어 있는 노드들의 개수 = 최소 R간선의 개수 => 최대 B간선의 개수 구할 수 있음
		}

		// x<= K <=y 라면 조건 만족하므로 1 출력
		cout<<(x<=k && k<=y)<<'\n';
		cin>>n>>m>>k;
	}

	return 0;
}