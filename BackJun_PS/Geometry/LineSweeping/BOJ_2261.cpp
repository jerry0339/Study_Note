// <가장 가까운 두 점> - BOJ_2261
// Line Sweeping
// 기하학 문제는 아님

#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define pb push_back
#define xx first
#define yy second
using namespace std;;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;

int N;
vector<pii> v; // xx: x pos, yy: y pos
set<pii> s; // xx: y pos, yy: x pos

double dist(pii a, pii b){
	return (double)((b.xx-a.xx)*(b.xx-a.xx) + (b.yy-a.yy)*(b.yy-a.yy));
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
	cin>>N;
	int a,b;
    for(int i=0; i<N; i++){
		cin>>a>>b;
		v.pb({a,b});
	}
	sort(all(v));

	double md = dist(v[0],v[1]);
	s.insert({v[0].yy,v[0].xx});
	s.insert({v[1].yy,v[1].xx});
	
	int st = 0;
	for(int i=2; i<N; i++){
		while(st<i){
			int t = v[i].xx-v[st].xx;
			if(t*t<=md) break;
			else {
				s.erase({v[st].yy, v[st].xx});
				st++;
			}
		}

		int mind = sqrt(md);
		auto lob = s.lower_bound({v[i].yy-mind, -INF});
		auto upb = s.upper_bound({v[i].yy+mind, INF});

		for(auto it = lob; it!=upb; ++it)
			md = min(md, dist({it->yy,it->xx},v[i]));
		
		s.insert({v[i].yy, v[i].xx});
	}

	cout<<(int)md;
}