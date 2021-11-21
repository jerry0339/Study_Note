// <벽 부수고 이동하기 4> - BOJ_16946
// 그래프이론, BFS, 사이클탐색으로 품

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

int N,M;
int m[1010][1010]{};
pii dp[1010][1010]{}; // set num, number of 0
bool vi[1010][1010]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void solve(int sty, int stx, int setn){
	vector<pii> v;
	queue<pii> q;
	q.push({sty,stx});
	vi[sty][stx] = true;
	v.pb({sty,stx});

	int sets = 1;
	while(!q.empty()){
		int cy = q.front().xx;
		int cx = q.front().yy;
		q.pop();

		for(int i=0; i<4; i++){
			int ny = cy+ dy[i];
			int nx = cx+ dx[i];
			if(ny<0 || nx<0 || ny>=N || nx>=M || vi[ny][nx] || m[ny][nx]) continue;
			q.push({ny,nx});
			vi[ny][nx] = true;
			v.pb({ny,nx});
			sets++;
		}
	}

	for(int i=0; i<v.size(); i++){
		dp[v[i].xx][v[i].yy] = {setn, sets};
	}
}

set<int> ss;
int ans[1010][1010]{};
int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
	cin>>N>>M;
	string str;
	for(int i=0; i<N; i++){
		cin>>str;
		for(int j=0; j<M; j++){
			m[i][j] = str[j]-'0';
		}
	}
	int setn = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(m[i][j]) continue;
			else {
				if(vi[i][j]) continue;
				solve(i,j,setn++);
			}
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(!m[i][j]) continue;
			ans[i][j] = 1;
			ss.clear();
			for(int k=0; k<4; k++){
				int ni = i+dy[k];
				int nj = j+dx[k];
				if(ni<0 || nj<0 || ni>=N || nj>=M || ss.count(dp[ni][nj].xx)) continue;
				ss.insert(dp[ni][nj].xx);
				ans[i][j] += dp[ni][nj].yy;
			}
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout<<ans[i][j]%10;
		}cout<<'\n';
	}
}