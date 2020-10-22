// <벽 부수고 이동하기3> - BOJ_16933
// 그래프 이론, BFS, DP

#include <bits/stdc++.h>
using namespace std;

int N,M,K;
bool m[1010][1010]{};
bool vi[1010][1010][11][2]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

struct Node{
	int d,w,y,x,dn;// dis,wall,y,x, day&night(0&1)
	Node(int d_, int w_, int y_, int x_, int dn_)
	:d(d_), w(w_), y(y_), x(x_), dn(dn_){}
}; 

int solve(){
	queue<Node> q;
	q.emplace(Node(1,0,0,0,0));
	vi[0][0][0][0] = true;

	while(!q.empty()){
		int cd = q.front().d;
		int cw = q.front().w;
		int cy = q.front().y;
		int cx = q.front().x;
		int cdn = q.front().dn;
		q.pop();

		if(cy==N-1 && cx==M-1) return cd;
		
		int ndn = (cdn+1)%2;
		if(!vi[cy][cx][cw][ndn]) {
			q.emplace(Node(cd+1,cw,cy,cx,ndn));
			vi[cy][cx][cw][ndn] = true;
		}
		for(int i=0; i<4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
			int nw = cw;
			if(m[ny][nx]){
				nw++;
				if(vi[ny][nx][nw][ndn]) continue;
				if(nw>K) continue;
				if(cdn) continue;
			} else if(vi[ny][nx][nw][ndn]) continue;
			q.emplace(Node(cd+1,nw,ny,nx,ndn));
			vi[ny][nx][nw][ndn] = true;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
	cin>>N>>M>>K;
	string str;
	for(int i=0; i<N; i++){
		cin>>str;
		for(int j=0; j<M; j++){
			m[i][j] = str[j] - '0';
		}
	}

	cout<<solve();
}