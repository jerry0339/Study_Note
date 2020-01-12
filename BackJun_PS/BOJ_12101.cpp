// <1,2,3 더하기 2> - 12101
// DP 이용
#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<n; i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, K;
	cin>>N>>K;
	vector<int> D(N+1);
	D[0]=1, D[1]=1, D[2]=2;
	rep(i, 3, N+1) D[i]=D[i-1]+D[i-2]+D[i-3];

	if(D[N]<K) {
		cout<<-1;
		return 0;
	}

	bool first=true;
	while(N>0) {
		if(!first) cout<<'+';
		first=false;
		if(K<=D[N-1]) N-=1, cout<<1;
		else if(K-D[N-1]<=D[N-2]) K-=D[N-1], N-=2, cout<<2;
		else K-=D[N-1]+D[N-2], N-=3, cout<<3;
	}
}

//http://boj.kr/c1d04693d2774a559b2efb8192c1520e
// DP사용
// c++ 입출력, 함수인자 속도 아래 블로그참고
// https://blog.naver.com/acelhj/221316329745
// <내용>
// 1) ios_base::sync_with_stdio(false); cin.tie(nullptr);
//     ㄴ> sync_with_stdio(false)는 c++ iostream 버퍼와 c의 stdio 버퍼의 동기화에 대한 함수 : false설정시 동기화, iostream만의 버퍼를 만듬
//     ㄴ> cin.tie(nullptr); : 없으면 무조건 cin이랑 cout 들어올 때 버퍼 비움.
// 2) 문자열 함수인자로 받을때는 &을 꼭 이용 ( call by reference )
// 3) int값을 함수인자로 받을때는 그냥 call by value