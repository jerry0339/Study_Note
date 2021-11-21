// <벽 부수고 이동하기2> - BOJ_14442
// 그래프 이론, BFS, DP

#include <bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x))
#define rall(v) (v).rbegin(), (v).rend()
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<pii> vecpii;
typedef vector<int> veci;
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;

int N,M,K;
bool m[1010][1010]{};
bool vi[1010][1010][11]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int solve(){
	queue<pair<pii,pii>> q;
	q.push({{1,0},{0,0}});
	vi[0][0][0] = true;

	while(!q.empty()){
		int cd = q.front().xx.xx;
		int cw = q.front().xx.yy;
		int cy = q.front().yy.xx;
		int cx = q.front().yy.yy;
		q.pop();

		if(cy==N-1 && cx==M-1) return cd;

		for(int i=0; i<4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
			int nw = cw;
			if(m[ny][nx]) {
				nw++;
				if(vi[ny][nx][nw]) continue;
				if(K<nw) continue;
			}else {
				if(vi[ny][nx][nw]) continue;
			}
			q.push({{cd+1,nw},{ny,nx}});
			vi[ny][nx][nw]=true;
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