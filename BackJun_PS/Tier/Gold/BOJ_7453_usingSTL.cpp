// <합이 0인 네 정수> - BOJ_7453
// stl함수를 이용한 풀이 - equal_range, distance: 반복자

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for(int i=0; i<n; i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	vector<int> sa, sb;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++){
		sa.push_back(a[i]+b[j]); sb.push_back(-c[i]-d[j]);
	}

	sort(sa.begin(), sa.end());
	sort(sb.begin(), sb.end());
    
	long long ans = 0;
	for(auto i : sa){
		auto it = equal_range(sb.begin(), sb.end(), i);
		ans += distance(it.first, it.second);
	}
	cout << ans;
}