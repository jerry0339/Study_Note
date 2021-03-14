#include<bits/stdc++.h>
using namespace std;
/*
void test() {
    while(d){
		if(d&1) v = b * v;
		b = b * b;
		d >>= 1;
	}
}
*/

long long a,n;
// a의n제곱
// 시간복잡도 : log(n)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>n;

    long long result = 1;
    long long multiply = a;
    while(n>0){
        if(n%2 == 1) result = (result*multiply);
        multiply = (multiply*multiply);
        n /= 2;
    }

    cout<<result;
}

// 재귀버전: 에라테네스의 체를 이용한 소인수분해 참고 -> seive&factorization.cpp
