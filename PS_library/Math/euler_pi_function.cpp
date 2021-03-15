// BOJ_11689

#include <iostream>
using namespace std;
typedef long long ll;

ll n;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin>>n;
	ll pi = n;
	ll prime = 2;

	while (prime * prime <= n) {
		if (n % prime == 0)
			pi = pi / prime * (prime - 1);
		while (n % prime == 0) // n에 prime 소인수를 전부 제거
			n = n / prime;
		prime++;
	}

	if (n != 1) { // 소인수가 남아있다면
		pi = pi / n * (n - 1);
	}
	cout<<pi;
}