#include<bits/stdc++.h>
using namespace std;

int mod(string num, int a) {
	int res = 0;

	for (int i = 0; i < num.length(); i++)
		res = (res * 10 + (int)num[i] - '0') % a;

	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	string num = "12316767678678";
	cout << mod(num, 10);
	return 0;
}
