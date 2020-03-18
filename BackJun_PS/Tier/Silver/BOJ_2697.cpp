// <다음수 구하기> - BOJ_2697
// 테스트 케이스 수는 최대 80자리의 자연수가 들어갈 수 있으므로 정수형으로는 풀이가 불가능
// next_permutation()을 이용한 풀이

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    while (n--) {
        string num; cin >> num;
        if (next_permutation(num.begin(), num.end()))
            cout << num << '\n';
        else cout << "BIGGEST\n";

    }
}