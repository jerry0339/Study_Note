// <단어정렬> - 1181
// 중복제거 unique함수말고 간단하게(c++11이상), sort조건 설정(cmp함수) 
#include<bits/stdc++.h>
using namespace std;

bool cmp(string &p1, string &p2) {
    if (p1.length() == p2.length())
        return p1 < p2;
    else return p1.length() < p2.length();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        // 중복 제거하기 위한 조건 ...!
        if (v[i] != v[i + 1]) cout << v[i] << "\n"; 
        // c++11 이후만 적용가능 c++버전에서는 컴파일에러남. (v[i+1]에서 index out of range)
    }
}