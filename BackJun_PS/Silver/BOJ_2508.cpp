// <사탕 박사 고창영> - 2508
// string클래스 : find(), substr(), length() 함수 이용
#include <bits/stdc++.h>
#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, cnt = 0;
    cin >> N;

    while (N--) {
        
        int a, b;
        cin >> a >> b;
        vector<string> str1(a);
        vector<string> str2(b);

        rep(i, 0, a) {
            cin >> str1[i]; // 문자들 str1에 입력받음.

            //가로사탕 검색
            int c = str1[i].find(">o<");
            string cut = str1[i];
            while (c != -1) {
                cnt++;
                cut = cut.substr(c + 3, cut.length());
                c = cut.find(">o<");
            }
        }

        //transpose 시킴
        rep(i, 0, b) {
            rep(j, 0, a) { // str1문자들 transpose시켜 str2에 입력
                str2[i].push_back(str1[j][i]);
            }

            // 세로사탕 검색
            int c = str2[i].find("vo^");
            string cut = str2[i];
            while (c != -1) {
                cnt++;
                cut = cut.substr(c + 3, cut.length());
                c = cut.find("vo^");
            }
        }

        cout << cnt << "\n";
        cnt = 0;
    }
}

/*
input :
2

6 6
vvvvvv
oooooo
^^^^^^
vvvvvv
oooooo
^^^^^^

5 4
.>o<
v.^.
ooo.
^.^.
>o<<

output :
12
3

*/