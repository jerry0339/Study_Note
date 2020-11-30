// <수들의 합> - BOJ_2268
// 펜윅트리

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Fenwick {
	vector<ll> psum;
	Fenwick(int N) {
		psum.resize(N+1,0);
	}
	void add(int i, ll val) {
		while(i<psum.size()){
			psum[i]+=val;
			i+=i&-i;
		}
	}
	ll sum(int i) {
		ll ret=0;
		while(i>0){
			ret+=psum[i];
			i-=i&-i;
		}
		return ret;
	}
	ll rangeSum(int i, int j) {
		return sum(j) - sum(i-1);
	}
	void change(int i, ll val) {
		ll before = rangeSum(i,i);
		add(i, val - before);
	}
};
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M;cin>>N>>M;
	Fenwick fw(N);
	while(M--){
		ll a, b, c; cin>>a>>b>>c;
		if(a==0){
			if(b>c) swap(b,c);
			cout<<fw.rangeSum(b,c)<<"\n";
		}
		else if(a==1) {
			fw.change(b,c);
		}
	}
}