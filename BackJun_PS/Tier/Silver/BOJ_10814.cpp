// <나이순 정렬> - 10814
// stable_sort(), pair 클래스이용 (make_pair()함수도 사용)
// +a : 2차원 벡터를 이용한 정답출력(주석처리된 코드)

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,string> p1, pair<int,string> p2){
    if(p1.first == p2.first) return false; // first가 같을경우, 즉 second는 비교하지 않음
    else return p1.first < p2.first; // first만 오름차순
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    int age; string name;
    vector<pair<int, string>> id;

    for(int i=0; i<n; i++) {
        cin>>age>>name;
        id.push_back(make_pair(age,name));
    }
    stable_sort(id.begin(),id.end(),cmp);

    for (pair<int, string> value : id) {
		cout << value.first << ' ' << value.second << '\n';
	}
}

// 신박한 방법....
/*
vector<vector<string>> v; // 2차원 string배열로 v[나이][이름]

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n; v.resize(201); // 나이가 1~200까지이므로 인덱스 0 ~ 200까지 할당
	for (int i = 0; i < n; i++) {
		int age; string name; cin >> age >> name; v[age].push_back(name);
	}

	for (int i = 1; i <= 200; i++) // 나이 인덱스
		for (int j = 0; j < v[i].size(); j++) // 해당나이의 size 즉 이름이 들어가 있을때 출력
			cout << i << " " << v[i][j] << '\n';
}
*/