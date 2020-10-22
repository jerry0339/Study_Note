// <가장 가까운 두 점> - BOJ_2261
// Line Sweeping, closest pair problem
// 2차원 좌표 스위핑 O(NlogN)

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

		int mind = sqrt(md); // double값 int형으로 변환되면서 내림수
		auto lob = s.lower_bound({v[i].yy-mind, -INF}); // (y값 - 내림수)이상
		auto upb = s.upper_bound({v[i].yy+mind, INF}); //  (y값 + 내림수)초과까지의 범위 확인해야 함
		// x좌표도 lob에서는 최소, upb에서는 최대까지 범위에 포함될 수 있도록 각각 -INF, INF로 설정

		for(auto it = lob; it!=upb; ++it) // it: y좌표로 정렬 되어 있는거 조심
			md = min(md, dist({it->yy,it->xx},v[i]));
		
		s.insert({v[i].yy, v[i].xx});
	}

	cout<<(int)md;
}